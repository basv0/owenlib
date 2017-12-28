/****************************************************************************
** Meta object code from reading C++ file 'testowen.h'
**
** Created: Sat Jun 13 10:54:10 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "testowen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testowen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestOwen[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x08,
      45,   10,    9,    9, 0x08,
      74,   69,    9,    9, 0x08,
     102,    9,    9,    9, 0x08,
     123,    9,    9,    9, 0x08,
     145,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestOwen[] = {
    "TestOwen\0\0checked\0on_rdbSerial_clicked(bool)\0"
    "on_rdbUSB_clicked(bool)\0arg1\0"
    "on_spbNum_valueChanged(int)\0"
    "on_cmdOpen_clicked()\0on_cmdClose_clicked()\0"
    "on_cmdConnect_clicked()\0"
};

const QMetaObject TestOwen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TestOwen,
      qt_meta_data_TestOwen, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestOwen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestOwen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestOwen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestOwen))
        return static_cast<void*>(const_cast< TestOwen*>(this));
    return QWidget::qt_metacast(_clname);
}

int TestOwen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_rdbSerial_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_rdbUSB_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: on_spbNum_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_cmdOpen_clicked(); break;
        case 4: on_cmdClose_clicked(); break;
        case 5: on_cmdConnect_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
