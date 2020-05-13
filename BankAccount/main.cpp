#include <iostream>

using namespace std;
class BankAccount
{
    char name[20];
    int accountno;
    float Balance;
    public:void read()
    {
        cout<<"Enter Name: "<<endl;
        cin>>name;
        cout<<"Enter Account Number: "<<endl;
        cin>>accountno;
        cout<<"Enter the current Balance:"<<endl;
        cin>>Balance;
    }
    void deposit()
    {
        float amt;
        cout<<"Enter the amount to be deposited: "<<endl;
        cin>>amt;
        Balance=Balance+amt;
    }
    void withdrawal()
    {
        int amt;
        cout<<"Enter the amount to be withdrawal: "<<endl;
        cin>>amt;
        if(amt>Balance)
            cout<<"U have InSufficient Balanace"<<endl;
        else
            Balance = Balance - amt;
    }
    void display()
    {
        cout<<"Name of the Account Holder:"<<name<<endl;
        cout<<"Balance: "<<Balance<<endl;
    }
};
int main()
{
    cout<<"Made By Shubham"<<endl;
    BankAccount ba1;
    ba1.read();
    ba1.display();
    ba1.deposit();
    ba1.withdrawal();
    ba1.display();
    return 0;
}
