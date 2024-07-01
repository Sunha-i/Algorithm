//
//  main.cpp
//  1181 단어 정렬
//
//  Created by Sun on 2024/07/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<string> wordlist;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        wordlist.push_back(word);
    }
    
    sort(wordlist.begin(), wordlist.end(), [](const string& a, const string& b) {
        if (a.size() == b.size())
            return a < b;               // 2. 길이가 같으면 사전 순으로
        return a.size() < b.size();     // 1. 길이가 짧은 것부터
    });
    
    for (int i = 0; i < N; i++) {
        if (i > 0 && wordlist[i] == wordlist[i-1])
            continue;       // 단, 중복된 단어는 하나만 남기고 제거.
        cout << wordlist[i] << endl;
    }
    
    return 0;
}

// 먼가 람다 함수를 쓰고 싶어서 이참에 공부해봤다 (gdngy.tistory.com/184)

// 람다 함수를 정의해서 sort 함수 compare에 넣어주는 방식.
// sort 함수에 넣어주는 compare 함수의 경우 앞 뒤에 있는 두 수 i,j에 대해
// ex) i>j가 참이면 1, 거짓이면 0을 반환해서 참인 경우에만 sort를 실시 -> 내림차순으로 정렬되는 원리
// 중복 단어 제거는 마지막에 해준다.
