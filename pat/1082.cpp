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

struct PalyerInfo
{
    int id;
    double fs;
    /* data */
};

int cmp(PalyerInfo a, PalyerInfo b){
    return a.fs > b.fs;
}

int main() {
    int n, x, y;
    cin >> n;
    PalyerInfo player[n];
    for (int i = 0; i < n; i++){
        cin >> player[i].id >> x >> y;
        player[i].fs = sqrt(x * x * 1.0 + y * y * 1.0);
    }
    sort(player, player + n, cmp);
    printf("%04d %04d", player[n - 1].id, player[0].id);
    system("pause");
    return 0;
}