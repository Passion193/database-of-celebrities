//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//模糊搜索判断是否符合筛选条件
int mohu(char* key,char* str)
{
    typedef struct 
    {
      char son[11];
    }Element;
    int i,j,k=0,l=0,m=0;
    
    int f=0;//f=1为符合筛选条件
  
  int N1=0,N2=0;//N1为str的长度 N2为str连续子串的个数
  N1=strlen(str);
  
  for(i=1;i<=N1;i++)/*计算连续子串的个数*/
    N2+=i;
    /*计算连续子串的个数*/
    //i控制子字符串的长度
    //j控制赋值
    //k控制新的线性结构b的下标
    //l控制子数组的首项在原数组中的位置
    //m控制即将用作赋值的str的下标
    Element *b=(Element *)calloc(N2,sizeof(Element));
    for(i=1;i<=N1;i++)
    {
        l=0;
        /*while循环内为给一个子字符串数组赋值*/
        while(1)
            {
            m=l;
            for(j=0;j<i;j++)
            {
                b[k].son[j]=str[m];
                m++;
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

//struct Figure
//{
//char name[30];
//char courtesy[30];
//char gender[5];
//char birth[10];
//char death[10];
//char dynasty[20];
//char nation[10];
//char status[50];
//char introduction[9999];
//struct Figure *next;
//};

void print(struct Figure *p)
{
    printf("姓名：%s 字号：\n%s 性别：%s \n生：%s 卒：\n%s 朝代：%s 民族：%s \n头衔：%s \n简介：%s\n\n",p->name,p->courtesy,p->gender,p->birth,p->death,p->dynasty,p->nation,p->status,p->introduction);
}

//struct Figure *read(void)
//{
//	FILE *p;
//	struct Figure *head,*p1,*p2;
//	int n=0,t;
//	if((p=fopen("zhmrk","rb"))==NULL) {printf("file open errror!\n");fclose(p);return(NULL);}
//	p1=p2=(struct Figure *)malloc(sizeof(struct Figure));
//	head=NULL;
//	while(!feof(p))
//	{
//	   if(fread(p1,sizeof(struct Figure),1,p)!=1) {printf("read error!\n");break;}
//	   n++;
//	   if(n==1) head=p1;
//	   else p2->next=p1;
//	   p2=p1;
//	   p1=(struct Figure *)malloc(sizeof(struct Figure));
//    }
//    p2->next=NULL;
//    fclose(p);
//
//	return(head);
//}
//
//int main()
//{
//	struct Figure *p,*q;
//	int i,s,x,f=0;
//	char key[100];
//	q=p=read();
//    s=1;
//    while(s=1)
//   {	
//    f=0;
//	printf("想用姓名搜索请输入1\n");
//    printf("想用字号搜索请输入2\n");
//    printf("想用朝代搜索请输入3\n");
//    printf("想用头衔搜索请输入4\n");
//    scanf("%d",&x);
//    switch(x)
//    {
//        case 1:
//		{
//            printf("请输入你想搜索的名\n");getchar();
//            gets(key);
//            while(p!=NULL)
//            {
//                if(mohu(key,p->name))  
//				{  print(p);
//				   f=1;
//				}
//                p=p->next;
//            }
//            if(f==0)
//            printf("找不到类似名的名人\n");
//            p=q;
//            break;
//        }
//        case 2:
//		{
//            printf("请输入你想搜索的字\n");getchar();
//            gets(key);
//            while(p!=NULL)
//            {
//                if(mohu(key,p->courtesy)) 
//				{  print(p);
//				   f=1;
//				}
//                p=p->next;
//            }
//            if(f==0)   
//			printf("找不到类似字号的名人\n");
//			p=q;
//            break;
//        }
//        case 3:
//		{
//            printf("请输入你想搜索的朝代\n");getchar();
//            gets(key);
//            while(p!=NULL)
//            {
//                if(mohu(key,p->dynasty))
//                    {  print(p);
//                       f=1;
//					}
//                p=p->next;
//            }
//            if(f==0)
//            printf("找不到类似朝代的名人\n");
//            p=q;
//            break;
//        }
//        case 4:
//		{
//            printf("请输入你想搜索的头衔\n");getchar();
//            gets(key);
//            while(p!=NULL)
//            {
//                if(mohu(key,p->status))
//                    {  print(p);
//                       f=1;
//                    }
//                p=p->next;
//           }
//            if(f==0)
//            printf("找不到类似头衔的名人\n");
//            p=q;
//            break;
//        }
//    }
//    printf("如果想继续搜索请输入1\n如果想退出程序请输入其他数字\n");
//    scanf("%d",&s);
//   }
//	return 0;
//}

