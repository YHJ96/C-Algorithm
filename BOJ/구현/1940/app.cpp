#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
int ret = 0;
int head = 0;
int tail;

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int item;
        cin >> item;
        v.push_back(item);
    }
    // tail의 지점을 벡터의 맨 끝점 - 1로 초기화
    tail = v.size() - 1;
    // 오름차순 정렬
    sort(v.begin(), v.end());
    // 요소 순회 시작
    for(int i = 0; i < n; i++) {
        // head가 tail보다 크거나 같으면 포인터 초과로 break 처리
        if (head >= tail) break;
        // 합 초기화
        int sum = v[head] + v[tail];
        // 합이 m 보다 크면 head 증가 m 보다 작으면 tail 감소 같으면 각각 증가 감소를 진행한 뒤 ret + 1
        if (sum < m) head++;
        if (sum > m) tail--;
        if (sum == m) {
            head++;
            tail--;
            ret++;
        } 
    }
    cout << ret;
}