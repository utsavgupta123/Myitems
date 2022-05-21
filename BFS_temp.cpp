void BFS(int source,vector<vector<int>>&g)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;
    level[source]=1;
    while(q.size()>0)
    {
        int curr_v=q.front();
        q.pop();
        for(auto child:g[curr_v])
        {
            if(!vis[child])
            {
                vis[child]=1;
                level[child]=1+level[curr_v];
                q.push(child);

            }
        }
    }

}