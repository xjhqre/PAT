#include <algorithm>
#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <string.h>
#include <cctype>
#include <math.h>
#include <vector>
using namespace std;

int cmp(int a, int b){
    return a > b;
}

int bj[10000], ss[10000], ss2[10000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> ss[i];
        ss2[i] = ss[i];
    }
    for (int i = 0; i < n; i++){
        while (ss[i] != 1){
            if (ss[i] % 2 == 0){
                ss[i] /= 2;
                bj[ss[i]] = 1;
            }
            else{
                ss[i] = (ss[i] * 3 + 1) / 2;
                bj[ss[i]] = 1;
            }
        }
    }
    sort(ss2, ss2 + n, cmp);
    int flag = 0;
    for (int i = 0; i < n; i++){
        if (bj[ss2[i]] == 0){
            if (flag == 0){
                cout << ss2[i];
                flag = 1;
            }
            else{
                cout << ' ' << ss2[i];
            }
        }
    }
    system("pause");
    return 0;
}