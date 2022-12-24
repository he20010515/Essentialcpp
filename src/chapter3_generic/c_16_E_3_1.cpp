/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-24 12:07:00
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-24 12:22:45
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_16_E_3_1.cpp
 * @Description: 读取文本文件,并将其中的每个单词存入map,map的key是单字,value是频率. 再定义一个排除字眼组成的set.其中包含 a, and, but 等之类的单词.
 */
#include <unistd.h>
#include <filesystem>
#include <istream>
#include <iterator>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iostream>
inline void chdir_to_src_path()
{
    std::__fs::filesystem::path src_path(__FILE__);
    chdir(src_path.parent_path().c_str());
}

int main(int argc, char const *argv[])
{
    chdir_to_src_path();
    using namespace std;

    vector<string> text;
    ifstream in_file("c_16_input.txt");
    istream_iterator<string> is(in_file), eof;
    copy(is, eof, back_inserter(text));

    map<string, int> mapper;
    string ex_word[] = {
        "is", "an", "the", "a"};
    set<string> except_word(ex_word, ex_word + 4);
    for (auto &&s : text)
        if (except_word.find(s) == except_word.end())
            mapper[s]++;

    for (auto &&pair : mapper)
    {
        cout << "key  :" << pair.first << endl
             << "value:" << pair.second << endl
             << "======" << endl;
    }

    sort(text.begin(), text.end(), [](string a, string b) -> bool
         { return a.length() < b.length(); });
    for (auto &&word : text)
    {
        cout << word << " " << endl;
    }

    return 0;
}
