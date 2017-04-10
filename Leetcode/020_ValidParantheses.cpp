#include <stack>
#include <string>
#include <map>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(stk.empty()) {
                    return false;
                }
                else {
                    if(stk.top() != m[s[i]]) {
                        return false;
                    }
                    stk.pop();
                }
            }
        }
        if(!stk.empty()) {
            return false;
        }
        return true;
    }
};