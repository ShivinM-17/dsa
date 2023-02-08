#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int arr1[n1], arr2[n2];
    for(int i=0;i<n1;i++) arr1[i] = arr[low+i];
    for(int i=0;i<n2;i++) arr2[i] = arr[mid+i+1];

    int k = low, i = 0, j = 0;
    while(i<n1 && j<n2){
        if(arr1[i]>arr2[j]){
            arr[k]=arr2[j];
            j++;
        } else {
            arr[k]=arr1[i];
            i++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=arr1[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        k++; j++;
    }
}

void mergersort(int arr[], int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    mergersort(arr,low,mid);
    mergersort(arr,mid+1,high);

    merge(arr,low,mid,high);
}

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergersort(arr,0,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}