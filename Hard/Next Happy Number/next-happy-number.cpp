//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    bool isHappy(int n){
        
           // code here
        if(n == 1 || n== 7){
            return true;
        }
        else if(n >= 2 && n  <= 9){
            return false;
        }
        else{
            
            int sum = 0;
            while(n != 0){
                sum += (n % 10)*(n % 10);
                n = n/10;
            }
           return isHappy(sum); 
        }
    }
    int nextHappy(int n){
     
     while(n++){
         
         if(isHappy(n) == true){ return n; }
     }
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends