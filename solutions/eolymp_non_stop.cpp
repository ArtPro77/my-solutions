#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i] - (i + 1)] ++;
    }

    long long ans = 0;
    for (auto& [key, value]: mp)
    {
        ans += value*(value-1)/2;
    }
    cout << ans << "\n";
}
