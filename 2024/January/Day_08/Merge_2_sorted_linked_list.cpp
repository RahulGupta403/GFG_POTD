//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* previous = NULL;   
        Node* current = head;  
     
        while (current != NULL)
        {
            
            Node* next = current->next;
            current->next = previous;    
     
            previous = current;
            current = next;
        }
     
        head = previous;
        return head;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        node1=reverse(node1);
        node2=reverse(node2);
        
        Node* head=NULL;
        Node* tail=NULL;
        
        while(node1 and node2)
        {
            if(node1->data>node2->data)
            {
                Node* newnode=newNode(node1->data);
                if(!head)
                {
                    head=newnode;
                    tail=newnode;
                }
                else
                {
                    tail->next=newnode;
                    tail=newnode;
                }
                node1=node1->next;
            }
            else
            {
                Node* newnode=newNode(node2->data);
                if(!head)
                {
                    head=newnode;
                    tail=newnode;
                }
                else
                {
                    tail->next=newnode;
                    tail=newnode;
                }
                node2=node2->next;
            }
        }
        
        while(node1)
        {
            Node* newnode=newNode(node1->data);
            if(!head)
            {
                head=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            node1=node1->next;
        }
        
        while(node2)
        {
            Node* newnode=newNode(node2->data);
            if(!head)
            {
                head=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            node2=node2->next;
        }
        
        return head;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}




// Easy Approach
class Solution
{
    public:
    struct Node* reverse(Node* head){
        struct Node* current=head;
        struct Node* nextt=NULL;
        struct Node* prev=NULL;
        while(current){
            nextt=current->next;
            current->next=prev;
            prev=current;
            current=nextt;
        }
    return prev;
    }
    struct Node* Merge(Node* head1,Node* head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        if(head1->data<=head2->data){
            head1->next=Merge(head1->next,head2);
            return head1;
        }else{
            head2->next=Merge(head1,head2->next);
            return head2;
        }
    }
    struct Node *mergeResult(Node *head1,Node *head2)
    {
        struct Node* head=Merge(head1,head2);
        head=reverse(head);
        return head;
    }
};
