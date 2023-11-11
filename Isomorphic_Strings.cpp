class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        unordered_map<char,int>map1,map2;
        if(str1==str2){
            return true;
        }
        if(str1.length()!=str2.length()){
            return false;
        }
        int n=str1.length();
        for(int i=0;i<n;i++){
            if(map1[str1[i]]!=map2[str2[i]]){
                return false;
            }else{
                map1[str1[i]]=i+1;
                map2[str2[i]]=i+1;
            }
        }
    return true;
    }
};
