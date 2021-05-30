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
    cin >> n;
    map<char, char> mapp;
    string wifi;
    mapp['A'] = '1', mapp['B'] = '2', mapp['C'] = '3', mapp['D'] = '4'; 
    for (int i = 0; i < n; i++){
        char temp, flag;
        char ch;
        for (int j = 0; j < 4; j++){
            cin >> temp >> ch >> flag;
            if (flag == 'T'){
                wifi += mapp[temp];
            }
        }
    }
    cout << wifi;
    system("pause");
    return 0;
}