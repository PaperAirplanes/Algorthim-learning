#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> getdp(vector<char> &str1, vector<char> &str2);

int main(){
    char temp1; char temp2;
    vector<char> str1 = "ABCDG";
    vector<char> str2 = "BCDFEG";
    cout << str1[0] <<" "<<str2[0]<<endl;
    vector<vector<int>> dp = getdp(str1, str2);
    return 0;
}

vector<vector<int>> getdp(vector<char> &str1, vector<char> &str2) {
    vector<vector<int>> dp(str1.size() + 1,vector<int>(str2.size() + 1, 0));
    dp[0][0] = str1[0] == str2[0] ? 1 : 0;
    for(int i = 1; i < str1.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], str1[i] == str2[0] ? 1 : 0);
    }
    for(int j = 1; j < str2.size(); j++) {
        dp[0][j] = max(dp[0][j - 1], str1[0] == str2[j] ? 1 : 0);
    }
    for (int i = 1; i < str1.size(); i++){
        for (int j = 1; j < str2.size(); j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(str1[i] == str2[j]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp;
}

