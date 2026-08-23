#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m;
    cin>>t;

    while(t--){
        cin>>n>>m;
        int bea1, dummy;
        cin>>bea1;
        int beaCycle = n;
        beaCycle--;
        while(beaCycle--){
            cin>>dummy;
        }

        int ver1;
        cin>>ver1;
        beaCycle = m-1;
        while(beaCycle--){
            cin>>dummy;
        }

        if(bea1+n-1 >=ver1+m-1){
            cout<<"1\n";
        } else cout<<"2\n";
    }

    return 0;
}