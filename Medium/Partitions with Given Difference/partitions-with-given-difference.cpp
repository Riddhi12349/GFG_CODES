//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  const int mod = 1e9+7;
  
  int findCount(int s2 , int i , vector<int>& a , int n , vector<vector<int>>& dp){
      
      if(i >= n){
          return s2==0;
        }
        
    if(dp[i][s2] != -1) return dp[i][s2]%mod;
      
      int p = 0;
      
      if(s2-a[i] >= 0)
        p = findCount(s2-a[i] , i+1 , a , n , dp);
      
      int np = findCount(s2, i+1 , a , n , dp);
      
      return dp[i][s2] = (p+np)%mod;
  }
  
    int countPartitions(int n, int d, vector<int>& a) {
        
     int tot  = 0;
        for(auto x : a) tot+=x;
    
      int s2 = 0;
      
        if((tot-d < 0) || ((tot-d) % 2 != 0)) return 0;
        else s2 = ((tot-d)/2);
        
     vector<vector<int>> dp(n+1 , vector<int>(s2+1 , -1));
     return findCount(s2 ,0, a, n ,dp);
    
     
 
    //  dp[n][0] = 1;
    // for(int i = n-1 ; i >= 0 ; i--){
    //     for(int j = 0 ; j <= s2 ; j++){
            
    //         if(i==n-1){
                
    //       if(a[i]==0 && j == 0) dp[i][j] = 2;
    //       else if((j == 0 )|| (j == a[i])) dp[i][j] =  1;
    //       else  dp[i][j] = 0;
    //       continue;
    //         }
            
    //         if(j == 0 && i != n-1) { dp[i][j] == 1; continue; }
            
    //         int p = 0;
    //         if(a[i] <= j)
    //           p = dp[i+1][j-a[i]];
    //         int np = dp[i+1][j];
            
    //         dp[i][j] = (p+np)%mod;
    //     }
    // }
    
    // return dp[0][s2]%mod;
    }
    /*
    s1 >= s2 
    s1-s2 = d
    tot-s2-s2 = d
    tot-2*s2 = d
    s2 = (tot-d)/2; s2 >= 0 && tot-d =even 
    basically, count partitions with sum = s2
    */
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends