//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string s){
    string p = s; // bbbab
        reverse(p.begin() , p.end()); // babbb
        
          
        int l1 = p.size() , l2 = s.size();
        
        vector<vector<int>> dp(l1+1 , vector<int>(l2+1 , 0));
        
        for(int i = l1-1 ; i >= 0 ; i--){
            for(int j = l2-1 ; j >= 0  ; j--){
                              
                if(p[i] == s[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                dp[i][j] = max(dp[i+1][j+1] , 
                               max(dp[i][j+1] , dp[i+1][j]));
                }
                
            }
        }
        
        int mxLen_Palindromic_Subseq = max(1 ,dp[0][0]);
        
        int ans = s.size() - mxLen_Palindromic_Subseq;
        return ans; // itne characters aur insert krne padenge to make palindrome....
         
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends