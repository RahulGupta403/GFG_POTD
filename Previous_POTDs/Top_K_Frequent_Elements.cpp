//Min Heap Code Implementation
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto it=map.begin();it!=map.end();it++){
            pq.push({it->second,it->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//Max Heap Code Implementation
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto &it: map){
            pq.push({it.second,it.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
