class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1==str2){
            return false;
        }
        int n=str1.length();
        int m=str2.length();
        if(n!=m){
            return false;
        }
        // Used to check string rotation
        // string temp=str1+str1;
        // return temp.find(str2)!=string::npos;
        
        string temp="";
        for(int i=0;i<n-2;i++){
            temp+=str1[i];
        }
        string res="";
        for(int i=n-2;i<n;i++){
            res+=str1[i];
        }
        temp=res+temp;
        // cout<<temp<<" "<<str2<<endl;
        if(temp==str2){
            return true;
        }
        temp="";
        for(int i=n-2;i<n;i++){
            temp+=str2[i];
        }
        res="";
        for(int i=0;i<n-2;i++){
            res+=str2[i];
        }
        temp+=res;
        // cout<<temp<<" "<<str2<<endl;
        if(temp==str1){
            return true;
        }
        return false;
    }
};

















// Approach -02 Using Substr function
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1==str2){
            return false;
        }
        if(str1.length()!=str2.length()){
            return false;
        }
        int n=str1.length();
        string temp=str1.substr(2,n)+str1.substr(0,2);
        if(temp==str2){
            return true;
        }
        temp=str2.substr(2,n)+str2.substr(0,2);
        if(temp==str1){
            return true;
        }
        return false;
    }
};
