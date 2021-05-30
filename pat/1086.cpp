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
    int n, m;
    cin >> n >> m;
    string s = to_string(n * m);
    reverse(s.begin(), s.end());
    cout << stoi(s);
    system("pause");
    return 0;
}