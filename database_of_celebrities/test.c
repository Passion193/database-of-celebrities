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
	strcpy(a.name,"李白");strcpy(a.courtesy,"太白");strcpy(a.gender,"男");
	strcpy(a.birth,"AC701年");strcpy(a.death,"AC762年");strcpy(a.dynasty,"唐朝"); 
	strcpy(a.nation,"汉族");strcpy(a.status,"诗人");strcpy(a.introduction,"被后人誉为诗仙");
printf("%s",a.introduction); 
}
