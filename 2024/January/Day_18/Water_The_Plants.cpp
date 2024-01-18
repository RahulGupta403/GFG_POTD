//OPTIMIZED
class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> spk;
        for(int i=0;i<n;i++)
        {
            if(gallery[i]!=-1)
            spk.push_back({ max(0, i-gallery[i]), min(n-1, i+gallery[i])});
        }
        
        sort(spk.begin(),spk.end());
        
        
        int start=0;
        int i=0;
        int ans=0;
        
        while(start<n)
        {
            int maxr=-1e9;
            while(i<spk.size())
            {
                if(spk[i].first>start)
                break;
                
                maxr=max(maxr,spk[i].second);
                i++;
            }
            
            if(maxr<start)
            return -1;
            
            ans++;
            start=maxr+1;
        }
        
        return ans;
    }
};
