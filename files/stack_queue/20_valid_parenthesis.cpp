// Idea:
// Maintain a stack of "opening parenthesis"
// As soon as a closing one comes, if it matches the opening one then pop the opening.
// If it does not, return false.


// Edge cases: 1. More OPENING than closing: Stack is Not Empty after scanning the entire string
//             2. More CLOSING than opening: while attempting to pop the parenthesis, stack goes empty.

// So all and all:
// During loop if stack goes empty, next read char MUST BE an opening one.
//  After the loop stack must be empty.

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for(int i=0; i<s.length(); i++){
            // if any kind of opening, push it.
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stk.push(s[i]);
            }

            // For popping , the closing should match the opening one.
            // Loop entered means chaaracter exists. It bypassed first if means it is not opening thus closing. If stack is empty now possible closing>opening case.
            else if(stk.empty()) return false;

            else if((stk.top() == '(' && s[i]==')') || (stk.top() == '{' && s[i]=='}') || (stk.top() == '[' && s[i]==']')){

                stk.pop();

            }
            else{
                // Unmatching type
                return false;
            }
        }

        // after loop if stack is not empty return false else return true
        return stk.empty();
    }
};