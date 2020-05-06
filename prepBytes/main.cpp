#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int sum = 0,n,rem;
        cin>>n;
        for(int i=1; i<n; i++){
            rem = n%i;
            if(rem==0){
                sum = sum+i;
            }
        }
        cout<<"Sum = "<<sum<<endl;
        if(sum==n)
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}
