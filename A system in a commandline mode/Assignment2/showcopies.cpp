#include "showcopies.h"
#include "ui_showcopies.h"
#include <sstream>
#include <ctime>
#include <QtSql>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QStaticText>
#include <QFont>

showCopies::showCopies(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showCopies)
{
    ui->setupUi(this);

    //Set cells of table widget uneditable
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Set columns sortable
    ui->tableWidget->setSortingEnabled(true);

    //Add item form combo box
    QList<QString> items;
    items.append("Select List Type");
    items.append("List Current Borrowed");
    items.append("List Overdue");
    items.append("List All");

    ui->comboBox->addItems(items);
}

showCopies::~showCopies()
{
    delete ui;
}

//Get data model from main
void showCopies::setDb(list<MultimediaCollection> &cols,
                          list<CopyCollection> &copies,
                          list<Borrower> &borrowers)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
}

//Handle combo box selected item
void showCopies::on_comboBox_currentIndexChanged(const QString &arg1)
{
    //List copies that currently borrowed
    if(arg1 == "List Current Borrowed")
    {
        ui->tableWidget->setColumnCount(6); //Set num columns of table - 6

        int row = 0; //num rows of table
        qDebug() << "Num copies " << QString::number(copies->size());
        list<CopyCollection>::iterator it = copies->begin();
        while(it != copies->end())
        {
            if(it->getDateBorrowed().length() > 1)
                row++;
            *it++;
        }
        ui->tableWidget->setRowCount(row);
        qDebug() << "Num row: " << row;

        //Display data
        int count = 0;
        it = copies->begin();
        while(it != copies->end())
        {
            //Check if copies that currently borrowed
            if(it->getStatus() == "Borrowed")
            {
                //Display Cid and barcode
                ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getCid()));
                ui->tableWidget->setItem(count, 1, new QTableWidgetItem(it->getBarcode()));

                list<MultimediaCollection>::iterator subIt = cols->begin();
                while(subIt != cols->end())
                {
                    if(it->getCid() == subIt->getCid())
                    {
                        //Display title and publisher of this copy
                        ui->tableWidget->setItem(count, 2, new QTableWidgetItem(subIt->getTitle()));
                        ui->tableWidget->setItem(count, 3, new QTableWidgetItem(subIt->getPublisher()));
                    }
                    *subIt++;
                }

                //Display date borrowed and num days borrowed
                ui->tableWidget->setItem(count, 4, new QTableWidgetItem(it->getDateBorrowed()));
                ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(it->getNumDayBorrowed())));          

                count++;
            }

            *it++;
        }

        //Build table header
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cid"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Barcode"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Title"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Publisher"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Date Borrowed"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Days Borrowed"));
    }

    //List overdue copies
    if(arg1 == "List Overdue")
    {
        //Set number of column the table has
        ui->tableWidget->setColumnCount(7);

        int row = 0; //Remember number of rows the table has
        list<CopyCollection>::iterator it = copies->begin();
        while(it != copies->end())
        {
            if(it->getStatus() == "Borrowed"
                    && calNumDays(it->getDateBorrowed()) > it->getNumDayBorrowed())
                row++;
            *it++;
        }
        ui->tableWidget->setRowCount(row);

        //Display data
        it = copies->begin();
        int count = 0;
        while(it != copies->end())
        {
            //Check if copies that currently borrowed but overdue
            if(it->getStatus() == "Borrowed"
                    && calNumDays(it->getDateBorrowed()) > it->getNumDayBorrowed())
            {
                qDebug() << "Num days from current " << calNumDays(it->getDateBorrowed());
                //Display Cid and barcode
                ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getCid()));
                ui->tableWidget->setItem(count, 1, new QTableWidgetItem(it->getBarcode()));

                list<MultimediaCollection>::iterator subIt = cols->begin();
                while(subIt != cols->end())
                {
                    if(it->getCid() == subIt->getCid())
                    {
                        //Diplay title and publisher
                        ui->tableWidget->setItem(count, 2, new QTableWidgetItem(subIt->getTitle()));
                        ui->tableWidget->setItem(count, 3, new QTableWidgetItem(subIt->getPublisher()));
                    }
                    subIt++;
                }

                //Display date borrowed and num days borrowed
                ui->tableWidget->setItem(count, 4, new QTableWidgetItem(it->getDateBorrowed()));
                ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(it->getNumDayBorrowed())));

                //Calculate how many days late and display
                int numDays = calNumDays(it->getDateBorrowed()) - it->getNumDayBorrowed();
                ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number(numDays)));

                count++;
            }

            *it++;
        }

        //Table headers
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cid"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Barcode"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Title"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Publisher"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Date Borrowed"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Days Borrowed"));
        ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Late Days"));
    }

    if(arg1 == "List All")
    {
        ui->tableWidget->setColumnCount(6); //Set num columns of table - 6


        //Display data
        int count = 0;
        list<CopyCollection>::iterator it = copies->begin();
        while(it != copies->end())
        {
            //Display Cid and barcode
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getCid()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(it->getBarcode()));

            list<MultimediaCollection>::iterator subIt = cols->begin();
            while(subIt != cols->end())
            {
                if(it->getCid() == subIt->getCid())
                    {
                        //Display title and publisher of this copy
                        ui->tableWidget->setItem(count, 2, new QTableWidgetItem(subIt->getTitle()));
                        ui->tableWidget->setItem(count, 3, new QTableWidgetItem(subIt->getPublisher()));
                    }
                *subIt++;
            }
            //Display date borrowed and num days borrowed
            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(it->getDateBorrowed()));
            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(it->getNumDayBorrowed())));

            count++;
            *it++;
        }

        //Build table header
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cid"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Barcode"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Title"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Publisher"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Date Borrowed"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Days Borrowed"));
    }
}


//Source code: http://answers.yahoo.com/question/index?qid=20120927094228AAagMFB
//This calculate how many date from julian date to current
int showCopies::julianDays(int year, int month, int day)
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
int showCopies::calNumDays(QString date)
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

void showCopies::closeEvent(QCloseEvent *event)
{
    mW->show();
    event->accept();
}

void showCopies::keyPressEvent(QKeyEvent *key)
{
    if(key->key() == Qt::Key_Escape)
    {
        mW->show();
        showCopies::reject();
    }
}

void showCopies::on_previewBtn_clicked()
{
    //display print preview dialog
    QPrinter printer( QPrinter::HighResolution );
    QPrintPreviewDialog preview( &printer, this );
    connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
    preview.exec();
}

void showCopies::on_printBtn_clicked()
{
    //display print dialog and if accepted print
    QPrinter printer( QPrinter::HighResolution );
    QPrintDialog dialog( &printer, this );
    if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}

void showCopies::print(QPrinter *printer)
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
