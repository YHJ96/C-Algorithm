#include <bits/stdc++.h>
using namespace std;
vector<int> v = {1,2,3,3,3,4};
int _max = 0;
int ret = 0;
int cnt = 0;

int solution(vector<int> array) {
    map<int, int> _map;
    // 자료구조 map을 이용해서 숫자와 숫자의 개수 등록
    for(auto item: array) _map[item]++;
    // 최대값 추출
    for(auto item: _map) _max = max(_max, item.second);
    for(auto item: _map) {
        // 최빈값의 숫자 저장
        if (item.second == _max) {
            ret = item.first;
            cnt++;
        }
    }
    // 최빈값이 2개 이상 예외처리
    if (cnt > 1) return -1;
    return ret;
}

int main(void) {
    cout << solution(v);
}