class Solution
{
    public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list 
    #define ll long long unsigned int
    #define mod 1000000007
    Node* reverse(Node* head){
        Node* current=head;
        Node* prevnode=NULL;
        Node* nextnode=NULL;
        while(current){
            nextnode=current->next;
            current->next=prevnode;
            prevnode=current;
            current=nextnode;
        }
    return prevnode;
    }
    ll power(ll a,ll b){
        if(a==0){
            return 0*1LL;
        }
        if(b==0){
            return 1*1LL;
        }
        ll ans=power(a,b/2)%mod;
        if(b%2==0){
            return (ans*ans)%mod;
        }
        else{
            return (ans*ans*a)%mod;
        }
    }
    long long unsigned int decimalValue(Node *head)
    {
       head=reverse(head);
       ll ans=0;
       ll count=0;
       Node* temp=head;
       while(temp){
           ans=(ans+((temp->data)*power(2,count))%mod)%mod;
           count++;
           temp=temp->next;
       }
    return 1LL*ans%mod;
    }
};
