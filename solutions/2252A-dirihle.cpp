#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        int mx = 0;
        int el = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]] ++;

            if (cnt[a[i]] > mx)
            {
                mx = cnt[a[i]];
                el = a[i];
            }
        }
        
        if (n >= 2*mx - 1) cout << accumulate(a.begin(), a.end(), 0) << "\n";
        else
        {
            int ans = 0;
            int cnt_el = 0;
            for (int x: a)
            {
                if (x != el) 
                {
                    ans += x;
                    cnt_el ++;
                }
                
            }
            ans += el*(cnt_el+2);

            cout << ans << "\n";
        }
    }
}
