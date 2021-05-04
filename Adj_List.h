#pragma once
#ifndef __ADJ_LIST_H__
#define __ADJ_LIST_H__
 
#define MAX_VERTEX_NUM 20
 

 

 
//

typedef struct Edge{
    
    long pre_node;
    struct Edge * next;
    double length;
    //double lat,lot;//store the coordinate of the corresponding node
    /*这两个与图的查找以及求长度无关*/
    int way;
    int id;
}Edge;

typedef struct Vex{
    
    long node;
    int idt;//easy for find
    double latitude,longitude;
    Edge * next;
    
}Vex;

typedef struct Graph{
    
    int edge,vex;
    Vex VexArray[3941];
    
}Graph;

double get_length(Graph * G, int start, int end);

void shortest_path(Graph * G, int start, int end, int pre[], double dis[], char * filename);


//test
void get_length_test(Graph * G, char * filename);
void shortest_path_test(Graph * G, char * filename);

#endif /* __ADJ_LIST_H__*/

