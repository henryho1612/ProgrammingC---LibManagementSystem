/****************************************************************************
** Meta object code from reading C++ file 'showallcollections.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Assignment2/showallcollections.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showallcollections.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_showAllCollections_t {
    QByteArrayData data[16];
    char stringdata[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_showAllCollections_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_showAllCollections_t qt_meta_stringdata_showAllCollections = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 21),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 30),
QT_MOC_LITERAL(4, 73, 4),
QT_MOC_LITERAL(5, 78, 10),
QT_MOC_LITERAL(6, 89, 12),
QT_MOC_LITERAL(7, 102, 5),
QT_MOC_LITERAL(8, 108, 13),
QT_MOC_LITERAL(9, 122, 10),
QT_MOC_LITERAL(10, 133, 3),
QT_MOC_LITERAL(11, 137, 26),
QT_MOC_LITERAL(12, 164, 19),
QT_MOC_LITERAL(13, 184, 5),
QT_MOC_LITERAL(14, 190, 9),
QT_MOC_LITERAL(15, 200, 23)
    },
    "showAllCollections\0on_pushButton_clicked\0"
    "\0on_comboBox_currentTextChanged\0arg1\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "keyPressEvent\0QKeyEvent*\0key\0"
    "on_printpreviewBnt_clicked\0"
    "on_printBtn_clicked\0print\0QPrinter*\0"
    "on_pushButton_2_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showAllCollections[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    1,   55,    2, 0x08,
       5,    1,   58,    2, 0x08,
       8,    1,   61,    2, 0x08,
      11,    0,   64,    2, 0x08,
      12,    0,   65,    2, 0x08,
      13,    1,   66,    2, 0x08,
      15,    0,   69,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,

       0        // eod
};

void showAllCollections::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        showAllCollections *_t = static_cast<showAllCollections *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->on_printpreviewBnt_clicked(); break;
        case 5: _t->on_printBtn_clicked(); break;
        case 6: _t->print((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject showAllCollections::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_showAllCollections.data,
      qt_meta_data_showAllCollections,  qt_static_metacall, 0, 0}
};


const QMetaObject *showAllCollections::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showAllCollections::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_showAllCollections.stringdata))
        return static_cast<void*>(const_cast< showAllCollections*>(this));
    return QDialog::qt_metacast(_clname);
}

int showAllCollections::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
