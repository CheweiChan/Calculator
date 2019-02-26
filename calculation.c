#include"stdio.h"
#include <stdlib.h>
#include "math.h"


#define SUB 100000001
#define PLUS 100000002
#define EQU 100000003
#define DIV 100000005
#define MUL 100000004
#define NOP_ 100000006


int stage=0;
int number=0;
int len=0;


typedef struct
{
    int num0[100];
    int num1[100];
    int num2[100];
    char s0[100];
    char s1[100];
    char s2[100];
    int solution[100];
}ST_matrix;

ST_matrix matrix;
/********************************************************************************************
 100000005 -> /
 100000004 -> *
 100000003 -> =
 100000002 -> +
 100000001 -> -
 100000006 -> nop
 100000007 -> (
 100000008 -> )
*********************************************************************************************/

/********************************************************************************************/
void print_solution(void)
{
    int i=0;
    
    while(matrix.solution[i] !=EQU)
    {
       
        i++;
        
    }
    printf("\nsolution=%d\n",matrix.solution[i-1]);
}
/********************************************************************************************/




void print_matrix(int* s)
{
    int i=0;
    printf("matrix=");
    while(s[i] !=EQU)
    {
        printf("%d ",s[i]);
        i++;
    }
    printf("\n");
}

void clear_intmatrix(int* s)
{
    int i=0;
    while(i<100)
    {
        s[i]=0;
        i++;
    }
}

void clear_charmatrix(char* s)
{
    int i=0;
    while(i<100)
    {
        s[i]=0;
        i++;
    }
}

void operation(int* s,int *sol)
{
    int j=0,i=0;
    int cnt=0;
    printf("---operation---\n");
    while(s[i] != EQU)
    {
        if(s[i]==MUL)
        {
            while(j-- && s[j] != PLUS && s[j] != SUB)
            {
                if(s[j] != NOP_)
                s[j]= s[j]*s[i+1];    
            }
            s[i]=s[i+1]=NOP_;
            j=i;
        }
        if(s[i]==DIV)
        {
            while(j-- && s[j] != PLUS && s[j] != SUB)
            {
                if(s[j] != NOP_)
                s[j]= s[j]/s[i+1];    
            }
            s[i]=s[i+1]=NOP_;
            j=i;
        }
        i++;
        j++;
    }

    i=0;
    while(s[i] != EQU)
    {
        if(s[i] != NOP_) 
        {
        sol[cnt]=s[i];
        cnt++;
        }
        i++;
    }
    sol[cnt]=EQU;
    
    i=0;
    while(sol[i] != EQU)
    {
        if(sol[i]==NOP_)
        {
            i++;
            continue;
        }
        if(sol[i]==PLUS)
        {
            printf("%d+%d\n",sol[i-1],sol[i+1]);
            sol[i+1]=sol[i-1]+sol[i+1];
        }
        if(sol[i]==SUB)
        {
            printf("%d-%d\n",sol[i-1],sol[i+1]);
            sol[i+1]=s[i-1]-s[i+1];
        }
        i++;
    }
    number=sol[i-1];
    printf("---operation---\n");
}
/********************************************************************************************/


void TakeBrackets(char* string1,char* string2)
{
    int i=0,j=0;

    while(string1[i] != '\0')
    {
        if(string1[i] =='(')
        {
            while(string1[i] !=')')
            {
                if(string1[i]!='(') 
                string2[j++]=string1[i];
                string1[i]='a';
                i++;
            }
            break;
        }  
      i++;
    }
    string2[j]='=';
}

void stoi(char* string,int* s)
{
    int cnt=0,cnt2=0,cnt3=0;
printf("\n");
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
                    s[cnt3++]=PLUS;
                }
                else if(string[cnt] =='-')
                {
                    s[cnt3++]=SUB;
                }
                else if(string[cnt]=='=')
                {
                    s[cnt3++]=EQU;
                }    
                else if(string[cnt]=='*')
                {
                    s[cnt3++]=MUL;
                }
                else if(string[cnt]=='/')
                {
                    s[cnt3++]=DIV;
                }
            cnt2=0;
        }
        cnt++;
        
    }
    s[cnt3]='\0';

}


void RemoveTempNum(char *s)
{
    int i=0,j=0,k=0,q=0;
    char temp=0;
    int cnt=0;
    char temp2[20];

    if(number >9)
    {
        while( number != 0)
        {
        temp2[i++]=(number%10)+'0';
        number /=10;
        printf("%c,%d  ",temp2[i-1],i);
        
        }
        cnt=i;
        temp2[i]= '\0';
        i--;
        for(;i>=0;i--)
        {
            if(i<j) break;
                temp = temp2[i];
                temp2[i] = temp2[j];
                temp2[j++] = temp;  
        }
        while(s[i] != '\0')
        {
            if(s[i] == ')' )
            {
                k=i;
                q=cnt;
                for(j=0;j<cnt;j++)
                {
                    s[k--]=temp2[--q];
                }
            }
    i++;
        }
    }
    else
    {
        while(s[i] != '\0')
        {
            if(s[i] == ')' )
            {    
                s[i]= number +'0';
                break;
            }
            i++;
        }
    }

}

void copyString(char *s1,char* s2)
{
    int i;

    for(i=0;i<100;i++)
    {
        s1[i]=s2[i];
    }

}


void removeA(char *s)
{
    char temp[100];
    int i=0,j=0,k=0;
    while( s[i] !='\0')
    {
        if(s[i] != 'a')
        {
            temp[j++]=s[i];
            printf("%c ",temp[j-1]);
        }
        i++;
    }
    temp[j]='\0';

    for(i=0;i<100;i++)
    {
        s[i]=temp[i];
    }
}

int stringLen(char *s)
{
    int i=0;
        while(s[i] != '\0')
        {
            i++;
        }
    return i;
}


void InitMatrix(void)
{
    clear_intmatrix(matrix.num0);
    clear_intmatrix(matrix.num1);
    clear_intmatrix(matrix.num2);
    clear_charmatrix(matrix.s0);
    clear_charmatrix(matrix.s1);
    clear_charmatrix(matrix.s2);
}

void PressNumber(char *s)
{
    scanf("%s",s);   
    len= stringLen(s);
    s[len]='=';
    s[len+1]='\0';

}

int HaveBrackets(char *s)
{
    int i=0;
    while(matrix.s0[i] != '\0')
    {
        if(matrix.s0[i] == '(')
        { 
            return 1;
        }
        i++;
    }
    return 0;
}


int main(int argc, const char * argv[]) 
{
    while(1)
    {  
        switch(stage)
        {
            case 0:
                InitMatrix();
                printf("please press number\n");
                PressNumber(matrix.s0);
                if(HaveBrackets(matrix.s0))
                stage=2;
                else 
                stage =1;                 
                break;
                    
            case 1:
                stoi(&matrix.s0[0], &matrix.num0[0]);
                operation(&matrix.num0[0],matrix.solution);
                print_solution();
                stage=0;
                break;
                    
            case 2:
                clear_intmatrix(&matrix.num0[0]);
                clear_intmatrix(&matrix.solution[0]);
                clear_intmatrix(&matrix.num1[0]);
                TakeBrackets(matrix.s0,matrix.s1);
                stoi(matrix.s1, &matrix.num0[0]);
                operation(&matrix.num0[0],matrix.solution);
                
                RemoveTempNum(matrix.s0); 
                removeA(matrix.s0);

                if(HaveBrackets(matrix.s0))
                {                    
                    stage = 2;
                }
                else 
                {
                    stoi(&matrix.s0[0],&matrix.num1[0]);
                    operation(&matrix.num1[0],matrix.solution);
                    print_solution();
                    stage = 0;
                }
                break;

            default:
                break;
        }    
        
    }

    return 0;
}
/********************************************************************************************/
