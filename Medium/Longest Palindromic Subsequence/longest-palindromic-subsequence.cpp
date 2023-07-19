//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s1) {
        
        // VARIATION OF LCS
        int n = s1.size();
        
        string s2 = s1;
        reverse(s1.begin() , s1.end());
        
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        
        // BOTTOM - UP APPROACH
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                
                int take = 0;
                if(s1[i] == s2[j]) 
                take = 1 + dp[i+1][j+1];
                
                dp[i][j] = max(dp[i][j+1] , max(dp[i+1][j] , take));
            }
        }
        
        return dp[0][0];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends