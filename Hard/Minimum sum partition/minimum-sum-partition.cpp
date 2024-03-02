//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
// **********(3,5,7,2,4,6)=>27/2=13+1=14+(13)=27
   
	void find(int sum , int n , int a[],vector<vector<int>>& dp){
	    dp[n][0]=1;
	    for(int i= n-1 ; i >= 0 ; i--){
	        for(int k = 0 ; k <= sum ; k++){
	            
	            //pick = dp[i+1][tar-a[i]];
	            //not-pick = dp[i+1][tar];
	            if(k==0) {dp[i][k]=1; continue; }
	            int p = 0;
	            if(k-a[i]>=0)
	                 p = dp[i+1][k-a[i]];
	            int np = dp[i+1][k];
	            
	            dp[i][k] = p|np;
	        }
	    }
	}
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	   // s1-s2=min,
	   // s2 = k
	   // s1 = min-k=0-k=k
	    /*
	    if(tot_sum % 2 == 0){ // we will partition array 
	    //into 2 arrays with equal sum -- such that diff=0
	    //case---1 : type =====> (2*k)
	    }
	    else{
	        //we will partition array into 2 arrays such that 
	        // diff=1,
	        //one array sum = (tot_sum/2);and other = (tot_sum/2)+1
	        //case--2 : type =====> (2*k+1)
	    } 
	    */
	    //HENCE, IN BOTH CASES WE HAVE TO FIND (tot_sum/2)
	    //Same qs AS ******** SUBSET--SUM **********
	   
	   /* int sum= accumulate(a , a+n , 0);
	    int tar = 0;
	    
	    if(sum % 2 == 0) tar = sum/2;
	    else tar = (sum/2)+1;
	    
	    find()
	    */
	    //*************this ^ method will fail if we can't generate sum of array = k
      //*****so , we have to find difference for all possible values of s1 from 0 to tot_sum 
      
        int sum = accumulate(a , a+n ,0);
    vector<vector<int>> dp(n+1 , vector<int>(sum+1 , 0));
        find(sum  , n , a ,dp);
        
        int d = INT_MAX;
        
        for(int i = 0 ; i <= sum ; i++){
            if(dp[0][i]==1){
                int s1 = i; int s2 = sum-i;
                int dif = abs(s2-s1);
                d = min(d , dif);
             //   cout << d << endl;
            }
        }
 return d;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends