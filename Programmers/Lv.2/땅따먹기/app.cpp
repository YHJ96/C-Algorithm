#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> land = {{1,2,3,5},{5,6,7,8},{4,3,2,1}};

int solution(vector<vector<int> > land) {
    int answer = -987654321;
    // 동적 계획법 실행
    for(int i = 1; i < land.size(); i++) {
        // 다음 칸수는 전에 칸수를 입력하지 못함으로 제일 큰 수를 적립하면서 내려오기
        land[i][0] += max({ land[i-1][1], land[i-1][2], land[i-1][3] });
        land[i][1] += max({ land[i-1][0], land[i-1][2], land[i-1][3] });
        land[i][2] += max({ land[i-1][0], land[i-1][1], land[i-1][3] });
        land[i][3] += max({ land[i-1][0], land[i-1][1], land[i-1][2] });
    }
    // 최대값 출력
    for(int i = 0; i < 4; i++) {
        answer = max(answer, land[land.size() - 1][i]);
    }

    return answer;
}

int main(void) {
    cout << solution(land);
}