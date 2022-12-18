/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-17 17:44:59
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-18 15:24:20
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_09_iterator.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <vector>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    auto vector_begin = vector.begin(); // 可读可写
    std::vector<int>::iterator vector_begin_1 = vector.begin();
    const std::vector<int> vector_c;
    auto vector_c_begin = vector_c.begin(); // 这是一个只读的指针
    std::cout << "value \ti-vector_begin\t&(*vector_begin)" << std::endl;
    std::cout
        << *vector_begin << "\t" << vector_begin - vector_begin_1 << "\t" << &(*vector_begin) << std::endl
        << *(++vector_begin) << "\t" << vector_begin - vector_begin_1 << "\t" << &(*vector_begin) << std::endl
        << *(++vector_begin) << "\t" << vector_begin - vector_begin_1 << "\t" << &(*vector_begin) << std::endl
        << *(--vector_begin) << "\t" << vector_begin - vector_begin_1 << "\t" << &(*vector_begin) << std::endl
        << *(--vector_begin) << "\t" << vector_begin - vector_begin_1 << "\t" << &(*vector_begin) << std::endl
        << *(--vector_begin) << "\t" << vector_begin - vector_begin_1 << "\t" << &(*vector_begin) << std::endl
        << *(--vector_begin) << "\t" << vector_begin - vector_begin_1 << "\t" << &(*vector_begin) << std::endl;

    return 0;
}
