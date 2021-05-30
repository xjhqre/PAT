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

map<string, int> cnt, flag;    //score记录每个学校的分数，cnt记录人数,  flag判断学校名称是否出现过
map<string, double> score;

string lower(string a){
    string b;
    for (int i = 0; i < a.size(); i++)  b += tolower(a[i]);
    return b;
}

struct SchoolInfo
{
    string name;
    int score, cnt;
};

int cmp(SchoolInfo a, SchoolInfo b){
    if (a.score != b.score) return a.score > b.score;
    else if (a.cnt != b.cnt) return a.cnt < b.cnt;
    else return a.name < b.name;
}

int main() {
    int n, temp_fs, c = 0;  //c记录学校个数
    cin >> n;
    string temp_kh, temp_xx, s[n];   //s记录学校的名称
    for (int i = 0; i < n; i++){
        cin >> temp_kh >> temp_fs >> temp_xx;
        temp_xx = lower(temp_xx);
        if (flag[temp_xx] == 0){
            s[c] = temp_xx;
            c++;
            flag[temp_xx] = 1;
        }
        cnt[temp_xx]++;
        if (temp_kh[0] == 'A') score[temp_xx] += temp_fs;
        else if (temp_kh[0] == 'B') score[temp_xx] += temp_fs / 1.5;
        else if (temp_kh[0] == 'T') score[temp_xx] += temp_fs * 1.5;
    }
    SchoolInfo school[c];
    for (int i = 0; i < c; i++){
        school[i].name = s[i];
        school[i].score = (int) score[s[i]];
        school[i].cnt = cnt[s[i]];
    }
    sort(school, school + c, cmp);
    int pre = school[0].score, rank1[c] = {0};
    rank1[0] = 1;
    for (int i = 1; i < c; i++){
        if (school[i].score == pre){
            rank1[i] = rank1[i - 1];
        }
        else {
            pre = school[i].score;
            rank1[i] = i + 1;
        }
    }
    cout << c << endl;
    for (int i = 0; i < c; i++) printf("%d %s %d %d\n", rank1[i], school[i].name.c_str(), school[i].score, school[i].cnt);
    system("pause");
    return 0;
}