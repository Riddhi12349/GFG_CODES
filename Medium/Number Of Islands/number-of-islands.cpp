//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSets{
  public:
  vector<int> parent , size;
  DisjointSets(int v){
      parent.resize(v+1);
      size.resize(v+1);
      for(int i = 0;  i <= v ; i++){
          parent[i]=i;
          size[i]=1;
      }
  }
  
  int findUParent(int node){
      if(parent[node]==node)
         return node;
      
      return parent[node] = findUParent(parent[node]);
  }
  
  void unionBySize(int u , int v){
      
      int ulp_u = findUParent(u);
      int ulp_v = findUParent(v);
      
      if(ulp_u == ulp_v) return;
      
      if(size[ulp_u] >= size[ulp_v]){
          parent[ulp_v] = ulp_u;
          size[ulp_u] += size[ulp_v];
      }
      else{
          parent[ulp_u] = ulp_v;
          size[ulp_v]+=size[ulp_u];
      }
  }
};

class Solution {
  public:
  
    bool isvalid(int x,int y , int m,int n){
      if(x>=0 && x<m && y >= 0 && y < n)
        return true;
     return false;
  }
  
    vector<int> numOfIslands(int rows, int cols, vector<vector<int>> &operators) {
        
        DisjointSets ds(rows*cols);
        
        vector<int> ans;
        int vis[rows][cols];
        memset(vis, 0 , sizeof(vis));
        
        int dx[] = {-1,+1,0,0};
        int dy[] = {0,0,-1,+1};
        
        int cnt=0;
        
        for(auto it : operators){
            int u =  it[0] , v = it[1];
            if(vis[u][v]==1){
                ans.push_back(cnt); continue;
            }
            cnt++;
            vis[u][v]=1;
            int node = u*cols+v;
            
            for(int i=0 ; i < 4; i++){
             
                int new_u  = u+dx[i] , new_v = v+dy[i];
                
                if(isvalid(new_u , new_v , rows, cols) 
                && (vis[new_u][new_v]==1)){
               
                    int adj_node = new_u*cols + new_v;
                    if(ds.findUParent(node) != ds.findUParent(adj_node)){
                      cnt--;
                      ds.unionBySize(node , adj_node);
                     }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends