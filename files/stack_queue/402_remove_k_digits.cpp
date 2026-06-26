// Use string as stack directly. String also supports basic str.pop_back .push_back which are the operations of a stack.
// 

class Solution {
public:
// Logic: Say 527 remove 1.
// What to remove? 7? 2? 5?
// See, 5 removal gives us smallest: because the numbers closer to the beginning are being smaller.

// Again: 18463 remove 2.
// First, 1 can not be removed to make a number starts with >1.
// So, then? removing 8 gives us a number 14...
// Removing 4 gives us 18...
// Definitely 8 removal makes the entire number smaller.

// Now notice: removing a greater number before a smaller number gives us a smaller nmber.
// Because if we have decreasing sequence, that is the greatest. MSB is what making it large... so we can remove msbs from such sequence to make smaller number

// say 1 8 4 6 3
// we scan one by one 1, then 8(>1)
// then comes 4. 4<8, we can remove 8 and keep 4 for a smaller number (basically trying to maintain a increasing seq cuz with given digits that is the smallest possible number)
// Then 6 >4. So far 146
// Then comes 3. Remove 6 (6>3).
// 143 aaand we ran out of characters to do: so ans 143.
// <See, this IS the monotonic stack behaviour... maintaining ascending order WITH a condition that number of pops should be = k>

// There may be case say rem_k = 2, number 1458.
// If the number is already in increasing order, removing from last gives the smaller number. 
// So ans 14
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i = 0; i<num.length(); i++){
            // If empty just push 
            // If not maintain increasing property. With count in check
            while(!s.empty() && ((s.top() - '0') > (num[i]-'0')) && k>0){
                k--;
                s.pop();
            }
            s.push(num[i]);
        }

        while(k--){
            s.pop();
        }

        if(s.empty()) return "0"; // special case to encode 0

        // String is now in reverse order. Fix it.
        string str = "";
        while(!s.empty()){
            str.push_back(s.top());
            s.pop();
        }
        std::reverse(str.begin(), str.end());

        for(int i=0; i<str.size(); i++){
            if(str[i]-'0' > 0) return str.substr(i, str.size()-i);
        }
        return "0";
    }
};


// optimized

string removeKdigits(string num, int k) {
    string st;
    st.reserve(num.size()); // We know the size for sure...

    for(char c : num){
        while(!st.empty() && st.back() > c && k > 0){
            st.pop_back();
            k--;
        }
        st.push_back(c);
    }

    while(k > 0){
        st.pop_back();
        k--;
    }

    //Skip leading zeroes.
    int i = 0;
    while(i < st.size() && st[i] == '0')
        i++;

    st = st.substr(i); // If size not given assumed untill last ------> NOTE

    return st.empty() ? "0" : st; // if string is empty, then "0" otherwise whatever we got
}