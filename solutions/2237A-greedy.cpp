#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int mn = a[0];
        int ans = mn;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < mn) mn = a[i];
            ans += mn;
        }

        cout << ans << "\n";
    }
}
