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

void print(struct Figure *p)
{
    printf("姓名：%s 字号：\n%s 性别：%s \n生：%s 卒：\n%s 朝代：%s 民族：%s \n头衔：%s \n简介：%s\n\n",p->name,p->courtesy,p->gender,p->birth,p->death,p->dynasty,p->nation,p->status,p->introduction);
}

