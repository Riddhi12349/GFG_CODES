//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    
    void print(vector<int>& v1 , int n){
        for(int i = 0 ; i < n ; i++){
            cout << v1[i] << " ";
        }
        cout << endl;
    }
    vector <int> maxOfMin(int arr[], int n){
    
    stack<pair<int,int>> st;
    
    vector<int> nxt_smaller_indx(n);
    // find next smaller
    for(int i = n-1 ; i >= 0 ; i--){
        if(st.empty()){
            nxt_smaller_indx[i] = n;
            st.push({arr[i] , i}); 
        }
        else{
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            if(st.empty()) nxt_smaller_indx[i] = n;
            else nxt_smaller_indx[i] = st.top().second;
            st.push({arr[i] , i});
        }
    }
    
   
    
    stack<pair<int,int>> st2;
    // find prv smaller
    
    vector<int> prv_smaller_indx(n);
    
        for(int i = 0 ; i < n ; i++){
            if(st2.empty()){
             prv_smaller_indx[i] = -1;  
             st2.push({arr[i] , i});
            }
            else{
               while(!st2.empty() && st2.top().first >= arr[i]){
                st2.pop();
            } 
             if(st2.empty()) prv_smaller_indx[i] = -1;
            else prv_smaller_indx[i] = st2.top().second;
            st2.push({arr[i] , i});
            }
        }
        
        // PEHLE HAMNE FIND KIA KI EK ELEMENT KI POSSIBLE RANGE KYA HO SKTI H
    // AGAR FOR AN ELEMENT ; WINDOW-KA-SIZE = 7 ; 
    //ISKA MTLB WO WINDOW-SIZE = 7 KE LIYE MINm ELEMENT HO SKTA HAI
    // AGAR EK ELEMENT KAM BHI KROGE UNN 7 MEIN SE TOH BHI VO MINm HI RAHEGA 
        // USKE ACC APNA ANS ARRAY BNA LIA 
        // AND THEN USS ANS ARRAY MEIN MAXm VALUE KO STORE KIA 
        // FROM THE LAST OF ARRAY
        
        vector<int> size(n);
        for(int i = 0 ; i < n ; i++){
            size[i] =  nxt_smaller_indx[i] -  prv_smaller_indx[i] -1;
        }
        
        
        vector<int> ans(n , 0);
        for(int i = 0 ; i < n ; i++){
            ans[size[i]-1] = max(ans[size[i]-1] , arr[i]);
        }
        //  print(nxt_smaller_indx , n);
        //  print(prv_smaller_indx , n);
        //  print(size , n);
        //  print(ans , n);
         
         // WE WILL START FROM THE END OF THE ARRAY
         for(int i = n-2 ; i >= 0 ; i--){
            ans[i] = max(ans[i] , ans[i+1]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends