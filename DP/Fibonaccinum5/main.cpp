//
//  main.cpp
//  10870 피보나치 수 5
//
//  Created by Sun on 2024/10/14.
//

#include <iostream>

using namespace std;

int d[20];

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

// 단순하게 n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램
// 점화식은 Fn = Fn-1 + Fn-2 (n >= 2)
