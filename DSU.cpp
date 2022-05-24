int N=1e5;
int parent[N];
int size[N];
    
void make(int u)
{
    parent[u]=u;
    size[u]=1;
}

int find(int u)
{
    if(parent[u]==u)return u;
    return parent[u]=find(parent[u]);
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {
        if(size[a]<size[b])swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)make(i);
}