#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cctype>
#include <math.h>
using namespace std;

int main() {
    int first, n, k;
    cin >> first >> n >> k;
    int data[100005], last[100005], next[100005];
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    int sum = 0;
    while (first != -1){
        last[sum] = first;
        first = next[first];
        sum++;
    }
    int cnt = 0, last2[100005];
    for (int i = 0; i < sum; i++){
        if (data[last[i]] < 0){
            last2[cnt] = last[i];
            cnt++;
        }
    }
    for (int i = 0; i < sum; i++){
        if (data[last[i]] >= 0 && data[last[i]] <= k){
            last2[cnt] = last[i];
            cnt++;
        }
    }
    for (int i = 0; i < sum; i++){
        if (data[last[i]] > k){
            last2[cnt] = last[i];
            cnt++;
        }
    }
    for (int i = 0; i < sum - 1; i++){
        printf("%05d %d %05d\n", last2[i], data[last2[i]], last2[i + 1]);
    }
    printf("%05d %d -1", last2[sum - 1], data[last2[sum - 1]]);
    system("pause");
    return 0;
}