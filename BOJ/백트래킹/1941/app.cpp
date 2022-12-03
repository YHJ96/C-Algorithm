#include <bits/stdc++.h>
using namespace std;
char a[5][5];
vector<int> v;
vector<vector<int>> ret;
int dy[4] = {1, 0,-1, 0}, dx[4] = {0, 1, 0, -1};

/*
  1. 25명중에 7명을 뽑는다.
  2. 이다솜파 학생이 4명이상 있는지 확인한다.
  3. 7명이 인접해있는지 bfs로 탐색한다.
*/

bool isCheck(vector<int> v) {
    int cnt = 0;
    for(auto item: v) {
        int y = item / 5;
        int x = item % 5;
        if (a[y][x] == 'S') cnt++;
    }
    if (cnt >= 4) return true;
    return false;
}

void combi(int num, vector<int> v) {
    if (v.size() == 7) {
        ret.push_back(v);
        return;
    } else {
        for(int i = num; i < 25; i++) {
            v.push_back(i);
            combi(i + 1, v);
            v.pop_back();
        }
    }
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    combi(0, v);

    for(auto item: ret) {
        int cnt = 0;
        int visited[5][5];
        queue<pair<int, int>> q;
    }
}