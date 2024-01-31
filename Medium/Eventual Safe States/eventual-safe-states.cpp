//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int src, vector<int> adj[], 
    vector<int>& vis,vector<int>& path_vis,vector<int>& ans){
        
        vis[src]=1; path_vis[src]=1;
        
        for(auto it: adj[src]){
            if(!vis[it]){
               if(dfs(it,adj,vis,path_vis,ans))
                       return true;
            }
            else if(vis[it]==1 && path_vis[it]==1){
                return true;
            }
        }
        
        path_vis[src]=0;
        ans.push_back(src);
        return false;
    }
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vector<int> ans, vis(v,0) , path_vis(v,0);
        
        for(int i=0 ; i<v ; i++){
            if(!vis[i]){
                dfs(i,adj,vis,path_vis,ans);
            }
        }
        sort(ans.begin(),ans.end());
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