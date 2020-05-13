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

class Test:  public Student
{
protected:
    int sub1;
    int sub2;
public:
    void getmarks(int n1, int n2)
    {
        sub1=n1;
        sub2=n2;
    }
    void putmarks()
    {
        cout<<"subject 1 marks is: "<<sub1<<endl;
        cout<<"subject 2 marks is: "<<sub2<<endl;
    }
};
class Sports
{
protected:
    int score;
public :
    void getscore(int s)
    {
        score = s;
    }
    void putscore()
    {
        cout<<"Your Score is : "<<score<<endl;
    }
};
class Result: public Test, public Sports
{
    int total;
public:
    void display()
    {
        total = sub1 + sub2 + score;
        print();
        putmarks();
        putscore();
        cout<<"Total Marks you Scored: "<<total<<endl;
    }
};

int main()
{
    Result r1;
    r1.read("Shubham",10);
    r1.getmarks(98,99);
    r1.getscore(99);
    r1.display();
    return 0;
}
