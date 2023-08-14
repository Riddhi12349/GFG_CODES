//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> v1;
        for(int i = 0 ; i < M.size() ; i++){
            int f = 0;
            for(int j = 0 ; j < M[0].size() ; j++){
                if(M[i][j] == 1){
                    f =1; break;
                }
            }
            if(f == 0) v1.push_back(i);
        }
        
        if(v1.size() != 1){
            return -1;
        }
        int indx = v1[0];
        for(int i = 0 ; i < M.size() ; i++){
            if(i != indx && M[i][indx] != 1){
                return -1;
            }
        }
        return indx;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends