//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;

    void find(string& s , int i){
        
        if(i >= s.size()){
            ans.push_back(s);
            return;
        }
        
        for(int k = i ; k < s.size() ; k++){
            swap(s[k] , s[i]);
            find(s , i+1);
            swap(s[k] , s[i]);
        }
    }
    vector<string> permutation(string s)
    {
       find(s , 0);
       sort(ans.begin() , ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends