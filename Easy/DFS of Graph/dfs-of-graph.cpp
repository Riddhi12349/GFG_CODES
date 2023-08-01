//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int n , int s , vector<int> adj[] , vector<int>& ans , vector<int>& vis){
        
        vis[s] = 1;
        ans.push_back(s);
        
        for(auto neighbor : adj[s]){
            if(!vis[neighbor])
            dfs(n , neighbor , adj , ans , vis);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans , vis(V,0);
        dfs(V , 0 , adj , ans , vis);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends