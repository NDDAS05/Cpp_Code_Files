#include<iostream>
using namespace std;

class solution{
    public:
    string validParenthesis(string& s){
        // Keeping a count variable.
        // Employing a voting like algorithm.
        // For every opening parenthesis +1
        // For every closing one -1;
        // When 0->1 transition happens, that is start of an component.
        // When 1-> transition happens, that is end of a component.
        int prev_val = 0;
        int current_val=0;
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ')'){
                current_val = prev_val - 1;
            }
            else current_val = prev_val +1;
            
            // Removing for 0->1 or 1->0 transition;
            if((current_val==1 && prev_val==0)||(current_val==0 && prev_val==1)) {
                s.erase(i,1);
                i--;
            }
            prev_val = current_val;
        }

        return s;
    }
};

int main(){
    string s = "(()())(())";
    solution sol;
    cout<<sol.validParenthesis(s)<<endl;
    return 0;
}