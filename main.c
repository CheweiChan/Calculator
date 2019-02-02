//
//  main.c
//  calcuation
//
//  Created by Chewei Chan on 2018/4/2.
//  Copyright © 2018年 Chewei Chan. All rights reserved.
//

#include <stdio.h>
#include"math.h"
#include"calcuation_H.h"
char string[1000],num;
int s[100]={0};
int stage=0,i;
int main(int argc, const char * argv[]) {
    //input:1+2+3=
    //output:6
while(1)
{
    
    switch(stage)
    {
    case 0:
            printf("please press number\n");
            scanf("%s",&string[0]);
            stage=1;
        break;
            
    case 1:
            printf("calcuation\n");
            stoi(&string[0], &s[0]);
            print_s(&s[0]);
            operation(&s[0]);
            print_sol(&s[0]);
            stage=2;
        break;
            
    case 2:
            printf("init matrix\n");
            for(i=0;i<100;i++)
            {
                s[i]=0;
                string[i]=0;
            }
            stage=0;
        break;
    }

    
    
    
    
    
    
    
    
    
}

    return 0;
}
