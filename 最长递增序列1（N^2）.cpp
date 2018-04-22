#include<bits/stdc++.h>
using namespace std;
vector<int> getdp1(vector<int> &arr);
vector<int> generateLIS(vector<int> &arr, vector<int>&dp);

int main() {
    vector<int> arr;
    int temp;
    while(cin >> temp){
        arr.push_back(temp);
    }
    vector<int> dp = getdp1(arr);
    vector<int> lis = generateLIS(arr, dp);
    for (int i = 0; i < lis.size(); i++){
        cout << lis[i]<<endl;
    }
    return 0;
}

vector<int> getdp1(vector<int> &arr){
    vector<int> dp(arr.size(), 0);
    for(int i = 0; i < arr.size(); i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[j]+ 1, dp[i]);
            }
        }
    }
    return dp;
}

vector<int> generateLIS(vector<int> &arr, vector<int> &dp){
    int len = 0; int index = 0;
    for (int i = 0; i < dp.size(); i++) { //寻最长递增子序列末尾的位置和值
        if (dp[i] > len) {
            len = dp[i];
            index = i;
        }
    }
    vector<int> lis(len, 0);
    lis[--len] = arr[index];
    for (int i = index; i >= 0; i--){
        if (arr[i] < arr[index] && dp[i] == dp[index] - 1){  //从后往前找子序列
            lis[--len] = arr[i];
            index = i;
        }
    }
    return lis;
}
