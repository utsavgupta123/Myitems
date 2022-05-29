vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto ne : adj[i])
        {
            indegree[ne]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (q.size() > 0)
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for (auto ne : adj[curr])
        {
            indegree[ne]--;
            if (indegree[ne] == 0)
                q.push(ne);
        }
    }
    return ans;
}