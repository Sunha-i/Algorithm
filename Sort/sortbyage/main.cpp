//
//  main.cpp
//  10814 나이순 정렬
//
//  Created by Sun on 2024/07/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<pair<int, string>> v;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
    stable_sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b){
        return a.first < b.first;
    });
    
    for (int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    
    return 0;
}

// pair을 담은 vector에 대해 sort, compare 함수 사용

// 입력 시 인덱스를 같이 저장하는 방법..? 밖에 생각이 안났는데
// 같은 값에 대해 원래의 순서를 유지하는 std::stable_sort라는게 있다고 함.
// 사실 디폴트가 오름차순이고 pair 중 앞에거가 기준이라 stable_sort를 사용할 경우
// comapre 함수를 굳이 작성하지 않아도 되지만.. 연습 겸 ~

// 그리고 귀찮지만.. 인덱스를 이용하는 방법도 알아야 함. stable_sort를 모른다면..?
// 구조체나 <pair<pair<int,int>,string>> 이런형태를 이용해 입력순서를 같이 저장하고
// 람다 함수 [](){ if (age가 같음) return a.idx < b.idx; return a.age < b.age; }를 이러케 정의해주기 ~
