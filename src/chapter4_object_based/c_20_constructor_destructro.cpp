#include <iostream>

class Triangular
{
private:
    int _length, _beg_pos, _next;

public:
    Triangular() { Triangular(1, 1); };          // Default constructor
    Triangular(int len) { Triangular(len, 1); }; // this constructor will be called when `Triangular a = 1;`. **not** assignment operator.
    Triangular(int len, int beg_pos)
    {
        _length = len > 0 ? len : 1;
        _beg_pos = beg_pos > 0 ? beg_pos : 1;
        _next = _beg_pos - 1;
    };
    ~Triangular(){};
};

int main(int argc, char const *argv[])
{
    ;
    return 0;
}
