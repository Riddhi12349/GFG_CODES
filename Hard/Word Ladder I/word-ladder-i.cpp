//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        unordered_map <string,int> mp;
        for(int i = 0 ; i < wordList.size() ; i++){
            mp[wordList[i]]++;
        }
        
        queue<pair<string,int>> q;
        q.push({startWord,1});
        mp[startWord]++;
        mp.erase(startWord);
        
        while(!q.empty()){
        
            string f = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if(f == targetWord) return steps;
            
            for(int i = 0; i<f.size() ; i++){
                string orig = f;
                
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    
                    
                    f[i] = ch;
                    
                    if(mp.find(f) != mp.end()){
                   //     cout << f << endl;
                        q.push({f,steps+1});
                        mp.erase(f);
                        }
                }
                
                f = orig;
            }
            
            
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends