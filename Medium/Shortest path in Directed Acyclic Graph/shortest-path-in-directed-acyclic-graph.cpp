//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int src, vector<int>& vis , vector<pair<int,int>> adj[] , stack<int>& st){
         
         vis[src] = 1;
         
         for(auto it : adj[src]){
             if(!vis[it.first]){
                 dfs(it.first , vis, adj , st);
             }
         }
         st.push(src);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
           
      
           vector<pair<int,int>> adj[n];
           
           // 1.create adj list--
           for(int i = 0 ; i < m ; i++){
               adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
           }
           
           vector<int> vis(n,0); stack<int> st;
        //   for(int i = 0 ; i < n ; i++){
        //       if(!vis[i]){ 
               dfs(0,vis,adj,st);
        //       }
        //   }
        
           
           vector<int> dist(n,INT_MAX);
           dist[0] = 0;
           
           while(!st.empty()){
               int f = st.top(); st.pop(); 
               for(auto it : adj[f]){
                   dist[it.first] = min(dist[it.first] , dist[f] + it.second);
               }
           }
           
           for(int i = 0; i < n ; i++){
               if(dist[i] == INT_MAX) dist[i] = -1;
           }
           
           return dist;
        }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends