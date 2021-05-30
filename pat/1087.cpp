#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cstdio>
#include <string>
#include <string.h>
#include <cctype>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int n;
    set<int> s;
    cin >> n;
    for (int i = 1; i <= n; i++){
        s.insert(floor(i*1.0/2) + floor(i*1.0/3) + floor(i*1.0/5));
    }
    cout << s.size();
    system("pause");
    return 0;
}