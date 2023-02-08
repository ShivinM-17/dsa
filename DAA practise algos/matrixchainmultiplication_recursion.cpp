#include<iostream>
#include<algorithm>
using namespace std;

int matrixchainmulti(int p[], int i, int j){
    if(i==j) return 0;
    int k, mini = INT_MAX, count;

    for(k = i ; k<j ; k++){
        count = matrixchainmulti(p,i,k)
                + matrixchainmulti(p,k+1,j)
                + p[i-1]*p[k]*p[j];
        mini = min(count,mini);
    }
    return mini;
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<matrixchainmulti(arr,1,n-1);
    return 0;
}