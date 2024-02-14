//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSets{
   public:
    vector<int> parent , size;
    DisjointSets(int v){
        parent.resize(v+1);
        size.resize(v+1);
        for(int i = 0  ; i <= v ; i++){
            parent[i] = i;
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
        
        if(ulp_u == ulp_v)
             return;
             
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

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
       
       int mxrow = 0 , mxcol = 0;
       for(int i = 0 ; i < n ; i++){
           mxrow = max(mxrow , stones[i][0]);
           mxcol = max(mxcol , stones[i][1]);
       }
       
       DisjointSets ds(mxrow+mxcol+1);
       unordered_map <int,int> mp;
       int cnt=0;
       
       for(int i = 0 ; i < n ; i++){
           
           int row = stones[i][0] ;
           int col = mxrow+1+stones[i][1];
           ds.unionBySize(row , col);
           cnt++; mp[row]++; mp[col]++;
           
         //this is wrong to store at that moment
         //since ulp are changing dynamically
         /*  int ulp1 = ds.findUParent(row);
           int ulp2 = ds.findUParent(col);
           mp[ulp1]++; mp[ulp2]++;
           cnt++;*/
       }
       
       int comp = 0;
       for(auto it : mp){
           if(ds.parent[it.first]==it.first)
             comp++;
       }
       
       int ans = cnt - comp;
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends