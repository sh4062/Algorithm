#include<stdio.h>
int couple[100000];
int man[100000]={0};
#define MAX 100000
int ans[100000]={0};
int main()
{
    int n,i=0;
    int a,b;
    scanf("%d",&n);
    for(i=0;i<MAX;i++)
        couple[i]=-1;       //��ʼ��Ϊ-1��Ϊ�˱����IDΪ00000�Ŀ�����ɸ��ţ��������ʼ������ôû�ж���Ŀ���ͨͨ�ᱻ��Ϊ�����IDΪ00000
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        couple[a]=b;        //�����±��ʾ����ID��Ԫ��ֵ��ʾ������ID
        couple[b]=a;
    }
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a);
        man[a]=1;       //�±��ʾ����ID��ֵΪ1��ʾ�ÿ������ˣ�Ϊ0��ʾû��
    }
    int cnt = 0,j=0;
    for(i=0;i<MAX;i++)
        if(man[i]==1&&man[couple[i]]!=1)
        {
            cnt++;
            ans[j]=i;
            j++;
        }
    printf("%d\n",cnt);
    if(cnt==0)
        return 0;
    for(i=0;i<j-1;i++)
    {
        printf("%05d ",ans[i]);
    }
    printf("%05d",ans[j-1]);
    return 0;
}