#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Figure
{
char name[30];
char courtesy[30];
char gender[5];
char birth[10];
char death[10];
char dynasty[20];
char nation[10];
char status[50];
char introduction[9999];
struct Figure *next;
};

main()
{
	FILE *p1;
	struct Figure *p2;
	struct Figure a,b,c,d,e,f,g,h,i;
	strcpy(a.name,"���");strcpy(a.courtesy,"̫��");strcpy(a.gender,"��");
	strcpy(a.birth,"AC701��");strcpy(a.death,"AC762��");strcpy(a.dynasty,"�Ƴ�"); 
	strcpy(a.nation,"����");strcpy(a.status,"ʫ��");strcpy(a.introduction,"��������Ϊʫ��");
printf("%s",a.introduction); 
}
