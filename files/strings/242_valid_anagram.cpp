#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    bool validAnagram(string s, string t){
        sort(s.begin(), s.end());
        cout<<s<<endl;
        sort(t.begin(), t.end());
        cout<<t<<endl;

        if(s==t) return true;
        return false;
    }

    // This implementation reduces 2 nlogn sorting. Array access is very very fast.
    // Also 5*10^4 is very large compared to 256.
    bool validAnagramBetter(string s, string t){
        // Without adjusting for UNICODE characters....
        if(s.length() != t.length()) return false;

        array<int, 256> hashmap={0}; // hashmap[character] = frequency

        for(size_t i=0; i<s.length(); i++){
            hashmap[s[i]]++;
            hashmap[t[i]]--;
        }

        for(auto i: hashmap){
            if(i!=0) return false;
        }
        
        return true;
    }
};

int main(){
    solution s;
    cout<<s.validAnagramBetter("carpet", "petbar")<<endl;
    return 0;
}