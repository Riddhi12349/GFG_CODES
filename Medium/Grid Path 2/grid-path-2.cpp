//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int dp[502][502];
  const int mod = 1e9+7;
  
    int find(int i,int j , int m, int n,vector<vector<int>>& grid){
    
        if(i==0 && j==0){
             if(grid[i][j]==0) return 1;
             return 0;
        }
        if(i<0 || j<0) return 0;
        
        if(grid[i][j]==1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int p1 = find(i-1,j,m,n,grid);
        int p2 = find(i,j-1,m,n,grid);
        
        return dp[i][j]=( p1+p2)%mod;
    }
    
    int totalWays(int m,int n, vector<vector<int>>& grid) {
        
    //memset(dp , 0 ,sizeof(dp));
      //return  find(m-1,n-1,m,n,grid);
    int dp[m][n];
    
    for(int i = m-1 ; i >= 0; i--){
        for(int j = n-1 ; j >= 0 ; j--){
            
            if(grid[i][j]==1) { dp[i][j]=0; continue; }
            if(i==m-1 && j==n-1) { dp[i][j] = 1; continue; }
          
            int op1 = 0 , op2= 0;
            if(i+1 < m) op1 = dp[i+1][j];
            if(j+1 < n) op2 = dp[i][j+1];
            
            dp[i][j] = (op1+op2)%mod;
        }
    }
    
    return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends