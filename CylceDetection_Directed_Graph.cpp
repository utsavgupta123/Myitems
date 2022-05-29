// DFS

bool cycle(int src, vector<int> adj[], vector<int> &dfsvis, vector<bool> &vis)
{
    vis[src] = true;
    dfsvis[src] = true; // current path mae daal rhe

    for (auto ne : adj[src])
    {
        if (!vis[ne])
        {
            if (cycle(ne, adj, dfsvis, vis))
                return true;
        }
        else if (dfsvis[ne])
        {
            return true;
        }
    }
    dfsvis[src] = false; // current path se nikal rhe
    return false;
}

// BFS
// apply khans algp and see if toposort.size()!=V return true cycle present else return false
