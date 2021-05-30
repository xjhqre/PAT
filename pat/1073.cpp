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

struct ProblemInfo{
    int right;
    int number;
    int score;
    int ans;
};

int main() {
    int n, m;
    cin >> n >> m;
    int anumber[n][m];
    int answer[n][m];
    memset(answer, 0, sizeof(answer));
    memset(anumber, 0, sizeof(anumber));
    ProblemInfo pro[m];
    map<char, int> mapp;
    mapp['a'] = 1, mapp['b'] = 10, mapp['c'] = 100, mapp['d'] = 1000, mapp['e'] = 10000; 
    for (int i = 0; i < m; i++){
        cin >> pro[i].score >> pro[i].number >> pro[i].right;
        for (int j = 0; j < pro[i].right; j++){
            char temp;
            cin >> temp;
            pro[i].ans += mapp[temp];
        }
    }
    char ch1, ch2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> ch1 >> anumber[i][j];
            for (int v = 0; v < anumber[i][j]; v++){
                if (v == anumber[i][j] - 1){
                    char temp;
                    cin >> temp >> ch2;
                    answer[i][j] += mapp[temp];
                }
                else{
                    char temp;
                    cin >> temp;
                    answer[i][j] += mapp[temp];
                }
            }
        }
    }
    string mapp2 = "abcde";
    double sum[n];
    int error[m][5];
    memset(sum, 0.0, sizeof(sum));
    memset(error, 0, sizeof(error));
    //统计各个选择题的错误答案
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            string temp1 = to_string(answer[i][j]);
            string temp2 = to_string(pro[j].ans);
            reverse(temp1.begin(), temp1.end());
            reverse(temp2.begin(), temp2.end());
            while (temp1.size() < 5){
                temp1 += '0';
            }
            while (temp2.size() < 5){
                temp2 += '0';
            }
            for (int v = 0; v < 5; v++){
                if (temp1[v] != temp2[v]){
                    error[j][v]++;
                }
            }
        }
    }
    //计算分数
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            string temp1  = to_string(answer[i][j]);
            string temp2  = to_string(pro[j].ans);
            reverse(temp1.begin(), temp1.end());
            reverse(temp2.begin(), temp2.end());
            while (temp1.size() < 5){
                temp1 += '0';
            }
            while (temp2.size() < 5){
                temp2 += '0';
            }
            if(temp1 == temp2){
                sum[i] += pro[j].score * 1.0;
            }
            else{
                int flag = 1;
                for (int v = 0; v < 5; v++){
                    if (temp2[v] == '0' && temp1[v] == '1'){
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1){
                    sum[i] += pro[j].score * 1.0 / 2;
                }
            }
        }
    }
    //统计错误最多
    int maxn = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < 5; j++){
            if (error[i][j] > maxn){
                maxn = error[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%.1f\n", sum[i]);
    }
    if (maxn == 0){
        cout << "Too simple";
    }
    else{
        for (int i = 0; i < m; i++){
            for (int j = 0; j < 5; j++){
                if (error[i][j] == maxn){
                    cout << maxn << ' ' << i + 1 << '-' << mapp2[j] << endl;
                }
            }
        }
    }
    system("pause");
    return 0;
}