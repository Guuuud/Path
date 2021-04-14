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


int main(){
    
    
//    char a[100];
//    char b[100];
//    char c[20];
//    char d[20];
//    long a1,b2,c3;
//    char str[500];
//
//
//
//    printf("%s\n%ld\n%ld\n%ld\n",a,a1,b2,c3);
//
//
//    FILE * fp;
//    //fp = fopen("/Users/lee/Desktop/book.txt", "r");
//    fp = fopen("/Users/lee/Desktop/Final_Map(1).map", "r");
//    while( fgets (str, 500, fp)!=NULL ) {
//
//          //puts(str);
//        if (strstr(str, "link")) {
//            sscanf(str,"%*[^=]=%ld %*[^=]=%ld %*[^=]=%ld",&a1,&b2,&c3);
//            if (b2 == 55424440 || c3 == 55424440) {
//                printf("h\n");
//            }
//        }
//        //printf("%s",str);
//       }
//       fclose(fp);
    Graph * G = (Graph*)malloc(sizeof(Graph));
    //printf("KLKLKKLKL");
    G = File_read_vex("/Users/lee/Desktop/Final_Map(1).map", G);

    for (int i =0; i < G->vex; i++) {
        printf("%ld\t",G->VexArray[i].node);
        
            printf("%lf\n\n",G->VexArray[i].next->length);
        
    }
    
}
