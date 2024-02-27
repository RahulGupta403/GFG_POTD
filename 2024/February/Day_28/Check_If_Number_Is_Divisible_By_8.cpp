class Solution{
    public:
    int DivisibleByEight(string s){
        int n=s.size();
        int ch;
        if(n<3){
            ch=stoi(s);
        }
        else if(n>=3){
            string sub=s.substr(n-3,3);
            ch=stoi(sub);
        }
        if(ch%8==0){
            return 1;
        }
        return -1;
    }
};
