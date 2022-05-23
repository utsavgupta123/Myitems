int INF=1e9+10;
void dijikstra(int source ,vector<vector<pair<int,int>>>&g)
{
    vector<int>vis(N,0);
    vector<int>dist(N,INF);
    set<pair<int,int>>s;
    s.insert({0,source});   //wt,node
    dist[source]=0;
    
    while(s.size()>0)
    {
        auto node=*st.begin();
        int curr_n=node.second;
        int curr_wt=node.first;
        if(vis[curr_v]==1)continue;
        vis[curr_v]=1;

        for(auto child:g[curr_n])
        {
            int child_v=child.first;
            int child_wt=child.second;
            if(dist[child_v]>child_wt+dist[curr_v])
            {
                dist[child_v]=wt+dist[curr_v];
                s.insert({dist[child_v],child_v});
            }
        }
    }
}