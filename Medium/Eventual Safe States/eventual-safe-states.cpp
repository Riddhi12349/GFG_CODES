//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        
        vector<int> ans;
        //for using topo-sort and detecting cycle-nodes, we will reverse the edges
        
        vector<int> adj1[v]; vector<int> indeg(v,0);
        
        for(int i=0 ; i < v ; i++){
            for(auto it : adj[i]){
                adj1[it].push_back(i);
            }
        }
        
        for(int i = 0 ; i < v ; i++){
            for(auto it : adj1[i])
                indeg[it]++;
        }
        
        queue<int> q;
        
        for(int i = 0 ; i < v ; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        //vector<int> ans;
        
        while(!q.empty()){
            int f = q.front(); q.pop();
            ans.push_back(f);
            for(auto it : adj1[f]) {
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        
        sort(ans.begin() , ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends