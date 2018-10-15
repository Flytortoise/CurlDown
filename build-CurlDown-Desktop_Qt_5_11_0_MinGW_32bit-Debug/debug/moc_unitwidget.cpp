/****************************************************************************
** Meta object code from reading C++ file 'unitwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CurlDown/Widget/unitwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unitwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UnitWidget_t {
    QByteArrayData data[11];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnitWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnitWidget_t qt_meta_stringdata_UnitWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UnitWidget"
QT_MOC_LITERAL(1, 11, 5), // "Close"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "UnitWidget*"
QT_MOC_LITERAL(4, 30, 5), // "Pause"
QT_MOC_LITERAL(5, 36, 10), // "CancelFunc"
QT_MOC_LITERAL(6, 47, 2), // "OK"
QT_MOC_LITERAL(7, 50, 10), // "OnProgress"
QT_MOC_LITERAL(8, 61, 7), // "dltotal"
QT_MOC_LITERAL(9, 69, 5), // "dlnow"
QT_MOC_LITERAL(10, 75, 10) // "TimeUpdate"

    },
    "UnitWidget\0Close\0\0UnitWidget*\0Pause\0"
    "CancelFunc\0OK\0OnProgress\0dltotal\0dlnow\0"
    "TimeUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnitWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    2,   50,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    8,    9,
    QMetaType::Void,

       0        // eod
};

void UnitWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UnitWidget *_t = static_cast<UnitWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Close((*reinterpret_cast< UnitWidget*(*)>(_a[1]))); break;
        case 1: _t->Pause(); break;
        case 2: _t->CancelFunc(); break;
        case 3: _t->OK(); break;
        case 4: _t->OnProgress((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->TimeUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< UnitWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UnitWidget::*)(UnitWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UnitWidget::Close)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UnitWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UnitWidget::Pause)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UnitWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UnitWidget.data,
      qt_meta_data_UnitWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UnitWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnitWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UnitWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UnitWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UnitWidget::Close(UnitWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UnitWidget::Pause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
