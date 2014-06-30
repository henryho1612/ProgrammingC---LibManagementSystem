#include "changestatusform.h"
#include "ui_changestatusform.h"

ChangeStatusForm::ChangeStatusForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeStatusForm)
{
    ui->setupUi(this);

    //Initialize for comboboxes
    QList<QString> types;
    types.append("Barcode");
    types.append("Title/Author");
    ui->typeCBB->addItems(types);
}

ChangeStatusForm::~ChangeStatusForm()
{
    delete ui;
}

//Get data model from main
void ChangeStatusForm::setDb(list<MultimediaCollection> &cols,
                          list<CopyCollection> &copies,
                          list<Borrower> &borrowers)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
}

bool ChangeStatusForm::checkBidExist(QString bid)
{
    list<Borrower>::iterator it = borrowers->begin();
    while(it != borrowers->end())
    {
        if(it->getBorrowerId() == bid)
            return true;
        *it++;
    }

    return false;
}

bool ChangeStatusForm::checkValidBid(QString bid)
{
    if(bid.length() != 8)
    {
        return false;
    } else {
        if(bid.at(0) != 's' && bid.at(0) != 'l' && bid.at(0) != 'v')
        {
            return false;
        } else {
            return true;
        }
    }
}

void ChangeStatusForm::on_searchBtn_clicked()
{
    //ui->tableWidget->setColumnCount(2);
    //ui->tableWidget->setItem(0, 0, new QTableWidgetItem("it->getCid())"));
    //ui->tableWidget->setItem(0, 1, new QTableWidgetItem("adfdfad"));
    //ui->tableWidget->setItem(0, 2, new QTableWidgetItem("jfaifadfd"));
    //qDebug() << ui->tableWidget->item(0,0)->text().append("abc");
    qDebug() << ui->tableWidget->size();
    qDebug() << "adfadsfadfa";
    //ui->tableWidget->showRow(0);
    /*
    //Remove old items and content
    listCBB.clear();
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);

    //Getting the input
    QString typeSearch = ui->typeCBB->currentText();
    QString textSearch = ui->searchF->text();


    //Search by barcode
    if(typeSearch == "Barcode")
    {
        list<CopyCollection>::iterator it = copies->begin();
        int result = 0; //Check how many result rows
        while(it != copies->end())
        {
            if(it->getBarcode() == textSearch)
            {
                ui->tableWidget->setItem(result, 0, new QTableWidgetItem(it->getBarcode()));
                ui->tableWidget->setItem(result, 1, new QTableWidgetItem(it->getBorrowingTimes()));

                //Setup status combobox
                QComboBox *temp = new QComboBox;
                items.append(it->getStatus());
                if(it->getStatus() != "In Library")
                    items.append("In Library");
                if(it->getStatus() != "Borrowed")
                    items.append("Borrowed");
                if(it->getStatus() != "In Storeroom")
                    items.append("In Storeroom");
                if(it->getStatus() != "Lost")
                    items.append("Lost");

                temp->addItems(items);

                //ui->tableWidget->setCellWidget(result, 2, temp);

                listCBB.push_back(temp);

                result++;
            }

            *it++;
        }

        //Handle result
        if(result == 0)
        {
            ui->error->setText("No matching barcode!");
        }
        else
        {
            ui->error->setText("");
        }
    }

    //Search by title/author
    if(typeSearch == "Title/Author")
    {
        list<MultimediaCollection>::iterator it = cols->begin();
        int result = 0;
        while(it != cols->end())
        {
            if(it->getTitle().contains(textSearch) || it->getPublisher().contains(textSearch))
            {
                list<CopyCollection>::iterator it1 = copies->begin();
                while(it1 != copies->end())
                {
                    if(it1->getCid() == it->getCid())
                    {
                        ui->tableWidget->setItem(result, 0, new QTableWidgetItem(it1->getBarcode()));
                        ui->tableWidget->setItem(result, 1, new QTableWidgetItem(it1->getBorrowingTimes()));

                        //Setup status combobox
                        QComboBox *temp = new QComboBox;
                        items.append(it1->getStatus());
                        if(it1->getStatus() != "In Library")
                            items.append("In Library");
                        if(it1->getStatus() != "Borrowed")
                            items.append("Borrowed");
                        if(it1->getStatus() != "In Storeroom")
                            items.append("In Storeroom");
                        if(it1->getStatus() != "Lost")
                            items.append("Lost");

                        temp->addItems(items);
                        //ui->tableWidget->setCellWidget(result, 2, temp);

                        listCBB.push_back(temp);

                        result++;
                    }
                    *it1++;
                }
            }
            *it++;
        }

        if(result == 0)
        {
            ui->error->setText("No matching title/author!");
        }
        else
        {
            ui->error->setText("");
        }
    }

    qDebug() << listCBB.size();
    */
}

