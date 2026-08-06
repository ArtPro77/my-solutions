#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n; cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        if (accumulate(a.begin(), a.end(), 0) % 4 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
