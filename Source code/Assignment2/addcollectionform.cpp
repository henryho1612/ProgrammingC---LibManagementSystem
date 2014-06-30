#include "addcollectionform.h"
#include "ui_addcollectionform.h"
#include <QMessageBox>
#include "copystatusform.h"

AddCollectionForm::AddCollectionForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCollectionForm)
{
    ui->setupUi(this);

    //Initialize for comboboxes
    QList<QString> types;
    types.append("Dvd");
    types.append("Vcd");
    types.append("Blu-ray");
    ui->typeCBB->addItems(types);

    QList<QString> datatypes;
    datatypes.append("Images");
    datatypes.append("Video");
    datatypes.append("Audio");
    ui->datatypeCBB->addItems(datatypes);

    QList<QString> years;
    for(int i=1800; i<2014; i++)
        years.append(QString::number(i));
    ui->yearCBB->addItems(years);

    QList<QString> numCopies;
    for(int i=20; i<31; i++)
    {
        numCopies.append(QString::number(i));
    }
    ui->numcopiesCBB->addItems(numCopies);

}

AddCollectionForm::~AddCollectionForm()
{
    delete ui;
}

//Get data model from main
void AddCollectionForm::setDb(list<MultimediaCollection> &cols,
                              list<CopyCollection> &copies,
                              list<Borrower> &borrowers,
                              DatabaseHandler *db)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
    this->dbHandler = db;
}

void AddCollectionForm::on_okBtn_clicked()
{
    QRegExp cidRegex ("[A-Z]+[0-9]{4,}");
    QRegExp versionRegex ("([0-9]+\\.{1}[0-9]{1,2}\\.*)+");
    QRegExp durationRegex ("[0-9]{2,3}");

    QString cid = ui->cidF->text();
    if(!cidRegex.exactMatch(cid))
    {
        ui->cidErr->setText("Wrong Format! Example A0001");
        ui->cidF->setFocus();
    }
    else {
        if(checkCidExist(cid))
        {
            ui->cidErr->setText("Collection Id existed!");
            ui->cidF->setFocus();
        }
        else {
            ui->cidErr->setText("");
            QString title = ui->titleF->text();
            if(title.length() < 4)
            {
                ui->titleErr->setText("Title too short!");
                ui->titleF->setFocus();
            } else {
                ui->titleErr->setText("");
                QString version = ui->versionF->text();
                if(!versionRegex.exactMatch(version))
                {
                    ui->versionErr->setText("Wrong Format! Example 1.1.0");
                    ui->versionF->setFocus();
                } else {
                    ui->versionErr->setText("");
                    QString publisher = ui->publisherF->text();
                    if(publisher.length() < 4)
                    {
                        ui->publisherErr->setText("Publisher too short!");
                        ui->publisherF->setFocus();
                    } else {
                        ui->publisherErr->setText("");
                        QString duration = ui->durationF->text();
                        if(!durationRegex.exactMatch(duration))
                        {
                            ui->durationErr->setText("Wrong Format! 10-999");
                            ui->durationF->setFocus();
                        } else {
                            int counter = 0;
                            ui->durationErr->setText("");

                            //Add new collection
                            QString type = ui->typeCBB->currentText();
                            QString datatype = ui->datatypeCBB->currentText();
                            int recordYear = ui->yearCBB->currentText().toInt();


                            CollectionType colType(ui->typeCBB->currentIndex()+1, type);
                            CollectionDataType colDataType(ui->datatypeCBB->currentIndex()+1,datatype);

                            list<Category> categories;
                            if(ui->animationCB->isChecked())
                            {
                                counter++;
                                Category cate1(1,ui->animationCB->text());
                                categories.push_back(cate1);
                            }
                            if(ui->adventureCB->isChecked())
                            {
                                counter++;
                                Category cate2(2,ui->adventureCB->text());
                                categories.push_back(cate2);
                            }
                            if(ui->fantasyCB->isChecked())
                            {
                                counter++;
                                Category cate3(3,ui->fantasyCB->text());
                                categories.push_back(cate3);
                            }
                            if(ui->comedyCB->isChecked())
                            {
                                counter++;
                                Category cate4(4,ui->comedyCB->text());
                                categories.push_back(cate4);
                            }
                            if(ui->dramaCB->isChecked())
                            {
                                counter++;
                                Category cate5(5,ui->dramaCB->text());
                                categories.push_back(cate5);
                            }

                            if (counter == 0)
                            {
                                QMessageBox::critical(0, QObject::tr("Information"),
                                                   "At least 1 category mus be chosen!");
                            }
                            else
                            {
                                MultimediaCollection mc(cols->size()+1, cid, title, colType,
                                                        colDataType, version, publisher, recordYear,
                                                        duration.toInt());

                                mc.setCategories(categories);
                                int numCopies = ui->numcopiesCBB->currentText().toInt();

                                CopyStatusForm copySF;
                                copySF.setModal(true);
                                copySF.aCF = this;
                                copySF.dbHandler = this->dbHandler;
                                copySF.setDb(cols, copies, numCopies, mc);
                                qDebug() << "Test pos1!";
                                copySF.buildUI();
                                qDebug() << "Test pos2!";
                                copySF.setFocus();
                                copySF.exec();
                            }
                        }
                    }
                }
            }

        }
    }

}

bool AddCollectionForm::checkCidExist(QString cid)
{
    list<MultimediaCollection>::iterator it = cols->begin();
    while(it != cols->end())
    {
        if(it->getCid() == cid)
            return true;

        *it++;
    }

    return false;
}

void AddCollectionForm::on_cancelBtn_clicked()
{
    this->clearFocus();
    this->hide();
}
