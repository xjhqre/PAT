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
    int n, win = 0, lose = 0, ss[3] = {0}, sss[3] = {0};
    cin >> n;
    string j[n], y[n];
    for (int i = 0; i < n; i++){
        cin >> j[i] >> y[i];
    }
    for (int i = 0; i < n; i++){
        if (j[i] == "C" && y[i] == "J"){
            win++;
            ss[1]++;
        }
        else if (j[i] == "C" && y[i] == "B"){
            lose++;
            sss[0]++;
        }
        else if (j[i] == "J" && y[i] == "C"){
            lose++;
            sss[1]++;
        }
        else if (j[i] == "J" && y[i] == "B"){
            win++;
            ss[2]++;
        }
        else if (j[i] == "B" && y[i] == "J"){
            lose++;
            sss[2]++;
        }
        else if (j[i] == "B" && y[i] == "C"){
            win++;
            ss[0]++;
        }
    }
    printf("%d %d %d\n", win, n - win - lose, lose);
    printf("%d %d %d\n", lose, n - win - lose, win);
    string x = "BCJ";
    int max1 = 0, max2 = 0;
    for (int i = 0; i < 3; i++){
        if (ss[i] > ss[max1]){
            max1 = i;
        }
        if (sss[i] > sss[max2]){
            max2 = i;
        }
    }
    cout << x[max1] << ' ' << x[max2];
    system("pause");
    return 0;
}