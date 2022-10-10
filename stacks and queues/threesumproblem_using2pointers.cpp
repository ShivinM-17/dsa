#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(auto &i: arr){
        cin>>i;
    }
    bool found=false;
    int a1,a2,a3;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int lo = i+1, hi=n-1;
        while(lo<hi){
            int current = arr[i] + arr[lo] + arr[hi];
            if(current==target){
                found=true;
                a1=arr[i];
                a2=arr[lo];
                a3=arr[hi];
                break;
            }
            else if(current<target){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    if(found){
        cout<<"Triplets found equal to sum: "<<a1<<" "<<a2<<" "<<a3<<endl;
    } else {
        cout<<"No such triplets found"<<endl;
    }

    return 0;
}