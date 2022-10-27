/****************************************************************************

File name: �л����˿�
Description: �˳���Ϊһ�л����˴����ݿ⣬�в��ҡ����롢ɾ�����޸ĵȹ��ܣ����ҹ����ֿ����������֡���������ݷֱ����������
             Ϊ�û��ṩ�л����˼�飬���������֡��Ա������ꡢ���������塢��ݡ����ܵȡ� 
Author: Ф־�� Ԭ����
Date:2020.12.26 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*����ṹ������*/ 
struct Figure
{
char name[30];           /*��������*/ 
char courtesy[30];       /*���˱���*/
char gender[10];          /*�����Ա�*/
char birth[20];          /*��������*/
char death[20];          /*��������*/
char dynasty[20];        /*���������*/
char nation[30];         /*��������*/
char status[99];         /*�������*/
char introduction[9999]; /*���˼��*/
struct Figure *next;     /*�ṹ��ָ��*/
};

/****************************************************************************
*��������main����
*���ܣ���������չʾ���ݿ�����˵������ø����Ӻ���
*���룺��
*������� 
*/ 
main()
 {
 	int i;               /*�����Ӻ���ѡ��ֵ*/ 
 	char a='y';          /*����aֵ������ѭ��*/ 
 	struct Figure *head; /*��������ͷָ��*/
 	
 	/*�������Ӻ���*/ 
 	struct Figure *read();                     
 	void test(struct Figure *head);
 	struct Figure *insert(struct Figure *head);
 	struct Figure *del(struct Figure *head);
 	int search(struct Figure *head);
 	int mohu(char* key,char* str);
 	struct Figure *amend(struct Figure *head);
 	
 	/*�����Ӻ���read*/  
 	if((head=read())==NULL){printf("error!\n");exit(0);}
	test(head);
	
	/*���ÿ��˳�����ѭ��չʾ�˵���*/  
	while(a=='y')
   {
	printf("****************************************************************\n");
 	printf("*************		��ӭʹ���л����˿⣡		****************\n");
	printf("*1.��ѯ\n");
	printf("*2.����\n");
	printf("*3.ɾ��\n");
	printf("*4.�޸�\n"); 
	printf("*0.�˳�\n");
	printf("****************************************************************\n");
	label1:printf("\n����������ʹ�õĹ�����ţ�(����0�˳�)\n");
	scanf("%d",&i);
	switch(i)
	{
	 case 0:{printf("��л����ʹ�ã�\n");exit(0);}                          /*�˳�ѭ������������*/ 
	 case 1: {search(head);break;}                                         /*������ҹ���*/
	 case 2: {head=insert(head);break;}  /*������빦��*/
	 case 3: {head=del(head);break;}     /*����ɾ������*/
	 case 4: {head=amend(head);break;}   /*�����޸Ĺ���*/
	 default:{printf("��������ȷ����ţ�\n");goto label1;break;}
	}
   } 
 }

/****************************************************************************
*��������struct Figure *read()
*���ܣ��������ļ��ж�ȡ������Ϣ
*���룺�� 
*���������������Ϣ�����ͷָ�� 
*/ 
struct Figure *read(void)
{
	FILE *p;                       /*�����ļ�ָ��*/
	struct Figure *head,*p1,*p2;   /*����ṹ��ָ��*/
	int n=0;                       /*�������*/ 
	
	/*��ֻ����ʽ���ļ����л����˿⡱*/
	if((p=fopen("zhmrk","rb"))==NULL) {printf("file open errror!\n");fclose(p);return(NULL);} 
	
	/*���ٶ�̬�洢�ռ乹������*/ 
	p1=p2=(struct Figure *)malloc(sizeof(struct Figure));
	head=NULL;                     
	while(!feof(p))
	{  
	   if(fread(p1,sizeof(struct Figure),1,p)!=1) break;   /*�������ж���������Ϣ*/
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
*��������test��struct Figure *head) 
*���ܣ����������Ϣ
*���룺����ͷָ�� 
*������� 
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
*��������int mohu(char* key,char* str)
*���ܣ�ʹ���������ܵ���ʵ��ģ������
*���룺�����ַ���key���׵�ַ�������ַ���str���׵�ַ
*�������������f��ֵ
*/ 
int mohu(char* key,char* str)
{   
    /*���ṹ���������ñ��Element����Ϊģ�������Ա���*/
    typedef struct 
    {
      char son[9999];
    }Element;
    int i,j,k=0,l=0,m=0;
    
    int f=0;
	//f=1Ϊ����ɸѡ����
    /*N1Ϊstr�ĳ��� N2Ϊstr�����Ӵ��ĸ���*/
    int N1=0,N2=0; 
    N1=strlen(str);
    for(i=1;i<=N1;i++)/*���������Ӵ��ĸ���*/
    N2+=i;
    
	/*���������Ӵ��ĸ���*/
    Element *b=(Element *)calloc(N2,sizeof(Element));
    for(i=1;i<=N1;i++)              /*i�������ַ����ĳ���*/ 
    {
        l=0;                        /*l�����������������ԭ�����е�λ��*/
        
		/*whileѭ����Ϊ��һ�����ַ������鸳ֵ*/
        while(1)
            {
            m=l;
            for(j=0;j<i;j++)        /*j���Ƹ�ֵ*/
            {
                b[k].son[j]=str[m]; /*k�����µ����Խṹb���±�*/ 
                m++;                /*m���Ƽ���������ֵ��str���±�*/
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

/****************************************************************************
*��������void print(struct Figure *p)
*���ܣ��������ĳһ�ṹ����������г�Աֵ
*���룺ָ��������ĳһ�ṹ������ĵ�ֵַ
*�������
*/ 
void print(struct Figure *p)
{
    printf("������%s\n�ֺţ�%s\n�Ա�%s\n����%s\n�䣺%s\n������%s\n���壺%s\n��ݣ�%s\n��飺%s\n\n",p->name,p->courtesy,p->gender,p->birth,p->death,p->dynasty,p->nation,p->status,p->introduction);
}

/****************************************************************************
*��������int search (struct Figure *head)
*���ܣ����������֡���������ݽ���ģ������
*���룺����������Ϣ�������ͷָ��
*�����һ����������0
*/ 
int search(struct Figure *head)
{
	struct Figure *p,*q;
	/*�������f�����ж��Ƿ��ҵ����ѯ������ */ 
	int i,s,x,f=0;
	/*�������Ĺؼ��� �����ַ�����key�� */ 
	char key[100];
	q=p=head;
	/*����ģ�������Ӻ��� */ 
	int mohu(char* key,char* str);
    s=1;
    /*��һ����ѭ��ʵ�ֶ������  */ 
    while(s=1)
   {	
    f=0;
    printf("********************��ӭʹ�ò�ѯϵͳ��***************************\n");
	printf("*1.��������\n");
    printf("*2.�ֺ�����\n");
    printf("*3.��������\n");
    printf("*4.�������\n");
    printf("*0.�˳�\n"); 
    printf("******************************************************************\n");
    label2:printf("������������ʽ�����\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
		{
            printf("������������������\n");
            /*getchar�Ե��ո�*/  
			getchar();
			/*���������ؼ��� */ 
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
            printf("�Ҳ���������������\n");
            p=q;
            break;
        }
        case 2:
		{
            printf("������������������\n");
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
			printf("�Ҳ��������ֺŵ�����\n");
			p=q;
            break;
        }
        case 3:
		{
            printf("���������������ĳ���\n");
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
            printf("�Ҳ������Ƴ���������\n");
            p=q;
            break;
        }
        case 4:
		{
            printf("�������������������\n");
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
            printf("�Ҳ���������ݵ�����\n");
            p=q;
            break;
        }
        case 0: {return 0;break;}
        default:{printf("��������ȷ����ţ�\n");goto label2;}
    }
   }
	return 0;
}

/****************************************************************************
*�������� struct Figure *insert(struct Figure *head)
*���ܣ�ʵ�ֶ����˿����ݵĲ���
*���룺����������Ϣ�������ͷָ��
*�������������Ϣ��������ͷָ�� 
*/ 
struct Figure *insert(struct Figure *head)
{
	FILE *fp;                                                /*�ļ�ָ��*/ 
	struct Figure *p1,*p2,*q;                                /*�ṹ��ָ��*/
	int flag;                                                /*��Ϊ�����Ƿ��ظ��ı�־*/
	p1=(struct Figure *)malloc(sizeof (struct Figure));      /*�����µĴ洢�ռ����������������Ϣ*/ 
	
	/*�������������������*/ 
	printf("�������������������ϣ�\n");getchar();
	printf("����");gets(p1->name);
	printf("�֣�");gets(p1->courtesy);
	printf("�Ա�");gets(p1->gender);
	printf("���꣺");gets(p1->birth);
	printf("���꣺");gets(p1->death);
	printf("������");gets(p1->dynasty);
	printf("���壺");gets(p1->nation);
	printf("��ݣ�");gets(p1->status);
	printf("������ܣ�");gets(p1->introduction);
	printf("finished��\n");
	flag=1;                                                /*��Ϊ�����Ƿ��ظ��ı�־*/
	q=head; 
	
	/*Ѱ�������������˳�����ͬ������*/
	if(strcmp(q->dynasty,p1->dynasty)==0) p2=head;         /*�������е�һ���˾������������˳�����ͬ*/
	 else                                                  /*�����������˳�����ͬ���˲��������е�һ���˵����*/
    {
	   while(q->next!=NULL)                                
	    {if(strcmp(q->next->dynasty,p1->dynasty)==0) break;
	     else q=q->next;
	    }	
	   p2=q;
	}
	q=head;                                                 /*�ָ�����ָ��λ�ã��������ز���*/
	
	/*�����Ƿ�����ظ�������*/
	while(q!=NULL)
	  { if((strcmp(q->name,p1->name)==0)&&(strcmp(q->courtesy,p1->courtesy)==0))
	     {printf("�����Ѵ��ڣ�\n");flag=0;}
	    q=q->next;
	  }
	  
	/*�����������˲����������������ļ�*/  
	if(flag) 
	 {  /*��������*/
	    if(p2->next==NULL) {p2->next=p1;p1->next=NULL;}
	    else if(p2=head) {p1->next=p2;head=p1;}
		else {p1->next=p2->next;p2->next=p1;}
		
		/*�����ļ�*/
		q=head;
	    fp=fopen("zhmrk","wb");
	    while(q!=NULL)
	    { fwrite(q,sizeof(struct Figure),1,fp);
	      q=q->next;
	    }
	    fclose(fp);
	 }
	q=head;
    return q;                                                /*���ͷָ��ֵ*/
}

/****************************************************************************
*��������struct Figure *del(struct Figure *head) 
*���ܣ�ʵ�ֶ����ݿ���ĳһ�������ݵ�ɾ��
*���룺����������Ϣ�������ͷָ��
*�����ɾ��ĳ������Ϣ��������ͷָ�� 
*/ 
struct Figure *del(struct Figure *head)
{
	FILE *q;                             /*�ļ�ָ��*/
	struct Figure *p1,*p2;               /*�ṹ��ָ��*/
	char str1[20],str2[20];              /*�ַ����������Ҫɾ������ʷ���˵�������*/
    p1=p2=head;       
    
	/*������ɾ�����˵�������*/
	printf("��������ɾ��������������֣�\n");getchar();
	printf("����");gets(str1);
	printf("�֣�");gets(str2);
	
	/*ɾ������*/
	if((strcmp(str1,p1->name)==0)&&(strcmp(str2,p1->courtesy)==0))       /*�����еĵ�һ����Ϊ��ɾ�����˵����*/
	 {head=p1->next;free(p1);printf("ɾ����ɣ�\n");}
	else                                                                 /*�����еĵ�һ���˲�Ϊ��ɾ�����˵����*/
	 {
	    while(p1!=NULL)
		  {
		  if((strcmp(str1,p1->next->name)==0)&&(strcmp(str2,p1->next->courtesy)==0))
		    {p2=p1->next;p1->next=p2->next;free(p2);printf("ɾ����ɣ�\n");break;}
		  p1=p1->next;
	      }
	    if(p1==NULL) printf("δ�ҵ���ɾ�����\n");                     /*�ж��Ƿ���ڸ�����*/ 
     }
    
	/*��ɾ�����˺����������ļ���*/ 
	p1=p2=head;
	q=fopen("zhmrk","wb");
    while(p1!=NULL)
    {  fwrite(p1,sizeof(struct Figure),1,q);
       p1=p1->next;
	}
    return p2;                                                           /*����ɾ�����˺������ͷָ��ֵ*/ 
}

/****************************************************************************
*��������void amend(struct Figure *head)
*���ܣ��޸�������Ϣ
*���룺����ͷָ��ֵ
*�������
*��ע����ʹ���޸Ĺ���ʱ��Ҫ׼ȷ����������˵������֣���������������ȷ�ϸ����˵������ֺ��ٽ����޸ġ� 
*/ 
struct Figure *amend(struct Figure *head)

{
    struct Figure *p;
    FILE *fp;
    p=head;
    int x=0,m,n;
    char key[100],key2[100];
    printf("����������Ҫ�޸ĵ����˵�������\n");getchar();
    printf("����");gets(key);
    printf("�֣�");gets(key2);
    while(p!=NULL)
    {
        if((strcmp(p->name,key)==0)&&(strcmp(p->courtesy,key2)==0))
        {
           printf("���������ڵ������������\n");
           print(p);
         while(1)
         {
           printf("***************************��ӭʹ���޸�ϵͳ��*********************\n");
           printf("*1.�޸�����\n");
           printf("*2.�޸��ֺ�\n");
           printf("*3.�޸��Ա�\n");
           printf("*4.�޸�����\n");
           printf("*5.�޸�����\n");
           printf("*6.�޸ĳ���\n");
           printf("*7.�޸�����\n");
           printf("*8.�޸����\n");
           printf("*9.�޸ļ��\n");
           printf("*0.�˳�\n");
           printf("******************************************************************\n");
           printf("����������ʹ�õĹ�����ţ�\n");
           scanf("%d",&n);
           m=0;
           switch(n)
           {
           case 1:
            {
                printf("������������µ�����\n");
                getchar();
                gets(p->name);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 2:
            {
                printf("������������µ��ֺ�\n");
                getchar();
                gets(p->courtesy);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 3:
            {
                printf("������������µ��Ա�\n");
                getchar();
                gets(p->gender);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 4:
            {
                printf("������������µ�����\n");
                getchar();
                gets(p->birth);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 5:
            {
                printf("������������µ�����\n");
                getchar();
                gets(p->death);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 6:
            {
                printf("������������µĳ���\n");
                getchar();
                gets(p->dynasty);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 7:
            {
                printf("������������µ�����\n");
                getchar();
                gets(p->nation);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 8:
            {
                printf("������������µ����\n");
                getchar();
                gets(p->status);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 9:
            {
                printf("������������µļ��\n");
                getchar();
                gets(p->introduction);
                printf("���ڸ����˵���Ϣ����\n");
                print(p);
                break;
            }
            case 0:{p=head;goto save;}
			default :{printf("��������ȷ����ţ�\n");break;}	
           }
           x=1;}
        }
        p=p->next;
    }
    if(x==0)
        printf("���󣡲��Ҳ��������޸ĵ�����\n");
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


