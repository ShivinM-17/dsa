#include<iostream>
using namespace std;

int max_center_sum(int arr[],int low, int mid, int high){
    int left_sum = INT_MIN;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }
    int right_sum = INT_MIN;
    sum=0;
    for(int i=mid;i<=high;i++){
        sum += arr[i];
        if(sum>right_sum){
            right_sum=sum;
        }
    }
    return max(left_sum+right_sum-arr[mid],max(left_sum,right_sum));
}
int max_sum_subarray(int arr[], int low, int high){
    if(low>high) return INT_MIN;
    if(low==high) return arr[low];
    int mid = (low+high)/2;
    return max(max_sum_subarray(arr,low,mid-1),
               max(max_center_sum(arr,low,mid,high),max_sum_subarray(arr,mid+1,high)));

}
int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<max_sum_subarray(arr,0,n)<<endl;
    return 0;
}