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
	strcpy(a.name,"���");strcpy(a.courtesy,"̫��");strcpy(a.gender,"��");
	strcpy(a.birth,"701");strcpy(a.death,"762");strcpy(a.dynasty,"�Ƴ�"); 
	strcpy(a.nation,"����");strcpy(a.status,"ʫ��");a.next=&b;
	strcpy(a.introduction,"������ܻ�����ׯ˼��Ӱ�죬�С���̫�׼���������ʫ���ж�����ʱд�ģ��������С���®ɽ�ٲ�������·�ѡ�������ѡ��������ơ������ø������緢�׵۳ǡ��ȶ��ס�");
    strcpy(b.name,"�Ÿ�");strcpy(b.courtesy,"����");strcpy(b.gender,"��");
	strcpy(b.birth,"712");strcpy(b.death,"770");strcpy(b.dynasty,"�Ƴ�");
	strcpy(b.nation,"����");strcpy(b.status,"ʫ��"); 	b.next=&c;
	strcpy(b.introduction,"testagain��"); 
    strcpy(c.name,"������");strcpy(c.courtesy,"Զ��");strcpy(c.gender,"��");
	strcpy(c.birth,"1785");strcpy(c.death,"1850");strcpy(c.dynasty,"�峯");
	strcpy(c.nation,"����");strcpy(c.status,"����������������μҡ����¼ҡ���ѧ�ҡ�˼��ҡ���ʷ��ˮ����"); c.next=NULL;
	strcpy(c.introduction,"����ȡ��");
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
