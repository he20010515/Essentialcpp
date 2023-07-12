/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-03-30 13:36:15
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-03-30 13:56:36
 * @FilePath: /Essentialcpp/src/chapter5_object_oriented/c_25_others.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>

class LibMat
{
private:
    ;

public:
    LibMat() { std::cout << "LibMat::LibMat() default constructor!" << std::endl; };
    ~LibMat() { std::cout << "LibMat::~LibMat() default destructor!" << std::endl; };
    virtual void print() { std::cout << "LibMat::print() -- I am a LibMat object!" << std::endl; };
};

class Book : public LibMat
{
private:
    ;

public:
    Book() { std::cout << "Book::Book() default constructor!" << std::endl; };
    ~Book() { std::cout << "Book::~Book() defaut destructor!" << std::endl; };
    virtual void print() { std::cout << "Book::print() -- I am a LibMat object!" << std::endl; }
};

void print(LibMat &mat)
{
    mat.print();
    return;
}

int main(int argc, char const *argv[])
{
    Book book;
    LibMat mat;

    print(book);
    print(mat);
    return 0;
}
