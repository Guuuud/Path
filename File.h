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
#endif /* File_h */


Graph * File_read_vex(char * filename,Graph * G);

Graph * File_read_edge(char * filename,Graph * G);




Edge * create_edge(long node,int length,Edge * edge);

Edge * create_head(long node,int length,Vex * vex);
