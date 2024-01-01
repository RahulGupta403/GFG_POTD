class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n=nums.size();
        if(n%2==1){
            return false;
        }
        unordered_set<int>set;
        for(int i=0;i<n;i++){
            int rem1=(nums[i]%k);
            if(set.find(k-rem1)!=set.end())
                set.erase(k-rem1);
            else if(rem1==0 && set.find(0)!=set.end())
                set.erase(0);
            else
                set.insert(nums[i]%k);
        }
    return set.size()==0;
    }
};
