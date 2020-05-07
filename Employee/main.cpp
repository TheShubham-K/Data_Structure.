#include <iostream>

using namespace std;
class Employee
{
    char Ename[10];
    int salary, Enumber;
public:
    void read()
    {
        cout<<"Enter Name: "<<endl;
        cin>>Ename;
        cout<<"Enter your Enumber: "<<endl;
        cin>>Enumber;
        cout<<"Enter your salary: "<<endl;
        cin>>salary;
    }
    void Display()
    {
        cout<<"Name of the Employee is "<<Ename<<endl;
        cout<<"Your Enumber :"<<Enumber<<endl;
        cout<<"Your Salary :"<<salary<<endl;
    }
};
int main()
{
    int n;
    cout<<"How many Employees in the Company."<<endl;
    cin>>n;
    Employee E[n];
    for(int i=1;i<=n;i++)
    {
        E[i].read();
        cout<<"Details of the Employee "<<i<<" is"<<endl;
        E[i].Display();
    }
    return 0;
}
