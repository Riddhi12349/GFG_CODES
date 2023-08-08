//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    
    static bool cmp(pair<int,int> p1 ,  pair<int,int> p2){
        return p1.second < p2.second;
    }
    
    int countFractions(int n, int N[], int D[])
    {
        
        for(int i = 0 ; i < n ; i++){
            
            int g = __gcd(N[i],D[i]);
            
              N[i] = N[i]/g ; D[i] = D[i]/g ;
            
        }
       
       map<pair<int,int>,int> mp;
       
       mp[{N[0] , D[0]}]++;
       int ans = 0;
       
       for(int i = 1 ; i < n ; i++){
               int p = D[i]-N[i];
               if(mp.count({p , D[i]}) > 0) 
                        ans += mp[{p , D[i]}];
               mp[{N[i] , D[i]}]++;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends