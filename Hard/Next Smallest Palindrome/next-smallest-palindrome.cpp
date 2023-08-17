//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:
vector<int> generateNextPalindrome(int nu[], int n) {
        
        vector<int> num(n,0);
        
        for(int i=0;i<n;i++){
            num[i]=nu[i];
        }
        for(int i=0;i<=n/2;i++){
            
            num[n-1-i]=num[i];
        }
        
        
       // for(int i=0;i<n;i++){
       //     cout << num[i]<<" ";
       // }
       
        
        for(int i=n/2;i<n;i++){
            if(num[i]>nu[i]){
                return num;
            }
            else if(num[i]==nu[i]){
                continue;    
            }
            else break;
            
            
        }
        
        
        
        int flag=0;
        if(n%2==0){
            int end=n/2,start=end-1;
            
            while(start>=0){
                if(num[start]==9){
                    
                    num[start]=0;
                    num[end]=0;
                    start--;
                    end++;
                }
                
                else{
                    num[start]=num[start]+1;
                    num[end]=num[end]+1;
                    flag=1;
                    break;
                }
            }
        }
        
        else{
            int mid=n/2;
            if(num[mid]!=9){
                num[mid]=num[mid]+1;
                return num;
                
            }
            else{
                num[mid]=0;
            
            int end=mid+1,start=mid-1;
            
            while(start>=0){
                
                
                if(num[start]==9){
                    num[start]=0;
                    num[end]=0;
                    start--;
                    end++;
                    
                }
                else{
                    num[start]=num[start]+1;
                    num[end]=num[end]+1;
                    flag=1;
                    break;
                }
            }
                
            }
        }
        
        if(flag==0){
            
            vector<int> exception(n+1,0);
            
            exception[0]=1;
            exception[n]=1;
            return exception;
        }
        
        else{
            return num;
        }
    }

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends