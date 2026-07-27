// Not the best implementation but idea should be same.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // creating set from existing wordlist for quick lookup @ ~ O(1)
        unordered_map<string, int> ump;
        for(auto str: wordList){
            ump[str] =0;
        }

        // endWord does not exist.
        if(ump.find(endWord) == ump.end()) return 0;

        int lvlCount = 1; // for beginWord

        // length starts from 1 (@ beginWord)
        // Idea: pop a word from queue (length ++) // end word is also counted
        // push "1 word different" words than the popped one into the queue
        // Keep on doing untill queue is empty. Or if the popped word is found while inserting.
        
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            // level wise traversal needed as we are counting how deep we are going to return final answer. we need to know when level counter will increase.
            int currSize = q.size();
            for(int i=0; i<currSize; i++){
                string s = q.front();
                q.pop();
                if(s == endWord) return lvlCount;
                
                // now generate 1 letter different words
                for(int j=0; j<s.size(); j++){
                    char c = s[j];
                    for(char k='a'; k<='z'; k++) {// looping over alphabets
                        s[j] = k;
                        if(ump.find(s) == ump.end() || ump[s] == 1) continue; // if does not exist or included already, do not bother
                        else{
                            if(s == endWord) return lvlCount+1;
                            else{
                                q.push(s);
                                ump[s]=1;
                            }
                        }
                    }
                    s[j]=c;
                }
            }
            lvlCount++;
        }

        return 0;
    }
};