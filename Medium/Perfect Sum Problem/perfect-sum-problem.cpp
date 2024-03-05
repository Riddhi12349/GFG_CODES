//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	const int mod = 1e9+7;
/*	
	int find(int i , int sum , int a[] , int n, vector<vector<int>>& dp){
	   
	    if(i >= n){ return sum==0;}
	    
	    if(dp[i][sum] != -1) return dp[i][sum]%mod;
	    
	    int pick = 0;
	    if(sum-a[i] >= 0)
	      pick = find(i+1 , sum-a[i] , a , n, dp);
	    
	    int notpick = find(i+1 , sum , a, n , dp);
	    
	    return dp[i][sum] = (pick+notpick)%mod;
	}
*/
	int perfectSum(int a[], int n, int sum)
	{
	    vector<vector<int>> dp(n+2 , vector<int>(sum+2 , 0));
       //return find(0 , sum , a , n , dp);
    //   dp[n][0]=1; 
    //   /
    
    // for(int i = 0 ; i <= n  ; i++)
    //   dp[i][0] = 1;
      dp[n][0]=1;
      
       for(int i = n-1 ; i >= 0 ; i--){
           for(int j = 0 ;  j <= sum ; j++){
                
            //  if(j==0){dp[i][j]=1;}
             
                int p = 0;
                if(j-a[i] >= 0)
                    p = dp[i+1][j-a[i]];
                
                int np = dp[i+1][j];
                
                dp[i][j] = (p+np)%mod;
            //    if(j==0){dp[i][j]=max(dp[i][j],1);}
           }
       }
       
       return dp[0][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends