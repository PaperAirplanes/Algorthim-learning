// ��Ǯ�ķ����� <��̬�滮> <���Ӷ�0(N*aim)>
// ����ռ临�Ӷ� o(aim)
#include<bits/stdc++.h>
using namespace std;
int coins5(int arr[], int aim);

int main(){
    int N, aim; cin >> N >> aim;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << coins5(arr, aim) <<endl;
    return 0;
}

int coins5(int arr[], int aim){
    int dp[aim + 1];
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j * arr[0] <= aim; j++){
        dp[j * arr[0]] = 1;
    }
    for (int i = 1; i < sizeof(arr); i++) {
        for (int j = 1; j <= aim; j++){
            dp[j] += j - arr[i] >= 0 ? dp[j - arr[i]] : 0;
      //      cout << i <<","<< j <<": "<< dp[j]<<endl;
        }
    }
    return dp[aim];
}
