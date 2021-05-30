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

int main() {
    string n, m;
    int cnt[256] = {0};
    getline(cin, n);
    getline(cin, m);
    for (int i = 0; i < n.size(); i++){
        if (cnt[n[i]] == 0){
            cout << n[i];
            cnt[n[i]] = 1;
        }
    }
    for (int i = 0; i < m.size(); i++){
        if (cnt[m[i]] == 0){
            cout << m[i];
            cnt[m[i]] = 1;
        }
    }
    system("pause");
    return 0;
}