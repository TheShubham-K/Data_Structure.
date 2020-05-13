#include <iostream>

using namespace std;
class Time
{
    int hours;
    int minute;
public:
    int read(int h, int m)
    {
        hours = h;
        minute = m;
    }
    void display()
    {
        cout<<"Number of hours: "<<hours<<" Minutes: "<<minute<<endl;
    }
    Time compute(Time A, Time B)
    {
        int h= (A.minute+B.minute)/60;
        minute = (A.minute+B.minute)%60;
        hours=h+A.hours+B.hours;
    }
};
int main()
{
    Time t1, t2, t3;
    t1.read(2,30);
    t1.display();
    t2.read(3,45);
    t2.display();
    t3.compute(t1,t2);
    t3.display();
    return 0;
}
