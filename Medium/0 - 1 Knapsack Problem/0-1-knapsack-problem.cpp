//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // Function to return max value that can be put in knapsack of capacity W.
    
    int dp[1005][1005];
    
    int find(int i , int tot_wt , int wt[] , int val[], int n){
        
        if(i >= n || tot_wt==0) return 0;
        
        if(dp[i][tot_wt] != -1)
            return dp[i][tot_wt];
        
        int pick = 0;
          if(wt[i] <= tot_wt)
             pick = val[i] + find(i+1  , tot_wt-wt[i] , wt, val , n);
             
         int notpick = find(i+1 , tot_wt , wt, val , n);
         
         return dp[i][tot_wt] = max(pick , notpick);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp , -1 , sizeof(dp));
       return find(0 , W , wt , val , n);
                  
                // int dp[n+1][W+1];
                // memset(dp , 0 , sizeof(dp));
                
                // for(int i = 0 ; i < n ; i++){
                //     for(int w = 0 ; w <= W ; w++){
                        
                //         int p = 0 , np = 0;
                //         if(w-wt[i] >= 0)
                //           p = dp[i+1][w-wt[i]] + val[i];
                           
                //         np = dp[i+1][w];
                        
                //         dp[i][w] = max(p,np);
                //     }
                // }
                
                // return dp[0][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends