//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
      
//               i
//                  j
//  /S =   "aabacbebebe"    /mp -> b=1 , c=1 , e=1
//   s= "ifisarkdlkk"
  
      int i = 0 , j = 0 , mxlen  = 0;
      unordered_map<char,int> mp;
      
      while(j < s.size()){
     
          ++mp[s[j]];
          ++j;
          
          if(mp.size() == k){
              mxlen = max(mxlen , j-i);
            //   string t= s.substr(i , j-i);
            //   cout<<t<<endl;
          }
           if(mp.size() > k){
             mp[s[i]]--;
              while(mp[s[i]] > 0){
                  i++; 
                  mp[s[i]]--;
              }
              if(mp[s[i]] == 0) mp.erase(s[i]);
              i++;
          }
      }
       //mxlen = max(mxlen , j-i);
      return mxlen == 0?-1:mxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends