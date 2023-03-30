/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2023-02-11 12:56:51
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2023-03-14 13:35:40
 * @FilePath: /Essentialcpp/src/chapter5_object_oriented/c_24_book_class_system.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
class LibMeta
{
private:
    ;

public:
    LibMeta() { std::cout << "LibMeta::LibMeta() default constructor" << std::endl; };
    virtual ~LibMeta() { std::cout << "LibMeta::~LibMeta() default destructor" << std::endl; };
    virtual void print() const { std::cout << "LibMeta::print() I am a LibMeta object" << std::endl; };
};
class Book : public LibMeta
{
private:
    std::string bookname;
    std::string author;

public:
    Book()
    {
        std::cout << "Book::Book() default constructor" << std::endl;
        this->bookname = "none_name";
        this->author = "none_author";
    };
    Book(std::string &_bookname, std::string &_author)
    {
        std::cout << "Book::Book(std::string &_bookname, std::string &_author)  constructor" << std::endl;
        this->bookname = _bookname;
        this->author = _author;
    }
    Book(const char *_bookname, const char *_author)
    {
        std::cout << "Book(char *_bookname, char *_author) constructor" << std::endl;
        this->bookname = _bookname;
        this->author = _author;
    }
    ~Book() { std::cout << "Book::~Book() default destructor" << std::endl; };
    virtual void print() const
    {
        std::cout << "LibMeta::print() I am a Book Object" << std::endl;
        std::cout << "bookname:" << this->bookname << std::endl
                  << "author  :" << this->author << std::endl;
    };
};

void print(const LibMeta &obj)
{
    std::cout << "in global print():about to print obj.print()" << std::endl;
    obj.print();
}

int main(int argc, char const *argv[])
{
    // std::cout << std::endl
    //           << "Creating a LibMeta obj to print()" << std::endl;
    // LibMeta obj;
    Book b("关于我没有学非线性这件事", "😅");
    print(b);
    // print(obj);
    return 0;
}
