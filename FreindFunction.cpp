#include<iostream>
using namespace std;

class B; //forward declaration.
class A
{
    int int1;
public:
    void setdata(int i)
    {
        int1 = i;
    }
    friend void max(A, B); //friend function.
};

class B
{
    int int2;
public:
    void setdata(int i)
    {
        int2 = i;
    }
    friend void max(A, B);
};
void max(A a, B b)
{
    if (a.int1 >= b.int2)
        cout << a.int1 << endl;
    else
        cout << b.int2 << endl;
}
int main()
{
    A a;
    B b;
    a.setdata(10);
    b.setdata(20);
    max(a, b);
    return 0;
}
