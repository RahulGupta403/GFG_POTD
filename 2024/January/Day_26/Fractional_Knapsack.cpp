//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static comp(pair<double,double>&a,pair<double,double>&b){
        double ans1=(a.first)/(a.second);
        double ans2=(b.first)/(b.second);
        return ans1>ans2;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        double ans=0.0;
        vector<pair<double,double>> pair;
        for(int i=0;i<n;i++){
            pair.push_back({arr[i].value,arr[i].weight});
        }
        sort(begin(pair),end(pair),comp);
        for(int i=0;i<n;i++){
            if(pair[i].second<=w){
                ans+=pair[i].first;
                w-=pair[i].second;
            }
            else{
                ans+=pair[i].first*((double)w/pair[i].second);
                break;
            }
        }
    return ans;
    }        
};
