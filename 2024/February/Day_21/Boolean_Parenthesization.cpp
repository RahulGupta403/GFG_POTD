class Solution{
public:
    int dp[201][201][2]; //Cache matrix for fast response, 3D Matrix = Nightmare  
    int helper(string &s, int i, int j, bool isTrue){
        if(i > j) return 0; //If there are no elements then return 0
        //If subproblem is already calculated then return from there
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        //Base case, if there is only one element
        if(i == j){
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        int ans = 0;
        // All possibilities for getting true and false as well
        for(int k=i+1;k<=j-1;k+=2){
            int LT = helper(s, i, k-1, true);
            int LF = helper(s, i, k-1, false);
            int RT = helper(s, k+1, j, true);
            int RF = helper(s, k+1, j, false);
            if(s[k] == '&'){
                if(isTrue) ans += LT*RT; //'AND' operation for getting 'True' as answer
                else ans += LF*RF + LF*RT + LT*RF; //'AND' operation for getting 'False' as answer
            }
            else if(s[k] == '|'){
                if(isTrue) ans += LT*RT + LT*RF + LF*RT; //'OR' operation for getting 'True' as answer
                else ans += LF*RF; //'OR' operation for getting 'False' as answer
            }
            else if(s[k] = '^'){
                if(isTrue) ans += LT*RF + LF*RT; //'XOR' operation for getting 'True' as answer
                else ans += LT*RT + LF*RF; //'XOR' operation for getting 'False' as answer
            }
        }
    return dp[i][j][isTrue] = ans%1003; //Store and return  the answer
    }
    int countWays(int N, string S){
        memset(dp, -1, sizeof(dp)); //Initialize matrix with '-1'
        return helper(S,0,N-1,true)%1003;
    }
};
