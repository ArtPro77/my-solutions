#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t; cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n; cin >> n;
        string s; cin >> s;
 
        string groups;
        vector<int> len;
        
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            groups.push_back(s[i]);
            len.push_back(j-i);
            i = j;
        }
 
        bool single = false;
        bool two = false;
 
        int g = groups.size();
 
        for (int i = 1; i + 1 < g; i++)
        {
            if (len[i] == 1)
            {
                single = true;
                break;
            }
        }
 
        for (int i = 1; i + 1 < g; i++)
        {
            if (groups[i - 1] == groups[i + 1] && len[i] == 1)
            {
                two = true;
                break;
            }
        }
        
        if (two) cout << g - 2 << endl;
        else if (single) cout << g - 1 << endl;
        else cout << g << endl;
    }
}
