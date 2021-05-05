//
//  main.c
//  UnityTest
//
//  Created by wvwuu on 2021/5/4.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "File.h"
#include "unity.h"

int main(int argc, const char * argv[]) {
    
    Graph * G = (Graph*)malloc(sizeof(Graph));
    G = File_read_vex("/Users/lee/Desktop/Final_Map(1).map", G);
    
    UnityBegin("/Users/lee/Documents/Program for Xcode/path_test/path_test");
    UnityDefaultTestRun(test_file_exist, "file_read", 1,G,"/Users/lee/Desktop/lines.txt");
    
    UnityDefaultTestRun(Gnu_lines_test, "Gnu_lines_write", 2,G,"/Users/lee/Desktop/lines.txt");
    
    UnityDefaultTestRun(file_write_test, "file_write", 3,G,"/Users/lee/Desktop/lines.txt");
    
    UnityDefaultTestRun(get_length_test, "get_length", 3,G,"/Users/lee/Desktop/lines.txt");
    
    UnityDefaultTestRun(shortest_path_test, "shortest_path", 3,G,"/Users/lee/Desktop/lines.txt");
    
    return UnityEnd();
}
