//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//ģ�������ж��Ƿ����ɸѡ����
int mohu(char* key,char* str)
{
    typedef struct 
    {
      char son[11];
    }Element;
    int i,j,k=0,l=0,m=0;
    
    int f=0;//f=1Ϊ����ɸѡ����
  
  int N1=0,N2=0;//N1Ϊstr�ĳ��� N2Ϊstr�����Ӵ��ĸ���
  N1=strlen(str);
  
  for(i=1;i<=N1;i++)/*���������Ӵ��ĸ���*/
    N2+=i;
    /*���������Ӵ��ĸ���*/
    //i�������ַ����ĳ���
    //j���Ƹ�ֵ
    //k�����µ����Խṹb���±�
    //l�����������������ԭ�����е�λ��
    //m���Ƽ���������ֵ��str���±�
    Element *b=(Element *)calloc(N2,sizeof(Element));
    for(i=1;i<=N1;i++)
    {
        l=0;
        /*whileѭ����Ϊ��һ�����ַ������鸳ֵ*/
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

    //�����ȶ�
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
    printf("������%s �ֺţ�\n%s �Ա�%s \n����%s �䣺\n%s ������%s ���壺%s \nͷ�Σ�%s \n��飺%s\n\n",p->name,p->courtesy,p->gender,p->birth,p->death,p->dynasty,p->nation,p->status,p->introduction);
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
//	printf("������������������1\n");
//    printf("�����ֺ�����������2\n");
//    printf("���ó�������������3\n");
//    printf("����ͷ������������4\n");
//    scanf("%d",&x);
//    switch(x)
//    {
//        case 1:
//		{
//            printf("������������������\n");getchar();
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
//            printf("�Ҳ���������������\n");
//            p=q;
//            break;
//        }
//        case 2:
//		{
//            printf("������������������\n");getchar();
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
//			printf("�Ҳ��������ֺŵ�����\n");
//			p=q;
//            break;
//        }
//        case 3:
//		{
//            printf("���������������ĳ���\n");getchar();
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
//            printf("�Ҳ������Ƴ���������\n");
//            p=q;
//            break;
//        }
//        case 4:
//		{
//            printf("����������������ͷ��\n");getchar();
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
//            printf("�Ҳ�������ͷ�ε�����\n");
//            p=q;
//            break;
//        }
//    }
//    printf("������������������1\n������˳�������������������\n");
//    scanf("%d",&s);
//   }
//	return 0;
//}

