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
    string fh, x, s;
    cin >> fh;
    getchar();
    getline(cin, x);
    int cnt = 0;
    if (fh == "C"){
        for (int i = 0; i < x.size() - 1; i++){
            while (x[i] == x[i + 1]){
                cnt++;
                i++;
            }
            if (cnt > 0){
                s = s + to_string(cnt + 1) + x[i];
                cnt = 0;
            }
            else{
                s += x[i];
            }
        }
        if (x[x.size() - 1] != x[x.size() - 2]){
            s += x[x.size() - 1];
        }
    }
    if (fh == "D"){
        int g = 0;
        for (int i = 0; i < x.size(); i++){
            if (isdigit(x[i])){
                while (isdigit(x[i])){
                    g = g * 10 + (x[i] - '0');
                    i++;
                }
                for (int j = 0; j < g; j++){
                    s += x[i];
                }
                g = 0;
            }
            else {
                s += x[i];
            }
        }
    }
    cout << s;
    system("pause");
    return 0;
}