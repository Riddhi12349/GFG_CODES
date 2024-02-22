//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int dp[105][105];
  const int mod = 1e9+7;
   int find(int i , int j , int m , int n , vector<vector<int>>& grid){
       
       if(i==m-1 && j==n-1 && grid[i][j]==0) return 1;
       
       if(i<0 || j<0 || i>= m || j>=n) return 0;
       if(grid[i][j]==1) return 0;
       if(dp[i][j] != -1) return dp[i][j];
       
      int p = find(i+1, j, m , n , grid);
      int q = find(i , j+1 , m , n , grid);
       
      return dp[i][j] = (p+q)%mod;
   }
    int totalWays(int m, int n, vector<vector<int>>& grid) {
     
    //  vector<vector<int>> dp(m , vector<int>(n,0));
      memset(dp , -1, sizeof(dp));
      return find(0,0,m,n,grid);
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