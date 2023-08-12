//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
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

int lengthOfLIS(int nums[] , int n)
{
 
    // Binary search approach
   // int n = nums.size();
    vector<int> ans;
 
    // Initialize the answer vector with the
    // first element of nums
    ans.push_back(nums[0]);
 
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
 
            // If the current number is greater
            // than the last element of the answer
            // vector, it means we have found a
            // longer increasing subsequence.
            // Hence, we append the current number
            // to the answer vector.
            ans.push_back(nums[i]);
        }
        else {
 
            // If the current number is not
            // greater than the last element of
            // the answer vector, we perform
            // a binary search to find the smallest
            // element in the answer vector that
            // is greater than or equal to the
            // current number.
 
            // The lower_bound function returns
            // an iterator pointing to the first
            // element that is not less than
            // the current number.
            int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i])
                      - ans.begin();
 
            // We update the element at the
            // found position with the current number.
            // By doing this, we are maintaining
            // a sorted order in the answer vector.
            ans[low] = nums[i];
        }
    }
 
    // The length of the answer vector
    // represents the length of the
    // longest increasing subsequence.
    return ans.size();
}
 

   int longestSubsequence(int n, int a[]){
//     {
//     //     vector<int> res;
//     //     memset(dp , -1 , sizeof(dp));
//     //  int p = find(a , n , 0 , res);
     

//     //   return p;
//     return lis(a , n);
return lengthOfLIS(a , n);
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