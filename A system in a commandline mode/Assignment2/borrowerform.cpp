#include "borrowerform.h"
#include "ui_borrowerform.h"
#include <sstream>
#include <ctime>
#include <QGraphicsScene>
#include <QStaticText>
#include <QFont>

BorrowerForm::BorrowerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BorrowerForm)
{
    ui->setupUi(this);

    //Set cells of table widget uneditable
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Set columns sortable
    ui->tableWidget->setSortingEnabled(true);

    //Add item form combo box
    QList<QString> items;
    items.append("Select List Type");
    items.append("Basic Info Borrower");
    items.append("Overdue Borrower");

    ui->comboBox->addItems(items);
}

BorrowerForm::~BorrowerForm()
{
    delete ui;
}

//Get data model from main
void BorrowerForm::setDb(list<MultimediaCollection> &cols,
                          list<CopyCollection> &copies,
                          list<Borrower> &borrowers)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
}

//Handle combo box selected item
void BorrowerForm::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //List basic information of borrower
    if(arg1 == "Basic Info Borrower")
    {
        ui->tableWidget->setColumnCount(6); //Set num columns of table - 6
        ui->tableWidget->setRowCount(borrowers->size()); //Set num rows of table
        qDebug() << "Num copies " << QString::number(borrowers->size());

        list<Borrower>::iterator it = borrowers->begin();

        //Display data
        int count = 0;
        while(it != borrowers->end())
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getBorrowerId()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(it->getName()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(it->getMobile()));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QString::number(it->getNoReturnedLate())));

            //Calculate num copies borrow in the past and current
            int passBorrow = 0;
            int curBorrow = 0;

            list<History> histories = it->getHistories();
            list<History>::iterator subIt = histories.begin();
            while(subIt != histories.end())
            {
                if(subIt->isReturned() == 0)
                    passBorrow++;
                else
                    curBorrow++;

                *subIt++;
            }

            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number(passBorrow)));
            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(curBorrow)));

            count++;
            *it++;
        }

        //Build table header
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Borrower ID"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Full Name"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Mobile"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("No Return Late"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Pass Borrow"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Cur Borrow"));
    }

    //Overdue borrowers
    if(arg1 == "Overdue Borrower")
    {
        ui->tableWidget->setColumnCount(8); //Set num columns of table - 7

        list<Borrower>::iterator it = borrowers->begin();
        int count = 0;
        while(it != borrowers->end())
        {
            //Travelling history of borrower
            list<History> histories = it->getHistories();
            list<History>::iterator subIt = histories.begin();
            while(subIt != histories.end())
            {
                //If there is a copy collection is not returned
                if(subIt->isReturned() == 1)
                {
                    //Check if overdue
                    QString date = subIt->getBorrowingDate();
                    if(calNumDays(date) > subIt->getBorrowingDays())
                    {
                        int daysLate = calNumDays(date) - subIt->getBorrowingDays();
                        //Insert new row
                        //ui->tableWidget->insertRow(1);

                        //Display information
                        ui->tableWidget->setItem(count, 0, new QTableWidgetItem(subIt->getBorrowerId()));
                        ui->tableWidget->setItem(count, 1, new QTableWidgetItem(it->getName()));
                        ui->tableWidget->setItem(count, 2, new QTableWidgetItem(it->getMobile()));

                        CopyCollection tempCop = findCopyCollection(subIt->getBarcode());
                        MultimediaCollection tempCol = findCollection(tempCop.getCid());

                        ui->tableWidget->setItem(count, 3, new QTableWidgetItem(tempCol.getCid()));
                        ui->tableWidget->setItem(count, 4, new QTableWidgetItem(tempCol.getTitle()));
                        ui->tableWidget->setItem(count, 5, new QTableWidgetItem(subIt->getBorrowingDate()));
                        ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number(subIt->getBorrowingDays())));
                        ui->tableWidget->setItem(count, 7, new QTableWidgetItem(QString::number(daysLate)));
                    }

                    count++;
                }

                *subIt++;
            }

            *it++;
        }

        //Build table header
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Borrower ID"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Full Name"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Mobile"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Cid"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Title"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Date Borrow"));
        ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Num Days"));
        ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("Days Late"));
    }
}

//Source code: http://answers.yahoo.com/question/index?qid=20120927094228AAagMFB
//This calculate how many date from julian date to current
int BorrowerForm::julianDays(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    if (year > 1582 || (year == 1582 && month > 10) || (year == 1582 && month == 10 && day >= 15))
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    else
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
}

//Calculate how may date from the date as parameter to current.
int BorrowerForm::calNumDays(QString date)
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    int curYear = now->tm_year + 1900;
    int curMonth = now->tm_mon+1;
    int curDay = now->tm_mday;
    int curHour = now->tm_hour;
    int curMinute = now->tm_min;

    int year, month, day, hour, minute;

    string d = date.toStdString();
    stringstream(d.substr(6,4)) >> year;
    stringstream(d.substr(0,2)) >> day;
    stringstream(d.substr(3,2)) >> month;
    stringstream(d.substr(11,2)) >> hour;
    stringstream(d.substr(13,2)) >> minute;

    int julianCur = julianDays(curYear, curMonth, curDay);
    int julianBorrowed = julianDays(year, month, day);

    int days = julianCur - julianBorrowed;
    if(curHour*60 + curMinute > hour*60 + minute)
        days++;

    return days;
}

//Find a collection by its id
MultimediaCollection BorrowerForm::findCollection(QString id)
{
    list<MultimediaCollection>::iterator it = cols->begin();
    while(it != cols->end())
    {
        if(it->getCid() == id)
            return *it;
        *it++;
    }

    //return NULL;
}

//Find a copy collection by barcode
CopyCollection BorrowerForm::findCopyCollection(QString barcode)
{
    list<CopyCollection>::iterator it = copies->begin();
    while(it != copies->end())
    {
        if(it->getBarcode() == barcode)
            return *it;
        *it++;
    }
    //return NULL;
}

void BorrowerForm::closeEvent(QCloseEvent *event)
{
    mW->show();
    event->accept();
}

void BorrowerForm::keyPressEvent(QKeyEvent *key)
{
    if(key->key() == Qt::Key_Escape)
    {
        mW->show();
        BorrowerForm::reject();
    }
}

void BorrowerForm::on_previewBtn_clicked()
{
    //display print preview dialog
    QPrinter printer( QPrinter::HighResolution );
    QPrintPreviewDialog preview( &printer, this );
    connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
    preview.exec();
}

void BorrowerForm::on_printBtn_clicked()
{
    //display print dialog and if accepted print
    QPrinter printer( QPrinter::HighResolution );
    QPrintDialog dialog( &printer, this );
    if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}

void BorrowerForm::print(QPrinter *printer)
{
    //create painter for drawing print page
    QPainter painter( printer );
    int w = printer->pageRect().width();
    int h = printer->pageRect().height();
    QRect page( 0, 0, w, h );

    // create a font appropriate to page size
    QFont font = painter.font();
    font.setPixelSize( (w+h) / 100 );
    painter.setFont( font );

    QStaticText toPrint;

    QString content;
    content.append("<table><tr>");
    for(int i=0; i<ui->tableWidget->columnCount(); i++)
    {
        content.append("<td>");
        content.append(ui->tableWidget->horizontalHeaderItem(i)->text());
        content.append("</td>");
    }
    content.append("</tr>");
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        content.append("<tr>");
        for(int j=0; j<ui->tableWidget->columnCount(); j++)
        {
            content.append("<td>");
            content.append(ui->tableWidget->item(i,j)->text());
            content.append("</td>");
        }
        content.append("</tr>");
    }
    content.append("</table>");
    toPrint.setText(content);

    // draw labels in corners of page
    painter.drawText( page, Qt::AlignTop    | Qt::AlignLeft, "Assignment2 - C++" );
    painter.drawText(page, Qt::AlignCenter | Qt::AlignLeft, content);
    painter.drawText( page, Qt::AlignBottom | Qt::AlignRight,
                      QDateTime::currentDateTime().toString( Qt::DefaultLocaleShortDate ) );


    page.adjust( w/20, h/20, -w/20, -h/20 );

    QGraphicsScene *scene = new QGraphicsScene;
    scene->render(&painter, page);

    delete scene;
}


