#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct tpl{
    int p, bt, prio;
};

void Solve()
{
    int n;
    cin >> n;
    cout << "Total Process: " << n << "\n";
    vector<tpl> proc(n);
    for(int i=0; i<n; i++){
        cin >> proc[i].bt >> proc[i].prio;
        proc[i].p = i+1;
    }

    sort(proc.begin(), proc.end(), [&](auto &a, auto &b){
        return a.prio < b.prio;
    });

    vector<int> tat(n), wt(n);
    int time = 0;
    double avgwt = 0;

    for(int i=0; i<n; i++){
        time += proc[i].bt;
        tat[i] = time;
        wt[i] = tat[i] - proc[i].bt;
        avgwt += wt[i];
    }

    cout << "P BT PRIO TAT    WT\n";
    for(int i=0; i<n; i++){
        cout << proc[i].p << " " << proc[i].bt << "  " << proc[i].prio << "    " 
             << tat[i] << "     " << wt[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << avgwt / n << "\n";
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
