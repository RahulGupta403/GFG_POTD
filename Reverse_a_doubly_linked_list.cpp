class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        if(head==NULL){
            return NULL;
        }
        Node* currentNode=head;
        Node* nextNode=NULL;
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        while(currentNode!=NULL){
            nextNode=currentNode->next;
            currentNode->next=currentNode->prev;
            currentNode->prev=nextNode;
            currentNode=nextNode;
        }
        currentNode=head;
        head=tail;
        tail=currentNode;
        return head;
    }
};
