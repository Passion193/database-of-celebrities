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

void print(struct Figure *p)
{
    printf("������%s �ֺţ�\n%s �Ա�%s \n����%s �䣺\n%s ������%s ���壺%s \nͷ�Σ�%s \n��飺%s\n\n",p->name,p->courtesy,p->gender,p->birth,p->death,p->dynasty,p->nation,p->status,p->introduction);
}

