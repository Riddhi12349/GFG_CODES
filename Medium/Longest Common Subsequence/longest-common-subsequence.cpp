//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    /*
    int dp[1002][1002];
    
    int find(int i , int j , string s1 , string s2){
       
       if(i >= s1.size() || j >= s2.size())
            return 0;
       
       if(dp[i][j] != -1){
           return dp[i][j];
       }
       
       if(s1[i] == s2[j]){
           int ans = 1 + find(i+1 , j+1 , s1 , s2);
            return dp[i][j] = ans;
       }
       
       else{
           
           int p = find(i , j+1 , s1 , s2);
           int q = find(i+1 , j , s1 , s2);
           
           return dp[i][j] = max(p ,q);
       }
    }*/
    
    int lcs(int n, int m, string s1, string s2)
    {
           
           int dp[1002][1002];
           memset(dp , 0 , sizeof(dp));
           
           for(int i = n-1; i >= 0 ; i--){
               for(int j = m-1 ; j >= 0 ; j--){
                  
                   if(s1[i] == s2[j]){
                        dp[i][j] = 1 + dp[i+1][j+1];
                   }
                   else{
                       dp[i][j] = max(dp[i][j+1] , dp[i+1][j]);
                   }
               }
           }
           
           return dp[0][0];
                   
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends