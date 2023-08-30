//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteNode(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T, i, n, l;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head = deleteNode(head,kk);
    printList(head);
    }
    return 0;
}

// } Driver Code Ends




/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    Node *temp, *ptr;
    int count = 0;
     if(!head)
    {
        return (NULL);
    }
    
    // delete first node
    if (x == 1)
    {
        temp = head;
        head = temp -> next;
        free(temp);
        return (head);
    }
    
    // find length of the list
    while(temp)
    {
        count++;
        temp = temp -> next;
    }
    
    // delete last node
    if (x == count)
    {
        temp = head;
        while(temp -> next -> next)
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
    
    // delete intermediate nodes
    else
    {
        temp = head;
        
        for(count = 1; count < x - 1; count++)
        {
            temp = temp -> next;
        }
        ptr = temp -> next -> next;
        free(temp -> next);
        temp -> next = ptr;
    }
    
    return (head);
}
