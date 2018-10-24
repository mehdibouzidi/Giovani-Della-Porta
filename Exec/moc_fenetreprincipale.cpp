/****************************************************************************
** Meta object code from reading C++ file 'fenetreprincipale.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChiffrementGiovaniDellaPorta/fenetreprincipale.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fenetreprincipale.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FenetrePrincipale_t {
    QByteArrayData data[14];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FenetrePrincipale_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FenetrePrincipale_t qt_meta_stringdata_FenetrePrincipale = {
    {
QT_MOC_LITERAL(0, 0, 17), // "FenetrePrincipale"
QT_MOC_LITERAL(1, 18, 7), // "crypter"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "decrypter"
QT_MOC_LITERAL(4, 37, 16), // "parametrageTable"
QT_MOC_LITERAL(5, 54, 15), // "augmenterLignes"
QT_MOC_LITERAL(6, 70, 1), // "i"
QT_MOC_LITERAL(7, 72, 7), // "okParam"
QT_MOC_LITERAL(8, 80, 12), // "nouvauCrypto"
QT_MOC_LITERAL(9, 93, 13), // "afficherClair"
QT_MOC_LITERAL(10, 107, 15), // "afficherChiffre"
QT_MOC_LITERAL(11, 123, 19), // "afficherParametrage"
QT_MOC_LITERAL(12, 143, 7), // "aPropos"
QT_MOC_LITERAL(13, 151, 12) // "afficheTable"

    },
    "FenetrePrincipale\0crypter\0\0decrypter\0"
    "parametrageTable\0augmenterLignes\0i\0"
    "okParam\0nouvauCrypto\0afficherClair\0"
    "afficherChiffre\0afficherParametrage\0"
    "aPropos\0afficheTable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenetrePrincipale[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FenetrePrincipale::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FenetrePrincipale *_t = static_cast<FenetrePrincipale *>(_o);
        switch (_id) {
        case 0: _t->crypter(); break;
        case 1: _t->decrypter(); break;
        case 2: _t->parametrageTable(); break;
        case 3: _t->augmenterLignes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->okParam(); break;
        case 5: _t->nouvauCrypto(); break;
        case 6: _t->afficherClair(); break;
        case 7: _t->afficherChiffre(); break;
        case 8: _t->afficherParametrage(); break;
        case 9: _t->aPropos(); break;
        case 10: _t->afficheTable(); break;
        default: ;
        }
    }
}

const QMetaObject FenetrePrincipale::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FenetrePrincipale.data,
      qt_meta_data_FenetrePrincipale,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FenetrePrincipale::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenetrePrincipale::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FenetrePrincipale.stringdata))
        return static_cast<void*>(const_cast< FenetrePrincipale*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FenetrePrincipale::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
