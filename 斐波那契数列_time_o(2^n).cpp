#include <bits/stdc++.h>
using namespace std;
int f1(int n){
    if(n < 1) return 0;
    if(n == 1 || n == 2) return 1;
    return f1(n-1)+f1(n-2);
}
int main(){
    int n;
    cin >> n;
    cout << f1(n);
}
