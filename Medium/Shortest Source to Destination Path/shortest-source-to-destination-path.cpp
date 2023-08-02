//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     /*         WRONG APPROACH--------------------->
     int dp[250][250];
     
    int  dfs(int sx , int sy , vector<vector<int>>& a , 
    int fx , int fy , int m , int n ){
        
        if(sx < 0  || sx >= m || sy < 0 || sy >= n ){
            return INT_MAX;
        }
        if(a[sx][sy] == 0){
            return INT_MAX; 
        }
        if(sx == fx && sy == fy){
            return 0;
        }
            
        if(dp[sx][sy] != -1){
            return dp[sx][sy];
        }
        
       a[sx][sy] = 0;
    int p =   dfs(sx + 1 , sy , a , fx ,fy , m , n);
    int q =  dfs(sx - 1 , sy , a , fx ,fy , m , n);
    int r =   dfs(sx , sy + 1 , a , fx ,fy , m , n);
    int f =   dfs(sx , sy - 1 , a , fx ,fy , m , n);
     //  a[sx][sy] = 1;
       
       return dp[sx][sy] = 1 + min(p , min(q , min(r , f)));
        
    }
    */
    
    bool isValid(int n , int m , vector<vector<int>>& a , int p , int q){
       
        if(p >= n || p < 0 || q >= m || q < 0){
            return 0;
        }
        if(a[p][q] == 0){
            return 0;
        }
        return 1;
    }
    
    int shortestDistance(int n, int m, vector<vector<int>> a ,
    int X, int Y) {
        
    //     memset(dp , -1 , sizeof(dp));
    //   return dfs(0 , 0 , a , x , y , n , m);
    
    if(a[0][0] == 0){
        return -1;
    }
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    vector<vector<int>> dist(n , vector<int>(m , 1e9));
    
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0]= 0;
    
    while(!q.empty()){
        
      int x , y;
      tie(x,y) = q.front();
      q.pop();
      
        for(int i = 0 ; i < 4; i++){
        
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isValid(n , m , a , nx , ny) && 
            dist[nx][ny] > dist[x][y] + 1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx , ny});
            }
        }
    }
    
    return (dist[X][Y] == 1e9) ? -1 : dist[X][Y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends