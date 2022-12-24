/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-24 11:23:26
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-24 11:46:43
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_14_use_map.cpp
 * @Description: 使用map和set两种无序容器
 */
#include <map>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::map<std::string, int> words;
    words["test"] = 1;
    std::string tword;
    while (std::cin >> tword)
    {
        if (tword == "break")
            break;
        words[tword]++;
    }

    auto it = words.begin();
    for (; it != words.end(); it++)
        std::cout << "key  :" << it->first << std::endl
                  << "value:" << it->second << std::endl;
    auto it2 = words.find("what");
    if (it2 != words.end())
        std::cout << "key  :" << it2->first << std::endl
                  << "value:" << it2->second << std::endl;

    return 0;
}
