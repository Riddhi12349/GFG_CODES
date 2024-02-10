//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSets{
  public:
   vector<int> rank , size , parent;
  
    DisjointSets(int v){
      rank.resize(v+1,0);
      size.resize(v+1);
      parent.resize(v+1);
      for(int i = 0 ; i <= v ; i++){
          parent[i] = i;
          size[i]=1;
    }
    }
    
    int findUParent(int node){
       
        if(parent[node] == node)
             return node;
       
       return parent[node] = findUParent(parent[node]);
    }
    
    void UnionByRank(int u , int v){
        
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        
        else if(rank[ulp_u] > ulp_v){
            parent[ulp_v] = ulp_u;
        }
        
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v] += 1;
        }
        
    }
    
    void UnionBySize(int u , int v){
          
          int ulp_u = findUParent(u);
          int ulp_v = findUParent(v);
          
          if(ulp_u == ulp_v) return;
          
          if(size[ulp_u] >= size[ulp_v]){
              parent[ulp_v] = ulp_u;
              size[ulp_u] += size[ulp_v];
          }
          else{
              parent[ulp_u] = ulp_v;
              size[ulp_v] += size[ulp_u];
          }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
     //USING KRUSKAL ALGORITHM
      vector<vector<int>> edges;
      for(int i = 0 ; i < v ; i++){
          for(auto it : adj[i]){
              edges.push_back({it[1],i,it[0]}); //{weight,node,adj}
          }
      }
      
      sort(edges.begin() , edges.end());
      
      DisjointSets obj(v);
      int mst_wt = 0;
      
      for(auto it : edges){
          int wt = it[0];
          int node = it[1];
          int adj = it[2];
          
          if(obj.findUParent(node)==obj.findUParent(adj)){
              continue;
          }
          else{
             mst_wt += wt; 
             obj.UnionBySize(node , adj);
          }
      }
      
      return mst_wt;
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