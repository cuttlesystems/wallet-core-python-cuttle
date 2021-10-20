// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "StoredKey.h"

#include "Account.h"
#include "CoinType.h"
#include "Data.h"
#include "HDWallet.h"
#include "PrivateKey.h"
#include "String.h"

static PyTypeObject PyStoredKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StoredKey",    /* tp_name */
    sizeof(PyStoredKeyObject), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    nullptr,                   /* tp_doc */
};

bool PyStoredKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStoredKeyType) != 0;
}

// Create PyStoredKey from enum TWStoredKey.
PyObject* PyStoredKey_FromTWStoredKey(TWStoredKey* value) {
  if (!value)
    return nullptr;

  PyStoredKeyObject* object = PyObject_New(PyStoredKeyObject, &PyStoredKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWStoredKey* PyStoredKey_GetTWStoredKey(PyObject* object) {
  assert(PyStoredKey_Check(object));
  return ((PyStoredKeyObject*)object)->value;
}

static void PyStoredKey_dealloc(PyStoredKeyObject* self) {
  if (self->value) {
    TWStoredKeyDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// static int PyStoredKey_init(PyStoredKeyObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyStoredKey_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyStoredKey_FromTWStoredKey((TWStoredKey)value);
// }

// static PyObject* PyStoredKey_str(PyStoredKeyObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Identifier
static const char PyStoredKeyIdentifier_doc[] =
    "TWString* TWStoredKeyIdentifier(struct TWStoredKey* key)";
static PyObject* PyStoredKeyIdentifier(PyStoredKeyObject* self, void*) {
  return PyUnicode_FromTWString(TWStoredKeyIdentifier(self->value));
}

// getter function for Name
static const char PyStoredKeyName_doc[] =
    "TWString* TWStoredKeyName(struct TWStoredKey* key)";
static PyObject* PyStoredKeyName(PyStoredKeyObject* self, void*) {
  return PyUnicode_FromTWString(TWStoredKeyName(self->value));
}

// getter function for IsMnemonic
static const char PyStoredKeyIsMnemonic_doc[] =
    "bool TWStoredKeyIsMnemonic(struct TWStoredKey* key)";
static PyObject* PyStoredKeyIsMnemonic(PyStoredKeyObject* self, void*) {
  return PyBool_FromLong(TWStoredKeyIsMnemonic(self->value));
}

// method function for Delete
static const char PyStoredKeyDelete_doc[] =
    "void TWStoredKeyDelete(struct TWStoredKey* key)";
static PyObject* PyStoredKeyDelete(PyStoredKeyObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWStoredKeyDelete(self->value);
  return nullptr;
}

// method function for Account
static const char PyStoredKeyAccount_doc[] =
    "struct TWAccount* TWStoredKeyAccount(struct TWStoredKey* key, size_t "
    "index)";
static PyObject* PyStoredKeyAccount(PyStoredKeyObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  TWAccount* result = TWStoredKeyAccount(self->value, arg0);
  return PyAccount_FromTWAccount(result);
}

// method function for AccountForCoin
static const char PyStoredKeyAccountForCoin_doc[] =
    "struct TWAccount* TWStoredKeyAccountForCoin(struct TWStoredKey* key, enum "
    "TWCoinType coin, struct TWHDWallet* wallet)";
static PyObject* PyStoredKeyAccountForCoin(PyStoredKeyObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  if (!PyHDWallet_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type HDWallet");
    return nullptr;
  }
  auto arg1 = PyHDWallet_GetTWHDWallet(args[1]);

  TWAccount* result = TWStoredKeyAccountForCoin(self->value, arg0, arg1);
  return PyAccount_FromTWAccount(result);
}

// method function for RemoveAccountForCoin
static const char PyStoredKeyRemoveAccountForCoin_doc[] =
    "void TWStoredKeyRemoveAccountForCoin(struct TWStoredKey* key, enum "
    "TWCoinType coin)";
static PyObject* PyStoredKeyRemoveAccountForCoin(PyStoredKeyObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  TWStoredKeyRemoveAccountForCoin(self->value, arg0);
  return nullptr;
}

// method function for AddAccount
static const char PyStoredKeyAddAccount_doc[] =
    "void TWStoredKeyAddAccount(struct TWStoredKey* key, TWString* address, "
    "enum TWCoinType coin, TWString* derivationPath, TWString* "
    "extetndedPublicKey)";
static PyObject* PyStoredKeyAddAccount(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  if (!PyUnicode_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Unicode");
    return nullptr;
  }
  auto arg2 = PyUnicode_GetTWString(args[2]);

  if (!PyUnicode_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type Unicode");
    return nullptr;
  }
  auto arg3 = PyUnicode_GetTWString(args[3]);

  TWStoredKeyAddAccount(self->value, arg0.get(), arg1, arg2.get(), arg3.get());
  return nullptr;
}

// method function for Store
static const char PyStoredKeyStore_doc[] =
    "bool TWStoredKeyStore(struct TWStoredKey* key, TWString* path)";
static PyObject* PyStoredKeyStore(PyStoredKeyObject* self,
                                  PyObject* const* args,
                                  Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  bool result = TWStoredKeyStore(self->value, arg0.get());
  return PyBool_FromLong(result);
}

// method function for DecryptPrivateKey
static const char PyStoredKeyDecryptPrivateKey_doc[] =
    "TWData* TWStoredKeyDecryptPrivateKey(struct TWStoredKey* key, TWData* "
    "password)";
static PyObject* PyStoredKeyDecryptPrivateKey(PyStoredKeyObject* self,
                                              PyObject* const* args,
                                              Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWStoredKeyDecryptPrivateKey(self->value, arg0.get());
  return PyByteArray_FromTWData(result);
}

// method function for DecryptMnemonic
static const char PyStoredKeyDecryptMnemonic_doc[] =
    "TWString* TWStoredKeyDecryptMnemonic(struct TWStoredKey* key, TWData* "
    "password)";
static PyObject* PyStoredKeyDecryptMnemonic(PyStoredKeyObject* self,
                                            PyObject* const* args,
                                            Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWStringPtr result = TWStoredKeyDecryptMnemonic(self->value, arg0.get());
  return PyUnicode_FromTWString(result);
}

// method function for PrivateKey
static const char PyStoredKeyPrivateKey_doc[] =
    "struct TWPrivateKey* TWStoredKeyPrivateKey(struct TWStoredKey* key, enum "
    "TWCoinType coin, TWData* password)";
static PyObject* PyStoredKeyPrivateKey(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  TWPrivateKey* result = TWStoredKeyPrivateKey(self->value, arg0, arg1.get());
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for Wallet
static const char PyStoredKeyWallet_doc[] =
    "struct TWHDWallet* TWStoredKeyWallet(struct TWStoredKey* key, TWData* "
    "password)";
static PyObject* PyStoredKeyWallet(PyStoredKeyObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWHDWallet* result = TWStoredKeyWallet(self->value, arg0.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// method function for ExportJSON
static const char PyStoredKeyExportJSON_doc[] =
    "TWData* TWStoredKeyExportJSON(struct TWStoredKey* key)";
static PyObject* PyStoredKeyExportJSON(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWStoredKeyExportJSON(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for FixAddresses
static const char PyStoredKeyFixAddresses_doc[] =
    "bool TWStoredKeyFixAddresses(struct TWStoredKey* key, TWData* password)";
static PyObject* PyStoredKeyFixAddresses(PyStoredKeyObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  bool result = TWStoredKeyFixAddresses(self->value, arg0.get());
  return PyBool_FromLong(result);
}

// static method function for Load
static const char PyStoredKeyLoad_doc[] =
    "struct TWStoredKey* TWStoredKeyLoad(TWString* path)";
static PyObject* PyStoredKeyLoad(PyStoredKeyObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  TWStoredKey* result = TWStoredKeyLoad(arg0.get());
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for ImportPrivateKey
static const char PyStoredKeyImportPrivateKey_doc[] =
    "struct TWStoredKey* TWStoredKeyImportPrivateKey(TWData* privateKey, "
    "TWString* name, TWData* password, enum TWCoinType coin)";
static PyObject* PyStoredKeyImportPrivateKey(PyStoredKeyObject* self,
                                             PyObject* const* args,
                                             Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  if (!PyCoinType_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type CoinType");
    return nullptr;
  }
  auto arg3 = PyCoinType_GetTWCoinType(args[3]);

  TWStoredKey* result =
      TWStoredKeyImportPrivateKey(arg0.get(), arg1.get(), arg2.get(), arg3);
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for ImportHDWallet
static const char PyStoredKeyImportHDWallet_doc[] =
    "struct TWStoredKey* TWStoredKeyImportHDWallet(TWString* mnemonic, "
    "TWString* name, TWData* password, enum TWCoinType coin)";
static PyObject* PyStoredKeyImportHDWallet(PyStoredKeyObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  if (!PyCoinType_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type CoinType");
    return nullptr;
  }
  auto arg3 = PyCoinType_GetTWCoinType(args[3]);

  TWStoredKey* result =
      TWStoredKeyImportHDWallet(arg0.get(), arg1.get(), arg2.get(), arg3);
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for ImportJSON
static const char PyStoredKeyImportJSON_doc[] =
    "struct TWStoredKey* TWStoredKeyImportJSON(TWData* json)";
static PyObject* PyStoredKeyImportJSON(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWStoredKey* result = TWStoredKeyImportJSON(arg0.get());
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for Create
static const char PyStoredKeyCreate_doc[] =
    "struct TWStoredKey* TWStoredKeyCreate(TWString* name, TWData* password)";
static PyObject* PyStoredKeyCreate(PyStoredKeyObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  TWStoredKey* result = TWStoredKeyCreate(arg0.get(), arg1.get());
  return PyStoredKey_FromTWStoredKey(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"Identifier", (getter)PyStoredKeyIdentifier, nullptr,
     PyStoredKeyIdentifier_doc},
    {"Name", (getter)PyStoredKeyName, nullptr, PyStoredKeyName_doc},
    {"IsMnemonic", (getter)PyStoredKeyIsMnemonic, nullptr,
     PyStoredKeyIsMnemonic_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyStoredKeyDelete, METH_FASTCALL,
     PyStoredKeyDelete_doc},
    {"Account", (PyCFunction)PyStoredKeyAccount, METH_FASTCALL,
     PyStoredKeyAccount_doc},
    {"AccountForCoin", (PyCFunction)PyStoredKeyAccountForCoin, METH_FASTCALL,
     PyStoredKeyAccountForCoin_doc},
    {"RemoveAccountForCoin", (PyCFunction)PyStoredKeyRemoveAccountForCoin,
     METH_FASTCALL, PyStoredKeyRemoveAccountForCoin_doc},
    {"AddAccount", (PyCFunction)PyStoredKeyAddAccount, METH_FASTCALL,
     PyStoredKeyAddAccount_doc},
    {"Store", (PyCFunction)PyStoredKeyStore, METH_FASTCALL,
     PyStoredKeyStore_doc},
    {"DecryptPrivateKey", (PyCFunction)PyStoredKeyDecryptPrivateKey,
     METH_FASTCALL, PyStoredKeyDecryptPrivateKey_doc},
    {"DecryptMnemonic", (PyCFunction)PyStoredKeyDecryptMnemonic, METH_FASTCALL,
     PyStoredKeyDecryptMnemonic_doc},
    {"PrivateKey", (PyCFunction)PyStoredKeyPrivateKey, METH_FASTCALL,
     PyStoredKeyPrivateKey_doc},
    {"Wallet", (PyCFunction)PyStoredKeyWallet, METH_FASTCALL,
     PyStoredKeyWallet_doc},
    {"ExportJSON", (PyCFunction)PyStoredKeyExportJSON, METH_FASTCALL,
     PyStoredKeyExportJSON_doc},
    {"FixAddresses", (PyCFunction)PyStoredKeyFixAddresses, METH_FASTCALL,
     PyStoredKeyFixAddresses_doc},
    {"Load", (PyCFunction)PyStoredKeyLoad, METH_FASTCALL | METH_STATIC,
     PyStoredKeyLoad_doc},
    {"ImportPrivateKey", (PyCFunction)PyStoredKeyImportPrivateKey,
     METH_FASTCALL | METH_STATIC, PyStoredKeyImportPrivateKey_doc},
    {"ImportHDWallet", (PyCFunction)PyStoredKeyImportHDWallet,
     METH_FASTCALL | METH_STATIC, PyStoredKeyImportHDWallet_doc},
    {"ImportJSON", (PyCFunction)PyStoredKeyImportJSON,
     METH_FASTCALL | METH_STATIC, PyStoredKeyImportJSON_doc},
    {"Create", (PyCFunction)PyStoredKeyCreate, METH_FASTCALL | METH_STATIC,
     PyStoredKeyCreate_doc},
    {}};

bool PyInit_StoredKey(PyObject* module) {
  // PyStoredKeyType.tp_new = PyStoredKey_new;
  // PyStoredKeyType.tp_init = (initproc)PyStoredKey_init;
  PyStoredKeyType.tp_dealloc = (destructor)PyStoredKey_dealloc;
  // PyStoredKeyType.tp_str = (reprfunc)PyStoredKey_str;
  PyStoredKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStoredKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStoredKeyType) < 0)
    return false;

  Py_INCREF(&PyStoredKeyType);
  if (PyModule_AddObject(module, "StoredKey", (PyObject*)&PyStoredKeyType) <
      0) {
    Py_DECREF(&PyStoredKeyType);
    return false;
  }

  return true;
}