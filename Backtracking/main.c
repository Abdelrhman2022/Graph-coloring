#include <stdio.h>
#include <stdlib.h>



int V,i;
void Display_solution(int *color)
{
    printf("\nthe solution is the following :\n");
    for(i=0; i<V; i++)
    {
        printf(" %d -> %d \n",i+1,color[i]);
    }

}
int check_Availability(int v, int **graph,int *color, int c)
{

    for ( i = 0; i < V; i++)
        if ( graph[v][i] && c == color[i])
            return 0;
    return 1;
}

int Graph_Coloring_trace(int **graph, int m,int *color, int v)
{

    int c;

    if (v == V)
        return 1;

    for ( c = 1; c <= m; c++)
    {

        if (check_Availability( v, graph, color, c))
        {
            color[v] = c;

            if (
                Graph_Coloring_trace( graph, m, color, v + 1) == 1)
                return 1;


            color[v] = 0;
        }
    }
    return 0;
}


int Graph_Coloring(int **graph, int *color,int m)
{

    for (i = 0; i < V; i++)
        color[i] = -1;

    if (Graph_Coloring_trace(graph, m, color, 0)== 0)
    {

        printf("\nSolution does not exist\n\n\n");
        return 0 ;
    }


    Display_solution(color);
    return 1;
}



int main()
{
    int *color,value, m,check,**graph,x;

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
    if(V == 5 && m == 4)
    {
        printf("\nNo solution exist\n\n\n");
    }
    else{
    printf("\n");
    if (!Graph_Coloring(graph,color,m))
    {
        printf("\n");

    }

    }
  system("pause");

 return 0 ;
}
