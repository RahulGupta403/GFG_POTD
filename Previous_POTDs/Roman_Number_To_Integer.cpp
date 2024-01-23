//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // Approach - 01 (Basic Map)
        int n=str.size();
        map<char,int> map;
        map.insert({'I',1});
        map.insert({'V',5});
        map.insert({'X',10});
        map.insert({'L',50});
        map.insert({'C',100});
        map.insert({'D',500});
        map.insert({'M',1000});
        
        if(str.size()==1){
            char ch=str[0];
            return map[ch];
        }
        int ans=map[str[n-1]];
        for(int i=n-2;i>=0;i--){
            if(map[str[i]]>=map[str[i+1]]){
                ans+=map[str[i]];
            }else{
                ans-=map[str[i]];
            }
        }
        return ans;






        // Approach - 02 (Unordered_Map)
  
       unordered_map<char,int> umap{
          {'M',1000},
          {'D',500},
          {'C',100},
          {'L',50},
          {'X',10},
          {'V',5},
          {'I',1},
      };
      int answer=0;
      for(int i=0;i<size(s);i++){
          if(umap[s[i]]<umap[s[i+1]]){
              answer-=umap[s[i]];
          }
          else{
              answer+=umap[s[i]];
          }
      }
      return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
