#include <iostream>
#include <string.h>

using namespace std;
class Number
{
    int value;
public:
    Number(int v)
    {
        value=v;
    }
    void display()
    {
        cout<<"value = "<<value<<endl;
    }
    friend Number Swap(Number &A, Number &B);
};
Number Swap(Number &A, Number &B)
{
    int temp;
    temp=A.value;
    A.value=B.value;
    B.value=temp;
    return temp;
}

int main()
{
    Number n1(10);
    cout<<"N1: "<<endl;
    n1.display();
    Number n2(20);
    cout<<"N2: "<<endl;
    n2.display();
    Swap(n1,n2);
    cout<<"After Swapping"<<endl;
    cout<<"N1: "<<endl;
    n1.display();
    cout<<"N2: "<<endl;
    n2.display();
    return 0;
}
