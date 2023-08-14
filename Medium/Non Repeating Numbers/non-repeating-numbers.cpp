//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Same Nos will be cancelled only the xor of two distinct nos will remain
        int XxorY = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            XxorY =  XxorY^nums[i];
        }
        
        // Finding the rightmost bit which is 1
        // By generating mask
        
        int rightmost_bit_mask =  XxorY&(-XxorY);
        
        //The  -XxorY will be 2's complement of  XxorY
        // The 2's comp is simply taking 1's complement and then adding 1
        // for eg :  XxorY = 110010 , then -XxorY =>
        // 1. 1's comp of  XxorY = 001101 
        // 2. Add 1 = 001101 + 1 = 001110
        
        // Then we will find the mask by taking AND OF  (XxorY &(- XxorY))
        // 110010 & (-001110) = (000010)
        
        //Hence ,  rightmost_bit_mask = (000010)
        
        
        int x = 0 , y = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if((nums[i] & rightmost_bit_mask) == 0){
                x = x^nums[i];
            }
            else{
                y = y^nums[i];
            }
        }
        
     vector<int> ans = {x,y};
     sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends