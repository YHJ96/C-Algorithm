#include <bits/stdc++.h>
using namespace std;
int n;
int a[500004];
map<int, int> _map;
int _max = -987654321, _min = 987654321, mode = 0, sum = 0;
vector <int> v;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        // map에 횟수 등록
        _map[a[i]]++;
        sum += a[i];
    }

    for(auto item: _map) {
        // 최대값, 최소값, 최빈값의 개수 정제
        _max = max(_max, item.first);
        _min = min(_min, item.first);
        mode = max(mode, item.second);
    }

    for(auto item: _map) {
        // 최빈값 추출
        if (mode == item.second) v.push_back(item.first);
    }
    // 오름차순 정렬
    sort(a, a + n);
    sort(v.begin(), v.end());
    // double 형변환
    double avg = (double) sum / (double) n;
    // -0 평균값 예외처리
    if (round(avg) == -0) cout << 0 << "\n";
    else cout << round(avg) << "\n";
    // 중앙값
    cout << a[n / 2] << "\n";
    // 최빈값이 1개 이상 예외처리
    if (v.size() == 1) cout << v[0] << "\n";
    else cout << v[1] << "\n";
    // 범위 출력
    cout << abs(_max - _min);
}