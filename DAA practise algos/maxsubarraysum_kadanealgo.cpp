#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cursum=0,maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        cursum+=arr[i];
        maxSum=max(maxSum,cursum);
        if(cursum<0){
            cursum=0;
        }
    }
    cout<<maxSum<<endl;
    return 0;
}