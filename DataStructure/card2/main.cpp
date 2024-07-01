//
//  main.cpp
//  2164 카드2
//
//  Created by Sun on 2024/07/01.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);
    
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();

    return 0;
}

// 큐로 구현하는게 가장 간단할거 같았음..(것보다 기본 함수들 그나마 외우고 있는거라)
// 이런 문제는 더 빠르고 깔끔하게 풀기..~
