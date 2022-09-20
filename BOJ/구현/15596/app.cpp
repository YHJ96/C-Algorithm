#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

/*
백준 정답은 아래 코드
#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for(int i = 0; i < a.size(); i++) ans += a[i];
	return ans;
}
*/

long long sum(vector<int> &a) {
    long long ans = 0;
    // 백터의 요소를 ans에 더함
    for(auto item: a) ans += item;
    return ans;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n) v.push_back(n);
    cout << sum(v);
}