#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> v(3);

    while(t--){
        cin >> v[0] >> v[1] >> v[2];
        std::sort(v.begin(), v.end());

        cout<< std::min(v[2]-v[0], v[1])<<endl;
    }

    return 0;
}