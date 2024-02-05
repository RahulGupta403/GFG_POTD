class Solution
{
    public:
    Node *sortedInsert(Node* head, int data){
        Node* temp=new Node(data);
        Node* curr=head;
        // Case 1. When there is no node and the inserted node is the new node
        if(head==NULL)
        {
            temp->next=temp;
            return temp;
        }
        //Case 2. When insertion is done before first node in circular LL
        else if(head->data>data)
        {
            while(curr->next!=head)
            {
                curr=curr->next;
            }
            curr->next=temp;
            temp->next=head;
            return temp;
        }
        //Case 3. When insertion is done anywhere between the circular LL
        else
        {
            while((curr->next->data < data) and (curr->next!=head))
            {
               curr=curr->next;
            }
            temp->next=curr->next;
            curr->next=temp;
            return head;
        }
    }
};
