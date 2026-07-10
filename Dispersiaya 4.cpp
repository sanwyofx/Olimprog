#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int t; 
    if (cin >> t) {
        while (t--) {
            int n; 
            cin >> n;
            
            vector<long long> a(n);
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            
            map<long long, int> cnt;
            int l = 0, mx = 0;
            
            for (int r = 0; r < n; r++) {
                cnt[a[r]]++; 
                
                while (cnt[a[r]] > 1) {
                    cnt[a[l]]--;
                    l++;
                }
                
                mx = max(mx, r - l + 1); 
            }
            
            cout << mx << "\n";
        }
    }
    
    return 0;
}
