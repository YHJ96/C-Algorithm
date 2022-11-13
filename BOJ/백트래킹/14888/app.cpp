#include <bits/stdc++.h>
using namespace std;
int n;
int a[15];
char operation[4] = {'+', '-', '*', '/'};
vector<char> v1;
vector<int> v2;
vector<vector<int>> ret;
int visited[15];
int _max = -987654321, _min = 987654321;

// 사칙연산 결과값 함수 생성 완료
int go(char operation, int a, int b) {
    if (operation == '+') return a + b;
    if (operation == '-') return a - b;
    if (operation == '*') return a * b;
    if (operation == '/') return a / b;
}

// 순열 함수 생성 완료
void permu(vector<int> v2) {
    // 벡터의 크기가 총 연산기호의 개수와 같다면 정지
    if (v2.size() == v1.size()) {
        // 해당 순열의 값 push
        ret.push_back(v2);
        return;
    }
    // 백트래킹 시작
    for(int i = 0; i < v1.size(); i++) {
        // 방문 예외처리
        if (visited[i]) continue;
        // 방문처리
        visited[i] = 1;
        // 해당 값 v2에 push
        v2.push_back(i);
        // 다음 좌표 진행
        permu(v2);
        // 방문 해제
        visited[i] = 0;
        // 해당 값 v2에서 pop
        v2.pop_back();
    }
} 

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 사칙연산의 개수만큼 반복문 실행
    for(int i = 0; i < 4; i++) {
        int cnt;
        cin >> cnt;
        // 해당 연산자의 개수만큼 v1에 push
        for(int j = 0; j < cnt; j++) {
            v1.push_back(operation[i]);
        }
    }
    // 순열 생성
    permu(v2);
    // ret의 순열의 개수 만큼 반복 시작
    for(auto list: ret) {
        // 초기값 설정
        int sum = go(v1[list[0]], a[0], a[1]);
        for(int i = 1; i < list.size(); i++) {
            // 연산 시작
            sum = go(v1[list[i]], sum, a[i+1]);
        }
        // 최대값, 최소값 정제
        _min = min(_min, sum);
        _max = max(_max, sum);
    }
    cout << _max << "\n";
    cout << _min;
}