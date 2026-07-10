#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long omega;
    if (!(cin >> n >> omega)) return 0;

    vector<pair<long long, int>> holes(n);
    for (int i = 0; i < n; i++) {
        cin >> holes[i].first;
        holes[i].second = i + 1;
    }
    sort(holes.begin(), holes.end());

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (omega > holes[i].first) {
            omega += holes[i].first;
            ans.push_back(holes[i].second);
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
