//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here
        int n = s.size(), j = 0;
        unordered_map<char, int> mp;
        int len = -1;
        for (int i = 0; i < n; ++i)
        {
            mp[s[i]]++;
            if (mp.size() > k)
            {
                while (j < n && mp.size() > k)
                {
                    mp[s[j]]--;
                    if (mp[s[j]] == 0)
                    {
                        mp.erase(s[j]);
                    }
                    j++;
                }
            }
            if (mp.size() == k)
                len = max(len, i - j + 1);
        }

        return len;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends