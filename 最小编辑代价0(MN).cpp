// 最小编辑代价 <动态规划> <复杂度0(M*N)>
#include<bits/stdc++.h>
using namespace std;
int mincost1(string str1, string str2, int ic, int dc, int rc);

int main(){
    string str1, str2;
    cin>>str1;
    cin>>str2;
    int ic = 5;    //插入一个字符的代价
    int dc = 3;    //删除一个字符的代价
    int rc = 2;    //替换一个字符的代价
    int result = mincost1(str1, str2, ic, dc, rc);
    cout<< result;
    return 0;
}

int mincost1(string str1, string str2, int ic, int dc, int rc){
    int row = str1.size() + 1;
    int col = str2.size() + 1;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    //考虑边界,第一列，第一行
    for(int i = 1; i < row; i++){
        dp[i][0] = dc * i;
    }
    for(int j = 1; j < col; j++){
        dp[0][j] = ic * j;
    }
    //其他位置进行从左到右，从上到下的填充
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(str1[i-1] != str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + rc;
            }else{
                dp[i][j] = dp[i-1][j-1];
            }
            dp[i][j] = min(dp[i][j], dc + dp[i-1][j]);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + ic);
        }
    }
    return dp[row-1][col-1];
}
/* input
ab12cd3
abcdf
*/
/* output
8
*/
