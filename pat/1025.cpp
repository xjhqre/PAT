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
    int n, k, first, temp;
    cin >> first >> n >> k;
    int data[100005], last[100005], nextt[100005];
    for (int i = 0; i < n; i++){
        cin >> temp;
        cin >> data[temp] >> nextt[temp];
    }
    int sum = 0;
    while (first != -1){
        last[sum] = first;
        sum++;
        first = nextt[first];
    }
    for (int i = 0; i + k <= sum; i += k){
        reverse(begin(last) + i, begin(last) + i + k);
    }
    for (int i = 0; i < sum - 1; i++){
        printf("%05d %d %05d\n", last[i], data[last[i]], last[i + 1]);
    }
    printf("%05d %d -1", last[sum - 1], data[last[sum - 1]]);
    system("pause");
    return 0;
}