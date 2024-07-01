//
//  main.cpp
//  2751 수 정렬하기 2
//
//  Created by Sun on 2024/07/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());   // 기본이 오름차순, 내림차순 하려면 [](){ return a > b; }
    
    for (int i = 0; i < N; i++) {
        cout << v[i] << "\n";
    }
    
    return 0;
}

// 이것도 너무 간단해서 시간복잡도가 문제일거임.
// 일반적인 stl sorting 함수는.. O(nlogn)이라 그랬음.
// 그러며는.. N=100만이니까 걍 그거써도 되지 않을까...생각함

// 그치만 시간초과를 받았음. 2초에 n=100만, O(2n+nlogn)인데 ......왜지 싶었지만
// 다른 방법을 떠올려보기 전에 기본적인 것부터 의심해서.. 아래거 추가로 해결 ~~
// ios_base::sync_with_stdio(false); -> stdio-iostream 동기화 비활성화 -> 독립 버퍼 생성
// cin.tie(0); -> cin을 cout으로부터 untie.. -> stream async -> flush 호출 줄임
// 이것만 해서는 안되고 endl(개행 + 버퍼flush) 대신 "\n"으로 바꿔줘야 함. 아님 그냥 stdio 입출력 쓰던가 ~
