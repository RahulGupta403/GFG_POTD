class Solution
{
    public:
    void insertattail(Node* &head,Node* &tail,int val){
        Node* temp=new Node(val);
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            tail->next=temp;
            tail=temp;
        }
    }
    Node* findIntersection(Node* head1, Node* head2)
    {
        if(head1==NULL or head2==NULL){
            return NULL;
        }
        Node* temp1=head1;
        Node* temp2=head2;
        Node* newHead=NULL;
        Node* newTail=NULL;
        while(temp1 and temp2){
            if(temp1->data>temp2->data){
                temp2=temp2->next;
            }
            else if(temp1->data<temp2->data){
                temp1=temp1->next;
            }else{
                insertattail(newHead,newTail,temp1->data);
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
    return newHead;
    }
};
