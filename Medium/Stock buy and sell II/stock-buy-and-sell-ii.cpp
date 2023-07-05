//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        /*
      [3,4,1,5]  ;  [3 , 4 , 6, 2 , 1 , 8 , 4]
  
                                        8
                          6            /\
           5             / \          /  \
      4   /             4   \        /    4
     /\  /             /     \      /
     3 \/             3       \    /
        1                      2  /
                                \/
                                 1
   */
    int mxprofit = 0;
    for(int i = 1 ; i < n ; i++){
        if(prices[i]>prices[i-1]){
            mxprofit += (prices[i] - prices[i-1]);
        }
    }
    
    return mxprofit;
    }   
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends