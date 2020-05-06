#include <iostream>

using namespace std;

class Student
{
protected:
    char name[20];
    int Usn;
public:
    void read()
    {
        cout<<"Enter Student's Name: "<<endl;
        cin>>name;
        cout<<"Enter Your USN: "<<endl;
        cin>>Usn;
    }
    void print()
    {
        cout<<"Student Name is: "<<name<<endl;
        cout<<"Usn No.: "<<Usn<<endl;
    }
};

class Test: virtual public Student
{
protected:
    int sub1;
    int sub2;
public:
    void getmarks()
    {
        cout<<"ENTER SUBJECT 1 MARKS: "<<endl;
        cin>>sub1;
        cout<<"ENTER SUBJECT 2 MARKS: "<<endl;
        cin>>sub2;
    }
    void putmarks()
    {
        cout<<"subject 1 marks is: "<<sub1<<endl;
        cout<<"subject 2 marks is: "<<sub2<<endl;
    }
};
class Sports:virtual public Student
{
protected:
    int score;
public :
    void getscore()
    {
        cout<<"Enter your score: "<<endl;
        cin>>score;
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
    int n,i;
    Result r[50];
    cout<<"Enter the Number of students: "<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        r[i].read();
        r[i].getmarks();
        r[i].getscore();
    }
    for(i=0;i<n;i++)
    {
        r[i].display();
    }
    return 0;
}
