// You can use the template for binary search similar to Solution-II for many binary search problems. It might be confusing looking at various binary search problems and knowing -

// If we must use L < R or L <= R as the loop condition,
// If we must do L = mid or L = mid+1 and R = mid or R = mid-1,
// If we should return L or R at the end of loop.
// I usually follow these steps in most cases -

// Initialize [L, R] to cover your search space and use L <= R condition since answer may lie anywhere in the whole range.

// You may use extra variable ans initialized to a value based on which condition in code marks your potential answer. Then you can use something similar to -

while (L <= R)
{
    mid = L + ((R - L) >> 1); // avoiding overflow
    if (condition(mid))
    {
        L = mid + 1;
        // ans = mid;            // <-  use when satisfaction of condition denotes a possible answer
    }
    else
    {
        R = mid - 1;
        // ans = mid;            // <-  use when condition not satisfied denotes a possible answer
    }
}
return ans;

// LOWER_BOUND

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int ans = nums.size();
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};