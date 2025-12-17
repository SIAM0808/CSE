#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

void Solve()
{
    ll n, f;
    cin >> n >> f;
    string s;
    cin >> s;

    list<char> l;
    unordered_map<char, list<char>::iterator> mp;

    ll hit = 0, fault = 0;

    for (char c : s)
    {
        if (mp.count(c))
        {
            hit++;
            l.erase(mp[c]); 
            l.push_front(c);
            mp[c] = l.begin();
        }
        else
        {
            fault++;
            if ((ll)l.size() == f)
            {
                char rem = l.back();
                l.pop_back();
                mp.erase(rem);
            }
            l.push_front(c);
            mp[c] = l.begin();
        }
    }

    double hit_ratio = (double)hit / n;
    double miss_ratio = (double)fault / n;

    cout << "Page Faults: " << fault << "\n";
    cout << "Page Hits: " << hit << "\n";
    cout << fixed << setprecision(6);
    cout << "Hit Ratio: " << hit_ratio << "\n";
    cout << "Miss Ratio: " << miss_ratio << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}
