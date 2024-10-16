//
//  main.cpp
//  2579 계단 오르기
//
//  Created by Sun on 2024/10/16.
//

#include <iostream>

using namespace std;

int d[2][301] = {0,};

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        int score;
        cin >> score;
        
        if (i == 1) {
            d[0][i] = score;
            d[1][i] = score;
            continue;
        }
        
        d[0][i] = d[1][i-1] + score;
        d[1][i] = max(d[0][i-2], d[1][i-2]) + score;
    }
    
    cout << max(d[0][N], d[1][N]);
    
    return 0;
}

// d[n]을 "n번째 계단까지 얻을 수 있는 총 점수의 최대값"으로 정의하겠음
// 그렇다면 n번째 계단에 도달하는 방법은 크게 (n-1번째 계단을 통해 or n-2번째 계단을 통해..) 일케 두 가지로 나눌 수 있음
// 근데 이전 계단까지를 어떻게 온건지 모르니까. 그냥 1차원 배열로 하면 연속된 세 개의 계단이 될 수도 있다는거..
// 그래서 이차원 배열로 만들어주고 [0]에는 바로 전에서 온 경우, [1]에는 두 개 전에서 온 경우를 저장해줬다.
// 그럼 이제 식을 세울 수 있게 됨..~

// 1차원 배열로는 어케푸나 궁금해서 찾아봄
// d[i] = max(d[i-2], score[i-1] + d[i-3]) + score[i];
// 이게 더 직관적인 듯
