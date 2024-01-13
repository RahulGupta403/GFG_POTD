// Brute Force Approach
class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        vector<int> ans;
        Node* temp=head;
        while(temp){
            ans.push_back(temp->data);
            temp=temp->next;
        }
        temp=head;
        sort(begin(ans),end(ans));
        int i=0;
        while(temp){
            temp->data=ans[i++];
            temp=temp->next;
        }
    return head;
    }
};


// Optimal Approach
class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        Node* dummy=new Node(100);
        while(head){
            Node* nextt=head->next;
            Node* temp=dummy;
            while(temp->next and temp->next->data<head->data){
                temp=temp->next;
            }
            head->next=temp->next;
            temp->next=head;
            head=nextt;
        }
    return dummy->next;
    }
};
