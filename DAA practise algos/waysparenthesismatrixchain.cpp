#include <iostream>
#include<cstring>
using namespace std;

int dp[100][100];

int MatrixChainOrder(int arr[], int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (i == j) return 1;
  dp[i][j] = 0;
  for (int k = i; k < j; k++) {
    dp[i][j] += MatrixChainOrder(arr, i, k) * MatrixChainOrder(arr, k + 1, j);
  }
  return dp[i][j];
}

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp, -1, sizeof(dp));
    cout << "Number of ways to parenthesize matrices: "
         << MatrixChainOrder(arr, 1, n) << endl;
    return 0;
}