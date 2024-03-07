class Solution {
  public:
    string longestSubstring(string s, int n) 
    {
        int i = 0;
        int j = 0;
        string ans = "-1";
        int size =0;
        while(i<n && j<n)
        {
            string str = s.substr(i,(j-i+1));
            if(s.find(str,(j+1)) != string::npos)
            {
                if(str.size()>size)
                {
                    ans = str;
                    size=str.size();
                }
                j++;
            }
            else i++;
        }
    return ans;
    }
};
