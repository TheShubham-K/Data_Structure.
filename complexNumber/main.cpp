#include <iostream>

using namespace std;
class Complex
{
    int real;
    float image;

public:
    void read(int r, float i)
    {
        real = r;
        image = i;
    }
    void display()
    {
        cout<<"Real: "<<real<<"\nImage: "<<image<<endl;
    }
    friend Complex add(Complex A, Complex B);
};
Complex add(Complex A, Complex B)
{
    Complex temp;
    temp.real= A.real+B.real;
    temp.image = A.image + B.image;
    return temp;
}

int main()
{
    Complex c1, c2, c3;
    c1.read(1,2);
    c2.read(2,3);
    c3 = add(c1,c2);
    cout<<"c3:"<<endl;
    c3.display();
    return 0;
}
