//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
      unordered_map<int,int> mp;
      
      Node* p = head;
      while(p != NULL){
          mp[p->data]++;
          p = p->next;
      }
        
        Node* dummy = new Node(0);
        dummy->next = NULL;
        Node* tmp = dummy;
        
        while(mp[0] != 0){
            Node* newNode = new Node(0);
            tmp->next = newNode;
            tmp = tmp->next;
            mp[0]--;
        }
        
        while(mp[1] != 0){
            Node* newNode = new Node(1);
            tmp->next = newNode;
            tmp = tmp->next;
            mp[1]--;
        }
        
        while(mp[2] != 0){
            Node* newNode = new Node(2);
            tmp->next = newNode;
            tmp = tmp->next;
            mp[2]--;
        }
    
        return  dummy->next;
    }
    
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends