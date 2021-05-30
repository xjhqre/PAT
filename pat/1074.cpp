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
    string sys, n, m, sum;
    cin >> sys >> n >> m;
    while (n.size() < sys.size()){
        n.insert(0, "0");
    }
    while (m.size() < sys.size()){
        m.insert(0, "0");
    }
    int temp = 0;
    for (int i = sys.size() - 1; i >= 0; i--){
        int mod = sys[i] == '0' ? 10 : (sys[i] - '0');
        sum += ((n[i] - '0') + (m[i] - '0') + temp) % mod + '0';
        temp = ((n[i] - '0') + (m[i] - '0') + temp) / mod;
    }
    if (temp != 0){
        sum = sum + '1';
    }
    reverse(sum.begin(), sum.end());
    int flag = 0;
    for(int i = 0; i < sum.size(); i++){
        if (sum[i] != '0' || flag == 1) {
            flag = 1;
            cout << sum[i];
            }
        }
    if (flag == 0) cout << 0;
    system("pause");
    return 0;
}