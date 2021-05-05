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
#include "unity.h"
//Variables Used for edges
int id;
long pre_node,next_node;
double length;
int way;
int way1,way2;

//Variables Used for Vex
double lat,lon;
long Vex_id;

extern int enterr;


//
Graph * File_read_vex(char * filename,Graph * G){
    
    char str[300];
    FILE * fp = fopen(filename, "r");
    //if file == NULL, exit the function
    if (fp == NULL) {
        printf("Sorry, no file existed for reading vex!\n");
        //enterr = 10;
        return 0;
    }
    int i = 0;//Count as the index of the array
    
    //read the data into the graph
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
    
    //read the length into the node
    G = File_read_edge(filename, G);
    return G;
}


//also the data into the edge
Graph * File_read_edge(char * filename,Graph * G){
    
    char str[300];
    FILE * fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Sorry, no file existed for reading edge!\n");
        return 0;
    }
    //int i = 0;
    while( fgets (str, 300, fp)!=NULL ) {
        if (strstr(str, "link")) {
            //正则表达式
            sscanf(str, "%*[^=]=%d %*[^=]=%ld %*[^=]=%ld %*[^=]=%d %*[^=]=%lf",&id,&pre_node,&next_node,&way,&length);//5个要读入的
        
            
            //id=-2143392630 node=454231775 node=1968799687 way=-7722 length=48.254007
            Edge * edge = (Edge*)malloc(sizeof(Edge));
            edge->id = id;
            edge->pre_node = next_node;
            //edge->next_node = next_node;
            //edge->way = way;
            edge -> next = NULL;
            edge->length = length;
            
            //use a for loop read the graph
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
    TEST_ASSERT_NOT_NULL_MESSAGE(fp, "The file cannot be detected");
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

//input the data to the file for gnu
void convert_to_dots(char * filename,Graph * G){
    
    
    FILE * fp = fopen(filename, "w");
    for (int i = 0; i < G->vex; i++) {
        Edge * edge = (Edge*)malloc(sizeof(Edge));
        edge = G->VexArray[i].next;
        while (edge) {
            //read the headnode
            fprintf(fp, "%lf %lf\n",G->VexArray[i].longitude,G->VexArray[i].latitude);
            for (int i = 0; i < G->vex; i++) {
                if (edge->pre_node == G->VexArray[i].node) {
                    //read the son node
                    fprintf(fp, "%lf %lf\n",G->VexArray[i].longitude,G->VexArray[i].latitude);
                }
            }
            edge = edge->next;
            //write a \n
            fprintf(fp, "\n");
        }
    }
}


void test_(){
    int a = 10;
    TEST_ASSERT_INT32_WITHIN_MESSAGE(1, 10, a,"hello");
}

void test_file_exist(Graph * G, char * filename){
    
    FILE * fp = fopen(filename, "r");
    TEST_ASSERT_NOT_NULL_MESSAGE(fp, "The file cannot be opened");
}

void Gnu_lines_test(Graph * G,char * filename){
    
    FILE * fp = fopen(filename, "r");
    TEST_ASSERT_NOT_NULL_MESSAGE(fp, "The file cannot be opened");
}

void file_write_test(Graph * G, char * filename){
    FILE * fp = fopen(filename, "r");
    TEST_ASSERT_NOT_NULL_MESSAGE(fp, "The file cannot be writed correctly");
}
