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

    queue<char> q;
    unordered_set<char> st;

    ll hit = 0, fault = 0;

    for (char c : s)
    {
        if (st.count(c))
        {
            hit++;
        }
        else
        {
            fault++;
            if ((ll)q.size() == f)
            {
                char rem = q.front();
                q.pop();
                st.erase(rem); 
            }
            q.push(c);
            st.insert(c);
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
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
