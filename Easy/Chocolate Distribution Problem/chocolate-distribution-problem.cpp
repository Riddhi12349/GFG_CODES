//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    using ll = long long;
    public:
    long long findMinDiff(vector<long long> a, long long N, long long M){
       
       sort(a.begin() , a.end());
    //     0
    //   [1 , 3 , 4 , 7 , 9 , 9 , 12 , 56]
       ll i = 0 , j = i+M-1 , diff = LLONG_MAX;
       for( ; j < N ; j++, i++){
           ll d = a[j]-a[i];
           if(diff > d) { diff = d; }
       }
       
       return diff;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends