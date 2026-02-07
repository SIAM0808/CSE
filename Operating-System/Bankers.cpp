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
    int numProcesses, numResources; 
    cout << "Enter number of processes: "; 
    cin >> numProcesses; 
 
    cout << "Enter number of resources: "; 
    cin >> numResources; 
 
    vector<vector<int>> allocation(numProcesses, vector<int>(numResources)); 
    vector<vector<int>> maxDemand(numProcesses, vector<int>(numResources)); 
    vector<int> available(numResources); 
 
    cout << "\nEnter Allocation Matrix :\n"; 
    for (int i = 0; i < numProcesses; i++) { 
        for (int j = 0; j < numResources; j++) { 
            cin >> allocation[i][j]; 
        } 
    } 
 
    cout << "\nEnter Maximum Demand Matrix :\n"; 
    for (int i = 0; i < numProcesses; i++) { 
        for (int j = 0; j < numResources; j++) { 
            cin >> maxDemand[i][j]; 
        } 
    } 
 
    cout << "\nEnter Available Resources : "; 
    for (int j = 0; j < numResources; j++) { 
        cin >> available[j]; 
    } 
    vector<vector<int>> need(numProcesses, vector<int>(numResources)); 
    for (int i = 0; i < numProcesses; i++) { 
        for (int j = 0; j < numResources; j++) { 
            need[i][j] = maxDemand[i][j] - allocation[i][j]; 
        } 
    } 
 
    vector<int> finished(numProcesses, 0);  
    vector<int> safeSequence; 
 
    for (int k = 0; k < numProcesses; k++) { 
        for (int i = 0; i < numProcesses; i++) { 
            if (finished[i] == 0) { 
                bool canExecute = true; 
                for (int j = 0; j < numResources; j++) { 
                    if (need[i][j] > available[j]) { 
                        canExecute = false; 
                        break; 
                    } 
                } 
                if (canExecute) { 
                    safeSequence.push_back(i); 
                    for (int j = 0; j < numResources; j++) { 
                        available[j] += allocation[i][j]; 
                    } 
                    finished[i] = 1; 
                } 
            } 
        } 
    } 
    if(safeSequence.size()<numProcesses){ 
        cout<<"There exists a deadloack"; 
        return 0; 
    } 
 
    cout << "\nThe SAFE Sequence is:\n"; 
    for (int i = 0; i < numProcesses; i++) { 
        cout << "P" << safeSequence[i]+1; 
        if (i != numProcesses - 1) 
            cout << " -> "; 
    } 
    cout << endl; 
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