#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int profit, weight;
};
static bool comparator(struct Item a, struct Item b){
    float r1 = (float)a.profit/(float)a.weight;
    float r2 = (float)b.profit/(float)b.weight;
    return r1>r2;
}
float total_profit(int sackWt, struct Item arr[], int n){
    sort(arr,arr+n,comparator);
    float final_prof = 0.0;
    for(int i=0;i<n;i++){
        if(arr[i].weight<=sackWt){
            sackWt-=arr[i].weight;
            final_prof += arr[i].profit;
        } 
        else{
            final_prof += arr[i].profit*((float)sackWt/(float)arr[i].weight);
            break;
        }
    }
    return final_prof;
}
int main()
{
    int n, sackwt; cin>>n>>sackwt;
    Item arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].profit;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].weight;
    }
    cout<<total_profit(sackwt,arr,n)<<endl;
    return 0;
}