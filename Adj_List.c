//
//  Adj_List.c
//  path_test
//
//  Created by wvwuu on 2021/4/10.
//

#include "Adj_List.h"
#include <stdio.h>
#define INF 200000


//For this function we use idt instead of node
double get_length(Graph * G, int start, int end){
    
    Edge * e;
    if (start == end) {
        return 0;
    }
    long real_end = 0;
    
    
    for (int i = 0; i < G->vex; i++) {
        if (G->VexArray[i].idt == end) {
            real_end = G->VexArray[i].node;
            break;
        }
    }
    
    e = G->VexArray[start].next;
    while (e) {
        if (e->pre_node == real_end) {
            return e->length;
        }
        //printf("THe prenode is %ld\n",e->pre_node);
        e = e -> next;
    }
    
    return INF;
}
 

void shortest_path(Graph * G, int start, int end, int pre[], double dis[],char * filename){
    
    int already[G->vex];
    double min;
    double temp;
    int id = 0;
    
    FILE * fp = fopen(filename, "w");
    int m = 0;//use to determine the shorteset path, 和k一样
    int i,j;
    //find the id of the Vexarray
    
    for (i = 0; i < G->vex; i++) {
        already[i] = 0;
        pre[i] = 0;
        dis[i] = get_length(G, start, i);
    }
    already[id] = 1;
    dis[id] = 0;
    
    for (i = 1; i < G->vex; i++) {
        min = INF;
        for (j = 0; j < G->vex; j++) {
            
            if (already[j] == 0 && dis[j] < min)
            {
                
                min = dis[j];
                m = j;
            }
        }
        
        already[m] = 1;
        for (j = 0; j < G->vex; j++) {
            
            temp = get_length(G, m, j);
            if (already[j] == 0 && min + temp < dis[j])
            {
                dis[j] = min + temp;
                pre[j] = m;
            }
        }
    }
    int rep = end;
    int u = 0;
    
//    while (u == 0) {
//        printf("%ld\n",G->VexArray[rep].node);
//        rep = pre[rep];
//        if (rep == 0) {
//            u = 10;
//        }
//    }
//    printf("%ld\n",G->VexArray[start].node);
//
//    printf("The shortest dis is %lf",dis[end]);
    fprintf(fp, "%lf %lf\n",G->VexArray[start].longitude,G->VexArray[start].latitude);
    fprintf(fp, "%lf %lf\n",G->VexArray[rep].longitude,G->VexArray[rep].latitude);
    fprintf(fp, "\n");
    while (u == 0) {
        printf("%ld\n",G->VexArray[rep].node);
        fprintf(fp, "%lf %lf\n",G->VexArray[rep].longitude,G->VexArray[rep].latitude);
        rep = pre[rep];
        fprintf(fp, "%lf %lf\n",G->VexArray[rep].longitude,G->VexArray[rep].latitude);
        fprintf(fp, "\n");
        if (rep == 0) {
            u = 10;
        }
    }
    printf("The shortest dis is %lf",dis[end]);
    
    
}

//if connected return normal, else return infinity
