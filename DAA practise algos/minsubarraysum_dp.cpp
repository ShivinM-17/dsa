#include<iostream>
using namespace std;

int min_subarray_sum(int arr[], int n){
    int curr= INT_MAX, mintillnow = INT_MAX;
    for (int i = 0; i < n; i++){
        if(curr>0) curr=arr[i];
        else{
            curr += arr[i];
        }
        mintillnow = min(mintillnow,curr);
    }
    return mintillnow;  
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<min_subarray_sum(arr,n);
    return 0;
}