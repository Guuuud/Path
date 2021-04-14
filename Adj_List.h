#pragma once
#ifndef __ADJ_LIST_H__
#define __ADJ_LIST_H__
 
#define MAX_VERTEX_NUM 20
 

 

 


typedef struct Edge{
    
    
    long pre_node;
    struct Edge * next;
    double length;
    /*这两个与图的查找以及求长度无关*/
    int way;
    int id;
}Edge;

typedef struct Vex{
    
    long node;
    double latitude,longitude;
    Edge * next;
    
}Vex;

typedef struct Graph{
    
    int edge,vex;
    Vex VexArray[3941];
    
}Graph;
 
#endif /* __ADJ_LIST_H__*/
