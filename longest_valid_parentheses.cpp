// Longest Valid Parentheses
// Approach: stack of indices. Time O(n), Space O(n).

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    st.push(-1);  // base index before the start of a valid substring
    int maxLen = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);  // unmatched ')' becomes the new base
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}

int main() {
    string tests[] = {"(()", ")()())", ""};
    for (const string& s : tests) {
        cout << "Input: \"" << s << "\"  Output: "
             << longestValidParentheses(s) << endl;
    }
    return 0;
}
