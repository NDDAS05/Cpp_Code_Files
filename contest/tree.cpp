#include <bits/stdc++.h>
using namespace std;

int solve(int a, const vector<vector<int>>& vec1, const vector<bool>& arr2, vector<int>& ans) {
    vector<int> tempArr;
    
    for (int b : vec1[a]) {
        if (solve(b, vec1, arr2, ans) == 1) {
            tempArr.push_back(b); 
        }
    }
    if (arr2[a]) {
        for (int b : tempArr) {
            ans.push_back(b);
        }
        return 1; 
    } else {
        if (tempArr.size() > 0) {
            for (int i = 0; i < (int)tempArr.size() - 1; i++) {
                ans.push_back(tempArr[i]);
            }
            return 1; 
        } else {
            return 0; 
        }
    }
}

void run() {
    int num1;
    cin >> num1;
    
    vector<vector<int>> vec1(num1 + 1);
    for (int i = 2; i <= num1; i++) {
        int x;
        cin >> x;
        vec1[x].push_back(i);
    }
    
    int num2;
    cin >> num2;
    
    vector<bool> arr2(num1 + 1, false);
    for (int i = 0; i < num2; i++) {
        int y;
        cin >> y;
        arr2[y] = true;
    }
    vector<int> ans;
    solve(1, vec1, arr2, ans);

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        run();
    }
    
    return 0;
}