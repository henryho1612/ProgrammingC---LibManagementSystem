/****************************************************************************
** Meta object code from reading C++ file 'showcopies.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Assignment2/showcopies.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showcopies.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_showCopies_t {
    QByteArrayData data[15];
    char stringdata[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_showCopies_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_showCopies_t qt_meta_stringdata_showCopies = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 31),
QT_MOC_LITERAL(2, 43, 0),
QT_MOC_LITERAL(3, 44, 4),
QT_MOC_LITERAL(4, 49, 10),
QT_MOC_LITERAL(5, 60, 12),
QT_MOC_LITERAL(6, 73, 5),
QT_MOC_LITERAL(7, 79, 13),
QT_MOC_LITERAL(8, 93, 10),
QT_MOC_LITERAL(9, 104, 3),
QT_MOC_LITERAL(10, 108, 21),
QT_MOC_LITERAL(11, 130, 19),
QT_MOC_LITERAL(12, 150, 5),
QT_MOC_LITERAL(13, 156, 9),
QT_MOC_LITERAL(14, 166, 18)
    },
    "showCopies\0on_comboBox_currentIndexChanged\0"
    "\0arg1\0closeEvent\0QCloseEvent*\0event\0"
    "keyPressEvent\0QKeyEvent*\0key\0"
    "on_previewBtn_clicked\0on_printBtn_clicked\0"
    "print\0QPrinter*\0on_saveBtn_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showCopies[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08,
       4,    1,   52,    2, 0x08,
       7,    1,   55,    2, 0x08,
      10,    0,   58,    2, 0x08,
      11,    0,   59,    2, 0x08,
      12,    1,   60,    2, 0x08,
      14,    0,   63,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,

       0        // eod
};

void showCopies::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        showCopies *_t = static_cast<showCopies *>(_o);
        switch (_id) {
        case 0: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: _t->on_previewBtn_clicked(); break;
        case 4: _t->on_printBtn_clicked(); break;
        case 5: _t->print((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 6: _t->on_saveBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject showCopies::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_showCopies.data,
      qt_meta_data_showCopies,  qt_static_metacall, 0, 0}
};


const QMetaObject *showCopies::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showCopies::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_showCopies.stringdata))
        return static_cast<void*>(const_cast< showCopies*>(this));
    return QDialog::qt_metacast(_clname);
}

int showCopies::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
