//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        
        // BRUTE FORCE----->
        /*
        int i = 0 , j = n-1 ,  maxdiff = 0;
        while(i <= j){
            
            if(arr[i] <= arr[j]){
                maxdiff = max(maxdiff , j-i);
                i++;
                j= n-1;
            }
            
            else{
                j--;
            }
        }
        
        return maxdiff;
        */
        
        int pref[n] , suff[n] ;
   
        pref[0] = arr[0];
        suff[n-1] = arr[n-1];
        
        for(int i = 1 ; i < n ; i++){
            pref[i] = min(pref[i-1] , arr[i]);
        }
        
        for(int j = n-2 ;  j >= 0 ; j--){
            suff[j] = max(suff[j+1]  , arr[j]);
        }
        
        int mxdiff = 0 ; int i = 0 , j = 0;
        
       while(i < n && j < n){
           
            if(pref[i] <= suff[j]){
                
                mxdiff = max(mxdiff , j-i);
                j++;
            }
            else{
                i++;
            }
        }
        
        return mxdiff;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends