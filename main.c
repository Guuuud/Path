//
//  main.c
//  path_test
//
//  Created by wvwuu on 2021/4/10.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "File.h"
//#include "interaction.h"


int main(){
    
    
 
    Graph * G = (Graph*)malloc(sizeof(Graph));
    G = File_read_vex("/Users/lee/Desktop/Final_Map(1).map", G);
    
    int pre[G->vex];
    double dis[G->vex];
    long node1,node2;
    int start = 30000,end = 30000;
    
//    printf("Enter the first node:\n");
//    scanf("%ld",&node1);
//    printf("Enter the second node:\n");
//    scanf("%ld",&node2);
//
//    for (int i = 0; i< G->vex; i++) {
//        if (node1 == G->VexArray[i].node) {
//            start = i;
//        }
//    }
//
//    for (int i = 0; i< G->vex; i++) {
//        if (node2 == G->VexArray[i].node) {
//            end = i;
//        }
//    }
//
//    if (start != 30000 && end != 30000) {
//        shortest_path(G, start, end, pre, dis);
//    }else if(start == 30000){
//        printf("No such node for %ld!\n",node1);
//    }else{
//        printf("No such node for %ld!\n",node2);
//    }
//
//    printf("END");
    Gnu_lines("/Users/lee/Desktop/circle.txt", G);
    convert_to_dots("/Users/lee/Desktop/lines的副本.txt", G);
    
    Edge * edge = (Edge*)malloc(sizeof(Edge));
    edge = G->VexArray[0].next;
    printf("%ld",G->VexArray[0].node);
    while (edge) {
        printf("\n%ld",edge->pre_node);
        edge = edge -> next;
        
    }

   
}
