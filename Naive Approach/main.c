#include <stdio.h>


int i,V;
int check_Availability(int **graph, int *color)
{

    int  j;

    for( i = 0; i < V; i++)
    {
        for ( j = i + 1; j < V; j++)
        {
            if ( graph[i][j] && color[i] == color[j])
            {
                return 0;
            }
        }
    }
    return 1;
}



int Graph_Coloring(int **graph, int m,int i, int *color)
{

    if (i == V)
    {

        if (check_Availability(graph, color))
        {

            Display_solution(color);
            return 1;
        }
        return 0;
    }
    int j;

    for ( j = 1; j <= m; j++)
    {
        color[i] = j;


        if (Graph_Coloring(
                    graph, m, i + 1, color))
            return 1;

        color[i] = 0;
    }
    return 0;
}

void Display_solution(int *color)
{
     printf("the solution is the following :\n");
    for(i=0; i<V; i++)
    {
        printf("%d->%d \n",i+1,color[i]);
    }
}



int main()
{

    int c,*color,m,x,i,value,check,**graph;

    printf("Enter  number of vertices : \n");
    scanf("%d",&V);
    printf("Enter  number of colors : \n");
    scanf("%d",&m);
    graph=(int**)malloc(V*sizeof(int*));
    for(i=0; i<V; i++)
        graph[i]=(int*)malloc(V*sizeof(int));
    for(i=0; i<V; i++)
    {
        for(x=0; x<V; x++)
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

    for ( i = 0; i < V; i++)
        color[i] = -1;

    if (!Graph_Coloring(graph, m, 0, color))
        printf("Solution does not exist\n\n\n");
    system("pause");
    return 0;
}
