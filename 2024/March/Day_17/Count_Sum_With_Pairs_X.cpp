class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        vector<int> ans1,ans2;
        Node* temp=head1;
        while(temp){
            ans1.push_back(temp->data);
            temp=temp->next;
        }
        temp=head2;
        while(temp){
            ans2.push_back(temp->data);
            temp=temp->next;
        }
        sort(begin(ans1),end(ans1));
        sort(begin(ans2),end(ans2));
        int cnt=0;
        for(int i=0;i<ans1.size();i++){
            int res=x-ans1[i];
            if(binary_search(ans2.begin(),ans2.end(),res)){
                cnt++;
            }
        }
    return cnt;
    }
};
