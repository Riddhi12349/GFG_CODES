//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
/*	  
 int helper(string s1 , string s2 , int i , int j , vector<vector<int>>& dp)
 {
      if(i >= s1.size() || j >= s1.size()) return 0;
	            
	    if(dp[i][j] != -1){
	        return dp[i][j];
	    }
	    
	  int ans = 0;
	  int t ;
	  for(t = j ; t < s2.size() ; t++)
	   if((s1[i] == s2[t]) && (t != i)) break;
	   
	    // Take 
	    if(t < s2.size())
	   ans =  1 + helper(s1 , s2 , i+1 , t+1 , dp);
	    
	    // Not Take
	   ans = max(ans , helper(s1 , s2 , i+1 , j , dp));
	  
       dp[i][j] = ans;
       
       return ans;
 }*/
 
		int LongestRepeatingSubsequence(string s){
            
            int n = s.size();
            
            vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
            
            // return helper(str , str , 0, 0 , dp);
            
              for(int i = n-1 ; i >= 0 ; i--){
                  for(int j = n-1 ; j >= 0 ; j--){
                      int take = 0;
                    if(s[i] == s[j] && i != j)
                        take = 1 + dp[i+1][j+1]; 
                
                  dp[i][j] = max(take , max(dp[i+1][j] , dp[i][j+1]));
                  
            }
              }   
              return dp[0][0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends