// 换钱的方法数 <动态规划> <复杂度0(N*aim)>
// 空间换时间，按顺序进行输出
// dp[i][j] = dp[i-1][j] + dp[i][j-arr[i]];
#include<bits/stdc++.h>
using namespace std;
int coins4(int arr[], int aim);

int main(){
    int N, aim; cin >> N >> aim;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << coins4(arr, aim) <<endl;
    return 0;
}

int coins4(int arr[], int aim){
    int dp[sizeof(arr)][aim + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < sizeof(arr); i++){
        dp[i][0] = 1;
    }
    for (int j = 1; j * arr[0] <= aim; j++){
        dp[0][j * arr[0]] = 1;
    }
    for (int i = 1; i < sizeof(arr); i++) {
        for (int j = 1; j <= aim; j++){
            dp[i][j] = dp[i - 1][j];
            dp[i][j] += (j - arr[i]) >= 0 ? dp[i][j - arr[i]] : 0;
      //      cout << i <<","<< j <<": "<< dp[i][j]<<endl;
        }
    }
    return dp[sizeof(arr) - 1][aim];
}
