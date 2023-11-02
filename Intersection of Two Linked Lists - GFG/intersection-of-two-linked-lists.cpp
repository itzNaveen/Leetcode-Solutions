//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        if(!head1 || !head2) return NULL;
        Node* d = new Node(-1);
        Node* dd = NULL;
        map<int,int>mpp;
        Node* node2 = head2;
        while(node2 != NULL){
            mpp[node2->data]++;
            node2 = node2->next;
        }
        Node* node1 = head1;
        while(node1 != NULL){
            if(mpp[node1->data]){
                Node* node = new Node(node1->data);
                if(dd == NULL){
                    d->next = node;
                    dd = node;
                }else{
                    dd->next = node;
                    dd = node;
                }
            }
            node1 = node1->next;
        }
        return d->next;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends