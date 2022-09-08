#include <bits/stdc++.h>
using namespace std;
int n, idx;
string s, a[100], head, tail;
int main(void) {
    // freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    // 해당 포인터 주소를 얻는다.
    idx = s.find('*');
    // '*'를 기준으로 head와 tail로 구분한다.
    head = s.substr(0, idx);
    tail = s.substr(idx + 1, s.size());
    // 요소만큼 반복문 실행
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        // 나눈 길이가 요소의 길이보다 크다면 "NE" 출력
        if(head.size() + tail.size() > a[i].size()) {
            cout << "NE" << "\n";
        } else {
            // head와 tail을 나눠서 일치하는지 확인
            if(head == a[i].substr(0, head.size()) && tail == a[i].substr(a[i].size() - tail.size(), a[i].size())) {
                cout << "DA" << "\n";
            } else {
                cout << "NE" << "\n";
            }
        }
    }
}