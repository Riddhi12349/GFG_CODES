//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSets{
  public:
    vector<int> rank , parent, size;
    
    DisjointSets(int v){
        
        rank.resize(v+1,0);
        parent.resize(v+1);
        size.resize(v+1);
        
        for(int i = 0 ; i <= v ; i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUParent(int node){
       
        if(parent[node]==node)
           return node;
           
        return parent[node] = findUParent(parent[node]);
    }
    
    void UnionByRank(int u, int v){
        
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v] +=1;
        }
    }

    
    void UnionBySize(int u , int v){
        
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v];
        }
        else if(size[ulp_v] >= size[ulp_u]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

 class Solution {
    public:
    int numProvinces(vector<vector<int>> adj, int v) {
    //find no of unconnected components
      
      DisjointSets obj(v);
      
      for(int i=0 ; i < v ; i++){
          for(int j = 0 ; j < v; j++){
              if(adj[i][j]==1){
                  obj.UnionBySize(i,j);
              }
          }
      }
      
      int ans = 0 ;
      for(int i = 0 ; i < v ; i++){
          if(obj.parent[i]==i) ans++;
      }
      
      return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends