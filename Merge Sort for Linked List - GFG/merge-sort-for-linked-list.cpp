//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  private:
    Node *getMid(Node *head){
        Node *slow = head, *fast = head->next;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node *merge(Node *first, Node *second){
        if(!first) return second;
        if(!second) return first;
        if(first->data <= second->data){
            first->next = merge(first->next,second);
            return first;
        }
        else{
            second->next = merge(second->next,first);
            return second;
        }
    }
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        Node* mid = getMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        
        //Sorting
        left = mergeSort(left);
        right = mergeSort(right);
        
        // Merge and return
        return merge(left,right);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends