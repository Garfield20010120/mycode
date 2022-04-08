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
        if(strlen(s[j])%3!=0&&a==0&&(a=(3-(strlen(s[j])%3)))!=0)    //判断当前的这个十六进制数的位数离3的倍数还差几位
        {
            for(k=0; k<a*4; k++)    //将三位16进制的转二进制，不足12位的，在前面补全0
                z[k]='0';//差x位就补x*4个零在二进制的前面 
        }
        for(i=0; i<strlen(s[j]); i++)   //将每位16进制位数转为四位二进制
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
            if(k==12)   //当三位十六进制都转为4为二进制后，开始将12位二进制变为四位八进制
            {
                for(cur=0; cur<12; cur+=3)  //四位体现在cur+=3
                    if(z[cur]=='0'&&z[cur+1]=='0'&&z[cur+2]=='0')if(ok);//if(ok)用以排除前置0 
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
                k=0;//将k置0，开始将下面三位16进制进行转换
            }
        }
        a=0;//假设第j个十六进制数的位数是三的倍数
        putchar('\n');
    }
    return 0;
}

