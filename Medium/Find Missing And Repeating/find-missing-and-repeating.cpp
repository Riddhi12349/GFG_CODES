//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> v1(n+1,0);
        
        for(int i=0;i<n;i++){
            v1[arr[i]]++;
        }
        
        int m=-1,r=-1;
        for(int i=1;i<=n;i++){
            if(v1[i]==0) m=i;
            if(v1[i]>1) r=i;
        }
        
        return {r,m};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends