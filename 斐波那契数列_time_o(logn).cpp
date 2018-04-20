#include<bits/stdc++.h>
using namespace std;
struct matrix{
    int m[2][2];
};
matrix base = {1, 1, 1, 0};

matrix mulimatrix(matrix m1, matrix m2) {
    matrix tmp;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++){
            tmp.m[i][j] = 0;  //³õÊ¼»¯
            for(int k = 0; k < 2; k++) {
                tmp.m[i][j] += m1.m[i][k] * m2.m[k][j];
            }
        }
    }
    return tmp;
}

int matrixPower(matrix a, int p){
    matrix res;
    res.m[0][0] = res.m[1][1] = 1;
    res.m[0][1] = res.m[1][0] = 0;
    for(; p!=0; p>>=1) {
        if((p&1) != 0) {
            res = mulimatrix(res, a);
        }
        a = mulimatrix(a, a);
    }
    return res.m[0][0] + res.m[1][0];
}
int main(){
    int n;
    while (cin >> n) {
        cout<< matrixPower(base, n-2) <<endl;
    }
    return 0;
}
