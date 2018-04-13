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
    QByteArrayData data[11];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "add_user"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 18), // "set_add_ingrediant"
QT_MOC_LITERAL(4, 40, 17), // "add_ingrediant_ok"
QT_MOC_LITERAL(5, 58, 21), // "ingrediantDataChanged"
QT_MOC_LITERAL(6, 80, 7), // "topLeft"
QT_MOC_LITERAL(7, 88, 11), // "bottomRight"
QT_MOC_LITERAL(8, 100, 12), // "QVector<int>"
QT_MOC_LITERAL(9, 113, 5), // "roles"
QT_MOC_LITERAL(10, 119, 17) // "remove_ingrediant"

    },
    "MainWindow\0add_user\0\0set_add_ingrediant\0"
    "add_ingrediant_ok\0ingrediantDataChanged\0"
    "topLeft\0bottomRight\0QVector<int>\0roles\0"
    "remove_ingrediant"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    3,   42,    2, 0x0a /* Public */,
      10,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex, 0x80000000 | 8,    6,    7,    9,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->add_user(); break;
        case 1: _t->set_add_ingrediant(); break;
        case 2: _t->add_ingrediant_ok(); break;
        case 3: _t->ingrediantDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 4: _t->remove_ingrediant(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
