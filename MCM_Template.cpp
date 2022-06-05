// Steps to write MCM DP-> Use it when we have different ways to solve problem and all giving differet answers.

// 1-Start with entire block/array.Mark them by i(start point) and j(endpoint).
// 2-Try all patition   (For loop to try all partitions)
// 3-Return best possible 2 partitions(sunproblem).
// 4-Write base case (ask minimum ex i==j)

// Code(MCM)->TC->O(N^3)

int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0; // single matrix (i-1) _A_(j+1)
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 1e9;
    for (int k = i; k < j; k++)
    {
        int v = arr[i - 1] * arr[k] * arr[j];                      // cost of this partition
        int cst = solve(i, k, arr, dp) + solve(k + 1, j, arr, dp); // solve for left right partition
        ans = min(ans, v + cst);
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // return solve(1,N-1,arr,dp); // returns the min multiplications from matrix 1->matrix N-1
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i; j < N; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                int ans = 1e9;
                for (int k = i; k < j; k++)
                {
                    int v = arr[i - 1] * arr[k] * arr[j]; // cost of this partition
                    int cst = dp[i][k] + dp[k + 1][j];    // solve for left right partition
                    ans = min(ans, v + cst);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[1][N - 1];
}