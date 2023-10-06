//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
   };

*/
class Solution
{
    public:
struct Node* reverse(struct Node *node){
        struct Node *prev = nullptr;
        while(node){
            Node *temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return (prev);
    }
    
    void assign(struct Node *n1,struct Node *n2){
        while(n1->next) n1 = n1->next;
        n1->next = n2;
    }
    
    void rearrange(struct Node *odd)
    {
        struct Node *n1 = odd,*n2 = odd->next;
        struct Node *even = nullptr;
        while(n1 && n2){
            if(!even) even = n2;
            n1->next = n2->next;
            n2->next = n2->next ? n2->next->next : nullptr;
            n1 = n1->next;
            n2 = n2->next;
        }
        
        even = reverse(even);
        assign(odd,even);
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends
