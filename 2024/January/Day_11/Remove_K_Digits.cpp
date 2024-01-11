class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char>st;
        for(int i = 0; i < S.size(); ++i){
            while(!st.empty() && K && (st.top() > S[i])){
               st.pop();
               --K; 
            }    
            if((S[i] != '0') || !st.empty()){
                st.push(S[i]);
            }
        }
        while(!st.empty() && K--){
              st.pop();  
        }
        string num = "";
        while(!st.empty()){
            num.push_back(st.top());
            st.pop();
        }
        reverse(num.begin(), num.end());
        if(num == ""){
            return "0";
        }
        return num;
    }
};
