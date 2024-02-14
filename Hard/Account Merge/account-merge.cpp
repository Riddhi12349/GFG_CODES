//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSets{
  public: 
  vector<int> parent,size;
 
  DisjointSets(int v){
      parent.resize(v+1);
      size.resize(v+1);
      for(int i=0 ; i<= v ; i++){
          parent[i]=i; size[i]=1;
      }
  }
  
  int findUParent(int node){
      if(parent[node]==node) 
          return node;
      return parent[node] = findUParent(parent[node]);
  }
  
  void unionBySize(int u , int v){
      int ulp_u = findUParent(u);
      int ulp_v = findUParent(v);
      
      if(ulp_u==ulp_v) return;
      
      if(size[ulp_u]<=size[ulp_v]){
          parent[ulp_u]=ulp_v;
          size[ulp_v] += size[ulp_u];
      }
      else{
          parent[ulp_v]=ulp_u;
          size[ulp_u] += size[ulp_v];
      }
  }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc) {
        
       
        unordered_map <string,int> mp; 
        int m = acc.size() ;
         DisjointSets ds(m);
         
        for(int i=0 ; i<m ; i++){
            for(int j=1 ; j < acc[i].size() ; j++){
                if(mp.count(acc[i][j])==0)
                    mp[acc[i][j]]=i;
                
                else{
                    int indx = mp[acc[i][j]];
                    ds.unionBySize(indx,i); }
            }
        }
        
        vector<vector<string>> ans;
        vector<string> mails[m];
        
        
        for(auto it : mp){
            int indx = ds.findUParent(it.second);
            // string name = acc[indx][0];
            // mp2[name].push_back(it.first);
            mails[indx].push_back(it.first);
        }
        
        for(int i=0 ; i<m ; i++){
            
            if(mails[i].size()==0) continue;
            
            vector<string> tmp;
            tmp.push_back(acc[i][0]);
           
            vector<string> mergedstr = mails[i];
            sort(mergedstr.begin() , mergedstr.end());
            for(auto it : mergedstr){
                tmp.push_back(it);
            }
    
            ans.push_back(tmp);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends