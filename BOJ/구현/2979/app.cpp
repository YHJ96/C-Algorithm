#include <bits/stdc++.h>
using namespace std;
int price[3];
int times[100];
int ret = 0;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 3; i++) cin >> price[i];
    for(int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        // 트럭의 도착시간과 떠나는 시간의 사이를 +1 증가
        for(int j = start; j < end; j++) times[j]++;
    }
    for(int i = 0; i < 100; i++) {
        // 시간별 트럭이 남아 있는 개수로 가격 증가
        if(times[i] == 1) ret += price[0];
        if(times[i] == 2) ret += (price[1] * 2);
        if(times[i] == 3) ret += (price[2] * 3);
    }
    cout << ret;
}