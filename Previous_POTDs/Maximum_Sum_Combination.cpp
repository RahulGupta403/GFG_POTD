class Solution {
  public:
    typedef pair<int,int> pi;
    typedef pair<int,pair<int,int>> ppi;
    vector<int> maxCombinations(int n,int k,vector<int>&arr,vector<int> &brr){
        vector<int> ans;
        set<pi> set;
        priority_queue<ppi>pq;
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        pq.push({arr[n-1]+brr[n-1],{n-1,n-1}});
        set.insert({n-1,n-1});
        while(k--){
            ppi temp=pq.top();
            int sum=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            ans.push_back(sum);
            pq.pop();
            if(set.find({x-1,y})==set.end()){
                pq.push({arr[x-1]+brr[y],{x-1,y}});
                set.insert({x-1,y});
            }
            if(set.find({x,y-1})==set.end()){
                pq.push({arr[x]+brr[y-1],{x,y-1}});
                set.insert({x,y-1});
            }
        }
    return ans;
    }
};
