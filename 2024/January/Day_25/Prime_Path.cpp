void sieve(vector<int> &primes){
        for(int i=2; i<=9999; i++){
            if(primes[i] != 0)  continue;
            for(int j=i; j<=9999; j+=i){
                primes[j] = i;
            }
        }
    }
    
    int get_int(string temp){
        int ans = 0;
        for(int i = 0; i<4; i++){
            ans = ans*10 + (temp[i] - '0');
        }
        
        return ans;
    }
    
    string get_string(int temp){
        string ans = "";
        int cnt = 0;
        while(cnt < 4){
            int rem = temp%10;
            ans += (rem + '0');
            temp/=10;
            
            cnt++;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    
    int f(int start, int end, vector<int>&primes){
        priority_queue< pair<int, int>, vector<pair<int, int>>  , greater<pair<int,int>> > pq;
        
        vector<int>dist(9999+1, 1e9);
        
        pq.push({0, start});
        while(!pq.empty()){
            auto front = pq.top();
            int cur = front.second;
            if(cur == end) return front.first;
            pq.pop();
            
            //can change in any index to any value
            string state = get_string(cur);
            
            for(int ind = 0; ind<4; ind++){
                char prev = state[ind];
                for(int num = 0; num<=9; num++){
                    if(ind == 0 && num == 0) continue;
                    state[ind] = (num+'0');
                    int next = get_int(state);
                    if(next == cur) continue;
                    if(primes[next] != next) continue;
                    
                    //dijkstra logic
                    if(dist[next] > front.first+1){
                        dist[next] = front.first+1;
                        pq.push({front.first+1, get_int(state)});
                        
                    }
                    
                    
                    
                }
                state[ind] = prev; //for backtracking
            }
            
               
        }
        
        return -1;
    }
    
    

    int solve(int Num1,int Num2)
    {   
      //code here
      
        vector<int>primes(9999+1, 0);
        sieve(primes);
        int ans = f(Num1, Num2, primes);
        return ans;
    }
