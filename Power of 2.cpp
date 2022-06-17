// modulo
int res = 0, mod = 1000000007;
vector<int> pre = {0, 1};
for (auto i = pre.size(); i <= nums.size(); ++i)
    pre.push_back((pre.back() << 1) % mod);