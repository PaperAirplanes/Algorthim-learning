#include<bits/stdc++.h>
using namespace std;

vector<int> getmax(string str1, string str2) {
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    vector<int> result(2, 0);
    for (int i = 0; i < str1.size(); i++){
        dp[i][0] = str1[i] == str2[0] ? 1 : 0;
    }
    for (int j = 0; j < str2.size(); j++){
        dp[0][j] =  str1[0] == str2[j] ? 1 : 0;
    }
    for (int i = 1; i < str1.size(); i++){
        for (int j = 1; j < str2.size(); j++){
            dp[i][j] = str1[i] == str2[j] ? dp[i-1][j-1] + 1 : 0;
        }
    }
    int max0 = 0;
    int end0 = 0;
    for (int i = 0; i < str1.size(); i++){
        for (int j = 0; j < str2.size(); j++){
            if(dp[i][j] > max0) {
                max0 = dp[i][j];
                end0 = i;
            }
        }
    }
    result[0] = max0;
    result[1] = end0;
    return result;
}

int main(){
    string str1, str2, str3;
//    str1 = "1AB2345CD";
//    str2 = "12345EF";
    cin >> str1 >> str2;
    vector<int> result = getmax(str1, str2);
    str3 = str1.substr(result[1] - result[0] + 1, result[0]);
    cout << str3;
    return 0;
}
