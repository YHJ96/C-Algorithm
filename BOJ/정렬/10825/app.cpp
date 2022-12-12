#include <bits/stdc++.h>
using namespace std;
int n;
struct person {
    string name;
    int kor, eng, math;
};

vector<person> v(100004);

// 커스텀 함수 생성
bool custom(person a, person b) {
    bool equalKor = a.kor == b.kor;
    bool equalEng = a.eng == b.eng;
    bool equalMath = a.math == b.math;
    // 국어 영어 수학이 같은 경우
    if (equalKor && equalEng && equalMath) return a.name < b.name;
    // 국어 영어가 같은 경우
    if (equalKor && equalEng) return a.math > b.math;
    // 국어가 같은 경우
    if (equalKor) return a.eng < b.eng;
    // 국어 영어 수학이 다른 경우
    return a.kor > b.kor;
}

int main(void) {
    freopen("./input.txt", "r", stdin);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
    }
    // 정렬 시작
    sort(v.begin(), v.end(), custom);
    for(int i = 0; i < n; i++) {
        cout << v[i].name << "\n";
    }
}