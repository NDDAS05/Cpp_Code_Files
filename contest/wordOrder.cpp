#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, m, n;
    cin>>t;

    while(t--){
        cin>>n>>m;
        unordered_set<char>ust;

        string s, s2;
        while(n--){
            cin>>s;
            ust.insert(s[0]-32);
        }
        bool flag = true;

        while(m--){
            cin>>s2;
            for(char ch: s2){
                if(ust.count(ch) == 0){
                    flag= false;
                    break;
                }
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

    return 0;
}