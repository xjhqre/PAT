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

int cmp(int a, int b){
    return a > b;
}

int main() {
    int n, m;
    cin >> n >> m;
    int ls[n] = {0}, sum[n] = {0};
    double g[n] = {0.0};
    for (int i = 0; i < n; i++){
        vector<int> xs;
        cin >> ls[i];
        for (int j = 1; j < n; j++){
            int temp;
            cin >> temp;
            if (temp >= 0 and temp <= m){
                xs.push_back(temp);
            }
        }
        sort(xs.begin(), xs.end());
        xs.pop_back();
        sort(xs.begin(), xs.end(), cmp);
        xs.pop_back();
        for (int v = 0; v < xs.size(); v++){
            sum[i] += xs[v];
        }
        g[i] = round((ls[i] + (sum[i] * 1.0 / xs.size())) / 2);
    }
    for (int i = 0; i < n; i++){
        cout << g[i] << endl;
    }
    system("pause");
    return 0;
}