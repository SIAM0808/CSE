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
    int n, f;

    cin >> n;

    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cin >> f;

    queue<int> q;
    unordered_set<int> s;

    int hit = 0, fault = 0;

    for (int i = 0; i < n; i++) {

        if (s.find(pages[i]) != s.end()) {

            hit++;
            cout << "Page " << pages[i] << " : Hit\n";
        }
        else {

            fault++;

            if (q.size() == f) {
                int x = q.front();
                q.pop();
                s.erase(x);
            }

            q.push(pages[i]);
            s.insert(pages[i]);

            cout << "Page " << pages[i] << " : Fault\n";
        }
    }

    double hitRatio = (double)hit / n;
    double missRatio = (double)fault / n;

    cout << "\nTotal Pages = " << n << endl;
    cout << "Page Hits = " << hit << endl;
    cout << "Page Faults = " << fault << endl;

    cout << "Hit Ratio = " << hitRatio << endl;
    cout << "Miss Ratio = " << missRatio << endl;
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