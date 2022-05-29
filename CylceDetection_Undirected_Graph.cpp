// DFS

bool cycle(int src, int par, vector<int> adj[], vector<bool> &vis)
{
    vis[src] = true;
    bool loopexists = false;
    for (auto ne : adj[src])
    {
        if (!vis[ne])
        {
            loopexists |= cycle(ne, src, adj, vis);
        }
        else if (ne != par)
        {
            return true;
        }
    }
    return loopexists;
}

// BFS

bool cycle(int src, int par, vector<int> adj[], vector<bool> &vis)
{
    queue<pair<int, int>> q;
    q.push({src, par});
    vis[src] = true;
    while (q.size() > 0)
    {
        auto node = q.front();
        q.pop();
        int curr = node.first;
        int par = node.second;
        for (auto ne : adj[curr])
        {
            if (!vis[ne])
            {
                q.push({ne, curr});
                vis[ne] = true;
            }
            else if (ne != par)
            {
                return true;
            }
        }
    }
    return false;
}