/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IntRangeValidator_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IntRangeValidator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IntRangeValidator_t qt_meta_stringdata_IntRangeValidator = {
    {
QT_MOC_LITERAL(0, 0, 17) // "IntRangeValidator"

    },
    "IntRangeValidator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntRangeValidator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void IntRangeValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject IntRangeValidator::staticMetaObject = {
    { &QValidator::staticMetaObject, qt_meta_stringdata_IntRangeValidator.data,
      qt_meta_data_IntRangeValidator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *IntRangeValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntRangeValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IntRangeValidator.stringdata0))
        return static_cast<void*>(const_cast< IntRangeValidator*>(this));
    return QValidator::qt_metacast(_clname);
}

int IntRangeValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QValidator::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_NotEditableDelegate_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotEditableDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotEditableDelegate_t qt_meta_stringdata_NotEditableDelegate = {
    {
QT_MOC_LITERAL(0, 0, 19) // "NotEditableDelegate"

    },
    "NotEditableDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotEditableDelegate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void NotEditableDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject NotEditableDelegate::staticMetaObject = {
    { &QItemDelegate::staticMetaObject, qt_meta_stringdata_NotEditableDelegate.data,
      qt_meta_data_NotEditableDelegate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NotEditableDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotEditableDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotEditableDelegate.stringdata0))
        return static_cast<void*>(const_cast< NotEditableDelegate*>(this));
    return QItemDelegate::qt_metacast(_clname);
}

int NotEditableDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[28];
    char stringdata0[356];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "closeDialog"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "drink_changed"
QT_MOC_LITERAL(4, 38, 4), // "text"
QT_MOC_LITERAL(5, 43, 10), // "make_drink"
QT_MOC_LITERAL(6, 54, 11), // "setup_login"
QT_MOC_LITERAL(7, 66, 12), // "user_pressed"
QT_MOC_LITERAL(8, 79, 5), // "admin"
QT_MOC_LITERAL(9, 85, 8), // "add_user"
QT_MOC_LITERAL(10, 94, 18), // "set_add_ingrediant"
QT_MOC_LITERAL(11, 113, 12), // "passwordFunc"
QT_MOC_LITERAL(12, 126, 12), // "set_add_user"
QT_MOC_LITERAL(13, 139, 17), // "add_ingrediant_ok"
QT_MOC_LITERAL(14, 157, 21), // "ingrediantDataChanged"
QT_MOC_LITERAL(15, 179, 7), // "topLeft"
QT_MOC_LITERAL(16, 187, 11), // "bottomRight"
QT_MOC_LITERAL(17, 199, 12), // "QVector<int>"
QT_MOC_LITERAL(18, 212, 5), // "roles"
QT_MOC_LITERAL(19, 218, 15), // "userDataChanged"
QT_MOC_LITERAL(20, 234, 17), // "remove_ingrediant"
QT_MOC_LITERAL(21, 252, 11), // "remove_user"
QT_MOC_LITERAL(22, 264, 10), // "set_levels"
QT_MOC_LITERAL(23, 275, 15), // "set_levels_done"
QT_MOC_LITERAL(24, 291, 13), // "set_add_drink"
QT_MOC_LITERAL(25, 305, 9), // "add_drink"
QT_MOC_LITERAL(26, 315, 23), // "add_ingredient_to_drink"
QT_MOC_LITERAL(27, 339, 16) // "drinkDataChanged"

    },
    "MainWindow\0closeDialog\0\0drink_changed\0"
    "text\0make_drink\0setup_login\0user_pressed\0"
    "admin\0add_user\0set_add_ingrediant\0"
    "passwordFunc\0set_add_user\0add_ingrediant_ok\0"
    "ingrediantDataChanged\0topLeft\0bottomRight\0"
    "QVector<int>\0roles\0userDataChanged\0"
    "remove_ingrediant\0remove_user\0set_levels\0"
    "set_levels_done\0set_add_drink\0add_drink\0"
    "add_ingredient_to_drink\0drinkDataChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  122,    2, 0x0a /* Public */,
       5,    0,  125,    2, 0x0a /* Public */,
       6,    0,  126,    2, 0x0a /* Public */,
       7,    0,  127,    2, 0x0a /* Public */,
       8,    0,  128,    2, 0x0a /* Public */,
       9,    0,  129,    2, 0x0a /* Public */,
      10,    0,  130,    2, 0x0a /* Public */,
      11,    0,  131,    2, 0x0a /* Public */,
      12,    0,  132,    2, 0x0a /* Public */,
      13,    0,  133,    2, 0x0a /* Public */,
      14,    3,  134,    2, 0x0a /* Public */,
      19,    3,  141,    2, 0x0a /* Public */,
      20,    0,  148,    2, 0x0a /* Public */,
      21,    0,  149,    2, 0x0a /* Public */,
      22,    0,  150,    2, 0x0a /* Public */,
      23,    0,  151,    2, 0x0a /* Public */,
      24,    0,  152,    2, 0x0a /* Public */,
      25,    0,  153,    2, 0x0a /* Public */,
      26,    0,  154,    2, 0x0a /* Public */,
      27,    3,  155,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 17,   15,   16,   18,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 17,   15,   16,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 17,   15,   16,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeDialog((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->drink_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->make_drink(); break;
        case 3: _t->setup_login(); break;
        case 4: _t->user_pressed(); break;
        case 5: _t->admin(); break;
        case 6: _t->add_user(); break;
        case 7: _t->set_add_ingrediant(); break;
        case 8: _t->passwordFunc(); break;
        case 9: _t->set_add_user(); break;
        case 10: _t->add_ingrediant_ok(); break;
        case 11: _t->ingrediantDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 12: _t->userDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 13: _t->remove_ingrediant(); break;
        case 14: _t->remove_user(); break;
        case 15: _t->set_levels(); break;
        case 16: _t->set_levels_done(); break;
        case 17: _t->set_add_drink(); break;
        case 18: _t->add_drink(); break;
        case 19: _t->add_ingredient_to_drink(); break;
        case 20: _t->drinkDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::closeDialog)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::closeDialog(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
