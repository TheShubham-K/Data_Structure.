#include <iostream>

using namespace std;
class B;
class A
{
    int value;
public:
    void read(int v)
    {
        value = v;
    }
    void print()
    {
        cout<<"value: "<<value<<endl;
    }
    friend void maximum(A obj1, B obj2);
};
class B
{
    int value;
public:
    void read(int v)
    {
        value = v;
    }
    void print()
    {
        cout<<"value: "<<value<<endl;
    }
    friend void maximum(A obj1, B obj2);
};
void maximum(A obj1, B obj2)
{
    if(obj1.value>obj2.value)
    {
        cout<<"maximum: "<<obj1.value<<endl;
    }
    else
    {
        cout<<"maximum: "<<obj2.value<<endl;
    }
}
int main()
{
    A a1;
    B b1;
    a1.read(10);
    b1.read(20);
    cout<<"a1: "<<endl;
    a1.print();
    cout<<"b1:"<<endl;
    b1.print();
    maximum(a1,b1);
    return 0;
}
