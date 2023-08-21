//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isValid(vector<vector<int>>& matrix , int i , int j){
        
        int cnt1 = 0;
        
        int m = matrix.size() , n = matrix[0].size();
        
         if(i-1 >= 0 && j < n && matrix[i-1][j] == 0) cnt1++;
         if(i+1 < m && j < n && matrix[i+1][j] == 0) cnt1++;
         if(j+1 < n && matrix[i][j+1] == 0) cnt1++;
         if(j-1 >= 0 && matrix[i][j-1] == 0) cnt1++;
         if(i+1 < m && j+1 < n && matrix[i+1][j+1] == 0) cnt1++;
         if(i-1 >= 0 && j+1 < n && matrix[i-1][j+1] == 0) cnt1++;
         if(i-1 >= 0 && j-1 >= 0 && matrix[i-1][j-1] == 0) cnt1++;
         if(i+1 < m && j-1 >= 0  && matrix[i+1][j-1] == 0) cnt1++;
         
         if(cnt1 > 0 && cnt1 % 2 == 0) return true;
         return false;
    }
    int Count(vector<vector<int> >& matrix) {
        
        int cnt = 0;
        
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == 1 && isValid(matrix , i , j))
                    cnt++;
            }
        }
    return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends