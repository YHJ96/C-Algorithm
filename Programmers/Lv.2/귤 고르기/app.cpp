#include <bits/stdc++.h>
using namespace std;
int k = 6;
vector<int> tangerine { 1, 3, 2, 5, 4, 5, 2, 3 };

/*
  1. k개의 과일을 판매한다.
  2. K개의 과일을 판매하는데 해당 과일의 종류가 최소가 되어야한다.

  풀이 방법
  1. 배열로 과일의 개수를 지정한다.
  2. 내림차순 정렬을 한다.
  3. k의 개수보다 과일의 개수가 큰 경우 answer + 1을 한 뒤 종료
  4. k의 개수보다 과일의 개수가 적은 경우 다음 요소 실행
*/

bool custom(pair<int, int> a, pair<int, int> b) {
    return b.second < a.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int sum = 0;
    map<int, int> _map;
    // 과일의 종류와 개수를 등록한다.
    for(int i = 0; i < tangerine.size(); i++) {
        _map[tangerine[i]]++;
    }
    // 정렬을 위해 벡터로 생성
    vector<pair<int, int>> v(_map.begin(), _map.end());
    // 값의 오름차순으로 정렬
    sort(v.begin(), v.end(), custom);
    for(int i = 0; i < v.size(); i++) {
        // 해당 과일의 총합이 k 보다 크거나 같으면 정지
        if (sum >= k) break;
        // 값을 더해주며 answer +1
        sum += v[i].second;
        answer++;
    }
    return answer;
}

int main(void) {
    cout << solution(k, tangerine);
}