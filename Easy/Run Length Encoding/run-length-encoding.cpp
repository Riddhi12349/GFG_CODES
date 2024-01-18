//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
 string ans = "";
 
  for(int i=0 ; i < src.size(); i++){
      int cnt=1;int j=i+1;
      for( j=i+1 ; j<src.size() ;j++){
          if(src[j]==src[i]) cnt++;
          else break;
      }
      ans += src[i];
      i=j-1;
      ans += to_string(cnt);
  }
  
  return ans;
}     
 
