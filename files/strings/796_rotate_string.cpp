#include<iostream>
#include<string>

using namespace std;

class solution{
    public:
    bool rotateString(string s, string goal){
        goal = goal + goal; // concatenation
        if(goal.find(s)!=string::npos && 2*s.length() == goal.length()) return true;
        return false;
    }
};

int main(){
    solution s;
    cout<<s.rotateString("bbbacddcebe", "ceebbbbacdd")<<endl;
    return 0;
}