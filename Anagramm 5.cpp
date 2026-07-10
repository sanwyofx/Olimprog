#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int MOD = 1e9 + 7;
    string s;
    cin >> s;
    int n = s.length();

    vector<long long> f(n+1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i-1] * i) % MOD;
    }

    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;

    long long ans = f[n];
    for (int i = 0; i < 26; i++) {
        if (count[i] > 1) {
            long long a = f[count[i]], p = MOD - 2;
            while (p > 0) {
                if (p % 2 == 1) ans = (ans * a) % MOD;
                a = (a * a) % MOD;
                p /= 2;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
