//
//  main.cpp
//  1463 1로 만들기
//
//  Created by Sun on 2024/10/16.
//

#include <iostream>

using namespace std;

int d[1000001];

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    d[0] = 1;
    d[1] = 0;
    
    for (int i = 2; i <= N; i++) {
        d[i] = d[i-1] + 1;
        if (i % 3 == 0) {
            d[i] = min(d[i], d[i/3] + 1);
        }
        if (i % 2 == 0) {
            d[i] = min(d[i], d[i/2] + 1);
        }
    }
    cout << d[N];
    
    return 0;
}

// d[n]을 "n에서 1을 만드는 데에 연산을 사용하는 횟수의 최솟값"으로 정의해보겠음..
// 1초에 1억번이면 0.15초에는 15,000,000번! 요기는 N이 최대 10^6이라 그냥 bottom-up으로 해도 됨.
//
// 참고로 top-down 방식(재귀)은 아래와 같은데 재귀 호출 스택 때문에 이게 더 오래걸린다
// int recursive(int N)
// {
//     if (N == 1)     return 0;
//     if (d[N] > 0)   return d[N];
//
//     d[N] = recursive(N-1) + 1;
//
//     if (N % 3 == 0) {
//         d[N] = min(d[N], recursive(N/3) + 1);
//     }
//     if (N % 2 == 0) {
//         d[N] = min(d[N], recursive(N/2) + 1);
//     }
//     return d[N];
// }
