#include <iostream>
#include <string.h>

using namespace std;
 class Student
{
protected:
    char name[20];
    int Usn;
public:
    void read(char *n, int u)
    {
        strcpy(name, n);
        Usn=u;
    }
    void print()
    {
        cout<<"Student Name is: "<<name<<endl;
        cout<<"Usn No.: "<<Usn<<endl;
    }
};

class Medical:  public Student
{
    int medno;
    int year;
public:
    void getdetails(int m, int y)
    {
        medno=m;
        year = y;
    }
    void display()
    {
        print();
        cout<<"Medical Number: "<<medno<<endl;
        cout<<"Year of Join: "<<year<<endl;
    }
};
class Engineering: public Student
{
    char  Branch[20];
    int Usn;
    int Sem;
public :
    void getdetails(char *b, int u, int s)
    {
        strcpy(Branch, b);
        Usn=u;
        Sem=s;
    }
    void display()
    {
        print();
        cout<<"Branch : "<<Branch<<endl;
        cout<<"Usn: "<<Usn<<endl;
        cout<<"SEM: "<<Sem<<endl;
    }
};

int main()
{
    Medical m1;
    m1.getdetails(202118,2018);
    m1.read("Shubham", 21);
    m1.display();
    Engineering e1;
    e1.getdetails("Computer Science", 418189,3);
    e1.read("Shubham", 21);
    e1.display();
    return 0;
}
