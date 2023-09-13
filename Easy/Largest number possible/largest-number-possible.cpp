//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n , int s){
        // code here
      //  n = 6 , s = 40
      //  9+9+9+9+4+0
        if(n == 1){
            string t = to_string(s);
            return (t.size()==n) ? t : "-1";
        }
        
        if(s <= 0){
            return "-1";
        }
        string ans = "";
        while(s >= 9){
            ans += '9';
            s -= 9;
        }
        
     
        if(s > 0 && s < 9 && ans.size() < n){
            string t = to_string(s);
            ans += t;
            s = 0;
        }
  
   
        while(ans.size() < n){
            ans += '0';
        }
        
        return  (ans.size() == n && s == 0) ? ans :  "-1";
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends