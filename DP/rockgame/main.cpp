//
//  main.cpp
//  9655 돌 게임
//
//  Created by Sun on 2024/10/15.
//

#include <iostream>

using namespace std;

bool d[1000];

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    d[0] = 0;
    d[1] = 1;
    d[2] = 0;
    
    for (int i = 3; i < N; i++) {
        d[i] = !d[i-3];
    }
    
    cout << (d[N-1] ? "CY" : "SK");
    
    return 0;
}

// 너무 경우의 수가 많은거 아닌가..라고 생각했는데 4개 이상부터는 무조건 자기턴에 3개씩 가져간다고 생각하면 됨
// 왜냐면 o o o o 이러케 남았을 때.. 3개를 가져가든 1개를 가져가든 먼저 가져가는 사람은 질 수 밖에 없는 구조
// 어떻게 나눠도 홀수는 홀수, 짝수는 짝수가 되기 때문에 그런거같음

// 게임 과정 횟수의 홀짝에 따라 승패를 결정해주는게 확장성 측면에서 더 좋을거같다.
// d[i] = min(d[i-1] + 1, d[i-3] + 1);
