//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class LFUCache {
public:
    int size , minfreq;
    unordered_map<int,pair<int,int>> keyval;
    unordered_map<int,list<int>::iterator> address;
    unordered_map<int,list<int>> freqlist;
    
    LFUCache(int capacity) {
        size = capacity;
        minfreq = 1;
    }
    
    // ALREADY EXISTING KEY KI KRENGE FREQ UPDATE
    void updatefreq(int key){
        
        int curfreq = keyval[key].second;
        freqlist[curfreq].erase(address[key]);
        address.erase(key);
        
        // NEW ASSIGNMENT
        keyval[key].second++;
        curfreq++;
        
        freqlist[curfreq].push_back(key);
        address[key] = --freqlist[curfreq].end();
        
         if(freqlist[minfreq].empty()){
            minfreq++;
        }
    }
    
    int get(int key) {
        
        if(keyval.find(key) == keyval.end()) return -1;
        updatefreq(key);
        return keyval[key].first;
    }
    
    void put(int key, int value) {
        
        if(size == 0){
            return;
        }
        if(keyval.find(key) != keyval.end()){
          
            keyval[key].first = value;
            
            updatefreq(key);
            
            return;
        }
        if(keyval.size() == size){
          
            // delete lru
            int del_key = freqlist[minfreq].front();
            address.erase(del_key);
            keyval.erase(del_key);
            freqlist[minfreq].pop_front();
        }
        
        //put the key with the val
        keyval[key] = {value , 1};
        freqlist[1].push_back(key);
        address[key] = --freqlist[1].end();
        
        minfreq = 1;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//{ Driver Code Starts.

int main(){
    int t = 1;
    cin >> t;

    while(t--){
        int capacity; cin >> capacity;
        LFUCache* obj = new LFUCache(capacity);

        int runs; cin >> runs;
        for(int i = 0;i<runs;i++){
            int s; cin >> s;
            if(s==1){
                int key; cin >> key;
                int param_1 = obj->get(key);
                cout << param_1 << endl;
            }else{
                int key,value;
                cin >> key >> value;
                obj->put(key,value);
            }
            
            
            
        }
        


    }
}

// } Driver Code Ends