//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int src, vector<vector<int>>& adj , stack<int>& st, vector<int>& vis){
        
        vis[src]=1;
        
        for(auto x : adj[src]){
            if(!vis[x]){
                dfs(x , adj , st , vis);
            }
        }
        
        st.push(src);
    }
    
    void dfs2(int src , vector<int> adj2[] , vector<int>& vis){
        
        vis[src] = 1;
        
        for(auto it : adj2[src]){
            if(!vis[it])
              dfs2(it , adj2 , vis);
        }
    }
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        // step-1 
        // sort all nodes on basis of finishing time
        // nodes that will be at the last of scc(s) will be present atthe bottom of the stack
        
        stack<int> st; vector<int> vis(v,0);
        
        for(int i =0 ; i < v; i++){
            if(!vis[i])
             dfs(i , adj , st , vis);
        } 
        
        //step-2
        //reversal of the edges of the graph
        //so,that we cannot move out of the scc
        
        vector<int> adj2[v];
        for(int i = 0 ; i < adj.size() ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                adj2[adj[i][j]].push_back(i);
            }
        }
        
        //step-3 (dfs---- to find all the nodes present in a scc)
         vis = vector<int>(v,0);
         int cnt = 0;
         
         while(!st.empty()){
          
          int node = st.top();  
          st.pop();
          if(!vis[node]){
              cnt++;
              dfs2(node , adj2 , vis);
          }
         }
         
         return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends