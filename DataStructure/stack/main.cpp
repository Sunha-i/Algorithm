//
//  main.cpp
//  10828 스택
//
//  Created by Sun on 2024/07/02.
//

#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    stack<int> stack;
    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int num;
            cin >> num;
            stack.push(num);
        }
        else if (command == "pop") {
            if (stack.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << stack.top() << "\n";
            stack.pop();
        }
        else if (command == "size") {
            cout << stack.size() << "\n";
        }
        else if (command == "empty") {
            cout << stack.empty() << "\n";
        }
        else if (command == "top") {
            if (stack.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << stack.top() << "\n";
        }
    }
    
    return 0;
}

// 엔터를 기준으로 입력받으려면.. getline을 사용해야 함 (두 가지가 있음)
// 1. <istream> - cin.getline()
// 2. <string> - getline()
// 그리고 cin은 버퍼에 '\n'을 남겨두니까 비워줘야 함 (cin.ignore)

// c++ switch문에서는 일반적인 방법으로 string을 쓸 수 없으니까
// 해시 함수(+constexpr)를 이용해 구현하는 법.. 나중에 공부해야지

// 처음엔 이렇게 getline(cin, command);으로 받아서
// if (command.substr(0,4) == "push") {
//     stack.push(command.substr(5));
// }
// 일케 했는데 굳이..였음
