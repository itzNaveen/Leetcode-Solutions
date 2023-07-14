//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
    // Declare a vector to store the elements
    vector<int> arr;
    // Declare variables to track the top indices of both stacks
    int top1, top2;
    
public:
    // Constructor to initialize the class
    twoStacks(int n = 100) {
        // Resize the vector to accommodate 'n' elements
        arr.resize(n);
        // Initialize top indices of both stacks
        top1 = -1;
        top2 = n;
    }

    // Function to push an element into stack1
    void push1(int x) {
        // Check if there is space available to push the element
        if (top1 + 1 < top2) {
            // Increment top1 and add the element to the vector
            arr[++top1] = x;
        }
    }

    // Function to push an element into stack2
    void push2(int x) {
        // Check if there is space available to push the element
        if (top2 - 1 > top1) {
            // Decrement top2 and add the element to the vector
            arr[--top2] = x;
        }
    }

    // Function to remove and return the top element of stack1
    int pop1() {
        // Check if stack1 is not empty
        if (top1 != -1) {
            // Return the element at top1 and decrement top1
            return arr[top1--];
        }
        // If stack1 is empty, return -1 (indicating underflow)
        return -1;
    }

    // Function to remove and return the top element of stack2
    int pop2() {
        // Check if stack2 is not empty
        if (top2 != arr.size()) {
            // Return the element at top2 and increment top2
            return arr[top2++];
        }
        // If stack2 is empty, return -1 (indicating underflow)
        return -1;
    }
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends