//
//  main.cpp
//  10845 큐
//
//  Created by Sun on 2024/07/02.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    queue<int> q;
    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (command == "pop") {
            if (q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }
        else if (command == "size") {
            cout << q.size() << "\n";
        }
        else if (command == "empty") {
            cout << q.empty() << "\n";
        }
        else if (command == "front") {
            if (q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
        }
        else if (command == "back") {
            if (q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << q.back() << "\n";
        }
    }
    
    return 0;
}

// 스택이랑 top <-> front/back만 다르고 samesame...
// 재밌는 문제였다..~
