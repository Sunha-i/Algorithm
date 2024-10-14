//
//  main.cpp
//  2748 피보나치 수 2
//
//  Created by Sun on 2024/10/14.
//

#include <iostream>

using namespace std;

long long d[90];

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    d[0] = 0;
    d[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        d[i] = d[i-1] + d[i-2];
    }
    cout << d[n];
    
    return 0;
}

// 이번에도 마찬가지로 n이 주어졌을 때, n번째 피보나치 수를 구해야 하는데..
// 10870번 문제랑 차이점은.. 최대 n이 20에서 90으로 늘어났다는거?
// 근데 이전 문제를 그냥 메모이제이션을 활용하는 방식으로 풀어서 그대로 사용해도 된다고 생각했는데 틀렸음.
// 시간 초과도 아니고 틀렸다는거 보면 오버플로우가 원인인거 같다고 생각했고,, long long으로 수정해서 통과 ~
// 참고로 long long은 8byte다.
