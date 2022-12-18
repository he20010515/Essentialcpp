/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-18 15:48:58
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-18 17:28:44
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_11_linear_container.cpp
 * @Description: 顺序型容器.
 */

#include <vector>
#include <list>
#include <deque>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // 1. 产生空的容器;
    list<string> s_list;
    vector<int> i_vector;
    // 2. 产生特定长度的容器,使用默认值;
    list<int> i_list(1024);
    vector<string> s_vector(24);
    // 3. 产生特定大小的容器,并为每个元素赋初值;
    vector<int> i_vector_init(10, 123);
    list<string> s_list_init(10, "unassigned");
    // 4. 通过一对迭代器产生容器
    int int_array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> i_vector_from_iterator(int_array, int_array + 8);
    // 5. 根据某个容器产生新的容器.复制原容器内的元素,作为新容器的初值
    auto v(s_vector); // vector<string> v(s_vector);
    

    return 0;
}
