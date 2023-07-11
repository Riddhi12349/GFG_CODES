//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int m ,int n,int k)
    {
 		// Your code goes here.
 		int top = 0 , bottom = m-1 , left = 0 , right = n-1;
 		vector<int> ans;
 		int dir = 0;
 		
 		while(ans.size() < m*n){
 		    
 		    if(dir == 0){
 		        for(int i = left ; i <= right ; i++)
 		        ans.push_back(a[top][i]);
 		        
 		        top++;
 		    }
 		    else if(dir == 1){
 		        for(int i= top ; i <= bottom ; i++)
 		        ans.push_back(a[i][right]);
 		        
 		        right--;
 		    }
 		    else if(dir == 2){
 		        for(int i = right ; i >= left ; i--)
 		        ans.push_back(a[bottom][i]);
 		        
 		        bottom--;
 		    }
 		    else if(dir == 3){
 		        for(int i = bottom ; i>= top ; i--)
 		        ans.push_back(a[i][left]);
 		        
 		        left++;
 		    }
 		    dir = (dir+1)%4;
 		}
 		
 		return ans[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends