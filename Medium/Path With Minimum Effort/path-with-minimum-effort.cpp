//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     using t = vector<int>;
    int MinimumEffort(vector<vector<int>>& hts) {
        // Code here
        int m = hts.size() , n = hts[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        
        priority_queue<t,vector<t>,greater<t>> min_pq;
        min_pq.push({0,0,0}); //{effort,x,y}
        
        int dx[] = {-1,+1,0,0};
        int dy[] = {0,0,1,-1};
        
        while(!min_pq.empty()){
            t v1 = min_pq.top(); min_pq.pop();
            int effort  = v1[0], x = v1[1] , y = v1[2];
            
            if(x==m-1 && y==n-1) return effort;
            
            for(int i=0 ;i<4 ; i++){
                int nx = x + dx[i] , ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n ){
                     int eff = max(effort , abs(hts[nx][ny]-hts[x][y]));
                     if(dist[nx][ny] > eff){
                         dist[nx][ny]=eff;
                     min_pq.push({eff,nx,ny});
                     }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends