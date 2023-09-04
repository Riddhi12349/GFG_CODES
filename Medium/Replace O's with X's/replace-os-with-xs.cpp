//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i ,int j, vector<vector<char>>& mat , vector<vector<char>>& ans){
        
        int m = mat.size() , n = mat[0].size();
      
        if(i >= m || j >= n || i < 0 || j < 0)
            return;
    
        if(mat[i][j] != 'O')
            return;
            
        if(mat[i][j] == 'O'){
            mat[i][j]= 'k';
            ans[i][j] = 'O';
            dfs(i+1,j,mat,ans);
            dfs(i,j+1,mat,ans);
            dfs(i,j-1,mat,ans);
            dfs(i-1,j,mat,ans);
          //  mat[i][j]='O';
        }
    }
    vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
    {
       vector<vector<char>> ans(m , vector<char>(n , 'X'));
      
       for(int i = 0 ; i < m ; i++){
          if(mat[i][0] == 'O')
             dfs(i,0,mat,ans);
       }
       
      for(int i = 0 ; i < m ; i++){
          if(mat[i][n-1] == 'O')
             dfs(i,n-1,mat,ans);
       }
      
      for(int i = 0 ; i < n ; i++){
          if(mat[0][i] == 'O')
             dfs(0,i,mat,ans);
       }
       
      for(int i = 0 ; i < n ; i++){
          if(mat[m-1][i] == 'O')
             dfs(m-1,i,mat,ans);
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends