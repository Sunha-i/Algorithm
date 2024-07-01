//
//  main.cpp
//  1920 수 찾기
//
//  Created by Sun on 2024/07/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarysearch(const vector<int>& arr, int key, int start, int end) {

    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (arr[mid] == key) {
            return true;
        }
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    int N, M, num;
    vector<int> A;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        A.push_back(num);
    }
    sort(A.begin(), A.end());
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        printf("%d\n", binarysearch(A, num, 0, N-1));
    }
    
    return 0;
}

// 이 문제는 너무 간단해서.. 시간복잡도가 그나마 고려사항일 수 밖에..
// N=100,000 x M=100,000 이러면 100억...? 정도라서 안댐.
// 탐색 알고리즘 중 binary search의 시간복잡도는 O(logN)
// 이를 위한 stl 정렬 함수 std::sort의 경우 O(NlogN)

// 근데 이분 탐색을 써도 시간초과가 났음. 결론적으로는 다음 두 가지가 원인이었는데 ..
// 1. iostream -> ios_base::sync_with_stdio(0);cin.tie(0); 이걸로 해결하거나 printf/scanf 쓰면 됨!
// 2. binarysearch 함수에 벡터를 전달할 때 참조가 아닌 값(복사)으로 전달해서. (성능 저하)
