// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "SegwitAddress.h"

#include "Data.h"
#include "HRP.h"
#include "PublicKey.h"
#include "String.h"

static PyTypeObject PySegwitAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.SegwitAddress",    /* tp_name */
    sizeof(PySegwitAddressObject), /* tp_basicsize */
    0,                             /* tp_itemsize */
    0,                             /* tp_dealloc */
    0,                             /* tp_print */
    0,                             /* tp_getattr */
    0,                             /* tp_setattr */
    0,                             /* tp_reserved */
    0,                             /* tp_repr */
    0,                             /* tp_as_number */
    0,                             /* tp_as_sequence */
    0,                             /* tp_as_mapping */
    0,                             /* tp_hash  */
    0,                             /* tp_call */
    0,                             /* tp_str */
    0,                             /* tp_getattro */
    0,                             /* tp_setattro */
    0,                             /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,            /* tp_flags */
    nullptr,                       /* tp_doc */
};

bool PySegwitAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PySegwitAddressType) != 0;
}

// Create PySegwitAddress from enum TWSegwitAddress.
PyObject* PySegwitAddress_FromTWSegwitAddress(TWSegwitAddress* value) {
  if (!value)
    return nullptr;

  PySegwitAddressObject* object =
      PyObject_New(PySegwitAddressObject, &PySegwitAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWSegwitAddress* PySegwitAddress_GetTWSegwitAddress(PyObject* object) {
  assert(PySegwitAddress_Check(object));
  return ((PySegwitAddressObject*)object)->value;
}

static void PySegwitAddress_dealloc(PySegwitAddressObject* self) {
  if (self->value) {
    TWSegwitAddressDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// static int PySegwitAddress_init(PySegwitAddressObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PySegwitAddress_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PySegwitAddress_FromTWSegwitAddress((TWSegwitAddress)value);
// }

// static PyObject* PySegwitAddress_str(PySegwitAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Description
static const char PySegwitAddressDescription_doc[] =
    "TWString* TWSegwitAddressDescription(struct TWSegwitAddress* address)";
static PyObject* PySegwitAddressDescription(PySegwitAddressObject* self,
                                            void*) {
  return PyUnicode_FromTWString(TWSegwitAddressDescription(self->value));
}

// getter function for HRP
static const char PySegwitAddressHRP_doc[] =
    "enum TWHRP TWSegwitAddressHRP(struct TWSegwitAddress* address)";
static PyObject* PySegwitAddressHRP(PySegwitAddressObject* self, void*) {
  return PyHRP_FromTWHRP(TWSegwitAddressHRP(self->value));
}

// getter function for WitnessProgram
static const char PySegwitAddressWitnessProgram_doc[] =
    "TWData* TWSegwitAddressWitnessProgram(struct TWSegwitAddress* address)";
static PyObject* PySegwitAddressWitnessProgram(PySegwitAddressObject* self,
                                               void*) {
  return PyByteArray_FromTWData(TWSegwitAddressWitnessProgram(self->value));
}

// method function for Delete
static const char PySegwitAddressDelete_doc[] =
    "void TWSegwitAddressDelete(struct TWSegwitAddress* address)";
static PyObject* PySegwitAddressDelete(PySegwitAddressObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWSegwitAddressDelete(self->value);
  return nullptr;
}

// static method function for Equal
static const char PySegwitAddressEqual_doc[] =
    "bool TWSegwitAddressEqual(struct TWSegwitAddress* lhs, struct "
    "TWSegwitAddress* rhs)";
static PyObject* PySegwitAddressEqual(PySegwitAddressObject* self,
                                      PyObject* const* args,
                                      Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PySegwitAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type SegwitAddress");
    return nullptr;
  }
  auto arg0 = PySegwitAddress_GetTWSegwitAddress(args[0]);

  if (!PySegwitAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type SegwitAddress");
    return nullptr;
  }
  auto arg1 = PySegwitAddress_GetTWSegwitAddress(args[1]);

  bool result = TWSegwitAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValidString
static const char PySegwitAddressIsValidString_doc[] =
    "bool TWSegwitAddressIsValidString(TWString* string)";
static PyObject* PySegwitAddressIsValidString(PySegwitAddressObject* self,
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

  bool result = TWSegwitAddressIsValidString(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
static const char PySegwitAddressCreateWithString_doc[] =
    "struct TWSegwitAddress* TWSegwitAddressCreateWithString(TWString* string)";
static PyObject* PySegwitAddressCreateWithString(PySegwitAddressObject* self,
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

  TWSegwitAddress* result = TWSegwitAddressCreateWithString(arg0.get());
  return PySegwitAddress_FromTWSegwitAddress(result);
}

// static method function for CreateWithPublicKey
static const char PySegwitAddressCreateWithPublicKey_doc[] =
    "struct TWSegwitAddress* TWSegwitAddressCreateWithPublicKey(enum TWHRP "
    "hrp, struct TWPublicKey* publicKey)";
static PyObject* PySegwitAddressCreateWithPublicKey(PySegwitAddressObject* self,
                                                    PyObject* const* args,
                                                    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyHRP_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type HRP");
    return nullptr;
  }
  auto arg0 = PyHRP_GetTWHRP(args[0]);

  if (!PyPublicKey_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type PublicKey");
    return nullptr;
  }
  auto arg1 = PyPublicKey_GetTWPublicKey(args[1]);

  TWSegwitAddress* result = TWSegwitAddressCreateWithPublicKey(arg0, arg1);
  return PySegwitAddress_FromTWSegwitAddress(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"Description", (getter)PySegwitAddressDescription, nullptr,
     PySegwitAddressDescription_doc},
    {"HRP", (getter)PySegwitAddressHRP, nullptr, PySegwitAddressHRP_doc},
    {"WitnessProgram", (getter)PySegwitAddressWitnessProgram, nullptr,
     PySegwitAddressWitnessProgram_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PySegwitAddressDelete, METH_FASTCALL,
     PySegwitAddressDelete_doc},
    {"Equal", (PyCFunction)PySegwitAddressEqual, METH_FASTCALL | METH_STATIC,
     PySegwitAddressEqual_doc},
    {"IsValidString", (PyCFunction)PySegwitAddressIsValidString,
     METH_FASTCALL | METH_STATIC, PySegwitAddressIsValidString_doc},
    {"CreateWithString", (PyCFunction)PySegwitAddressCreateWithString,
     METH_FASTCALL | METH_STATIC, PySegwitAddressCreateWithString_doc},
    {"CreateWithPublicKey", (PyCFunction)PySegwitAddressCreateWithPublicKey,
     METH_FASTCALL | METH_STATIC, PySegwitAddressCreateWithPublicKey_doc},
    {}};

bool PyInit_SegwitAddress(PyObject* module) {
  // PySegwitAddressType.tp_new = PySegwitAddress_new;
  // PySegwitAddressType.tp_init = (initproc)PySegwitAddress_init;
  PySegwitAddressType.tp_dealloc = (destructor)PySegwitAddress_dealloc;
  // PySegwitAddressType.tp_str = (reprfunc)PySegwitAddress_str;
  PySegwitAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PySegwitAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PySegwitAddressType) < 0)
    return false;

  Py_INCREF(&PySegwitAddressType);
  if (PyModule_AddObject(module, "SegwitAddress",
                         (PyObject*)&PySegwitAddressType) < 0) {
    Py_DECREF(&PySegwitAddressType);
    return false;
  }

  return true;
}