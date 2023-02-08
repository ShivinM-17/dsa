#include<iostream>
#include<algorithm>
using namespace std;

int total_prof(int sackwt, int prof[], int wt[], int n){
    int dp[sackwt+1];
    for(int i=0;i<=sackwt;i++){
        dp[i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int w=sackwt;w>=0;w--){
            if(wt[i-1]<=w){
                dp[w]=max(dp[w],dp[w-wt[i-1]]+prof[i-1]);
            }
        }
    }
    cout<<endl;
    return dp[sackwt];
}

int main()
{
    int sackwt, n;
    cin>>sackwt>>n;
    int prof[n],wt[n];
    for(int i=0;i<n;i++) cin>>prof[i];
    for(int i=0;i<n;i++) cin>>wt[i];
    cout<<total_prof(sackwt,prof,wt,n)<<endl;
    return 0;
}