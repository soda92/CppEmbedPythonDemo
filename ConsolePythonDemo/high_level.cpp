#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <cstdio>
#include <boost/filesystem.hpp>
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{

    LPWSTR* szArglist;
    int nArgs;
    std::ofstream out{ "D:/out_path.txt" };
    out << boost::filesystem::current_path();
    out.close();

    //szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
    //wchar_t* program = szArglist[0];
    //if (program == NULL) {
    //    fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
    //    exit(1);
    //}
    //Py_SetProgramName(program);  /* optional but recommended */
    Py_Initialize();
    /*PyRun_SimpleString("from time import time,ctime\n"
        "print('Today is', ctime(time()))\n");*/
    std::FILE* file = nullptr;
    fopen_s(&file, "qt_test.py", "r");
    PyRun_AnyFile(file, "qt_test.py");
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    //PyMem_RawFree(program);
    return 0;
}