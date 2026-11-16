#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        // A quick guard check: if length is odd, it's impossible to pair up
        if (s.length() % 2 != 0) return false;
        
        std::stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket, check for matching opening bracket
            else {
                // If the stack is empty, we have an unmatched closing bracket
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop(); // Valid match found, remove from stack
                } else {
                    return false; // Mismatched bracket type
                }
            }
        }
        
        // If the stack is empty, all brackets were successfully matched
        return st.empty();
    }
};