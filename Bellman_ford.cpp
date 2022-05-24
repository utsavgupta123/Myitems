    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V);
        for(int i=0;i<V;i++)dist[i]=1e8;
        dist[S]=0;
        for(int i=1;i<=V-1;i++)
        {
            for(int j=0;j<adj.size();j++)
            {
                
                    int u=adj[j][0];
                    int v=adj[j][1];
                    int wt=adj[j][2];
                    if(dist[u]!=1e8 && dist[v]>dist[u]+wt)
                    {
                        dist[v]=wt+dist[u];
                    }
                
            }
        }
        return dist;
    }