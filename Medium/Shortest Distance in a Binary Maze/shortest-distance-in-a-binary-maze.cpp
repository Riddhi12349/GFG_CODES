//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dst) {
                         
         int dx[] = {1,-1,0,0};
         int dy[] = {0,0,1,-1};
         
         int m = grid.size() , n = grid[0].size();
         
         vector<vector<int>> dist(m,vector<int>(n,1e9));
         
        //here, concept of dijkstra can be used, to find shortest distance- from src to dst
        //pq not needed b/c increasing by-fixed const distance=1
        
        queue<vector<int>> q;
        q.push({src.first ,src.second, 0});
        
        while(!q.empty()){
            
            auto it = q.front(); q.pop();
            
            int x = it[0] , y=it[1] , d=it[2];
            
            if(x == dst.first && y == dst.second) return d;
            
            for(int i=0 ;i<4 ; i++){
                int nx = x + dx[i] , ny =  y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0  && ny < n && grid[nx][ny]==1){
                    if(dist[nx][ny] > d + 1){
                        q.push({nx,ny,d+1}); dist[nx][ny] = d+1;
                    }
                }
            }
            
        }
        
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends