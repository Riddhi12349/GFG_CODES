//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    using P = pair<int,int>;
    int spanningTree(int v, vector<vector<int>> adj[])
    {
       priority_queue<P , vector<P> , greater<P>> pq;
       //{weight , node}
       pq.push({0 , 0});
       
       vector<bool> inMST(v , false);
       int sum = 0;
       
       while(!pq.empty()){
           
           auto p = pq.top();
           pq.pop();
           
           int wt = p.first;
           int node = p.second;
           
           if(inMST[node] == true) // already visited 
             continue;
           
           inMST[node] = true;
           sum += wt;
           
           for(auto &tmp : adj[node]){
               
                int neighbor = tmp[0];
                int neighbor_wt = tmp[1];
                
                if(inMST[neighbor] == false) // not visited
                {
                    pq.push({neighbor_wt , neighbor});
                }
           }
       }
       
       return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends