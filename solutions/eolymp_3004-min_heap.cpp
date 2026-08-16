#include <bits/stdc++.h>
 
using namespace std;

#define ll long long 

int main()
{
    int n, k; cin >> n >> k;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < min(n, k); i++) pq.push(a[i]);

    for (int i = k; i < n; i++) 
    {
        ll earliest = pq.top();
        pq.pop();
        pq.push(earliest + a[i]);
    }

    ll ans = 0;
    while (!pq.empty())
    {
        ans = max(ans, pq.top());
        pq.pop();
    }
    cout << ans << '\n';
}  
