#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    // 옷의 종류의 개수를 측정할 자료구조 map 선언
    map<string, int> _map;
    for(auto item: clothes) {
        _map[item[1]]++;
    }
    for(auto item: _map) {
        // 안 입는 조건을 + 1
        answer *= item.second + 1;
    }
    // 공집합 제거
    return answer - 1;
}

int main(void) {
    cout << solution(clothes);
}