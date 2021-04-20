//
//  File.c
//  path_test
//
//  Created by wvwuu on 2021/4/12.
//

#include "File.h"
#include "string.h"
#include "stdio.h"
#include <stdlib.h>
#include "Adj_List.h"
#include "interaction.h"
//Variables Used for edges
int id;
long pre_node,next_node;
double length;
int way;
int way1,way2;

//Variables Used for Vex
double lat,lon;
long Vex_id;





Graph * File_read_vex(char * filename,Graph * G){
    
    char str[300];
    FILE * fp = fopen(filename, "r");
    int i = 0;//Count as the index of the array
    
    while( fgets (str, 300, fp)!=NULL ) {
        if (strstr(str, "lat")) {
            sscanf(str, "%*[^=]=%ld %*[^=]=%lf %*[^=]=%lf",&Vex_id,&lat,&lon);//3个要读入的
            ///< id=-1887622551 lat=53.809915 lon=-1.553477 /node>
            G->VexArray[i].node = Vex_id;
            G->VexArray[i].latitude = lat;
            G->VexArray[i].longitude = lon;
            G->VexArray[i].idt = i;
            //Compute the number of the vex and let i++
            G->vex++;
            G->VexArray[i].next = NULL;
            i++;
        }
    }
    
    G = File_read_edge(filename, G);
    return G;
}

Graph * File_read_edge(char * filename,Graph * G){
    
    char str[300];
    FILE * fp = fopen(filename, "r");
    //int i = 0;
    while( fgets (str, 300, fp)!=NULL ) {
        if (strstr(str, "link")) {
            sscanf(str, "%*[^=]=%d %*[^=]=%ld %*[^=]=%ld %*[^=]=%d %*[^=]=%lf",&id,&pre_node,&next_node,&way,&length);//5个要读入的
        
            
            //id=-2143392630 node=454231775 node=1968799687 way=-7722 length=48.254007
            Edge * edge = (Edge*)malloc(sizeof(Edge));
            edge->id = id;
            edge->pre_node = next_node;
            //edge->next_node = next_node;
            //edge->way = way;
            edge -> next = NULL;
            edge->length = length;
            
            for (int i = 0; i < G ->vex; i++) {
                if (G->VexArray[i].node == pre_node) {
                    edge -> next = G->VexArray[i].next;
                    G->VexArray[i].next = edge;
                    break;
                }
            }
            edge = (Edge*)malloc(sizeof(Edge));
            edge->id = id;
            edge->pre_node = pre_node;
            //edge->next_node = next_node;
            //edge->way = way;
            edge->length = length;
            edge -> next = NULL;
            for (int i = 0; i < G -> vex; i++) {
                if (G->VexArray[i].node == next_node) {
                    edge -> next = G->VexArray[i].next;
                    G->VexArray[i].next = edge;
                    break;
                }
            }
            
        }
        
    }
    return G;
}

//this function is only for test
void Gnu_lines(char * filename,Graph * G){
    
    FILE * fp = fopen(filename, "w");
    for (int i = 0; i < G->vex; i++) {
        Edge * edge = (Edge*)malloc(sizeof(Edge));
        fprintf(fp, "%ld ",G->VexArray[i].node);
        edge = G->VexArray[i].next;
        while (edge) {
            fprintf(fp, "%ld ",edge->pre_node);
            edge = edge->next;
        }
        fprintf(fp, "\n");
    }
}

void convert_to_dots(char * filename,Graph * G){
    
    FILE * fp = fopen(filename, "w");
    for (int i = 0; i < G->vex; i++) {
        Edge * edge = (Edge*)malloc(sizeof(Edge));
        //fprintf(fp, "%ld  ",G->VexArray[i].node);
        if (G->VexArray[i].next != NULL) {
            fprintf(fp, "%lf %lf\n",G->VexArray[i].longitude,G->VexArray[i].latitude);
        }
        edge = G->VexArray[i].next;
        while (edge) {
            //fprintf(fp, "%ld ",edge->pre_node);
            for (int i = 0; i < G->vex; i++) {
                if (edge->pre_node == G->VexArray[i].node) {
                    //fprintf(fp, "%ld  ",edge->pre_node);
                    fprintf(fp, "%lf %lf\n",G->VexArray[i].longitude,G->VexArray[i].latitude);
                }
            }
            edge = edge->next;
        }
        fprintf(fp, "\n");
    }
}
