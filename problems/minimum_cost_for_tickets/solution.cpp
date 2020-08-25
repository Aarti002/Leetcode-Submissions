class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> s(begin(days),end(days));
        vector<int> dp(days.back()+1);
        dp[0]=0;
        for(int i=1;i<=days.back();i++)
        {
            if(s.find(i)==s.end())
                dp[i]=dp[i-1];
            else
                dp[i]=min({costs[0]+dp[i-1],dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]});
        }
        return dp[days.back()];
    }
}; 