#include <bits/stdc++.h>
using namespace std;
vector<int> numbers = {1, 1, 1, 1, 1};
int target = 3;
// 타켓넘버의 개수를 세는 함수 생성 완료
int dfs(int n, int t, vector<int> numbers, int target) {
    int ret = 0;
    if (n == numbers.size()) {
        // 해당 넘버가 타켓 넘버면 1의 값 아니면 0의 값을 출력
        if (t == target) return 1;
        return 0;
    }
    // 이진 트리 탐색 시작
    ret += dfs(n + 1, t + numbers[n], numbers, target);
    ret += dfs(n + 1, t - numbers[n], numbers, target);
    return ret;
}

int solution(vector<int> numbers, int target) {
    return dfs(0, 0, numbers, target);
}

int main(void) {
    cout << solution(numbers, target);
}