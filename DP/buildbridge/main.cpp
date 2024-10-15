//
//  main.cpp
//  1010 다리 놓기
//
//  Created by Sun on 2024/10/14.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        
        // M combination M-N
        int comb = 1;
        for (int j = 0; j < N; j++) {
            comb *= M-j;
            comb /= j+1;
        }
        cout << comb << '\n';
    }
    
    return 0;
}

// 그냥 확통에서 경우의 수 구했듯이,, M개의 사이트 중에서 M-N개를 빼주면 됨!
// 그럼 나머지 N개에 대한 답(서쪽의 어떤 사이트랑 이어질지)은 자동으로 정해지는 부분 ~
// nCm = n! / (n-m)!m! = n(n-1)(n-2)...(n-m+1)/m(m-1)(m-2)...1
// -> 분자가 n-(n-m)=m개, 분모도 m개로 동일하니까 for문 하나로 처리해주기

// ++ 이 문제를 좀 더 dp스럽게 풀려면.. nCm = n-1Cm-1 + n-1Cm 이라는 점을 이용하자.
