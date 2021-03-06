class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if(nums.empty()) return {};
		sort(nums.begin(),nums.end());
		int n=nums.size();
		vector<int> dp(n,1);
		dp[0]=1;
		vector<int> memo(n,-1);
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(nums[i]%nums[j]==0)
				{
					if(dp[j]+1>dp[i])
					{
						dp[i]=dp[j]+1;
						memo[i]=j;
					}
				}
			}
		}

		int idx=-1;
		int max=0;
		for(int i=0;i<dp.size();i++)
		{
			if(dp[i]>max)
			{
				max=dp[i];
				idx=i;
			}
		}

		vector<int> ans;

		while(idx>=0)
		{
			ans.push_back(nums[idx]);
			idx=memo[idx];
		}
		return ans;  
	}
};
