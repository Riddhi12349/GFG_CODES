//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    using t = vector<int>;
    int spanningTree(int v, vector<vector<int>> adj[])
    {
      
       vector<int> vis(v,0);
       priority_queue<t,vector<t>,greater<t>> min_pq;
       int sum = 0;
       
       min_pq.push({0,0,-1});// {WT,NODE,PARENT}
       
       while(!min_pq.empty()){
           
           auto it = min_pq.top();
           min_pq.pop();
       
           int wt = it[0] , node = it[1] , parent = it[2];
           
           if(vis[node]==1) continue;
           vis[node] = 1; sum += wt;
           
           for(auto itr : adj[node]){
               int adj_node = itr[0] , edw = itr[1];
               if(!vis[adj_node]){
                   min_pq.push({edw,adj_node,node});
               }
           }
       }
       
       return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends