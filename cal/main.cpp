#include <iostream>

using namespace std;
template <class T>
class Calculator
{
    T res;
    T op1, op2;
    char symbol;
public:
    void read()
    {
        cout<<"Enter the operand 1:"<<endl;
        cin>>op1;
        cout<<"Enter the operand 2:"<<endl;
        cin>>op2;
        cout<<"Enter the operation u want to perform:"<<endl;
        cin>>symbol;
    }
    void print()
    {
        cout<<"operand 1: "<<op1<<"operand 2 : "<<op2<<endl;
    }
    void compute()
    {
        switch(symbol)
        {
        case '+':
            res=op1+op2;
            break;
        case '-':
            res=op1-op2;
            break;
        case '*':
            res = op1*op2;
            break;
        case '/':
            res = op1/op2;
            break;
        default:
            cout<<"Invalid input"<<endl;
        }
        cout<<"Result : "<<res<<endl;
    }
};
int main()
{
    Calculator<int>c1;
    c1.read();
    c1.print();
    c1.compute();
    return 0;
}
