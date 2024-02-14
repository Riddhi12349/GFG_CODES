//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSets{
    public:
    vector<int> size , parent;
    
    DisjointSets(int v){
     
        size.resize(v+1);
        parent.resize(v+1);
        for(int i = 0 ; i <= v ; i++){
            parent[i]= i;
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
        
        if(ulp_u == ulp_v) return ;
        
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
    bool isvalid(int adj_r,int adj_c,int m,int n){
        if(adj_r < n && adj_c < n && adj_r >= 0 && adj_c >= 0)
           return true;
        return false;
    }
    
    int largestIsland(vector<vector<int>>& grid){
          
          //step-1
          //(will connect all the 1s and form separate components with different ultimate parents)
          
          int n = grid.size();
          DisjointSets ds(n*n);
          
          int dx[] = {-1,0,+1,0};
          int dy[] = {0,-1,0,+1};
          
          for(int i = 0 ; i < n ; i++){
              for(int j = 0 ; j < n ; j++){
                  if(grid[i][j]==0) continue;
                  
                  int node = i*n+j;
                  for(int k=0 ; k < 4 ; k++){
                     
                      int adj_r = i+dx[k];
                      int adj_c = j+dy[k];
                      if(isvalid(adj_r, adj_c , n , n) && ( grid[adj_r][adj_c]==1)){
                          
                          int adj_node = adj_r*n + adj_c;
                          ds.unionBySize(adj_node, node);
                      }
                  }
                  
              }
          }
          
          // step-2
          //(finding components and their maximum size possible on changing a cell from 0 to 1)
          
          int mx = 0;
          
          for(int i = 0 ; i < n ; i++){
              for(int j = 0 ; j < n ; j++){
                 
                 if(grid[i][j]==1) continue;
                 
                 unordered_map <int,int> mp;
                 
                 for(int k = 0 ; k < 4 ; k++){
                     
                     int adj_r = i + dx[k];
                     int adj_c = j + dy[k];
                     
                     if(isvalid(adj_r , adj_c , n , n) &&  (grid[adj_r][adj_c]==1)){
                         int ulp = ds.findUParent(adj_r*n+adj_c);
                         mp[ulp]++;
                     }
                 }
                 
                 int tot_size = 1;
                 for(auto x : mp){
                     tot_size += ds.size[x.first];
                 }
                 mx = max(mx, tot_size);
              }
          }
          
          //edge-case
          // if all are 1 
          for(int cellno = 0 ; cellno < n*n ; cellno++){
              mx = max(mx , ds.size[ds.findUParent(cellno)]);
          }
          
          return mx;
    } 
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends