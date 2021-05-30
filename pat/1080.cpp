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

struct StuInfo{
    string xh;
    int fs1, fs2, fs3;
    double zf;
};

int cmp(StuInfo a, StuInfo b){
    return a.zf != b.zf ? a.zf > b.zf : a.xh < b.xh;
}

map<string, int> fs1, fs2, fs3, c, c1, c2;
map<string, double> zf;

int main() {
    int p, m, n;
    cin >> p >> m >> n;
    string xh, stu[10005];
    int fs, cnt = 0;
    for (int i = 0; i < p; i++){
        cin >> xh >> fs;
        if (c[xh] == 0){
            stu[cnt] = xh;
            c[xh] = 1;
            cnt++;
        }
        fs1[xh] = fs;
    }
    for (int i = 0; i < m; i++){
        cin >> xh >> fs;
        if (c[xh] == 0){
            stu[cnt] = xh;
            c[xh] = 1;
            cnt++;
        }
        fs2[xh] = fs;
        c1[xh] = 1;
    }
    for (int i = 0; i < n; i++){
        cin >> xh >> fs;
        if (c[xh] == 0){
            stu[cnt] = xh;
            c[xh] = 1;
            cnt++;
        }
        fs3[xh] = fs;
        c2[xh] = 1;
    }
    for (int i = 0; i < 10005; i++){
        if (fs2[stu[i]] > fs3[stu[i]]){
            zf[stu[i]] = round(fs2[stu[i]] * 0.4 + fs3[stu[i]] * 0.6);
        }
        else{
            zf[stu[i]] = fs3[stu[i]];
        }
    }
    StuInfo stuinfo[10005];
    for (int i = 0; i < 10005; i++){
        if (c1[stu[i]] == 0) fs2[stu[i]] = -1;
        if (c2[stu[i]] == 0) fs3[stu[i]] = -1;
    }
    for (int i = 0; i < 10005; i++){
        stuinfo[i].xh = stu[i];
        stuinfo[i].fs1 = fs1[stu[i]];
        stuinfo[i].fs2 = fs2[stu[i]];
        stuinfo[i].fs3 = fs3[stu[i]];
        stuinfo[i].zf = zf[stu[i]];
    }
    sort(stuinfo, stuinfo + 10005, cmp);
    for (int i = 0; i < 10005; i++){
        if (stuinfo[i].fs1 >= 200 && stuinfo[i].zf >= 60){
            printf("%s %d %d %d %.0f\n", stuinfo[i].xh.c_str(), stuinfo[i].fs1,
            stuinfo[i].fs2, stuinfo[i].fs3, stuinfo[i].zf);
        }
    }
    system("pause");
    return 0;
}