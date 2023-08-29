//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    Node *Reverse(Node *head){
        Node *curr = head, *prev = NULL;
        while(curr != NULL){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    public:
    Node *compute(Node *head)
    {
        if(!head || !head->next) return head;
        head = Reverse(head);
        Node *curr = head;
        int maxValue = head->data;
        Node *prev = head;
        curr = curr->next;
        while(curr){
            if(curr->data >= maxValue){
                maxValue = curr->data;
                prev = curr;
                curr = curr->next;
            }
            else{
                prev->next = curr->next;
                curr = prev->next;
            }
        }
        return Reverse(head);
    }
    
};
   



//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends