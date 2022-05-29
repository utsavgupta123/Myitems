void topo_sort(int src, vector<bool> &vis, stack<int> &s, vector<int> g[])
{
    vis[src] = true;
    for (auto ne : g[src])
    {
        if (!vis[ne])
        {
            topo_sort(ne, vis, s, g);
        }
    }
    s.push(src);
    return;
}

// run this function for each node