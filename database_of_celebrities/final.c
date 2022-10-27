/****************************************************************************

File name: 中华名人库
Description: 此程序为一中华名人大数据库，有查找、插入、删除、修改等功能，查找功能又可利用名、字、朝代、身份分别进行搜索，
             为用户提供中华名人简介，包括名、字、性别、生卒年、朝代、民族、身份、介绍等。 
Author: 肖志超 袁振轩
Date:2020.12.26 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*定义结构体类型*/ 
struct Figure
{
char name[30];           /*名人姓名*/ 
char courtesy[30];       /*名人表字*/
char gender[10];          /*名人性别*/
char birth[20];          /*名人生年*/
char death[20];          /*名人卒年*/
char dynasty[20];        /*名人生活朝代*/
char nation[30];         /*名人民族*/
char status[99];         /*名人身份*/
char introduction[9999]; /*名人简介*/
struct Figure *next;     /*结构体指针*/
};

/****************************************************************************
*函数名：main（）
*功能：主函数，展示数据库操作菜单，调用各级子函数
*输入：无
*输出：无 
*/ 
main()
 {
 	int i;               /*调用子函数选项值*/ 
 	char a='y';          /*利用a值进行死循环*/ 
 	struct Figure *head; /*定义链表头指针*/
 	
 	/*声明各子函数*/ 
 	struct Figure *read();                     
 	void test(struct Figure *head);
 	struct Figure *insert(struct Figure *head);
 	struct Figure *del(struct Figure *head);
 	int search(struct Figure *head);
 	int mohu(char* key,char* str);
 	struct Figure *amend(struct Figure *head);
 	
 	/*调用子函数read*/  
 	if((head=read())==NULL){printf("error!\n");exit(0);}
	test(head);
	
	/*设置可退出的死循环展示菜单栏*/  
	while(a=='y')
   {
	printf("****************************************************************\n");
 	printf("*************		欢迎使用中华名人库！		****************\n");
	printf("*1.查询\n");
	printf("*2.插入\n");
	printf("*3.删除\n");
	printf("*4.修改\n"); 
	printf("*0.退出\n");
	printf("****************************************************************\n");
	label1:printf("\n请输入你想使用的功能序号：(输入0退出)\n");
	scanf("%d",&i);
	switch(i)
	{
	 case 0:{printf("感谢您的使用！\n");exit(0);}                          /*退出循环，结束程序*/ 
	 case 1: {search(head);break;}                                         /*进入查找功能*/
	 case 2: {head=insert(head);break;}  /*进入插入功能*/
	 case 3: {head=del(head);break;}     /*进入删除功能*/
	 case 4: {head=amend(head);break;}   /*进入修改功能*/
	 default:{printf("请输入正确的序号！\n");goto label1;break;}
	}
   } 
 }

/****************************************************************************
*函数名：struct Figure *read()
*功能：从已有文件中读取名人信息
*输入：无 
*输出：存有名人信息链表的头指针 
*/ 
struct Figure *read(void)
{
	FILE *p;                       /*定义文件指针*/
	struct Figure *head,*p1,*p2;   /*定义结构体指针*/
	int n=0;                       /*链表次序*/ 
	
	/*以只读方式打开文件“中华名人库”*/
	if((p=fopen("zhmrk","rb"))==NULL) {printf("file open errror!\n");fclose(p);return(NULL);} 
	
	/*开辟动态存储空间构建链表*/ 
	p1=p2=(struct Figure *)malloc(sizeof(struct Figure));
	head=NULL;                     
	while(!feof(p))
	{  
	   if(fread(p1,sizeof(struct Figure),1,p)!=1) break;   /*向链表中读入已有信息*/
	   n++;                                                
	   if(n==1) head=p1;
	   else p2->next=p1;
	   p2=p1;
	   p1=(struct Figure *)malloc(sizeof(struct Figure));
    }
    p2->next=NULL;
    fclose(p);
	return(head);
}

/****************************************************************************
*函数名：test（struct Figure *head) 
*功能：输出链表信息
*输入：链表头指针 
*输出：无 
*/ 
void test(struct Figure *head)
{
	struct Figure *q,*p;
	p=q=head;
	while(q!=NULL)
	{
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n",q->name,q->courtesy,q->gender,q->birth,q->death,q->dynasty,q->nation,q->status,q->introduction);
		q=q->next;
	}
}

/****************************************************************************
*函数名：int mohu(char* key,char* str)
*功能：使得搜索功能得以实现模糊搜索
*输入：已有字符串key的首地址与已有字符串str的首地址
*输出：整数常量f的值
*/ 
int mohu(char* key,char* str)
{   
    /*给结构体类型设置别称Element，作为模糊搜索对比量*/
    typedef struct 
    {
      char son[9999];
    }Element;
    int i,j,k=0,l=0,m=0;
    
    int f=0;
	//f=1为符合筛选条件
    /*N1为str的长度 N2为str连续子串的个数*/
    int N1=0,N2=0; 
    N1=strlen(str);
    for(i=1;i<=N1;i++)/*计算连续子串的个数*/
    N2+=i;
    
	/*计算连续子串的个数*/
    Element *b=(Element *)calloc(N2,sizeof(Element));
    for(i=1;i<=N1;i++)              /*i控制子字符串的长度*/ 
    {
        l=0;                        /*l控制子数组的首项在原数组中的位置*/
        
		/*while循环内为给一个子字符串数组赋值*/
        while(1)
            {
            m=l;
            for(j=0;j<i;j++)        /*j控制赋值*/
            {
                b[k].son[j]=str[m]; /*k控制新的线性结构b的下标*/ 
                m++;                /*m控制即将用作赋值的str的下标*/
            }
            l++;
            k++;
            if(m==N1)
                break;
            }
    }

    //挨个比对
    for(i=0;i<N2;i++)
        if(strcmp(key,b[i].son)==0)
        {
             f=1;
             break;
        }
    free(b);
    return f;
}

/****************************************************************************
*函数名：void print(struct Figure *p)
*功能：输出链表某一结构体变量的所有成员值
*输入：指向链表中某一结构体变量的地址值
*输出：无
*/ 
void print(struct Figure *p)
{
    printf("姓名：%s\n字号：%s\n性别：%s\n生：%s\n卒：%s\n朝代：%s\n民族：%s\n身份：%s\n简介：%s\n\n",p->name,p->courtesy,p->gender,p->birth,p->death,p->dynasty,p->nation,p->status,p->introduction);
}

/****************************************************************************
*函数名：int search (struct Figure *head)
*功能：利用名、字、朝代、身份进行模糊搜索
*输入：存有名人信息的链表的头指针
*输出：一个整数常量0
*/ 
int search(struct Figure *head)
{
	struct Figure *p,*q;
	/*构造变量f用于判断是否找到想查询的名人 */ 
	int i,s,x,f=0;
	/*将搜索的关键字 输入字符数组key中 */ 
	char key[100];
	q=p=head;
	/*调用模糊搜索子函数 */ 
	int mohu(char* key,char* str);
    s=1;
    /*用一个死循环实现多次搜索  */ 
    while(s=1)
   {	
    f=0;
    printf("********************欢迎使用查询系统！***************************\n");
	printf("*1.姓名搜索\n");
    printf("*2.字号搜索\n");
    printf("*3.朝代搜索\n");
    printf("*4.身份搜索\n");
    printf("*0.退出\n"); 
    printf("******************************************************************\n");
    label2:printf("请输入搜索方式的序号\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
		{
            printf("请输入你想搜索的名\n");
            /*getchar吃掉空格*/  
			getchar();
			/*输入搜索关键字 */ 
            gets(key);
            while(p!=NULL)
            {
                if(  mohu(key,p->name))  
				{  print(p);
				   f=1;
				}
                p=p->next;
            }
            if(f==0)
            printf("找不到类似名的名人\n");
            p=q;
            break;
        }
        case 2:
		{
            printf("请输入你想搜索的字\n");
			getchar();
            gets(key);
            while(p!=NULL)
            {
                if(  mohu(key,p->courtesy)) 
				{  print(p);
				   f=1;
				}
                p=p->next;
            }
            if(f==0)   
			printf("找不到类似字号的名人\n");
			p=q;
            break;
        }
        case 3:
		{
            printf("请输入你想搜索的朝代\n");
			getchar();
            gets(key);
            while(p!=NULL)
            {
                if(  mohu(key,p->dynasty))
                    {  print(p);
                       f=1;
					}
                p=p->next;
            }
            if(f==0)
            printf("找不到类似朝代的名人\n");
            p=q;
            break;
        }
        case 4:
		{
            printf("请输入你想搜索的身份\n");
			getchar();
            gets(key);
            while(p!=NULL)
            {
                if(  mohu(key,p->status))
                    {  print(p);
                       f=1;
                    }
                p=p->next;
           }
            if(f==0)
            printf("找不到类似身份的名人\n");
            p=q;
            break;
        }
        case 0: {return 0;break;}
        default:{printf("请输入正确的序号！\n");goto label2;}
    }
   }
	return 0;
}

/****************************************************************************
*函数名： struct Figure *insert(struct Figure *head)
*功能：实现对名人库数据的插入
*输入：存有名人信息的链表的头指针
*输出：插入新信息后的链表的头指针 
*/ 
struct Figure *insert(struct Figure *head)
{
	FILE *fp;                                                /*文件指针*/ 
	struct Figure *p1,*p2,*q;                                /*结构体指针*/
	int flag;                                                /*作为名人是否重复的标志*/
	p1=(struct Figure *)malloc(sizeof (struct Figure));      /*开辟新的存储空间存放欲插入的名人信息*/ 
	
	/*输入欲插入的名人资料*/ 
	printf("输入你想插入的名人资料：\n");getchar();
	printf("名：");gets(p1->name);
	printf("字：");gets(p1->courtesy);
	printf("性别：");gets(p1->gender);
	printf("生年：");gets(p1->birth);
	printf("卒年：");gets(p1->death);
	printf("朝代：");gets(p1->dynasty);
	printf("民族：");gets(p1->nation);
	printf("身份：");gets(p1->status);
	printf("人物介绍：");gets(p1->introduction);
	printf("finished！\n");
	flag=1;                                                /*作为名人是否重复的标志*/
	q=head; 
	
	/*寻找与欲插入名人朝代相同的名人*/
	if(strcmp(q->dynasty,p1->dynasty)==0) p2=head;         /*若链表中第一个人就与欲插入名人朝代相同*/
	 else                                                  /*与欲插入名人朝代相同的人不是链表中第一个人的情况*/
    {
	   while(q->next!=NULL)                                
	    {if(strcmp(q->next->dynasty,p1->dynasty)==0) break;
	     else q=q->next;
	    }	
	   p2=q;
	}
	q=head;                                                 /*恢复链表指针位置，进行验重操作*/
	
	/*检验是否插入重复的名人*/
	while(q!=NULL)
	  { if((strcmp(q->name,p1->name)==0)&&(strcmp(q->courtesy,p1->courtesy)==0))
	     {printf("人物已存在！\n");flag=0;}
	    q=q->next;
	  }
	  
	/*将欲插入名人插入链表，进而存入文件*/  
	if(flag) 
	 {  /*插入链表*/
	    if(p2->next==NULL) {p2->next=p1;p1->next=NULL;}
	    else if(p2=head) {p1->next=p2;head=p1;}
		else {p1->next=p2->next;p2->next=p1;}
		
		/*存入文件*/
		q=head;
	    fp=fopen("zhmrk","wb");
	    while(q!=NULL)
	    { fwrite(q,sizeof(struct Figure),1,fp);
	      q=q->next;
	    }
	    fclose(fp);
	 }
	q=head;
    return q;                                                /*输出头指针值*/
}

/****************************************************************************
*函数名：struct Figure *del(struct Figure *head) 
*功能：实现对数据库中某一名人数据的删除
*输入：存有名人信息的链表的头指针
*输出：删除某名人信息后的链表的头指针 
*/ 
struct Figure *del(struct Figure *head)
{
	FILE *q;                             /*文件指针*/
	struct Figure *p1,*p2;               /*结构体指针*/
	char str1[20],str2[20];              /*字符串，存放想要删除的历史名人的名和字*/
    p1=p2=head;       
    
	/*输入欲删除名人的名和字*/
	printf("输入你想删除的人物的名与字：\n");getchar();
	printf("名：");gets(str1);
	printf("字：");gets(str2);
	
	/*删除名人*/
	if((strcmp(str1,p1->name)==0)&&(strcmp(str2,p1->courtesy)==0))       /*链表中的第一个人为欲删除名人的情况*/
	 {head=p1->next;free(p1);printf("删除完成！\n");}
	else                                                                 /*链表中的第一个人不为欲删除名人的情况*/
	 {
	    while(p1!=NULL)
		  {
		  if((strcmp(str1,p1->next->name)==0)&&(strcmp(str2,p1->next->courtesy)==0))
		    {p2=p1->next;p1->next=p2->next;free(p2);printf("删除完成！\n");break;}
		  p1=p1->next;
	      }
	    if(p1==NULL) printf("未找到欲删除人物！\n");                     /*判断是否存在该名人*/ 
     }
    
	/*将删除名人后的链表存入文件中*/ 
	p1=p2=head;
	q=fopen("zhmrk","wb");
    while(p1!=NULL)
    {  fwrite(p1,sizeof(struct Figure),1,q);
       p1=p1->next;
	}
    return p2;                                                           /*返回删除名人后的链表头指针值*/ 
}

/****************************************************************************
*函数名：void amend(struct Figure *head)
*功能：修改名人信息
*输入：链表头指针值
*输出：无
*备注：因使用修改功能时需要准确的输入该名人的名和字，可先用搜索功能确认该名人的名和字后再进行修改。 
*/ 
struct Figure *amend(struct Figure *head)

{
    struct Figure *p;
    FILE *fp;
    p=head;
    int x=0,m,n;
    char key[100],key2[100];
    printf("请输入你想要修改的名人的名和字\n");getchar();
    printf("名：");gets(key);
    printf("字：");gets(key2);
    while(p!=NULL)
    {
        if((strcmp(p->name,key)==0)&&(strcmp(p->courtesy,key2)==0))
        {
           printf("该名人现在的相关数据如下\n");
           print(p);
         while(1)
         {
           printf("***************************欢迎使用修改系统！*********************\n");
           printf("*1.修改姓名\n");
           printf("*2.修改字号\n");
           printf("*3.修改性别\n");
           printf("*4.修改生年\n");
           printf("*5.修改卒年\n");
           printf("*6.修改朝代\n");
           printf("*7.修改民族\n");
           printf("*8.修改身份\n");
           printf("*9.修改简介\n");
           printf("*0.退出\n");
           printf("******************************************************************\n");
           printf("请输入您想使用的功能序号：\n");
           scanf("%d",&n);
           m=0;
           switch(n)
           {
           case 1:
            {
                printf("请输入该名人新的姓名\n");
                getchar();
                gets(p->name);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 2:
            {
                printf("请输入该名人新的字号\n");
                getchar();
                gets(p->courtesy);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 3:
            {
                printf("请输入该名人新的性别\n");
                getchar();
                gets(p->gender);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 4:
            {
                printf("请输入该名人新的生年\n");
                getchar();
                gets(p->birth);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 5:
            {
                printf("请输入该名人新的卒年\n");
                getchar();
                gets(p->death);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 6:
            {
                printf("请输入该名人新的朝代\n");
                getchar();
                gets(p->dynasty);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 7:
            {
                printf("请输入该名人新的民族\n");
                getchar();
                gets(p->nation);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 8:
            {
                printf("请输入该名人新的身份\n");
                getchar();
                gets(p->status);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 9:
            {
                printf("请输入该名人新的简介\n");
                getchar();
                gets(p->introduction);
                printf("现在该名人的信息如下\n");
                print(p);
                break;
            }
            case 0:{p=head;goto save;}
			default :{printf("请输入正确的序号！\n");break;}	
           }
           x=1;}
        }
        p=p->next;
    }
    if(x==0)
        printf("错误！查找不到你想修改的名人\n");
        save:p=head;
        fp=fopen("zhmrk","wb");
        while(p!=NULL)
        {fwrite(p,sizeof(struct Figure),1,fp);
         p=p->next;
		}
		fclose(fp);
		p=head;
        return p;
}


