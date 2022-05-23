int INF=1e9+10;
int N=510;
int dist[N][N];

int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)dist[i][j]=0;
            else
            {
                dist[i][j]=INF;
            }
        }
    }

    //We will intiallize the distance of i->j as given in the input

    //Algo

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF)          //CHECK FOR -VE WEIGHTS becuse INF-2<INF but INF path not exists
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}