#include "addborrowerform.h"
#include "ui_addborrowerform.h"
#include <QMessageBox>

AddBorrowerForm::AddBorrowerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBorrowerForm)
{
    ui->setupUi(this);

    //Initialize for comboboxes
    QList<QString> roles;
    roles.append("Student");
    roles.append("Lecture");
    ui->roleCBB->addItems(roles);

    QList<QString> departments;
    departments.append("BIT");
    ui->departmentCBB->addItems(departments);

}

AddBorrowerForm::~AddBorrowerForm()
{
    delete ui;
}

//Get data model from main
void AddBorrowerForm::setDb(list<MultimediaCollection> &cols,
                          list<CopyCollection> &copies,
                          list<Borrower> &borrowers , DatabaseHandler *db)
{
    this->cols = &cols;
    this->copies = &copies;
    this->borrowers = &borrowers;
    this->dbHandler = db;
}

void AddBorrowerForm::on_okBtn_clicked()
{
    QString borrowerId = ui->bidF->text();
    QString name = ui->nameF->text();
    QString mobile = ui->mobileF->text();
    QRegExp mobileReg("[0-9]{10,11}");

    if(!checkValidBid(borrowerId))
    {
        ui->bidErr->setText("Wrong Format! Example: s1234567");
        ui->bidF->setFocus();
    }
    else {
        ui->bidErr->setText("");
        if(checkBidExist(borrowerId))
        {
            ui->bidErr->setText("Borrower Exists!");
            ui->bidF->setFocus();
        }
        else
        {
            ui->bidErr->setText("");
            //validate name input
            if(name.length() == 0)
            {
                ui->nameErr->setText("No Data Input!");
                ui->nameF->setFocus();
            }
            else
            {
                ui->nameErr->setText("");
                //validate mobile phone
                if (!mobileReg.exactMatch(mobile))
                {
                    ui->mobileErr->setText("Wrong Format! (9/10 numbers)");
                    ui->mobileF->setFocus();
                }
                else
                {
                    ui->mobileErr->setText("");
                    Role role(ui->roleCBB->currentIndex()+1, ui->roleCBB->currentText());
                    Department department(ui->departmentCBB->currentIndex()+1, ui->departmentCBB->currentText());
                    Borrower newBorrower(borrowers->size()+1, borrowerId, name, role, department, mobile, 0, 0);

                    borrowers->push_back(newBorrower);

                    dbHandler->insertBorrower(&newBorrower);

                    QMessageBox::about(0, QObject::tr("Information"),
                                       "Add New Borrower Successfully!");
                    this->clearFocus();
                    this->close();
                }
            }
        }
    }
}

void AddBorrowerForm::on_cancelBtn_clicked()
{
    this->clearFocus();
    this->hide();
}

bool AddBorrowerForm::checkBidExist(QString bid)
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

bool AddBorrowerForm::checkValidBid(QString bid)
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

