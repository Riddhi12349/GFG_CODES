//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
/*
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
    }
};
*/
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto it: edges){
            graph[it[0]].push_back({it[1],it[2]});
            //graph[it[1]].push_back({it[0],it[2]});
        }
        set<pair<int,int>>s1;
        s1.insert({0,0});
        vector<int>vis(n+1,0);
        vector<int>res(n, -1);
        while(!s1.empty()){
            auto it = *s1.begin();
            s1.erase(s1.find(it));
            if(vis[it.second] == 1){
                continue;
            }
            vis[it.second]=1;
            res[it.second] = it.first;
            for(auto it1: graph[it.second]){
                if(!vis[it1.first]){
                    s1.insert({it.first + it1.second, it1.first});
                }
            }
        }
        return res;
        // code here
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