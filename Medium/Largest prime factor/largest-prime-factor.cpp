//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

/*
Point to keep in mind while dealing with prime factors : 

-- For any number N there exists at least one prime factor of N till sqrt(N). 
 
1. This can be used to check whether no is prime or not. If any
prime factor we can't find till sqrt(N) , it means that no is prime.

2. Prime Factorisation.
*******[Any no N = 2^a * 3^b * 4^c ....]******
*/

class Solution{
public: 
    long long int largestPrimeFactor(int N){
      
      int ans = 0;
      
      for(int i = 2 ; i*i <= N ; i++){
          
          if(N % i == 0){
              
              ans = i;
              while(N % i == 0){
                  N = N/i;
              }
          }
      }
      
      // MTLB koi prime factor jiske aage vo divisible ni h
      if(N > 1){
          ans = max(ans , N);
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends