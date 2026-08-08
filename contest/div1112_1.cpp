#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        unordered_map<long long, int> freq;
        long long total = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
            freq[a[i]]++;
        }

        long long value = 0;
        int max_freq = 0;
        for (auto &p : freq) {
            if (p.second > max_freq) {
                max_freq = p.second;
                value = p.first;
            }
        }

        long long wasteCount = max(0, 2 * max_freq - n - 2);
        long long ans = total - value * wasteCount;

        cout << ans << "\n";
    }
    return 0;
}