#include<iostream>
using namespace std;

int lcs(string str1, string str2, int m, int n){
    if(m==0 || n==0) return 0;
    if(str1[m-1] == str2[n-1])
        return 1 + lcs(str1,str2,m-1,n-1);
    else
        return max(lcs(str1,str2,m,n-1),lcs(str1,str2,m-1,n));
}
int main(){
    string str1, str2;
    cin>>str1>>str2;
    int m = str1.length(), n=str2.length();
    cout<<"Length of LCS: "<<lcs(str1,str2,m,n)<<endl;
    return 0;
}


