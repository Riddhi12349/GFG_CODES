//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

  //USING BINARY SEARCH AND USING RECURSION

class Solution
{
    public:
    // IF YOU WNT TO USE RECURSION THEN USE 1 MORE VARIABLE I.E PRV-INDX
  /*  int dp[10000];
    //Function to find length of longest increasing subsequence.
    int find(int a[] , int n , int i , vector<int>& res){
        
        if(i >= n){
            int t = res.size();
            return t;
            // return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int len1 = 0;
        
      //PICK
       if(res.size() == 0 || res[res.size()-1] < a[i]){
          res.push_back(a[i]);
          len1 = find(a , n , i+1 , res);
          res.pop_back();
       }
       
       // NOT - PICK
      int len2 =  find(a , n , i+1 , res);
       
       return dp[i] = max(len1 , len2);
    }*/

// USING BINARY SEARCH

   int longestSubsequence(int n, int a[]){
            
            vector<int> ans;
            ans.push_back(a[0]);
            
    for(int i = 1 ; i < n ; i++){
        if(a[i] > ans.back())
         ans.push_back(a[i]);
        else{
            int pos = lower_bound(ans.begin() , ans.end(), a[i])-ans.begin();
            ans[pos] = a[i];
        }
    }
    
    return ans.size();
    
  }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends