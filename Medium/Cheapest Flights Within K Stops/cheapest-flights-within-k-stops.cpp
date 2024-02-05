//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        
           int n1 = flights.size();
          vector<vector<int>> adj[n];
          
          for(int i=0 ; i<n1 ; i++){
              adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
          }
          
          vector<int> cost(n+1,1e9);
          queue<vector<int>> q; //{stops,node,dist}
          q.push({0,src,0});
          cost[src]=0;
          
          while(!q.empty()){
              
              auto f = q.front();
              q.pop();
              int stop = f[0], node = f[1], dist = f[2];
              
              if(stop > k) continue;
              
              for(auto it : adj[node]){
                  
                  int adj_node = it[0], edw = it[1];
                  if(cost[adj_node] > edw+dist && stop <= k){
                      cost[adj_node] = edw+dist;
                      q.push({stop+1,adj_node,edw+dist});
                  }
                  
              }
              
          }
          
          return ((cost[dst]==1e9)?-1:cost[dst]);
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends