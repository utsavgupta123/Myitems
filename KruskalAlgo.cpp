int totalcost = 0;
sort(edges.begin(), edges.end());
for (int i = 0; i < edges.size(); i++)
{
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    ll wt = edges[i].first;
    if (find(u) == find(v))
        continue;
    Union(u, v);
    totalcost += wt;
}