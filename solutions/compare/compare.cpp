/*
 * @Author: Dragonw
 * @LastEditors: Dragonw
 * @LastEditTime: 2022-04-25 16:15:24
 * @FilePath: /c++/solutions/compare/compare.cpp
 * 
 */
#include<cstdio>
#include<cstdlib>
 
int main()
{
    int tmp=0;
    for(int i=1;i<=10000;i++)
    {
        system("./data");
        system("./mycode");
        system("./stdcode");
        if(i/100>tmp) {printf("-- %d --\n",i);tmp=i/100;}
        if(system("diff test1.out.txt test2.out.txt"))
        {
            printf("wrong in --> %d \n",i);
            break;
        }
        
        else printf("passed\n");
    }
    return 0;
}