// Steps to write MCM DP-> Use it when we have different ways to solve problem and all giving differet answers.

// 1-Start with entire block/array.Mark them by i(start point) and j(endpoint).
// 2-Try all patition   (For loop to try all partitions)
// 3-Return best possible 2 partitions(sunproblem).
// 4-Write base case (ask minimum ex i==j)

// Code(PARTIONING)->TC->O(N^3)
#include <bits/stdc++.h>
bool ispalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(int i, string &s, vector<int> &dp)
{
    if (i == s.size())
        return 0;
    int mini = INT_MAX;
    if (dp[i] != -1)
        return dp[i];
    for (int j = i; j < s.size(); j++)
    {
        if (ispalindrome(i, j, s))
        {
            int cost = 1 + solve(j + 1, s, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}

int minimumCuts(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    // return solve(0,s,dp)-1;
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int mini = 1e9;
        for (int j = i; j < s.size(); j++)
        {
            if (ispalindrome(i, j, s))
            {
                int cost = 1 + dp[j + 1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }
    return dp[0] - 1;
}
