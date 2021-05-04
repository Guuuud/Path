//
//  File.h
//  path_test
//
//  Created by wvwuu on 2021/4/12.
//
#pragma once
#ifndef File_h
#define File_h

#include <stdio.h>
#include "Adj_List.h"
#include "interaction.h"
#endif /* File_h */
extern int enterr;

Graph * File_read_vex(char * filename,Graph * G);
Graph * File_read_edge(char * filename,Graph * G);




Edge * create_edge(long node,int length,Edge * edge);
Edge * create_head(long node,int length,Vex * vex);


void Gnu_lines(char * filename,Graph * G);
void convert_to_dots(char * filename,Graph * G);



//test
void Gnu_lines_test(Graph * G,char * filename);
void test();
void test_file_exist(Graph * G, char * filename);
void file_write_test(Graph * G, char * filename);
