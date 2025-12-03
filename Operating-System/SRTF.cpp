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
    deque<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    map<int, int> mp;
    map<int, int> arrival;
    map<int, int> waiting;
    map<int, int> turnaround;
    
    mp[0] = 0;
    v.front().first--;
    for(auto it : v) pq.push(it);
    
    int time = 0;
    for(int i=0; i<n; i++){
        arrival[i] = 0;
    }
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.first == 0) continue;
        
        time++;
        mp[it.second] = time;
        it.first--;
        
        if(it.first > 0){
            pq.push(it);
        }
    }
    
    
    cout << "Process ID | Burst Time | Completion Time | Waiting Time | Turnaround Time\n";
    cout << "--------------------------------------------------------------------\n";
    
    int totalWaiting = 0;
    int totalTurnaround = 0;
    
    for(int i=0; i<n; i++){
        int burstTime = v[i].first;
        int completionTime = mp[i];
        waiting[i] = completionTime - burstTime - arrival[i];
        turnaround[i] = completionTime - arrival[i];
        
        cout << "P" << i << "         | " << burstTime << "         | " << completionTime 
             << "              | " << waiting[i] << "           | " << turnaround[i] << "\n";
        
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }
    
    cout << "--------------------------------------------------------------------\n";
    cout << "Average Waiting Time: " << (double)totalWaiting/n << "\n";
    cout << "Average Turnaround Time: " << (double)totalTurnaround/n << "\n";
}


int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    while (t--)
        Solve();
    return 0;
}
