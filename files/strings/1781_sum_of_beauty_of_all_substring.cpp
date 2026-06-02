#include<iostream>
#include<string>
#include<climits>


/*

Logic: We generate all substrings.
       HOW?

       We fix i.
       We expand using j.
       Make a new freq[] map for EVERY j (i.e. every substring)

       Now for EACH substring:
        -> Iterate over the freq[] map.
        -> Ignore 0-s. We have not encountered them yet.
        -> Find the maxFreq. 
        -> Find minfreq.
        -> totalBeauty += (max-min)

For this problem constraint is 1-500 array length. Brute force ia necessary.
 */
using namespace std;

class solution {
public:
    int frequency(int (&arr)[26],bool isMax){

    }
    int beautySum(string s) {
        int totalBeauty=0, maxfreq, minfreq;
        for(int i=0; i<s.length(); i++){
            int freq[26]={0};

            for(int j=i;j<s.length();j++){

                freq[s[j] - 'a']++;

                maxfreq=INT_MIN;
                minfreq=INT_MAX;

                for(int k: freq){

                    if(k==0)  continue;
                    maxfreq=max(maxfreq, k);
                    minfreq =min(minfreq, k);

                }
                totalBeauty +=(maxfreq-minfreq);
            }
        }

        return totalBeauty;
    }
};

int main(){
    solution s;
    cout<<s.beautySum("aabcbaa");
    return 0;
}