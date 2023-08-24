//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    
        
    bool isValid(int x, int y , int p, string word ,vector<vector<char>>& grid){
        
        int m = grid.size() , n = grid[0].size();
        
        if(x < 0 || x >= m || y < 0 || y >= n) return 0;
        if(grid[x][y] != word[p]) return 0;
        
        return 1;
        
    }
    
        bool helper(int x , int y , int dir , int p, string word, vector<vector<char>>grid){
            
        int dx[8] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
        int dy[8] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
        
            if(p == word.size()-1) return 1;
            
            if(isValid(x + dx[dir] , y + dy[dir] , p+1 ,word, grid))
                return helper(x + dx[dir] , y + dy[dir] , dir , p+1 , word , grid);
                
            return 0;
        }
        
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){

        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < 8 ; k++){
                     if(isValid(i,j,0,word,grid) && helper(i,j,k,0,word,grid)){
                         vector<int> t = {i,j};
                         ans.push_back(t);
                         break;
                     }
                }
            }
        }
        
        return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends