//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    /*
using ll = long long;
 void  mergeF(ll a[] , int l , int m  ,int h){

    //[2, 6] + [1,3] = [1,2,3,6]

    int i = l , j = m+1 , k = 0;
    int b[1000000];

    while(i <= m && j <= h){
     if(a[i] < a[j]){
        b[k] = a[i];
        i++;
        k++;
     }    
     else{
        b[k] = a[j];
        j++;
        k++;
     }
    }

    while(i <= m){
        b[k++] = a[i++];
    }

    while(j <= h){
        b[k++] = a[j++];
    }
 
 for(int t = l ; t <= h ; t++){
    a[t] = b[t];
 }
 }
 void mergeSort(ll a[] , int l , int h){

  
    if(l < h){
          int m = (l+h)/2;
        mergeSort(a , 0 , m);
        mergeSort(a , m+1 , h);
        mergeF(a , 0 , m , h);
    }
 }
 */
  void merge(long long arr1[], long long arr2[], int n, int m) { 
    
    int i = n-1 , j = 0;
    while(i >= 0 && j < m){
        if(arr1[i] > arr2[j]){
            swap(arr1[i] , arr2[j]);
            i--;
            j++;
        }
        else{
            break;
        }
    }

    // mergeSort(arr1 , 0 , n-1);
    // mergeSort(arr2 , 0 , m-1);
    
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+m);

} 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends