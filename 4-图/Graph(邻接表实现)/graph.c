//
// Created by george on 19/9/9.
//

#include<stdlib.h>
#include<stdio.h>
#include "graph.h"
graph* graph_init(char nodes[],int nodeCnt)
{
    if(nodeCnt<1||nodes==NULL)
        return NULL;
    graph* g=(graph*)malloc(sizeof(graph));
    g->vertex=(vertex*)malloc(nodeCnt*sizeof(vertex));
    for(int i=0;i<nodeCnt;i++){
        g->vertex[i].data=nodes[i];
        g->vertex[i].i=i;
        g->vertex[i].firstArc=NULL;
    }
    g->eCount=0;
    g->vCount=nodeCnt;
    return g;
}
void graph_addEdge(graph*g,int i,int j,int wt)
{
    if(!g) return;
    if(i>=g->vCount || j>=g->vCount)return;
    arc* arc1 = g->vertex[i].firstArc;
    //新创建的弧
    arc *tmp = (arc *) malloc(sizeof(arc));
    tmp->next = NULL;
    tmp->wt = wt;
    tmp->adjVex = j;
    //i节点不存在弧
    if(!arc1) {
        g->vertex[i].firstArc = tmp;
        g->eCount++;
    }
    //存在弧，遍历到最后一个弧
    else{
        while(arc1->next){
            //已经存在了i-j边
            if(arc1->adjVex==j) return;
            arc1=arc1->next;
        }
        if(arc1->adjVex==j) return;
        arc1->next=tmp;
        g->eCount++;
    }
}
int graph_first(graph* g,int i)
{
    if(!g)  return -1;
    arc* arc1=g->vertex[i].firstArc;
    if(!arc1) return -1;
    else
        return arc1->adjVex;
}
int graph_next(graph*g,int i,int curr)
{
    if(!g) return -1;
    arc *arc1 = g->vertex[i].firstArc;
    while(arc1 && arc1->adjVex!=curr){
        arc1=arc1->next;
    }
    if(arc1 && arc1->next)
        return arc1->next->adjVex;
    else
        return -1;
}
void graph_print(graph* g)
{
    for(int i=0;i<g->vCount;i++){
        vertex v = g->vertex[i];
        printf("%c(%d)->",v.data,v.i);
        arc* tmp = v.firstArc;
        while(tmp){
            printf("%d->",tmp->adjVex);
            tmp=tmp->next;
        }
        printf("\n");
    }
}