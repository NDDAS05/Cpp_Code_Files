#include <bits/stdc++.h>
using namespace std;

int solve(int n, const string &str) {
    int zeros = count(str.begin(), str.end(), '0');
    int ones = n - zeros;
    int diff = zeros - ones;

    if (abs(diff) >= 3)
        return -1;

    int zeroRuns = 0, oneRuns = 0;

    for (int i = 0; i < n;) {
        char ch = str[i];

        while (i < n && str[i] == ch)
            i++;

        if (ch == '0')
            zeroRuns++;
        else
            oneRuns++;
    }

    int best = 0;

    if (-1 <= diff && diff <= 1)
        best = max(best, 2 * min(zeroRuns, oneRuns));

    if (0 <= diff && diff <= 2 && zeroRuns)
        best = max(best, 2 * zeroRuns - 1);

    if (-2 <= diff && diff <= 0 && oneRuns)
        best = max(best, 2 * oneRuns - 1);

    return n - best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        string str;
        cin >> n >> str;

        cout << solve(n, str) << '\n';
    }

    return 0;
}