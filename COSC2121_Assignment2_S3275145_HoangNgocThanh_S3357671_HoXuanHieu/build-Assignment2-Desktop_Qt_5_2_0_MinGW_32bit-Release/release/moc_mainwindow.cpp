/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Assignment2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata[521];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 22),
QT_MOC_LITERAL(4, 57, 24),
QT_MOC_LITERAL(5, 82, 20),
QT_MOC_LITERAL(6, 103, 21),
QT_MOC_LITERAL(7, 125, 20),
QT_MOC_LITERAL(8, 146, 20),
QT_MOC_LITERAL(9, 167, 25),
QT_MOC_LITERAL(10, 193, 20),
QT_MOC_LITERAL(11, 214, 37),
QT_MOC_LITERAL(12, 252, 31),
QT_MOC_LITERAL(13, 284, 32),
QT_MOC_LITERAL(14, 317, 32),
QT_MOC_LITERAL(15, 350, 35),
QT_MOC_LITERAL(16, 386, 30),
QT_MOC_LITERAL(17, 417, 33),
QT_MOC_LITERAL(18, 451, 32),
QT_MOC_LITERAL(19, 484, 35)
    },
    "MainWindow\0on_listColBtn_clicked\0\0"
    "on_listCopyBtn_clicked\0on_listBorrowBtn_clicked\0"
    "on_addColBtn_clicked\0on_addCopyBtn_clicked\0"
    "on_borrowBtn_clicked\0on_returnBtn_clicked\0"
    "on_addBorrowerBtn_clicked\0"
    "on_statusBtn_clicked\0"
    "on_actionAdd_New_Collection_triggered\0"
    "on_actionAdd_New_Copy_triggered\0"
    "on_actionBorrow_A_Copy_triggered\0"
    "on_actionReturn_A_Copy_triggered\0"
    "on_actionShow_Collections_triggered\0"
    "on_actionShow_Copies_triggered\0"
    "on_actionShow_Borrowers_triggered\0"
    "on_actionChange_Status_triggered\0"
    "on_actionAdd_New_Borrower_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08,
       3,    0,  105,    2, 0x08,
       4,    0,  106,    2, 0x08,
       5,    0,  107,    2, 0x08,
       6,    0,  108,    2, 0x08,
       7,    0,  109,    2, 0x08,
       8,    0,  110,    2, 0x08,
       9,    0,  111,    2, 0x08,
      10,    0,  112,    2, 0x08,
      11,    0,  113,    2, 0x08,
      12,    0,  114,    2, 0x08,
      13,    0,  115,    2, 0x08,
      14,    0,  116,    2, 0x08,
      15,    0,  117,    2, 0x08,
      16,    0,  118,    2, 0x08,
      17,    0,  119,    2, 0x08,
      18,    0,  120,    2, 0x08,
      19,    0,  121,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_listColBtn_clicked(); break;
        case 1: _t->on_listCopyBtn_clicked(); break;
        case 2: _t->on_listBorrowBtn_clicked(); break;
        case 3: _t->on_addColBtn_clicked(); break;
        case 4: _t->on_addCopyBtn_clicked(); break;
        case 5: _t->on_borrowBtn_clicked(); break;
        case 6: _t->on_returnBtn_clicked(); break;
        case 7: _t->on_addBorrowerBtn_clicked(); break;
        case 8: _t->on_statusBtn_clicked(); break;
        case 9: _t->on_actionAdd_New_Collection_triggered(); break;
        case 10: _t->on_actionAdd_New_Copy_triggered(); break;
        case 11: _t->on_actionBorrow_A_Copy_triggered(); break;
        case 12: _t->on_actionReturn_A_Copy_triggered(); break;
        case 13: _t->on_actionShow_Collections_triggered(); break;
        case 14: _t->on_actionShow_Copies_triggered(); break;
        case 15: _t->on_actionShow_Borrowers_triggered(); break;
        case 16: _t->on_actionChange_Status_triggered(); break;
        case 17: _t->on_actionAdd_New_Borrower_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
