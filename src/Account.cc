// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Account.h"

#include "CoinType.h"
#include "String.h"

static PyTypeObject PyAccountType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Account",    /* tp_name */
    sizeof(PyAccountObject), /* tp_basicsize */
    0,                       /* tp_itemsize */
    0,                       /* tp_dealloc */
    0,                       /* tp_print */
    0,                       /* tp_getattr */
    0,                       /* tp_setattr */
    0,                       /* tp_reserved */
    0,                       /* tp_repr */
    0,                       /* tp_as_number */
    0,                       /* tp_as_sequence */
    0,                       /* tp_as_mapping */
    0,                       /* tp_hash  */
    0,                       /* tp_call */
    0,                       /* tp_str */
    0,                       /* tp_getattro */
    0,                       /* tp_setattro */
    0,                       /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,      /* tp_flags */
    nullptr,                 /* tp_doc */
};

bool PyAccount_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyAccountType) != 0;
}

// Create PyAccount from enum TWAccount.
PyObject* PyAccount_FromTWAccount(TWAccount* value) {
  if (!value)
    return nullptr;

  PyAccountObject* object = PyObject_New(PyAccountObject, &PyAccountType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWAccount* PyAccount_GetTWAccount(PyObject* object) {
  assert(PyAccount_Check(object));
  return ((PyAccountObject*)object)->value;
}

static void PyAccount_dealloc(PyAccountObject* self) {
  if (self->value) {
    TWAccountDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// static int PyAccount_init(PyAccountObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyAccount_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyAccount_FromTWAccount((TWAccount)value);
// }

// static PyObject* PyAccount_str(PyAccountObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Address
static const char PyAccountAddress_doc[] =
    "TWString* TWAccountAddress(struct TWAccount* account)";
static PyObject* PyAccountAddress(PyAccountObject* self, void*) {
  return PyUnicode_FromTWString(TWAccountAddress(self->value));
}

// getter function for DerivationPath
static const char PyAccountDerivationPath_doc[] =
    "TWString* TWAccountDerivationPath(struct TWAccount* account)";
static PyObject* PyAccountDerivationPath(PyAccountObject* self, void*) {
  return PyUnicode_FromTWString(TWAccountDerivationPath(self->value));
}

// getter function for ExtendedPublicKey
static const char PyAccountExtendedPublicKey_doc[] =
    "TWString* TWAccountExtendedPublicKey(struct TWAccount* account)";
static PyObject* PyAccountExtendedPublicKey(PyAccountObject* self, void*) {
  return PyUnicode_FromTWString(TWAccountExtendedPublicKey(self->value));
}

// getter function for Coin
static const char PyAccountCoin_doc[] =
    "enum TWCoinType TWAccountCoin(struct TWAccount* account)";
static PyObject* PyAccountCoin(PyAccountObject* self, void*) {
  return PyCoinType_FromTWCoinType(TWAccountCoin(self->value));
}

// method function for Delete
static const char PyAccountDelete_doc[] =
    "void TWAccountDelete(struct TWAccount* account)";
static PyObject* PyAccountDelete(PyAccountObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWAccountDelete(self->value);
  return nullptr;
}

// static method function for Create
static const char PyAccountCreate_doc[] =
    "struct TWAccount* TWAccountCreate(TWString* address, enum TWCoinType "
    "coin, TWString* derivationPath, TWString* extendedPublicKey)";
static PyObject* PyAccountCreate(PyAccountObject* self,
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

  TWAccount* result = TWAccountCreate(arg0.get(), arg1, arg2.get(), arg3.get());
  return PyAccount_FromTWAccount(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"Address", (getter)PyAccountAddress, nullptr, PyAccountAddress_doc},
    {"DerivationPath", (getter)PyAccountDerivationPath, nullptr,
     PyAccountDerivationPath_doc},
    {"ExtendedPublicKey", (getter)PyAccountExtendedPublicKey, nullptr,
     PyAccountExtendedPublicKey_doc},
    {"Coin", (getter)PyAccountCoin, nullptr, PyAccountCoin_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyAccountDelete, METH_FASTCALL,
     PyAccountDelete_doc},
    {"Create", (PyCFunction)PyAccountCreate, METH_FASTCALL | METH_STATIC,
     PyAccountCreate_doc},
    {}};

bool PyInit_Account(PyObject* module) {
  // PyAccountType.tp_new = PyAccount_new;
  // PyAccountType.tp_init = (initproc)PyAccount_init;
  PyAccountType.tp_dealloc = (destructor)PyAccount_dealloc;
  // PyAccountType.tp_str = (reprfunc)PyAccount_str;
  PyAccountType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAccountType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAccountType) < 0)
    return false;

  Py_INCREF(&PyAccountType);
  if (PyModule_AddObject(module, "Account", (PyObject*)&PyAccountType) < 0) {
    Py_DECREF(&PyAccountType);
    return false;
  }

  return true;
}