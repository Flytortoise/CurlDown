/****************************************************************************
** Meta object code from reading C++ file 'curldownelement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CurlDown/curldownelement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'curldownelement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CurlDownElement_t {
    QByteArrayData data[6];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CurlDownElement_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CurlDownElement_t qt_meta_stringdata_CurlDownElement = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CurlDownElement"
QT_MOC_LITERAL(1, 16, 11), // "HasFinished"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "OnProgress"
QT_MOC_LITERAL(4, 40, 7), // "OnSpeed"
QT_MOC_LITERAL(5, 48, 5) // "Pause"

    },
    "CurlDownElement\0HasFinished\0\0OnProgress\0"
    "OnSpeed\0Pause"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CurlDownElement[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    2,   35,    2, 0x06 /* Public */,
       4,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CurlDownElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurlDownElement *_t = static_cast<CurlDownElement *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->HasFinished(); break;
        case 1: _t->OnProgress((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->OnSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->Pause(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CurlDownElement::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurlDownElement::HasFinished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CurlDownElement::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurlDownElement::OnProgress)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CurlDownElement::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurlDownElement::OnSpeed)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CurlDownElement::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CurlDownElement.data,
      qt_meta_data_CurlDownElement,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CurlDownElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CurlDownElement::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CurlDownElement.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int CurlDownElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CurlDownElement::HasFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CurlDownElement::OnProgress(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CurlDownElement::OnSpeed(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
