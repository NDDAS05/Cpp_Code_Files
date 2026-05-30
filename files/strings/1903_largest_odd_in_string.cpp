#include<iostream>
#include<string>
using namespace std;

class solution {
public:
    string largestOddNumber(string num) {
        // Odd is determined ONLY BY THE LAST DIGIT.
        // That means we can scan the string from last and the first index where we will find the odd, we return the entire
        // Substring without that.
        // OR, we can just keep on erasing the even digits from the last. 
        // The first ODD digit we will stop and return result.

        int j = num.size()-1;
        for(;j>=0;j--){
            if(((num.at(j) - '0') & 1) == 1 ) return num;

            num.erase(j,1);

            // 1 2 3 |4| 5 6
            // 1 2 3     5 6
            // Relative pos DID NOT CHANGE FROM START. 
            // arr[2] was 3 also now 3.
        }

        return num;
    }
};


int main(){
    string str = "4";
    solution s;
    cout<<s.largestOddNumber(str)<<endl;
    return 0;
}