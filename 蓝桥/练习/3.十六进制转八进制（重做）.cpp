#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k,a=0,cur,ok;
    char s[10][100000],z[12];
    scanf("%d",&n);
    for(j=0; j<n; j++)
        scanf("%s",s[j]);
    for(j=0; j<n; j++)
    {
        ok=1;
        if(strlen(s[j])%3!=0&&a==0&&(a=(3-(strlen(s[j])%3)))!=0)    //�жϵ�ǰ�����ʮ����������λ����3�ı������λ
        {
            for(k=0; k<a*4; k++)    //����λ16���Ƶ�ת�����ƣ�����12λ�ģ���ǰ�油ȫ0
                z[k]='0';//��xλ�Ͳ�x*4�����ڶ����Ƶ�ǰ�� 
        }
        for(i=0; i<strlen(s[j]); i++)   //��ÿλ16����λ��תΪ��λ������
        {

            switch(s[j][i])
            { 
            case '0':
                z[k]='0';
                z[k+1]='0';
                z[k+2]='0';
                z[k+3]='0';
                break;
            case '1':
                z[k]='0';
                z[k+1]='0';
                z[k+2]='0';
                z[k+3]='1';
                break;
            case '2':
                z[k]='0';
                z[k+1]='0';
                z[k+2]='1';
                z[k+3]='0';
                break;
            case '3':
                z[k]='0';
                z[k+1]='0';
                z[k+2]='1';
                z[k+3]='1';
                break;
            case '4':
                z[k]='0';
                z[k+1]='1';
                z[k+2]='0';
                z[k+3]='0';
                break;
            case '5':
                z[k]='0';
                z[k+1]='1';
                z[k+2]='0';
                z[k+3]='1';
                break;
            case '6':
                z[k]='0';
                z[k+1]='1';
                z[k+2]='1';
                z[k+3]='0';
                break;
            case '7':
                z[k]='0';
                z[k+1]='1';
                z[k+2]='1';
                z[k+3]='1';
                break;
            case '8':
                z[k]='1';
                z[k+1]='0';
                z[k+2]='0';
                z[k+3]='0';
                break;
            case '9':
                z[k]='1';
                z[k+1]='0';
                z[k+2]='0';
                z[k+3]='1';
                break;
            case 'A':
                z[k]='1';
                z[k+1]='0';
                z[k+2]='1';
                z[k+3]='0';
                break;
            case 'B':
                z[k]='1';
                z[k+1]='0';
                z[k+2]='1';
                z[k+3]='1';
                break;
            case 'C':
                z[k]='1';
                z[k+1]='1';
                z[k+2]='0';
                z[k+3]='0';
                break;
            case 'D':
                z[k]='1';
                z[k+1]='1';
                z[k+2]='0';
                z[k+3]='1';
                break;
            case 'E':
                z[k]='1';
                z[k+1]='1';
                z[k+2]='1';
                z[k+3]='0';
                break;
            case 'F':
                z[k]='1';
                z[k+1]='1';
                z[k+2]='1';
                z[k+3]='1';
                break;
            }
            k+=4;
            if(k==12)   //����λʮ�����ƶ�תΪ4Ϊ�����ƺ󣬿�ʼ��12λ�����Ʊ�Ϊ��λ�˽���
            {
                for(cur=0; cur<12; cur+=3)  //��λ������cur+=3
                    if(z[cur]=='0'&&z[cur+1]=='0'&&z[cur+2]=='0')if(ok);//if(ok)�����ų�ǰ��0 
                        else putchar('0');
                    else if(z[cur]=='0'&&z[cur+1]=='0'&&z[cur+2]=='1')
                    {
                        putchar('1');
                        ok=0;
                    }
                    else if(z[cur]=='0'&&z[cur+1]=='1'&&z[cur+2]=='0')
                    {
                        putchar('2');
                        ok=0;
                    }
                    else if(z[cur]=='0'&&z[cur+1]=='1'&&z[cur+2]=='1')
                    {
                        putchar('3');
                        ok=0;
                    }
                    else if(z[cur]=='1'&&z[cur+1]=='0'&&z[cur+2]=='0')
                    {
                        putchar('4');
                        ok=0;
                        
                    }
                    else if(z[cur]=='1'&&z[cur+1]=='0'&&z[cur+2]=='1')
                    {
                        putchar('5');
                        ok=0;
                    }
                    else if(z[cur]=='1'&&z[cur+1]=='1'&&z[cur+2]=='0')
                    {
                        putchar('6');
                        ok=0;
                    }
                    else if(z[cur]=='1'&&z[cur+1]=='1'&&z[cur+2]=='1')
                    {
                        putchar('7');
                        ok=0;
                    }
                k=0;//��k��0����ʼ��������λ16���ƽ���ת��
            }
        }
        a=0;//�����j��ʮ����������λ�������ı���
        putchar('\n');
    }
    return 0;
}

