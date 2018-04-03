#include <Python.h>

#include "x12.h"

static PyObject *x12_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    x12_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    x12_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef X12Methods[] = {
    { "getPoWHash", x12_getpowhash, METH_VARARGS, "Returns the proof of work hash using x12 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef X12Module = {
    PyModuleDef_HEAD_INIT,
    "x12_hash",
    "...",
    -1,
    X12Methods
};

PyMODINIT_FUNC PyInit_x12_hash(void) {
    return PyModule_Create(&X12Module);
}

#else

PyMODINIT_FUNC initx12_hash(void) {
    (void) Py_InitModule("x12_hash", X12Methods);
}
#endif
