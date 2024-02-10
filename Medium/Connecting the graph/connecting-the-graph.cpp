//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSets {
    public:
    vector<int> rank, parent, size; 
    DisjointSets(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUParent(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUParent(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u); 
        int ulp_v = findUParent(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void UnionBySize(int u, int v) {
        int ulp_u = findUParent(u); 
        int ulp_v = findUParent(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
  public:
    int Solve(int v, vector<vector<int>>& edges) {
        
        DisjointSets obj(v);
        int extra_edges = 0;
        
        for(auto it : edges){
            int u = it[0] , v = it[1];
            
            //extra-edge would be when 2 nodes dont have 
            //same ultimate-parents..
            // if they belong to diff components ,
            //they dont have same ultimate parents,and
            // that edge would not be an extra-edge
            if(obj.findUParent(u) == obj.findUParent(v))
               extra_edges++;
               
            obj.UnionBySize(u,v);
        }
        
        int no_of_unconnected = 0;
        for(int i = 0 ; i < v ; i++){
            if(obj.parent[i]==i)
              no_of_unconnected++;
        }
        
        int ans = no_of_unconnected-1;
        
        if(extra_edges >= ans)
           return ans;
           
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends