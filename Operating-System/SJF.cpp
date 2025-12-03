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
    int n;
    cin >> n;
    cout << "Total Process: " << n << endl;
    deque<pair<int, int>> proc(n);
    map<int, int> mp;
    for(int i=0; i<n; i++) {
        // cout << "\nBurst time of process " << i+1 << ": ";
        cin >> proc[i].first;
        proc[i].second = i+1;
        int x ;
        cin >> x;
        mp[i+1] = x;
    }
    vector<int> ans;
    int tem = 0;
    ans.push_back(proc[0].first);
    int p = proc[0].second;
    cout << "\nProcess " << proc[0].second << " : ";
    cout << "\nWaiting Time: " << tem << endl;
    // cout << "Arrival Time: " << mp[proc[0].second] << endl;
    tem += ans.back();
    int TT = tem - mp[p];
    cout << "Turn Around Time: " << TT << endl;
    // cout << "WT: " << tem - proc[0].first << endl;


    proc.pop_front();
    sort(proc.begin(), proc.end());
    int piche = proc.back().first;
    while(!proc.empty()){
        cout << "\nProcess " << proc.front().second << " : " << endl;
        cout << "Waiting Time: " << tem << endl;
        tem += proc.front().first;
        int tt = tem - mp[proc.front().second];
        cout << "Turn Around Time: " << tt << endl;
        // cout << "WT: " << tem - proc.front().first << endl;
        proc.pop_front();
    }

    int av = tem - piche;
    cout << "\nAverage Waiting Time: " << (double)av/n << endl;
    
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