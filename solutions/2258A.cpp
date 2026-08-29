#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n; cin >> n;
        vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
 
        cout << gcd(a[0], a[n-1]) << '\n';
    }
}
