//
//  main.cpp
//  2839 설탕 배달
//
//  Created by Sun on 2024/10/15.
//

#include <iostream>

using namespace std;

int d[5001] = {0,};

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    d[3] = 1;
    d[4] = -1;
    d[5] = 1;
    
    for (int i = 6; i < N+1; i++) {
        if (d[i-5]) {
            d[i] = d[i-5] + 1;
        }
        else if (d[i-3]) {
            d[i] = d[i-3] + 1;
        }
        else {
            d[i] = -1;
        }
    }
    cout << d[N];
    
    return 0;
}

// 음 이거는 쉬웠음. greedy로 풀어도 될 듯?!
