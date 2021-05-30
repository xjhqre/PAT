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
    int n;
    string s;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++){
        getline(cin, s);
        int f1 = 0, f2 = 0, f3 = 0;
        if (s.size() < 6) {
            cout << "Your password is tai duan le." << endl;
            continue;
        }
        else{
            for (int j = 0; j < s.size(); j++){
                if (!isalnum(s[j]) && s[j] != '.') f1 = 1;
                else if (isdigit(s[j])) f2 = 1;
                else if (isalpha(s[j])) f3 = 1;
            }
            if (f1 == 1) cout << "Your password is tai luan le." << endl;
            else if (f3 == 0) cout << "Your password needs zi mu." << endl;
            else if (f2 == 0) cout << "Your password needs shu zi." << endl;
            else cout << "Your password is wan mei." << endl;
        }
    }
    system("pause");
    return 0;
}