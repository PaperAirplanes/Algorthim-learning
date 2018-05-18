// 龙与地下城游戏<动态规划> <复杂度0(N^2)>
#include<bits/stdc++.h>
using namespace std;
int minHP1(vector<vector<int>> map1);

int main(){
    cout<<"输入地图的维度M,N: ";
    int M, N;
    int temp;
    cin>>M>>N;
    vector<vector<int>> map1;
    vector<int> v1;
    for(int i = 0; i < M; i++){
        map1.push_back(v1);
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> temp;
            map1[i].push_back(temp);
        }
    }

    int result = minHP1(map1);
    cout << "初始血量："<< result<<endl;
    return 0;
}

int minHP1(vector<vector<int>> map1){
    int row = map1.size()-1 ;
    int col = map1[0].size()-1 ;
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

/*    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            cout<<map1[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    dp[row][col] = map1[row][col] > 0 ? 1 : (-map1[row][col] + 1);
    for(int j = col - 1; j >= 0; j--){
        dp[row][j] = max(dp[row][j+1] - map1[row][j], 1);
    }
    int right =  0;
    int down = 0;
    for(int i = row - 1; i >= 0; i--){
        dp[i][col] = max(dp[i+1][col] - map1[i][col], 1);
        for(int j = col - 1; j >= 0; j--){
            right = max(dp[i][j+1] - map1[i][j], 1);
            down = max(dp[i+1][j] - map1[i][j], 1);
            dp[i][j] = min(right, down);
        }
    }
    return dp[0][0];
}
