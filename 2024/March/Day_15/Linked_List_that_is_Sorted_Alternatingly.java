class Solution {    
   public Node sort(Node head){
        if(head==null || head.next==null){
            return head;
        }
        Node temp=head;
        ArrayList<Integer> ans = new ArrayList<>();
        while(temp!=null){
            ans.add(temp.data);
            temp=temp.next;
        }
        ArrayList<Integer> ans1 = new ArrayList<>();
        for(int i=0;i<ans.size();i+=2){
            ans1.add(ans.get(i));
        }
        ArrayList<Integer> ans2 = new ArrayList<>();
        for(int i=1;i<ans.size();i+=2){
            ans2.add(ans.get(i));
        }
        Collections.reverse(ans2);
        temp=head;
        for(int i=0;i<ans1.size();i++){
            temp.data=ans1.get(i);
            temp=temp.next;
        }
        for(int i=0;i<ans2.size();i++){
            temp.data=ans2.get(i);
            temp=temp.next;
        }
    return head;
   }
}
