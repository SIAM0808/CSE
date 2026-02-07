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
    int n, tq;
    cin >> n;

    vector<int> at(n), bt(n), rt(n);
    vector<int> ct(n), tat(n), wt(n);

    for (int i = 0; i < n; i++) {
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cin >> tq;

    queue<int> q;
    vector<bool> vis(n, false);

    int time = 0, completed = 0;

    int idx = 0;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int a, int b) {
        return at[a] < at[b];
    });

    int ptr = 0;

    while (completed < n) {

        while (ptr < n && at[order[ptr]] <= time) {
            q.push(order[ptr]);
            vis[order[ptr]] = true;
            ptr++;
        }

        if (q.empty()) {
            time = at[order[ptr]];
            continue;
        }

        int p = q.front();
        q.pop();

        int exec = min(tq, rt[p]);

        rt[p] -= exec;
        time += exec;

        while (ptr < n && at[order[ptr]] <= time) {
            q.push(order[ptr]);
            vis[order[ptr]] = true;
            ptr++;
        }

        if (rt[p] > 0) {
            q.push(p);
        }
        else {
            completed++;
            ct[p] = time;
        }
    }

    double avgWaitingTime = 0, avgTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgWaitingTime += wt[i];
        avgTurnAroundTime += tat[i];
    }

    cout << "PID AT BT CT TAT WT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " "
             << at[i] << " "
             << bt[i] << " "
             << ct[i] << " "
             << tat[i] << " "
             << wt[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << avgWaitingTime / n << endl;
    cout << "Average Turnaround Time = " << avgTurnAroundTime / n << endl;
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