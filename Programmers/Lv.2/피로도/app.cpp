#include <bits/stdc++.h>
using namespace std;

/*
  1. 최소 피로도와 소모 피로도가 존재한다.
  2. 최대한 많은 던전의 수를 출력한다.
  3. 던전을 탐험하는 순열을 생성한다.
*/

int k = 80; 
vector<vector<int>> dungeons = {{80,20}, {50,40}, {30,10}};
int visited[8];
int temp[8];
vector<vector<int>> ret;

// n개의 순열을 뽑는 함수 생성
void permu(int depth, vector<vector<int>> dungeons) {
    if (depth == dungeons.size()) {
        vector<int> v;
        for(int i = 0; i < dungeons.size(); i++) v.push_back(temp[i]);
        ret.push_back(v);
        return;
    } else {
        // 백트래킹 시작
        for(int i = 0; i < dungeons.size(); i++) {
            if (visited[i]) continue;
            visited[i] = 1;
            temp[depth] = i;
            permu(depth + 1, dungeons);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    permu(0, dungeons);
    for(int i = 0; i < ret.size(); i++) {
        int cnt = 0;
        int score = k;
        for(auto idx: ret[i]) {
            int start = dungeons[idx][0];
            int minus = dungeons[idx][1];
            // 최소 필요도 예외처리
            if (score < start) break;
            cnt++;
            score -= minus;
        }
        // 최대값 정제
        answer = max(answer, cnt);
    }
    return answer;
}

int main(void) {
    cout << solution(k, dungeons);
}