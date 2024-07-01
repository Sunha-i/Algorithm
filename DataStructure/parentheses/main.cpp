//
//  main.cpp
//  9012 괄호
//
//  Created by Sun on 2024/07/01.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string isVPS(const string& ps) {
    stack<char> s;
    for (int i = 0; i < ps.length(); i++) {
        if (ps[i] == '(') {
            s.push('(');
        }
        else if (ps[i] == ')') {
            if (s.empty()) {
                return "NO\n";
            }
            s.pop();
        }
    }
    if (s.empty())
        return "YES\n";
    else
        return "NO\n";
}

int main(int argc, const char * argv[]) {

    int T;
    cin >> T;

    while (T--) {
        string ps;
        cin >> ps;
//        cout << isVPS(ps);
        
        int left = 0;
        int right = 0;

        bool isvalid = true;
        for (int i = 0; i < ps.length(); i++) {
            if (left == 0 && right == 0) {      // valid 상태에서
                if (ps[i] == ')') {             // 이게 먼저 들어오면 ..
                    isvalid = false;            // valid 하지 않음!
                    break;
                }
            }
            if (ps[i] == '(')       left++;
            else if (ps[i] == ')')  right++;
            if (left == right) {
                left = 0;
                right = 0;
            }
        }
        if (!isvalid)             cout << "NO\n";
        else if (left == right)   cout << "YES\n";
        else                      cout << "NO\n";
    }

    return 0;
}

// ())(()
// 눈으로 보기엔 알겠는데 패턴을 정의하기가.. 어렵다는 생각보단 쉬움 ㅎㅜ
// 코드가 깔끔하지 않다고 생각했는데 한번에 통과했음 ~~

// 근데 다른 풀이가 궁금해서 찾아봤더니 스택을 활용하는 문제였음
// ( 이거면 스택에 넣고, ) 이건데 스택이 비어있으면 invalid <-> 아니면 pop()
// 이건 isVPS 함수로 구현해줬다.
