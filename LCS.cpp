int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
    {
        return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
    }
    return dp[i][j] = max(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));
}

class Solution
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solve(n,m,s1,s2,dp);
        vector<int> prev(m + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            vector<int> curr(m + 1, 0);
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    curr[j] = 0;
                }

                else
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        curr[j] = 1 + prev[j - 1];
                    }
                    else
                        curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[m];

        // PRINT LCS
        int len = prev[m];
        string lcs = "";
        for (int i = 0; i < len; i++)
            lcs += '#';
        int indx = len - 1;
        int i = n - 1;
        int j = m - 1;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                lcs[indx] = s1[i - 1];
                indx--;
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        cout << lcs;
    }
};