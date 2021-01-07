#include <stdio.h>
int v,i,x;
int Graph_Coloring(int **graph,int *color,int m)
{
    char ch;
    int u,c;
    color[0]=1;

    for(u=1; u<v; u++)
    {
        color[u]=-1;
    }

    for(u=1; u<v; u++)
    {

        for(c = 1 ; c <= m ; c++)
        {

            for(x=0; x<v; x++)
            {
                color[u]=c;
                if(graph[u][x]==1 && (color[x] == c))
                {
                    color[u]=-1;
                    break;
                }

            }
            if(color[u] != -1)
            {
                break;
            }
        }
        if(color[u]==-1)
        {
            return 0;
        }
        if(u == v-1)
        {
            Display_solution(color);
            return 1;
        }
    }

}
void Display_solution(int *color)
{
    printf("the solution is the following :\n");
    for(i=0; i<v; i++)
    {
        printf("%d->%d \n",i+1,color[i]);
    }
}




int main()
{

    int *color,value, m,check,**graph;

    printf("Enter  number of vertices : \n");
    scanf("%d",&v);
    printf("Enter  number of colors : \n");
    scanf("%d",&m);
    graph=(int**)malloc(v*sizeof(int*));
    for(i=0; i<v; i++)
        graph[i]=(int*)malloc(v*sizeof(int));
    for(i=0; i<v; i++)
    {
        for(x=0; x<v; x++)
        {
            if(x==i)
                graph[i][x] = 0;
            if(i<x)
            {
                check=1;
                while(check)
                {

                    printf("Is vertix No. %d adjacent to vertix No. %d & vertix No. %d adjacent to vertix No. %d ? Enter 1 if adjacent else 0 \n",i+1,x+1,x+1,i+1);
                    scanf("%d",&value);
                    graph[i][x] =  graph[x][i] = value;
                    if(value == 1 || value == 0)
                        check= 0;
                    else
                    {
                        printf("\n Invalid input , please enter 1 if adjacent else 0\n");
                        check=1;
                    }
                }
            }
        }
    }
    color=(int*)malloc(m*sizeof(int));

    if(!Graph_Coloring(graph,color,m))
    {
        printf(" \nNo solution exist\n");

    }
    system("pause");
    return 0;
}

