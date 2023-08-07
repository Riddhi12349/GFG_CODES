//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(int grid[N][N] , int i , int j , int t){
      
      for(int a = 0 ; a < 9 ; a++){
          if(grid[i][a] == t) return false;
          if(grid[a][j] == t) return false;
      }    
      
      int start_row = i - (i % 3);
      int start_col = j - (j % 3);
      
      for(int i= 0 ; i<= 2 ; i++){
          for(int j = 0 ; j <= 2 ; j++){
              if(grid[i + start_row][j + start_col] == t){
                  return false;
              }
          }
      }
      
      return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
             
                if(grid[i][j] == 0){
                    for(int t = 1 ; t <= 9 ; t++){
                        if(isValid(grid , i , j, t)){
                            grid[i][j] = t;
                          bool ans =  SolveSudoku(grid);
                          if(ans == true){
                              return true;
                          }
                          grid[i][j] = 0;
                        }
                    }
                    return false;//**********
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j <9 ; j++){
                cout << grid[i][j] << " ";
            }
            // cout << endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends