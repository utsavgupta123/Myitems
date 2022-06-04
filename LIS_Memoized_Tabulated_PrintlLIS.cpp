int solve(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &dp)
{
    if (idx == nums.size())
        return 0;
    if (dp[idx][prev_idx + 1] != -1)
        return dp[idx][prev_idx + 1];
    int notpick = solve(idx + 1, prev_idx, nums, dp);
    int pick = 0;
    if (prev_idx == -1 || nums[idx] > nums[prev_idx])
        pick = 1 + solve(idx + 1, idx, nums, dp);
    return dp[idx][prev_idx + 1] = max(pick, notpick);
}
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,1));
        // return solve(0,-1,nums,dp);
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        int maxi = 1;
        int lastindex = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastindex = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastindex]);
        while (hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
            cout << it << " ";

        cout << endl;
        return maxi;
    }
};

// O(nlogn)
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> v;
        int len = 1;
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > v.back())
            {
                len++;
                v.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[idx] = nums[i];
            }
        }
        return len;
    }
};