//
//  calcuation_H.c
//  calcuation
//
//  Created by Chewei Chan on 2018/4/16.
//  Copyright © 2018年 Chewei Chan. All rights reserved.
//

#include "calcuation_H.h"
#include "math.h"
/********************************************************************************************

 100000003 -> =
 100000002 -> +
 100000001 -> -
5+2*3*2+2=
*********************************************************************************************/
void operation(int* s)
{
    int i=0;

    printf("---operation---\n");
while(s[i] != 100000003)
{
    if(s[i]==100000002)
    {
        printf("%d+%d\n",s[i-1],s[i+1]);
        s[i+1]=s[i-1]+s[i+1];
    }
    if(s[i]==100000001)
    {
        printf("%d-%d\n",s[i-1],s[i+1]);
        s[i+1]=s[i-1]-s[i+1];
    }
    i++;
}
        printf("---operation---\n");
}
/********************************************************************************************/
void print_s(int* s)
{
    int i=0;
    printf("matrix=");
    while(s[i] !=100000003)
    {
        printf("%d ",s[i]);
        i++;
    }
    printf("\n");
}
/********************************************************************************************/
void print_sol(int* s)
{
    int i=0;
    
    while(s[i] !=100000003)
    {
       
        i++;
        
    }
    printf("solution=%d\n",s[i-1]);
    
}
/********************************************************************************************/

void stoi(char* string,int* s)
{
    int cnt=0,cnt2=0,cnt3=0;
    while(string[cnt]!='\0')
    {
        cnt2++;
        if((string[cnt] !='+')&&(string[cnt] !='-')&&(string[cnt] != '*')&&(string[cnt] != '/')&&(string[cnt]!= '='))
        {
   
            string[cnt]=string[cnt]-'0';
            
        }
        else{
                while((cnt2-1))
                {
                    s[cnt3]+=string[cnt-(cnt2-1)]*pow(10,(cnt2-2));
                    cnt2--;
                }
                
                cnt3++;
                
                if(string[cnt] =='+')
                {
                    s[cnt3++]=100000002;
                }
                else if(string[cnt] =='-')
                {
                    s[cnt3++]=100000001;
                }
                else if(string[cnt]=='=')
                {
                    s[cnt3++]=100000003;
                }
            cnt2=0;
        }
        cnt++;
        
    }
    s[cnt3]='\0';
}
/********************************************************************************************/



