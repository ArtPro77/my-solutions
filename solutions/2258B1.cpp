#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        vector<int> suff(m+2, 0);
        vector<int> freq(m+1, 0);

        int ans = 0;
        vector<int> a(n); for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]] ++;
            ans = max(ans, freq[a[i]]);
        }
        
        for (int i = m; i >= 1; i--) suff[i] = suff[i+1] + freq[i];
        for (int x = 1; x <= m/2; x++) ans = max(ans, suff[x] + freq[2*x]);
        cout << ans << '\n';
    }
}
