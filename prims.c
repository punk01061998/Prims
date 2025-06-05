#include<stdio.h>
int prims(int n,int mincost,int cost[10][10])
{
    int ne=1;
    int x,y;
    int selected[10]={0};
    selected[0]=1;
    while(ne<n)
    {
        int min=999;
        x=0;
        y=0;
        for(int i=0;i<n;i++)
        {
            if(selected[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!selected[j]&&cost[i][j])
                    {
                        if(min>cost[i][j])
                        {
                            min=cost[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        printf("%d-%d:%d\n",x,y,cost[x][y]);
        selected[y]=1;
        mincost+=cost[x][y];
        ne++;
    }
    return mincost;
}

int main()
{
    int n,mincost=0,i,j,cost[10][10];
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    mincost=prims(n,mincost,cost);
    printf("The minimum spanning cost tree is:%d",mincost);
    return 0;
}