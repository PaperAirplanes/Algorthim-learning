#include<bits/stdc++.h>
using namespace std;
int *getdp1(int arr[]);

int main() {
    int N; cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int *dp;
    dp = getdp1(arr);
    for (int i = 0; i < N; i++){
        cout << dp[i] <<endl;
    }
    delete []dp;
    return 0;
}

int *getdp1(int arr[]){
    const int MAXL = 100005;
    int * dp = new int[MAXL];
    for(int i = 0; i < sizeof(arr); i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[j]+ 1, dp[i]);
            }
        }
    }
    return dp;
}
