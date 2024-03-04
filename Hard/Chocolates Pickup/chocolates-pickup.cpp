//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int find(int i , int acol , int bcol ,int m , int n , vector<vector<int>>& grid){
        
        if(acol >= n || acol < 0 || bcol >= n || bcol < 0) return 0;
        
        if(i == m-1){
            return (grid[i][acol]+grid[i][bcol]);
        }
        
        int mx = 0;
        
        for(int p= -1; p <= 1 ; p++){
            for(int q = -1 ; q <= 1 ; q++){
                mx = max(mx ,find(i+1 , acol+p , bcol+q , m, n , grid));
            }
        }
        
        int eaten = (acol != bcol) ? (grid[i][acol]+grid[i][bcol]) : grid[i][acol];
        return mx + eaten;
    }
    
    int solve(int m, int n, vector<vector<int>>& grid) {
        
        // **************** RECURSION ****************
       //  return find(0 , 0 , n-1, m, n , grid);
       
       //*********************** TABULATION ***************************
       //finding maximum choco can be eaten
       vector<vector<vector<int>>> dp(m+1 , vector<vector<int>>(n+1 , vector<int>(n+1 , 0)));
      
      for(int i = m-1 ; i >= 0 ; i--){
          for(int j = 0 ; j < n ; j++){
              for(int k = 0 ; k < n ; k++){
                  
                  int mx = 0;
                  
                  for(int p = -1 ; p <=1 ; p++){
                      for(int q = -1; q <= 1 ; q++){
                          if(j+p < n && k+q < n && j+p >= 0 && k+q >= 0)
                            mx = max(mx , dp[i+1][j+p][k+q]);
                      }
                  }
                  
                  
                  if(j != k)
                     dp[i][j][k] = grid[i][j]+grid[i][k]+mx;
                  else
                    dp[i][j][k] = mx + grid[i][j];
              }
          }
      }
      
      return dp[0][0][n-1];
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends