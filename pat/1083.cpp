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

int cnt[10005];

int main() {
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        cnt[abs(temp - i - 1)]++;
    }
    for (int i = 10004; i >= 0; i--){
        if (cnt[i] >= 2){
            printf("%d %d\n", i, cnt[i]);
        }
    }
    system("pause");
    return 0;
}