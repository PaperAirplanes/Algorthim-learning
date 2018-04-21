// 换钱的方法数 <暴力递归> <复杂度0(aim^N)>
#include <bits/stdc++.h>
using namespace std;
int process1(int arr[], int index, int aim);
int coins1(int arr[],int aim);

int main(){
    int N, aim; cin >> N >> aim;
    int arr[N];
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << coins1(arr, aim)<< endl;
    return 0;
}

int coins1(int arr[],int aim){
    if (arr == NULL || aim < 0){
        return 0;
    }
    return process1(arr, 0, aim);
}

int process1(int arr[], int index, int aim){
    int res = 0;
    if (index == sizeof(arr)){   //当指针指向数组的末尾，
        res = (aim ==0)? 1 : 0;  // 目标值被恰好分完，此时计数1
    }else {
        for(int i = 0; arr[index] * i <= aim; i++) {
            res += process1(arr, index+1, aim - arr[index] * i);
        }
    }
    return res;

}

