//Approach-01
// Brute But Accepted Approach
class Solution {
  public:
    int singleElement(int arr[] ,int n) {
        // code here
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        for(auto &it:map){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};


// Approach-02 (Optimal Approach)
class Solution {
  public:
    int singleElement(int arr[] ,int N)
    {
        int res=0;
        for(int i=0;i<32;i++)
        {
            int setbit=0;
            for(int j=0;j<N;j++)
            {
                if((arr[j]&(1<<i))!=0)
                setbit++;
            }
            if((setbit%3)==1)
            res=res|(1<<i);
        }
    return res;
    }
};
