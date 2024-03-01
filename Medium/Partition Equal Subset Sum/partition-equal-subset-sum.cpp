//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int find(int i , int tar ,int n, int a[]){
        
        if(tar == 0) return 1;
        if(i >= n) return 0;
        
        int p = find(i+1 , tar-a[i] , n , a);
        int np = find(i+1 , tar , n, a);
        
        return p|np;
    }
    int equalPartition(int n, int arr[])
    {
         int sum = accumulate(arr , arr+n , 0);
         
         if(sum % 2 != 0) return 0;
         int tar = sum/2;
         //WITH-RECURSION
        // return find(0 , tar , n , arr);
        
        vector<vector<int>> dp(n+1 , vector<int>(tar+1 , 0));
        //WITH-TABULATION
        dp[n][0]=1;
        for(int i = n-1 ; i >= 0 ; i--){
            for(int k = 0 ; k <= tar ; k++){
             
              if(k==0) { dp[i][k]=1; continue;}
              int p = 0;
              if(k-arr[i] >= 0)
                 p = dp[i+1][k-arr[i]];
              int np = dp[i+1][k];
              dp[i][k] = p|np;
            }
        }
        
        return dp[0][tar];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends