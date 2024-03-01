//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool find(int indx , int tar , vector<int>& a){
        
        if(tar == 0) return true;
        if(indx >= a.size()) return false;
        
        int pick = find(indx+1 , tar-a[indx] , a);
        if(pick == true) return true;
        int not_pick = find(indx+1 , tar , a);
        
        return not_pick;
    }
    
    bool isSubsetSum(vector<int>a, int sum){
        // code here 
      // return find(0 , sum , arr);
      
      //TABULATION
      int n  = a.size();
      vector<vector<int>> dp(n+1 , vector<int>(sum+1 , 0));
      dp[n][0]=1;
      
      for(int i = n-1 ; i >= 0 ; i--){
          for(int j = 0 ; j <= sum ; j++){
              
              if(j == 0) {dp[i][j] = 1; continue;}
              int pick = 0 , not_pick = 0;
              
              if(j-a[i] >= 0)
                  pick = dp[i+1][j-a[i]];
                  
               not_pick = dp[i+1][j];
              
              dp[i][j] = pick|not_pick;
          }
      }
      
      return dp[0][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends