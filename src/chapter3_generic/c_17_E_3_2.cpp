/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2022-12-24 12:59:12
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2022-12-24 14:03:09
 * @FilePath: /Essentialcpp/src/chapter3_generic/c_17_E_3_2.cpp
 * @Description: 利用istream_iterator 从标准输入读取一串整数.
 *               利用ostream_iterator将其中的奇数写入文件A,以空格分割
 *               将偶数写入另一文件,以换行符分割.
 */

#include <unistd.h>
#include <filesystem>
inline void chdir_to_src_path()
{
    std::__fs::filesystem::path src_path(__FILE__);
    chdir(src_path.parent_path().c_str());
}

#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    chdir_to_src_path();
    using namespace std;
    cout << "please input int list,split by \"\"" << endl;
    cout << ">>";
    istream_iterator<int> is(cin), eof;
    vector<int> int_buffer;
    copy(is, eof, back_inserter(int_buffer));
    ofstream outfile_1("c_17_output1.txt"), outfile_2("c_17_output2.txt");
    ostream_iterator<int> it1(outfile_1, " "), it2(outfile_2, "\n");

    for (auto &&i : int_buffer)
        if (i % 2 == 0)
            *(it2++) = i;
        else
            *(it1++) = i;

    return 0;
}
