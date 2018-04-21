// 换钱的方法数 <记忆化搜索> <复杂度0(N*aim^2)>
// 空间换时间
#include <bits/stdc++.h>
using namespace std;
int process2(int arr[], int index, int aim, int map1[][10001]);
int coins2(int arr[],int aim);

int main(){
    int N, aim; cin >> N >> aim;
    int arr[N];
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << coins2(arr, aim)<< endl;
    return 0;
}

int coins2(int arr[],int aim){
    if (arr == NULL || aim < 0){
        return 0;
    }
    int map1[sizeof(arr) + 1][10001];
    return process2(arr, 0, aim, map1);

}

int process2(int arr[], int index, int aim, int map1[][10001]){
    int res = 0;
    if (index == sizeof(arr)){   //当指针指向数组的末尾，
        res = (aim ==0)? 1 : 0;  // 目标值被恰好分完，此时计数1
    }else {
        int mapvalue = 0;
        for(int i = 0; arr[index] * i <= aim; i++) {
            mapvalue = map1[index + 1][aim - arr[index] * i];
            if (mapvalue != 0){
                res += mapvalue == -1 ? 0 : mapvalue;
            } else{
                res += process2(arr, index+1, aim - arr[index] * i, map1);
            }
        }
    }
    map1[index][aim] = res == 0 ? -1 : 0;
    return res;

}

