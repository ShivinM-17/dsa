#include<iostream>
#include<cstring>
using namespace std;

void longestcommonsubsequence(string str1, string str2){
    int m = str1.length();
    int n = str2.length();
    int LCS_table[m+1][n+1];
    for(int i=0;i<=m;i++) LCS_table[i][0]=0;
    for(int j=0;j<=n;j++) LCS_table[0][j]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1] == str2[j-1]){
                LCS_table[i][j] = LCS_table[i-1][j-1] + 1;
            }
            else if(LCS_table[i-1][j] >= LCS_table[i][j-1]){
                LCS_table[i][j] = LCS_table[i-1][j];
            } 
            else {
                LCS_table[i][j] = LCS_table[i][j-1];
            }
        }
    }
    int index = LCS_table[m][n];
    char lcs[index+1];
    lcs[index]='\0';

    int i=m, j=n;
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
            lcs[index-1] = str1[i-1];
            i--; j--; index--;
        }
        else if(LCS_table[i-1][j] > LCS_table[i][j-1]) i--;
        else j--;
    }
    cout<<"Longest common subsequence: "<<lcs<<endl;
    cout<<"Length of the LCS: "<<strlen(lcs)<<endl;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    longestcommonsubsequence(s1,s2);
    return 0;
}


