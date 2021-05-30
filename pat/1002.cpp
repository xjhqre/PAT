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
    string x, ss[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    cin >> x;
    int sum = 0;
    for (int i = 0; i < x.size(); i++){
        sum += x[i] - '0';
    }
    string sum2 = to_string(sum);
    cout << ss[sum2[0] - '0'];
    for (int i = 1; i < sum2.size(); i++){
        cout << ' ' << ss[sum2[i] - '0'];
    }
    system("pause");
    return 0;
}