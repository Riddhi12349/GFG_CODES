//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
   
    int func(int arr[] , int n , int i , vector<int>& dp){
        
        if(i >= n){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int c1 = arr[i] + func(arr , n , i+2, dp); // pick
        int c2 = func(arr , n , i+1 , dp);       // not pick
        
        return dp[i] =  max(c1 , c2);
    }
    int FindMaxSum(int arr[], int n)
    {
        
        vector<int> dp(n+1 , -1);
      return  func(arr , n , 0 , dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends