#include<bits/stdc++.h>
using namespace std;

int mincoins(vector<int> &arr, int aim){
    int n = arr.size();
    int max1 = 1000;
    vector<vector<int>> dp(n, vector<int>(aim+1, 0));
    dp[0][0] = 0;
    for(int j = 1; j <= aim; j++){
        dp[0][j] = max1;
        if(j - arr[0] >= 0 && dp[0][j - arr[0]] != max1){
            dp[0][j] = dp[0][j - arr[0]] + 1;
        }
    }
    int left = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= aim; j++){
            left = max1;
            if(j - arr[i] >= 0 && dp[i][j - arr[i]] != max1){
                left = dp[i][j - arr[i]] + 1;
            }
            dp[i][j] = min(left, dp[i - 1][j]);
        }
    }
    return dp[n-1][aim] != max1 ? dp[n-1][aim] : -1;
}

int main(){
    int aim;
    cin >> aim;
    vector<int> arr;
    int temp;
    while(cin >> temp){
        arr.push_back(temp);
    }
    cout<< arr[0]<<endl;
    cout<< aim<<endl;
    int result = mincoins(arr, aim);
    cout << result;
    return 0;
}
