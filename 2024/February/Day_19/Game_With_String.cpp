class Solution{
public:
    int minValue(string s, int k){
        int n=s.size();
        unordered_map<char,int> map;
        priority_queue<int>pq;
        for(auto it:s) map[it]++;
        for(auto it:map) pq.push(it.second);
        while(k--){
            int top=pq.top();
            pq.pop();
            top--;
            if(top==0){
                continue;
            }
            pq.push(top);
        }
        long long int ans=0;
        while(pq.size()){
            int top=pq.top();
            pq.pop();
            ans+=(top*top);
        }
    return ans;
    }
};
