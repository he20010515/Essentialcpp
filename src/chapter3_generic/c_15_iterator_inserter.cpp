/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-24 11:49:56
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-24 12:03:49
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_15_iterator_inserter.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

#include <unistd.h>
#include <filesystem>
inline void chdir_to_src_path()
{
    std::__fs::filesystem::path src_path(__FILE__);
    chdir(src_path.parent_path().c_str());
}

using namespace std;
int v1()
{
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());
    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);
    return 0;
}

int main(int argc, char const *argv[])
{
    chdir_to_src_path();
    ifstream in_file("c_15_infile.txt");
    ofstream out_file("c_15_outfile.txt");
    if (!in_file || !out_file)
    {
        cerr << "!! unable to open the necessary files." << endl;
        return -1;
    }
    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    ostream_iterator<string> os(out_file, " ");
    copy(text.begin(), text.end(), os);
}
