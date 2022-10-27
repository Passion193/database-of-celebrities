#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Figure
{
char name[30];
char courtesy[30];
char gender[10];
char birth[20];
char death[20];
char dynasty[20];
char nation[30];
char status[99];
char introduction[9999];
struct Figure *next;
};

main()
{
	FILE *p1;
	struct Figure *p2,*head;
	struct Figure a,b,c,d,e,f,g,h,i;
	strcpy(a.name,"李白");strcpy(a.courtesy,"太白");strcpy(a.gender,"男");
	strcpy(a.birth,"701");strcpy(a.death,"762");strcpy(a.dynasty,"唐朝"); 
	strcpy(a.nation,"汉族");strcpy(a.status,"诗人");a.next=&b;
	strcpy(a.introduction,"李白深受黄老列庄思想影响，有《李太白集》传世，诗作中多以醉时写的，代表作有《望庐山瀑布》《行路难》《蜀道难》《将进酒》《明堂赋》《早发白帝城》等多首。");
    strcpy(b.name,"杜甫");strcpy(b.courtesy,"子美");strcpy(b.gender,"男");
	strcpy(b.birth,"712");strcpy(b.death,"770");strcpy(b.dynasty,"唐朝");
	strcpy(b.nation,"汉族");strcpy(b.status,"诗人"); 	b.next=&c;
	strcpy(b.introduction,"testagain！"); 
    strcpy(c.name,"林则徐");strcpy(c.courtesy,"远抚");strcpy(c.gender,"男");
	strcpy(c.birth,"1785");strcpy(c.death,"1850");strcpy(c.dynasty,"清朝");
	strcpy(c.nation,"汉族");strcpy(c.status,"清代中期名臣、政治家、军事家、文学家、思想家、历史治水名人"); c.next=NULL;
	strcpy(c.introduction,"舍生取义");
	head=&a;p2=head;
	if((p1=fopen("zhmrk","wb+"))==NULL) 
	{printf("cannot open this file!\n");exit(0);}
	while(p2!=NULL)
	{   fwrite(p2,sizeof(struct Figure),1,p1);
//	    fprintf(p1,"\n");
	    p2=p2->next;
	}
	fclose(p1);
}
