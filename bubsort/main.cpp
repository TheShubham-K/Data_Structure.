#include <iostream>

using namespace std;
template <class T>
void bubsort(T a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
};

int main()
{
    int n=5;
    int a[n] = {8,5,6,4,3};
    float b[n] = {1.2,5.3,4.6,2.3,6.2};
    cout<<"Before Sorting: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"A: "<<a[i]<<endl;
    }
    bubsort(a, n);
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"A :"<<a[i]<<endl;
    }
    cout<<"Before Sorting: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"B: "<<b[i]<<endl;
    }
    bubsort(b, n);
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"B :"<<b[i]<<endl;
    }
    return 0;
}
