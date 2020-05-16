#include <iostream>

using namespace std;
class Shape
{
protected:
    double x;
    double y;
public:
    virtual void displayArea() = 0;
    void getdata (double a, double b)
    {
        x=a;
        y=b;
    }
};
class Triangle:public Shape
{
public:
    void displayArea()
    {
        cout<<"X :"<<x<<"\nY :"<<y<<endl;
        cout<<"Area of the Triangle is: "<<(x*y)/2<<endl;
    }
};
class Rectrangle: public Shape
{
public:
    void displayArea()
    {
        cout<<"X :"<<x<<"\nY :"<<y<<endl;
        cout<<"Area of the Rectrangle: "<<(x*y)<<endl;
    }
};
int main()
{
    Triangle t1;
    t1.getdata(5,6);
    t1.displayArea();
    Rectrangle r1;
    r1.getdata(5,4);
    r1.displayArea();
    return 0;
}
