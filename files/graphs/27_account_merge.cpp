#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(x ==  parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;

        if(size[x] < size[y]) swap(x,y);
        size[x]+=size[y];
        parent[y] = x;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // we need to map the accounts to some integers.
        int n = accounts.size();
        DSU d(n);
        unordered_map<string, int> ump;

        for(int user = 0; user<n; user++){ 
            for(int i=1; i<accounts[user].size(); i++){
                string email = accounts[user][i];
                if(ump.find(email) == ump.end()){
                    //set up
                    ump[email] = user;
                }
                else{
                    d.Union(user, ump[email]); // user2 and user1 same if email is common.
                    // Union of USERS; not EMAILS.
                    // IF u1, a,b and u2 a, d : when we encounter u2's a, we unite U1 and U2.
                    // d has ump[d] = u2. But since u2 is pointing to u1 now so u1 IS u2.

                    // That is why for every pair in ump, we find the parent of email's index and do not use index directly while creating final array.
                }
            }
        }

        // Now we collect the emails based on parent index.
        vector<vector<string>> collection(n, vector<string>{});
        for(auto itr: ump){
            int mainUser = d.find(itr.second); // returns user corresponding to itr.first mail.
            collection[mainUser].push_back(itr.first);
        }

        // Now reconstruct.
        // How? We need user and associated emails.
        // We can get the "associated emails" from collection array we just made.
        // How to get user name? Remember parent idx was same as the first time they appeared in accounts. So accounts[i][0] IS the user name.

        vector<vector<string>> ans;
        for(int i=0; i<n; i++){ // Over collection
            if(collection[i].empty()) continue;
            vector<string> userMails;
            userMails.push_back(accounts[i][0]); // user name;
            // Now we need to sort the collection[i] and then push the mails in userMails.
            std::sort(collection[i].begin(), collection[i].end());
            for(string s: collection[i]){
                userMails.push_back(s);
            }
            ans.push_back(userMails);
        }

        return ans;
    }
};
