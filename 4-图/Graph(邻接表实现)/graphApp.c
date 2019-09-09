//
// Created by george on 19/9/9.
//
#include "graphApp.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//为了graph_is_tree的辅助函数
void DFS_like(graph* g,int v,bool visited[],int* vCnt,int* eCnt)
{
    if(v==-1) return;
    (*vCnt)++;
    visited[v]=true;
    int next=graph_first(g,v);
    while(next!=-1){
        //每个顶点的边都被扫描一次
        (*eCnt)++;
        //顶点只会被扫描一遍
        if(!visited[next])
            DFS_like(g,next,visited,vCnt,eCnt);
        next=graph_next(g,v,next);
    }
}
bool graph_is_tree(graph* g)
{
    if(!g) return true;
    bool visited[g->vCount];
    for(int i=0;i<g->vCount;i++)
        visited[i]=false;
    int vCnt=0,eCnt=0;
    DFS_like(g,0,visited,&vCnt,&eCnt);
    printf("vcnt:%d,eCnt:%d\n",vCnt,eCnt);
    //当一次遍历顶点的数目等于图的数目，边的数目等于2倍(边的数目-1)时，为一棵树
    return vCnt==g->vCount && eCnt==(g->vCount-1)*2;
}
void DFS_recur(graph*g,int v,bool visited[])
{
    if(v==-1) return;
    visited[v]=true;
    printf("%c-->",g->vertex[v].data);
    int nxt = graph_first(g, v);
    while(nxt!=-1){
        if(!visited[nxt])
            DFS_recur(g,nxt,visited);
        nxt=graph_next(g,v,nxt);
    }
}
void DFS_traversal(graph* g)
{
    if(!g) return;
    bool* visited=(bool*)malloc(g->vCount*sizeof(bool));
    for(int i=0;i<g->vCount;i++)
        visited[i]=false;
    //扫描所有的独立的连通图
    for(int i=0;i<g->vCount;i++){
        if(visited[i]) continue;
        DFS_recur(g,i,visited);
        printf("\n");
    }
    printf("\n");
    free(visited);
}
/**非递归和递归实现visit的顺序并不相同，因为非递归用的栈
*  只有当一层结束之后才会弹出一个元素，所以相当于二叉树遍历顺序的"中右左"
*   DFS的递归版本相当于"中左右"前序遍历
*/
void DFS_non_recur(graph* g)
{
    if(!g) return;
    bool* visited=(bool*)malloc(g->vCount*sizeof(bool));
    for(int i=0;i<g->vCount;i++)
        visited[i]=false;
    int* stack=(int*)malloc(g->vCount*sizeof(int));
    int top=-1;
    for(int i=0;i<g->vCount;i++){
        //遍历所有连通的图
        if(visited[i]) continue;
        //首节点入栈
        stack[++top]=i;
        visited[i]=true;
        //遍历一张连通图
        while(top!=-1){
            int elem=stack[top--];
            printf("%c-->",g->vertex[elem].data);
            //所有未访问过的子节点入栈
            for(int nxt=graph_first(g,elem);nxt!=-1;nxt=graph_next(g,elem,nxt)){
                //将未曾入过栈的节点入栈
                if(visited[nxt]==false)
                    stack[++top]=nxt;
                visited[nxt]=true;
            }
        }
        printf("\n");
    }
}
//用DFS判断是否存在顶点vi到vj的路径
bool DFS_aux(graph* g,int i,int j,bool visited[])
{
    visited[i]=true;
    if(i==j)
        return true;
    for(int nxt=graph_first(g,i);nxt!=-1;nxt=graph_next(g,i,nxt)){
        if(visited[nxt])
            continue;
        if(DFS_aux(g, nxt, j, visited))
            return true;
    }
    return false;
}
bool BFS_aux(graph* g,int i,int j,bool visited[])
{
    int size=g->vCount;
    int* queue=(int*)malloc(size*sizeof(int));
    int front=-1,rear=-1;
    queue[++rear]=i;
    visited[i]=true;
    while(front!=rear){
        int pop=queue[++front];
        if(pop==j) return true;
        for(int nxt=graph_first(g,pop);nxt!=-1;nxt=graph_next(g,pop,nxt)){
            if(!visited[nxt]){
                queue[++rear]=nxt;
            }
            visited[nxt]=true;
        }
    }
    free(queue);
    return false;
}
bool graph_existPath_ij(graph* g,int i,int j)
{
    if(!g) return false;
    bool* visited=(bool*)malloc(g->vCount*sizeof(bool));
    memset(visited,false, g->vCount*sizeof(bool));
    bool fg= DFS_aux(g, i, j, visited);
    memset(visited,false, g->vCount*sizeof(bool));
    bool fg2=BFS_aux(g,i,j,visited);
    free(visited);
    if(fg==fg2)
        return fg;
    else
        exit(-1);
}
//d为distance,u为起始点,v为终止点,path为存储路径的数组
void graph_find_all_path_aux(graph*g,int u,int v,bool visited[],int path[],int d)
{
    path[++d]=u;
    visited[u]=true;
    if(u==v){
        printf("path is:");
        for(int i=0;i<=d;i++)
            printf("%d-->",path[i]);
        printf("\n");
    }
    int nxt=graph_first(g,u);
    while(nxt!=-1){
        if(!visited[nxt])
            graph_find_all_path_aux(g,nxt,v,visited,path,d);
        nxt=graph_next(g,u,nxt);
    }
    /**
     *注意这里把当前节点恢复了未访问的状态，是因为当前u节点的所有子路径都探索完毕了
     *把u节点释放提供给其他节点组成新的路径
     *这样做并不会导致造成死循环，因为while循环，假设
     *(顶点)v3->(first边)v1->(next边)v2->(next边)v4，这时即使visited[v1]=false,而按照while中v3先访问v1,再访问v2
     *是不会造成循环重复访问的
     */
    visited[u]=false;
}
void graph_find_all_path(graph* g,int u,int v)
{
    if(!g)return;
    int* path=(int*)malloc(g->vCount*sizeof(int));
    bool* visited=(bool*)malloc(g->vCount*sizeof(bool));
    memset(visited,false,g->vCount* sizeof(bool));
    graph_find_all_path_aux(g,u,v,visited,path,-1);
    free(path);
    free(visited);
}