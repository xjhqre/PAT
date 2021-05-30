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
    int n, h, dj = 3;
    char fh;
    cin >> n >> fh;
    if (n >= 1){
        n -= 1;
        h = 1;
    }
    while (n - 2 * dj > 0){
        n = n - 2 * dj;
        h++;
        dj += 2;
    }
    for (int i = h; i > 0; i--){
        for (int v = 0; v <= h - i - 1; v++){
            cout << ' ';
        }
        for (int j = 2 * i - 1; j >= 1; j--){
            cout << fh;
        }
        cout << endl;
    }
    for (int i = 2; i <= h; i++){
        for (int v = h - i - 1; v >=0; v--){
            cout << ' ';
        }
        for (int j = 1 ; j <= 2 * i - 1; j++){
            cout << fh;
        }
        cout << endl;
    }
    cout << n;
    system("pause");
    return 0;
}