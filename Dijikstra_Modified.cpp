int INF = 1e9 + 10;
int dijikstra(int source, vector<vector<pair<int, int>>> &g, int N)
{
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>> st;
    st.push({0, source}); // wt,node
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = st.top();
        int curr_v = node.second;
        int curr_wt = -1 * node.first;
        st.pop();

        if (curr_wt != dist[curr_v])
            continue;

        for (auto child : g[curr_v])
        {
            int child_v = child.first;
            int child_wt = child.second;
            if (dist[child_v] > child_wt + dist[curr_v])
            {
                dist[child_v] = child_wt + dist[curr_v];
                st.push({-1 * dist[child_v], child_v});
            }
        }
    }
}