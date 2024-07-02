//
//  main.cpp
//  11650 좌표 정렬하기
//
//  Created by Sun on 2024/07/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> coordlist;
    
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coordlist.push_back(make_pair(x, y));
    }
    sort(coordlist.begin(), coordlist.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });
    
    for (int i = 0; i < N; i++) {
        cout << coordlist[i].first << " " << coordlist[i].second << "\n";
    }
    
    return 0;
}

// 사실 이 문제는 compare 함수 정의 없이 그냥 쓰기만 해도.. 둘 다 오름차순이라 디폴트로 정렬되지만
// 그러며는 이 문제를 푸는 의미가 없으니까 compare 함수 쓰는 연습이나 해보았다.
// 한 번에 통과 햇 ~
