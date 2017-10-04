#include <Python.h>
#include <iostream>

PyObject * RepeatString(PyObject * pSelf, PyObject * pParams) {
    std::cout << "Repeat String was called from Python" << std::endl;
    char * pstrString;
    int iRepCount;
    if (!PyArg_ParseTuple(pParams, "si", &pstrString, &iRepCount)) {
        std::cerr << "Unable to parse parameter tuple." << std::endl;
        return nullptr;
    }
    for (int i = 0; i < iRepCount; i++) {
        std::cout << "\t" << i << ": " << pstrString << std::endl;
    }
    return PyInt_FromLong(iRepCount);
}

int main() {
    Py_Initialize();
    if (!Py_IsInitialized()) {
        std::cerr << "cannot initialize python env." << std::endl;
        return 1;
    }

    // Python call CPP functions. Modules provided by CPP must be registed into memory
    // before loading python script.
    PyMethodDef HostApiFuncs[] = {
        {"RepeatString", RepeatString, METH_VARARGS, NULL},
        {NULL, NULL, NULL, NULL}
    };
    if (!PyImport_AddModule("HostAPI")) {
        std::cerr << "Host API could not be created." << std::endl;
        return 1;
    }
    if (!Py_InitModule("HostAPI", HostApiFuncs)) {
        std::cerr << "Host API could not be initialzed." << std::endl;
        return 1;
    }

    // CPP init Python environments
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyObject * pName = PyString_FromString("test_01"); 
    PyObject * pModule = PyImport_Import(pName);
    if (!pModule) {
        std::cerr << "Cannot open script" << std::endl;
        return 1;
    }
    PyObject * pDict = PyModule_GetDict(pModule);

    PyObject * pParams = PyTuple_New(2);   // Use tuple to pass parameters
    // CPP call Python function "mul"
    PyObject * pMul = PyDict_GetItemString(pDict, "mul");
    PyTuple_SetItem(pParams, 0, PyInt_FromLong(6));
    PyTuple_SetItem(pParams, 1, PyInt_FromLong(2));
    PyObject * pResult = PyObject_CallObject(pMul, pParams);
    std::cout << "Result = " << PyInt_AsLong(pResult) << std::endl;

    // CPP call Python function "pstr"
    PyObject * pPstr = PyDict_GetItemString(pDict, "pstr");
    PyTuple_SetItem(pParams, 0, PyString_FromString("this is a test string"));
    PyTuple_SetItem(pParams, 1, PyInt_FromLong(4));
    PyObject * pIgnore = PyObject_CallObject(pPstr, pParams);

    Py_XDECREF(pIgnore);
    Py_XDECREF(pPstr);
    Py_XDECREF(pResult);
    Py_XDECREF(pMul);
    Py_XDECREF(pParams);
    // Py_XDECREF(pDict); 
    Py_XDECREF(pModule);
    Py_XDECREF(pName);

    Py_Finalize();
    return 0;
}