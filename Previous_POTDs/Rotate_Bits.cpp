#include<bits/stdc++.h>
using namespace std;
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            int left_rotation,right_rotation;
            d = d%16;
            left_rotation=(n<<d|(n>>(16-d)))&65535;
            right_rotation=(n>>d|(n<<(16-d)))&65535;
            return {left_rotation,right_rotation};
        }
};
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
