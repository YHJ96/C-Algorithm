#include <bits/stdc++.h>
using namespace std;
int n;
int temp[6];

// vector에서 6개를 뽑아 조합하는 함수 생성
void combi(int idx, int depth, vector<int> v) {
    if (depth == 6) {
        for(int i = 0; i < 6; i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    } else {
        for(int i = idx; i < v.size(); i++) {
            // 현재 i값을 temp에 저장
            temp[depth] = v[i];
            // 다음 combi 함수 실행
            combi(i + 1, depth + 1, v);
        }
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n) {
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int k;
            cin >> k;
            v.push_back(k);
        }
        combi(0, 0, v);
        cout << '\n';
    }
}