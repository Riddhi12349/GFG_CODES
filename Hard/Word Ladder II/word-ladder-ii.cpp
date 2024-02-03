//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
      
      vector<vector<string>> ans;
      queue <vector<string>> q;
      q.push({beginWord});
      
      unordered_map<string,int> mp;
    //   mp= mp(wordList.begin(),wordList.end());
       for(auto x:wordList) mp[x]++;
      
      mp[beginWord]++;
      mp.erase(beginWord);
      
      while(!q.empty()){
          
          int s = q.size();
         vector<string> erase;
          int f=0;
        
          for(int i=1 ; i<= s; i++){
           
            vector<string> v1 = q.front();
            q.pop();
          
            string word = v1.back();
            if(word == endWord) {
                ans.push_back(v1);f=1;
                continue;
            }
            
             for(int i=0 ; i<word.size() ; i++){
               string orig =  word;
              for(char ch = 'a' ; ch <= 'z' ; ch++){
                  word[i] = ch;
                  if(mp.count(word) > 0){
                   //    mp.erase(word);
                   vector<string> v2 = v1;
                      v2.push_back(word);
                      q.push(v2);
                      erase.push_back(word);
                      //f=1;
                    //  break;
                  }
                }  
                word = orig;
             }
          }
          
                    if(f==1) break;
          
       for(int i=0 ;i<erase.size() ; i++){
                 //putin vector-->words to be erased
             if(mp.count(erase[i])>0)
                 mp.erase(erase[i]);
          }

          
      }
      
      return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends