//
//  main.cpp
//  10816 숫자 카드 2
//
//  Created by Sun on 2024/07/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> um;

int binarysearch(vector<int>& arr, int start, int end, int n) {

    int cnt = 0;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == n) {    // 찾으면? 좌우로 경계를 찾아 몇개인지 알아내기
            int leftmid = mid;
            int rightmid = mid;
            while (leftmid--) {
                if (arr[leftmid] == n)  cnt++;
                else    break;
            }
            while (rightmid++ != arr.size()) {
                if (arr[rightmid] == n)  cnt++;
                else    break;
            }
            um.insert(make_pair(n, cnt+1));
            return cnt+1;
        }
        else if (arr[mid] > n)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return cnt;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    vector<int> cardlist;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cardlist.push_back(num);
    }
    sort(cardlist.begin(), cardlist.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        if (um.find(num) != um.end()) {
            cout << um[num] << " ";
            continue;
        }
        cout << binarysearch(cardlist, 0, N-1, num) << " ";
    }

    return 0;
}

// 시간 제한 1초. 카드 50만개.
// 50만개의 카드에 대해 50만개의 카드 리스트를 하나씩 대조하면서 찾는다면...? O(n^2)
// 500,000 * 500,000 = 250,000,000,000 ...시간초과가 난다. **
// 결론은 탐색시간을 줄여야 한다. 정렬을 통한 이분탐색으로 O(logn)을 만들자

// 단순한 이분탐색으로는 안되고... 아이디어가 필요함 -> 거창한건 아니고 숫자를 찾았을 때 좌우로 더 탐색하면서 경계를 판단해주는거!
// 근데 시간 초과가 떠서 stdio 입출력을 써줬는데 50% 쯤에서 또 시간초과가 남. ...그래서 dp까지 써줘야 했음
// 같은 숫자에 대해 중복해서 물어볼 때, unordered_map(카드버노 - 개수)으로 관리해주기
//
// 다른 풀이법이 궁금해서 검색해보다가 이 용도에 딱 맞는 함수가 있다는걸 알게 되었음..
// 1) STL의 lower_bound(), upper_bound() 함수는 이진탐색으로 원소를 탐색하면서
// 찾고자 하는 값(num)보다 같거나 큰 숫자가 처음 등장하는 위치와, 찾고자 하는 값을 초과하는 값이 가장 처음 나타나는 위치를 반환함.
// 이걸 이용한다면? upper_bound(arr, arr+N, num) - lower_bound(arr, arr+N, num) 이렇게 한줄로 끝난다.

// 근데 또 다른 방법이 있었다 ** 여기서 떠올린 두 번째 방법이 ..
// 그렇다고 모든 숫자 카드에 대해 개수를 저장해둔다면? 카드에 적힌 숫자 종류가 20,000,001.. 이 크기의 배열을 만들어야 한다 ;;
// 전역변수로 선언해서 data 영역에 할당하면? int arr[20000001] -> 80MB.. 정도로 메모리 제한은 안넘으니까 통과하긴 하지만 코드가 구림
//
// 2) 그래서 위와 같은 아이디어를 적용하되 구현상 좋은 방법은 시간복잡도가 O(1)인 HashMap을 이용하는거 𖤐
// 사실 해시맵이 unordered_map임. map과 unordered_map은 둘 다 key-value를 pair로 갖는 형태지만
// map은 자동으로 key를 기준으로 정렬을 해주는 반면 unordered_map은 닉값..그대로 해시테이블을 통해 자료를 넣음
// map이니까 코드는 아주 간단해지고, 시간 복잡도가 O(logN)인 std::map의 find() 함수보다 빠를 것
// unordered_map<int, int> um; 이걸 선언해주고, 카드가 들어올 때마다 um[card]++, 찾고 싶은 카드가 들어오면 cout << um[card].

// 암튼 정석적인 풀이법으로는 아래 두 개가 맞는 문제였고,,
// 적절한 함수나 자료구조를 모르면.. 이러케 돌아가야 한다는 깨달음을 얻었다 ..
