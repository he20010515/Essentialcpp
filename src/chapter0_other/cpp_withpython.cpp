/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-01-29 10:01:27
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-02-05 08:53:56
 * @FilePath: /Essentialcpp/src/chapter0_other/cpp_withpython.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Python.h"

int main(int argc, char const *argv[])
{
    Py_Initialize();
    PyRun_SimpleString("print(\"Hello OneFLOW CFD!\")");
    PyRun_SimpleString("import os");
    PyRun_SimpleString("print(os)");

    Py_Finalize();
    return 0;
}
