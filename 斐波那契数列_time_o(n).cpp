#include <bits/stdc++.h>
// ʱ�临�Ӷ� O(n) �������������ֵ
using namespace std;
int f2(int n){
    if (n < 1) return 0;
    if (n == 1 || n==2) return 1;
    int res = 1;
    int pre = 1;
    int tmp = 0;
    for (int i = 3; i <= n; i++) {
        tmp = res;  // ��ǰһ��ֵ����tmp������
        res = res + pre;
        pre = tmp;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    cout << f2(n);
}
