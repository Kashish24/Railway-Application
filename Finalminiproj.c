#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 11

#define INTMAX 99999

int mindist(int dist[], int set[], int V){
    int min=INTMAX, min_index, v;
    for(v=0;v<V;v++){
        if (set[v]==0 && dist[v]<min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}


void printpath(int parent[], int j){
    if(parent[j]==-1)
         return;

    printpath(parent, parent[j]);

    printf("%d ",j);
}


void print(int parent[], int src, int desti){

    printf("%d ",src);
    printpath(parent,desti);

}


int dijkstra(int graph[][MAX][MAX], int src, int desti, int V,int l){
    int dist[V];
    int set[V];
    int parent[V];
    int i,count,v,u;
    parent[src]=-1;
    for(i=0;i<=V;i++){
        dist[i]=INTMAX;
        set[i]=0;
    }
    dist[src]=0;
    for(count=0;count<V-1;count++){
        u=mindist(dist,set,V);
        set[u]=1;
        for(v=0;v<V;v++){
            if(!set[v] && graph[u][v][l] && dist[u] != INTMAX && (dist[u]+graph[u][v][l]) < dist[v]){
                parent[v]=u;
                dist[v]= dist[u]+graph[u][v][l];
            }
        }
    }
    return dist[desti];
}


void dijkstra1(int graph[][MAX][MAX], int src, int desti, int V,int ct, int l){
    int dist[V];
    int set[V];
    int parent[V];
    int i,count,v,u;
    parent[src]=-1;
    for(i=0;i<=V;i++){
        dist[i]=INTMAX;
        set[i]=0;
    }
    dist[src]=0;
    for(count=0;count<V-1;count++){
        u=mindist(dist,set,V);
        set[u]=1;
        for(v=0;v<V;v++){
            if(!set[v] && graph[u][v][l]  && (dist[u]+graph[u][v][l]) < dist[v]){
                parent[v]=u;
                dist[v]= dist[u]+graph[u][v][l];
            }
        }
    }
    if(ct==1){
        print(parent,src,desti);
    }
    else{
        printpath(parent,desti);
    }
}



int main()
{

        FILE *fp,*fp1;
        //fp=freopen("read6.txt","r",stdin);
        //fp1=freopen("write6.txt","w",stdout);
        fp=fopen("read6.txt","r");
        fp1=fopen("write1.txt","w");
        int graph[MAX][MAX][MAX]={0},source[100]={0},desti[100]={0},inter[100]={0};
        int test=0,edge=0,V[100]={0},i,x=0,y=0,cost=0,j,s1[MAX]={0},s2[MAX]={0},ct=1,k;
        int path_len[MAX]={0},count=0;
        char ch;
        //  printf("Enter total no. of Test cases : ");
        if((ch=getc(fp))==EOF)                                  //checking if the file is empty
        {
            printf("\n\t\t*******Empty File*******");
            exit(0);
        }
        fclose(fp);
        fp=fopen("read6.txt","r");
        while(ch=getc(fp)!=EOF){
            if((ch>=48 && ch<=57) || ch==32 || ch=='\n'){
                printf("\thello");
            }
            else{
                 printf("\t\tInvalid Data\n");
                return 0;
            }
        }
        /*fclose(fp);
        fp=fopen("read6.txt","r");
        while(ch=getc(fp)!='\n'){

        }
        count=0;
        while(ch=getc(fp)!='\n'){
            if(ch==' ')
                count++;
        }
        if(count!=1){
            printf("Insufficient Data\n");
            exit(0);
        }*/
        fclose(fp);
        fp=fopen("read6.txt","r");
        fscanf(fp,"%d",&test);

        //  fp=fopen("read6.txt","r");

        for(i=1;i<=test;i++)
        {

            fscanf(fp,"%d %d",&V[i],&edge);

            for(j=1;j<=edge;j++)
            {

                fscanf(fp,"%d %d %d",&x,&y,&cost);

                graph[x][y][i]=graph[y][x][i]=cost;

            }
          //  printf("Enter Source,Intermediate and Destination : ");
            fscanf(fp,"%d %d %d",&source[i],&inter[i],&desti[i]);

            s1[i]=dijkstra(graph,source[i],inter[i],V[i],i);
            s2[i]=dijkstra(graph,inter[i],desti[i],V[i],i);


            if(s1[i]==INTMAX||s2[i]==INTMAX)
            {
                path_len[i]=-1;
            }
        }
        for(i=1;i<=test;i++){
            if(path_len[i]==-1){
                printf("NO TRAIN FOUND\n");
            }
            else{
                printf("Shortest Path = %d\n",s1[i]+s2[i]);
                ct=1;
                dijkstra1(graph,source[i],inter[i],V[i],ct,i);
                ct=2;
                dijkstra1(graph,inter[i],desti[i],V[i],ct,i);
                printf("\n");
            }
        }
        fclose(fp);
        fclose(fp1);
        return 0;
}


