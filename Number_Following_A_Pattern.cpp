class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n=s.size();
        string ans="";
        string D="1";
        int count=1;
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                count++;
                D=to_string(count)+D;
            }else{
                ans+=D;
                count++;
                D=to_string(count);
            }
        }
        ans+=D;
        return ans;
    }
};
