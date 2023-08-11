//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     using ll = long long;
    ll  dp[1008][1008];
     
    ll find(int coins[] , int n , int sum , int i){
        
        if(sum == 0) return 1;
        if(sum < 0 || i >= n) return 0;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        ll x = find(coins , n , sum - coins[i] , i);
        ll y = find(coins , n , sum , i+1);
        
        return dp[i][sum] =  x+y;
    }
    long long int count(int coins[], int n, int sum) {

     
        memset(dp , -1 , sizeof(dp));
        
        return find(coins , n , sum , 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends