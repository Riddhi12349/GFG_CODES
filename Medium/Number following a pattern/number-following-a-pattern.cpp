//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
// ///IIIDDII
// sf:0002100
// a:12365478 
    string printMinNumberForPattern(string s){
        // code here 
        int n = s.size();
        
        vector<int> suff(n+1 , 0);
        for(int i= n-1 ; i>= 0 ; i--){
            if(s[i]=='D')
               suff[i] = suff[i+1]+1;
            else
               suff[i] = 0;
        }
        
        string ans = ""; int p; int j=0;
        if(s[0]=='I'){
            ans += "1";p=1;
        }
        else{
            p = suff[0]+1;int t=p;
            ans += to_string(t);
            t--;
            
            while(j<n && s[j]=='D'){
            ans += to_string(t);j++;
            t--;}
        }
        
        
        for(int i=j ; i < s.size() ; i++){
          
          if(i+1<s.size() && s[i+1] == 'D'){
              p = p + suff[i+1] + 1;
              ans += to_string(p);
              i++;
              int t = p;
              while(i < s.size() && s[i]=='D'){
                  t--; ans += to_string(t);i++;
                  }
                  i--;
          }
          else{
              p++;
              ans += to_string(p);
          }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends