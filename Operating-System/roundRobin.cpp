#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct tpl {
    int p, bt;
};

void Solve()
{
    int n, q;
    cin >> n >> q;
    cout << "Total Process: " << n << "\n";
    vector<tpl> proc(n);
    int pid, bt;
    for(int i=0; i<n; i++){
        cin >> pid >> bt;
        proc[i].p = pid; 
        proc[i].bt = bt; 
    }

    vector<int> rem(n), tat(n), wt(n);
    for(int i=0; i<n; i++) rem[i] = proc[i].bt;

    int time = 0;
    bool done = false;

    while(!done){
        done = true;
        for(int i=0; i<n; i++){
            if(rem[i] > 0){
                done = false;
                if(rem[i] > q){
                    time += q;
                    rem[i] -= q;
                } else {
                    time += rem[i];
                    tat[i] = time;
                    rem[i] = 0;
                }
            }
        }
    }

    double avgwt = 0;
    for(int i=0; i<n; i++){
        wt[i] = tat[i] - proc[i].bt;
        avgwt += wt[i];
    }

    cout << "P | BT | TAT  | WT\n";
    for(int i=0; i<n; i++){
        cout << proc[i].p << " | " << proc[i].bt << " | " << tat[i] << "    | " << wt[i] << "\n";
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
