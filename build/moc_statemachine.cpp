/****************************************************************************
** Meta object code from reading C++ file 'statemachine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/statemachine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statemachine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StateMachine_t {
    QByteArrayData data[16];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StateMachine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StateMachine_t qt_meta_stringdata_StateMachine = {
    {
QT_MOC_LITERAL(0, 0, 12), // "StateMachine"
QT_MOC_LITERAL(1, 13, 12), // "changeWidget"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "set_add_ingrediant"
QT_MOC_LITERAL(4, 46, 12), // "make_a_drink"
QT_MOC_LITERAL(5, 59, 5), // "admin"
QT_MOC_LITERAL(6, 65, 10), // "admin_back"
QT_MOC_LITERAL(7, 76, 10), // "scoreboard"
QT_MOC_LITERAL(8, 87, 17), // "startpage_pressed"
QT_MOC_LITERAL(9, 105, 8), // "login_ok"
QT_MOC_LITERAL(10, 114, 12), // "login_cancel"
QT_MOC_LITERAL(11, 127, 10), // "drink_back"
QT_MOC_LITERAL(12, 138, 8), // "add_user"
QT_MOC_LITERAL(13, 147, 11), // "add_user_ok"
QT_MOC_LITERAL(14, 159, 14), // "add_ingrediant"
QT_MOC_LITERAL(15, 174, 19) // "add_ingrediant_back"

    },
    "StateMachine\0changeWidget\0\0"
    "set_add_ingrediant\0make_a_drink\0admin\0"
    "admin_back\0scoreboard\0startpage_pressed\0"
    "login_ok\0login_cancel\0drink_back\0"
    "add_user\0add_user_ok\0add_ingrediant\0"
    "add_ingrediant_back"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StateMachine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    0,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   88,    2, 0x0a /* Public */,
       5,    0,   89,    2, 0x0a /* Public */,
       6,    0,   90,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    0,   95,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    0,   98,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

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

       0        // eod
};

void StateMachine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StateMachine *_t = static_cast<StateMachine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_add_ingrediant(); break;
        case 2: _t->make_a_drink(); break;
        case 3: _t->admin(); break;
        case 4: _t->admin_back(); break;
        case 5: _t->scoreboard(); break;
        case 6: _t->startpage_pressed(); break;
        case 7: _t->login_ok(); break;
        case 8: _t->login_cancel(); break;
        case 9: _t->drink_back(); break;
        case 10: _t->add_user(); break;
        case 11: _t->add_user_ok(); break;
        case 12: _t->add_ingrediant(); break;
        case 13: _t->add_ingrediant_back(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StateMachine::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateMachine::changeWidget)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (StateMachine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StateMachine::set_add_ingrediant)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject StateMachine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StateMachine.data,
      qt_meta_data_StateMachine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StateMachine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StateMachine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StateMachine.stringdata0))
        return static_cast<void*>(const_cast< StateMachine*>(this));
    return QObject::qt_metacast(_clname);
}

int StateMachine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void StateMachine::changeWidget(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StateMachine::set_add_ingrediant()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
