class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        for(char ch='a';ch<='z';ch++){
            auto found=s.find(ch);
            if(found==string::npos){
                return false;
            }
        }
    return true;
    }
};
