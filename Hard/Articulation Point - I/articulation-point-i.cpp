//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int timer= 0;
    
    void dfs(int src, int parent, vector<int>& tin, vector<int>& tlow , vector<int>& vis, 
    vector<int>& mark , vector<int> adj[]){
    
             vis[src]=1; 
             tlow[src] = tin[src] = timer;
             timer++;
             
             int child = 0;
            
             for(auto it : adj[src]){
                 if(it == parent) continue;
                 if(!vis[it]){
                     dfs(it, src, tin, tlow , vis, mark , adj);
                     tlow[src] = min(tlow[src] , tlow[it]);
                     if(tlow[it] >= tin[src] && parent != -1){
                          mark[src] = 1;}
                     child++;
                 }
                 else{
                     tlow[src] = min(tlow[src] , tin[it]);
                 }
             }
             
         if(child > 1 && parent == -1)
                mark[src]=1;
    }
    
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        
        vector<int> vis(v,0) , tin(v,INT_MAX) , tlow(v,INT_MAX) , mark(v,0);
        
        for(int i = 0 ; i < v ; i++){
            if(vis[i]==0)
               dfs(i,-1,tin,tlow,vis,mark,adj);
        }
        
        vector<int> ans;
        for(int i = 0 ; i < v ; i++){
            if(mark[i]==1) ans.push_back(i);
        }
        
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends