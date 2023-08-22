//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int p)
    {
        vector<int> v_row , v_col;
        int m = matrix.size() , n = matrix[0].size();
        
        for(int i = 0 ; i < m ; i++){
            int sum = 0;
            for(int j = 0 ; j <n ; j++){
                sum += matrix[i][j];
            }
            v_row.push_back(sum);
        }
        
        for(int j = 0 ; j < n ; j++){
            int sum = 0;
            for(int i= 0 ; i < m ; i++){
                sum += matrix[i][j];
            }
            v_col.push_back(sum);
        }
        
        sort(v_row.begin() , v_row.end());
        sort(v_col.begin() , v_col.end());
        
        int mx = max(v_row.back() , v_col.back());
        
        int ans1 = 0 , ans2 = 0;
        for(int  i = 0 ; i < v_row.size() ; i++){
            ans1 += mx - v_row[i];
            ans2 += mx - v_col[i];
        }
        
        return max(ans1 , ans2);
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends