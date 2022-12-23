/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-18 15:48:58
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-23 20:27:11
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_11_linear_container.cpp
 * @Description: 顺序型容器.
 */

#include <vector>
#include <list>
#include <deque>
#include <iostream>

using namespace std;

template <typename IterType>
void display(IterType begin, IterType end)
{
    cout << '[';
    while (begin != end)
    {
        std::cout << *begin << ", ";
        begin++;
    }
    cout << "\b\b]" << endl;
}

template <typename ContainerType>
void display(ContainerType &c)
{
    display(c.begin(), c.end());
}

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

    cout << "input your value enter to break" << endl;
    string buffer;
    deque<int> i_deque;
    while (true)
    {
        cout << ">>";
        getline(cin, buffer);
        if (buffer == "")
            break;
        i_deque.push_back(std::atoi(buffer.c_str()));
        cout << "size of i_deque:" << i_deque.size() << endl;
        cout << "i_deque.front()" << i_deque.front() << endl;
        display(i_deque.begin(), i_deque.end());
    }

    auto position = i_deque.begin() + 2;
    // 将value插入到position之前,他会返回一个iterator,指向被插入的元素.
    cout << "before insert" << endl;
    display(i_deque.begin(), i_deque.end());
    auto insert_position = i_deque.insert(position, 10);
    cout << "after insert" << endl;
    display(i_deque);
    cout << "insert_positon:" << *insert_position << endl;

    // 在position之前插入count个元素,这些元素的值与value相同
    cout << "before count insert" << endl;
    display(i_deque);
    i_deque.insert(position, 3, 666);
    cout << "after insert" << endl;
    display(i_deque);

    cout << "begin erase" << endl;
    auto pos = i_deque.erase(i_deque.begin());
    cout << "run: auto pos i_deque.erase(i_deque.begin());" << endl;
    display(i_deque);
    cout << "*pos: " << *pos << endl;

    return 0;
}
