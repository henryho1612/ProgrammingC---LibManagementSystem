#include "showallcollections.h"
#include "ui_showallcollections.h"
#include <QtSql>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QStaticText>
#include <QFont>

showAllCollections::showAllCollections(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showAllCollections)
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSortingEnabled(true);

    QList<QString> items;
    items.append("Select List Type");
    items.append("List By Type");
    items.append("List By DataType");
    items.append("List By Category");

    ui->comboBox->addItems(items);
}

showAllCollections::~showAllCollections()
{
    delete ui;
}

void showAllCollections::setDb(list<MultimediaCollection> &cols,
                          list<CopyCollection> &copies,
                          list<Borrower> &borrowers)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
}

//Press search button
void showAllCollections::on_pushButton_clicked()
{
    QString textSearch = ui->lineEdit->text();
    list<MultimediaCollection>::iterator it = cols->begin();
    int count = 0;
    while(it != cols->end())
    {
        if(it->getCid().contains(textSearch) || it->getTitle().contains(textSearch)
                || it->getPublisher().contains(textSearch)
                || QString::number(it->getRecordedYear()).contains(textSearch))
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getCid()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(it->getCollectionType().getName()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(it->getDataType().getName()));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(it->getTitle()));
            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(it->getPublisher()));
            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(it->getNumCopies())));

            int numInLibrary = 0;
            int numBorrowed = 0;

            list<CopyCollection> cC = it->getCopyCollections();
            list<CopyCollection>::iterator subIt = cC.begin();
            while(subIt != cC.end())
            {
                if(subIt->getStatus() == "In Library")
                    numInLibrary++;
                if(subIt->getStatus() == "Borrowed")
                    numBorrowed++;
                *subIt++;
            }

            ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number(numInLibrary)));
            ui->tableWidget->setItem(count, 7, new QTableWidgetItem(QString::number(numBorrowed)));
            count++;
        }
        *it++;
    }

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cid"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Type"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("DataType"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Title"));
    ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Publisher"));
    ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Num Copies"));
    ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("Availability"));
    ui->tableWidget->setHorizontalHeaderItem(7, new QTableWidgetItem("NoIsBorrowing"));
}

void showAllCollections::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "List By Type")
    {
        ui->tableWidget->setColumnCount(7);
        ui->tableWidget->setRowCount(cols->size());
        int count = 0;

        list<MultimediaCollection>::iterator it = cols->begin();
        while (it != cols->end())
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getCid()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(it->getCollectionType().getName()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(it->getTitle()));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(it->getPublisher()));
            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number(it->getNumCopies())));

            int numInLibrary = 0;
            int numBorrowed = 0;

            list<CopyCollection> cC = it->getCopyCollections();
            list<CopyCollection>::iterator subIt = cC.begin();
            while(subIt != cC.end())
            {
                if(subIt->getStatus() == "In Library")
                    numInLibrary++;
                if(subIt->getStatus() == "Borrowed")
                    numBorrowed++;
                *subIt++;
            }

            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(numInLibrary)));
            ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number(numBorrowed)));
            qDebug() << numInLibrary << " " << numBorrowed;
            count++;
            *it++;
        }

        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cid"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Type"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Title"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Publisher"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Num Copies"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Availability"));
        ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("NoIsBorrowing"));
    }

    if(arg1 == "List By DataType")
    {
        ui->tableWidget->setColumnCount(7);
        ui->tableWidget->setRowCount(cols->size());
        int count = 0;

        list<MultimediaCollection>::iterator it = cols->begin();
        while (it != cols->end())
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getCid()));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(it->getDataType().getName()));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(it->getTitle()));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(it->getPublisher()));
            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number(it->getNumCopies())));

            int numInLibrary = 0;
            int numBorrowed = 0;

            list<CopyCollection> cC = it->getCopyCollections();
            list<CopyCollection>::iterator subIt = cC.begin();
            while(subIt != cC.end())
            {
                if(subIt->getStatus() == "In Library")
                    numInLibrary++;
                if(subIt->getStatus() == "Borrowed")
                    numBorrowed++;
                *subIt++;
            }

            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(numInLibrary)));
            ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number(numBorrowed)));
            qDebug() << numInLibrary << " " << numBorrowed;
            count++;
            *it++;
        }

        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cid"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("DataType"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Title"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Publisher"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Num Copies"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Availability"));
        ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("NoIsBorrowing"));
    }

    if(arg1 == "List By Category")
    {
        ui->tableWidget->setColumnCount(7);
        ui->tableWidget->setRowCount(cols->size());
        int count = 0;

        list<MultimediaCollection>::iterator it = cols->begin();
        while (it != cols->end())
        {
            ui->tableWidget->setItem(count, 0, new QTableWidgetItem(it->getCid()));
            list<Category> categories = it->getCategories();
            list<Category>::iterator cateIt = categories.begin();
            QString cate = "";
            while(cateIt != categories.end())
            {
                cate += cateIt->getName() + " ";
                cateIt++;
            }
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem(cate));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem(it->getTitle()));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(it->getPublisher()));
            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number(it->getNumCopies())));

            int numInLibrary = 0;
            int numBorrowed = 0;

            list<CopyCollection> cC = it->getCopyCollections();
            list<CopyCollection>::iterator subIt = cC.begin();
            while(subIt != cC.end())
            {
                if(subIt->getStatus() == "In Library")
                    numInLibrary++;
                if(subIt->getStatus() == "Borrowed")
                    numBorrowed++;
                *subIt++;
            }

            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(numInLibrary)));
            ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number(numBorrowed)));
            qDebug() << numInLibrary << " " << numBorrowed;
            count++;
            *it++;
        }

        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Cid"));
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Category"));
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Title"));
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Publisher"));
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Num Copies"));
        ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Availability"));
        ui->tableWidget->setHorizontalHeaderItem(6, new QTableWidgetItem("NoIsBorrowing"));
    }
}

void showAllCollections::closeEvent(QCloseEvent *event)
{
    mW->show();
    event->accept();
}

void showAllCollections::keyPressEvent(QKeyEvent *key)
{
    if(key->key() == Qt::Key_Escape)
    {
        mW->show();
        showAllCollections::reject();
    }
}

void showAllCollections::print(QPrinter *printer)
{
    //create painter for drawing print page
    QPainter painter( printer );
    int w = printer->pageRect().width();
    int h = printer->pageRect().height();
    QRect page( 0, 0, w, h );

    //reate a font appropriate to page size
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

    //QStaticText test = "abc";

    // draw labels in corners of page
    painter.drawText( page, Qt::AlignTop    | Qt::AlignLeft, "QSimulate" );
    painter.drawText( page, Qt::AlignBottom | Qt::AlignLeft, QString(getenv("USER")) );
    painter.drawText(page, Qt::AlignCenter | Qt::AlignLeft, content);
    painter.drawText( page, Qt::AlignBottom | Qt::AlignRight,
                      QDateTime::currentDateTime().toString( Qt::DefaultLocaleShortDate ) );


    // draw simulated landscape
    page.adjust( w/20, h/20, -w/20, -h/20 );
    //m_scene->render( &painter, page );
    QGraphicsScene *scene = new QGraphicsScene;
    scene->render(&painter, page);

    delete scene;
}

void showAllCollections::on_printpreviewBnt_clicked()
{
    //display print preview dialog
    QPrinter printer( QPrinter::HighResolution );
    QPrintPreviewDialog preview( &printer, this );
    connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(print(QPrinter*)) );
    preview.exec();
}

void showAllCollections::on_printBtn_clicked()
{
    //display print dialog and if accepted print
    QPrinter printer( QPrinter::HighResolution );
    QPrintDialog dialog( &printer, this );
    if ( dialog.exec() == QDialog::Accepted ) print( &printer );
}
