#include<bits/stdc++.h>
using namespace std;

vector<int> getmax(string str1, string str2) {
    vector<int> result(2, 0);
    int max0 = 0;
    int end0 = 0;
    int row = 0;
    int col = str2.size() - 1;
    int len = 0;
    while(row < str1.size()){
        int i = row;
        int j = col;
        while(i < str1.size() && j < str2.size()){
            if(str1[i] != str2[j]){
                len = 0;
            } else {
                len++;
            }
            if (len > max0) {
                end0 = i;
                max0 = len;
            }
            i++;
            j++;
        }
        if (col > 0) {
            col--;
        } else {
            row++;
        }
    }
    result[0] = max0;
    result[1] = end0;
    return result;
}

int main(){
    string str1, str2, str3;
    str1 = "1AB2345CD";
    str2 = "12345EF";
//    cin >> str1 >> str2;
    vector<int> result = getmax(str1, str2);
    cout << result[0] << result[1] << endl;
    str3 = str1.substr(result[1] - result[0] + 1, result[0]);
    cout << str3;
    return 0;
}
