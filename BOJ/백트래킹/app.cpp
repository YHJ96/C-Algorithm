#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[12];
int visited[12];
int temp[12];

int permu(int depth) {
  if (depth == m) {
  for(int i = 0; i < m; i++) {
    cout << temp[depth];
  }
    return;
  } else {
    for(int i = 0; i < n; i++) {
      if (visited[i]) continue;
      visited[i] = 1;
      permu(depth + 1);
      visited[i] = 0;
    }
  }
}

int main(void) {
  freopen("./input.txt", "r", stdin);
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  permu(0);
}