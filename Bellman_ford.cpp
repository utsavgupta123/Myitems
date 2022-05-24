int INF=1e9+10;
int N=510;
int dist[N];

int main()
{
    for(int i=0;i<V;i++) dist[i][j]=INF;
    for(int i=1;i<=V-1;i++)
        {
            for(int j=0;j<E.size();j++)
            {
                int u=E[j][0];
                int v=E[j][1];
                int wt=E[j][2];
                if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt)       //CHECK FOR -VE WEIGHTS becuse INF-2<INF but INF path not exists
                {
                  dist[v]=wt+dist[u];
                }
            }
        }
}