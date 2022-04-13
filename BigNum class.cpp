#include <iostream>
using namespace std;
#define N 100

/*BigNum������ݳ�Ա������
��˽�����ݳ�Ա����ֵ��num(char []��)��
BigNum���Ա����������
���вι��캯��BigNum(char c[])�Ϳ������캯��BigNum(const  BigNum  &)�������вι��캯������Ĭ��ֵΪ"+0"�������Ϣ"BigNum Constructor run"���������캯�������Ϣ"BigNum CopyConstructor run"
�������������������������Ϣ"BigNum Destructor run"
�۹��к�����Աvoid  setNum(char c[])��char const *getNum(void) const�ֱ𷵻غ�������ֵ��
�����ء�+���������ʵ������BigNum������ӵ�����
�����ء�-���������ʵ������BigNum�������������
�޹��г�Ա����void show() const������ʾBigNum�������Ϣ����ʾ��ʽΪ��BigNum(<��ֵ��>)*/

#include<cstring>
class BigNum
{
private:
    char num[N];
public:
    BigNum( char c[N] = "+0" );
    BigNum( const BigNum &p );
    ~BigNum()
    {
        cout<<"BigNum Destructor run"<<endl;
    }
    void setNum( char c[N] );
    char const * getNum(void) const;
    BigNum operator + ( const BigNum &a );
    BigNum operator - (  BigNum &b );
    void show() const;
};


BigNum::BigNum( char c[N] )
{
    int i,j,a = strlen(c);
    if( c[0] != '-')
    {
        num[0] = '+';
        if( c )
        {
            for( i=strlen(c), j=0; i>=1; i--,j++)
            {
                num[i] = c[j];
            }
        }
        num[a+1] = '\0';
    }
    else
    {
        num[0] = c[0];
        for( i=strlen(c)-1, j=1; i>=1; i--,j++)
        {
            num[i] = c[j];
        }
        num[a] = '\0';
    }
    cout<<"BigNum Constructor run"<<endl;
}

BigNum::BigNum( const BigNum &p )
{
    int i=0;
    if(p.num)
    {
        while( p.num[i] != '\0' )
        {
            num[i] = p.num[i];
            i++;
        }
        num[i] = '\0';
    }
    cout<<"BigNum CopyConstructor run"<<endl;
}

void BigNum::setNum( char c[N] )
{
    int i,j,a = strlen(c);
    if( c[0] != '-')
    {
        num[0] = '+';
        if( c )
        {
            for( i=strlen(c), j=0; i>=1; i--,j++)
            {
                num[i] = c[j];
            }
        }
        num[a+1] = '\0';
    }
    else
    {
        num[0] = c[0];
        for( i=strlen(c)-1, j=1; i>=1; i--,j++)
        {
            num[i] = c[j];
        }
        num[a] = '\0';
    }
}

char const * BigNum::getNum(void) const
{
    return num;
}

BigNum BigNum::operator + ( const BigNum &a )
{
    BigNum s;
    BigNum s2(a);
    int i;
    int len1 = strlen(num);
    int len2 = strlen(s2.num);
    int Max=0;
    if( len1 > len2)
    {
        Max = len1;
        num[len1] = '0';
        for( i=len2; i<=len1; i++)
        {
            s2.num[i] = '0';
        }
    }
    else
    {
        if( len1 < len2)
        {
            Max = len2;
            s2.num[len2] = '0';
            for( i=len1; i<=len2; i++)
            {
                num[i] = '0';
            }
        }
        else
        {
            Max = len1;
            s2.num[len2] = '0';
            num[len1] = '0';
        }
    }
    if( (num[0]=='+' && s2.num[0]=='+') || (num[0]=='-' && s2.num[0]=='-') )
    {
        for( i=1; i<=Max; i++)
        {
            int c = ( (num[i]-'0') + (s2.num[i]-'0') );
            if( c>= 10 )
            {
                c -= 10;
                s.num[i] = char( c +'0');
                s2.num[i+1]++;
            }
            else
            {
                s.num[i] = char( c + '0');
            }
        }
        s.num[i] = '\0';
        if(num[0]=='+' && s2.num[0]=='+')
        {
            s.num[0] = '+';
        }
        if(num[0]=='-' && s2.num[0]=='-' )
        {
            s.num[0] = '-';
        }
    }
    if(num[0]=='+' && s2.num[0]=='-')
    {
        s2.num[0] = '+';
        char s1[N];
        char s3[N];
        int j;
        for( i=Max,j=0; i>0; j++,i--)
        {
            s1[j] = num[i];
        }
        s1[j] = '\0';
        for( i=Max,j=0; i>0; j++,i--)
        {
            s3[j] = s2.num[i];
        }
        s3[j] = '\0';
        if( strcmp(s1,s3)>0 )
        {
            s.num[0] = '+';
            for( i=1; i<=Max; i++)
            {
                int c = ( (num[i]-'0') - (s2.num[i]-'0'));
                if( c<0 )
                {
                    c+=10;
                    s.num[i] = char( c + '0');
                    num[i+1]--;
                }
                else
                {
                    s.num[i] = char( c + '0');
                }
            }
            s.num[i] = '\0';
        }
        else
        {
            if( strcmp(s1,s3)<0 )
            {
                s.num[0] = '-';
                for( i=1; i<=Max; i++)
                {
                    int c = ( (s2.num[i]-'0') - (num[i]-'0'));

                    if( c<0 )
                    {
                        c+=10;
                        s.num[i] = char( c + '0');

                        s2.num[i+1]--;
                    }
                    else
                    {
                        s.num[i] = char( c + '0');

                    }
                }
                s.num[i] = '\0';
            }
            else
            {
                s.num[0] = '+';
                s.num[1] = '0';
                s.num[2] = '\0';
            }
        }
    }
    if(num[0]=='-' && s2.num[0]=='+')
    {
        num[0] = '+';
        for( i=0; num[i]!='\0'; i++ )
        {
            char ch;
            ch = num[i];
            num[i] = s2.num[i];
            s2.num[i] = ch;
        }
        char s1[N];
        char s3[N];
        int j;
        for( i=Max,j=0; i>0; j++,i--)
        {
            s1[j] = num[i];
        }
        s1[j] = '\0';
        for( i=Max,j=0; i>0; j++,i--)
        {
            s3[j] = s2.num[i];
        }
        s3[j] = '\0';
        if( strcmp(s1,s3)>0 )
        {
            s.num[0] = '+';
            for( i=1; i<=Max; i++)
            {
                int c = ( (num[i]-'0') - (s2.num[i]-'0'));
                if( c<0 )
                {
                    c+=10;
                    s.num[i] = char( c + '0');
                    num[i+1]--;
                }
                else
                {
                    s.num[i] = char( c + '0');
                }
            }
            s.num[i] = '\0';
        }
        else
        {
            if( strcmp(s1,s3)<0 )
            {
                s.num[0] = '-';
                for( i=1; i<=Max; i++)
                {
                    int c = ( (s2.num[i]-'0') - (num[i]-'0'));

                    if( c<0 )
                    {
                        c+=10;
                        s.num[i] = char( c + '0');

                        s2.num[i+1]--;
                    }
                    else
                    {
                        s.num[i] = char( c + '0');

                    }
                }
                s.num[i] = '\0';
            }
            else
            {
                s.num[0] = '+';
                s.num[1] = '0';
                s.num[2] = '\0';
            }
        }
    }
    return s;
}

BigNum BigNum::operator - (  BigNum &b )
{
    BigNum s;
    BigNum s2(b);
    int i;
    int len1 = strlen(num);
    int len2 = strlen(s2.num);
    int Max=0;
    if( len1 > len2)
    {
        Max = len1;
        num[len1] = '0';
        for( i=len2; i<=len1; i++)
        {
            s2.num[i] = '0';
        }
    }
    else
    {
        if( len1 < len2 )
        {
            Max = len2;
            s2.num[len2] = '0';
            for( i=len1; i<=len2; i++)
            {
                num[i] = '0';
            }
        }
        else
        {
            Max = len1;
            s2.num[len2] = '0';
            num[len1] = '0';
        }
    }
    if( (num[0]=='+' && s2.num[0]=='+') || (num[0]=='-' && s2.num[0]=='-') )
    {
        if(num[0]=='-' && s2.num[0]=='-')
        {
            s2.num[0] = '+';
            num[0] = '+';
            for( i=0; num[i]!='\0'; i++ )
            {
                char ch;
                ch = num[i];
                num[i] = s2.num[i];
                s2.num[i] = ch;
            }
        }
        char s1[N];
        char s3[N];
        int j;
        for( i=Max,j=0; i>0; j++,i--)
        {
            s1[j] = num[i];
        }
        s1[j] = '\0';
        for( i=Max,j=0; i>0; j++,i--)
        {
            s3[j] = s2.num[i];
        }
        s3[j] = '\0';
        if( strcmp(s1,s3)>0 )
        {
            s.num[0] = '+';
            for( i=1; i<=Max; i++)
            {
                int c = ( (num[i]-'0') - (s2.num[i]-'0'));
                if( c<0 )
                {
                    c+=10;
                    s.num[i] = char( c + '0');
                    num[i+1]--;
                }
                else
                {
                    s.num[i] = char( c + '0');
                }
            }
            s.num[i] = '\0';
        }
        else
        {
            if( strcmp(s1,s3)<0 )
            {
                s.num[0] = '-';
                for( i=1; i<=Max; i++)
                {
                    int c = ( (s2.num[i]-'0') - (num[i]-'0'));

                    if( c<0 )
                    {
                        c+=10;
                        s.num[i] = char( c + '0');

                        s2.num[i+1]--;
                    }
                    else
                    {
                        s.num[i] = char( c + '0');

                    }
                }
                s.num[i] = '\0';
            }
            else
            {
                s.num[0] = '+';
                s.num[1] = '0';
                s.num[2] = '\0';
            }
        }
    }

    if(num[0]=='+' && s2.num[0]=='-')
    {
        s2.num[0] = '+';
        for( i=1; i<=Max; i++)
        {
            int c = ( (num[i]-'0') + (s2.num[i]-'0') );
            if( c>= 10 )
            {
                c -= 10;
                s.num[i] = char( c +'0');
                s2.num[i+1]++;
            }
            else
            {
                s.num[i] = char( c + '0');
            }
        }
        s.num[i] = '\0';
        s.num[0] = '+';
    }


    if(num[0]=='-' && s2.num[0]=='+')
    {
        s2.num[0] = '-';
        for( i=1; i<=Max; i++)
        {
            int c = ( (num[i]-'0') + (s2.num[i]-'0') );
            if( c>= 10 )
            {
                c -= 10;
                s.num[i] = char( c +'0');
                s2.num[i+1]++;
            }
            else
            {
                s.num[i] = char( c + '0');
            }
        }
        s.num[i] = '\0';
        s.num[0] = '-';
    }
    return s;
}

void BigNum::show() const
{
    char ch[N] = "+0";
    char c[N] = "+00";
    //cout<<num<<endl;
    if( strcmp(ch,num) == 0 || strcmp(c,num) == 0 )
    {
        cout<<"BigNum("<<ch<<")"<<endl;
    }
    else
    {
        cout<<"BigNum("<<num[0];
        int i;
        int flag;
        for( i=strlen(num)-1; i>=0; i--)
        {
            if(num[i]!='0')
            {
                flag = i;
                break;
            }
        }
        for( i=flag; i>=1; i--)
        {
            cout<<num[i];
        }
        cout<<")"<<endl;
    }
}
//������
int main(void)
{
    char c[100],op;
    cin>>c;
    BigNum b1(c),b2(b1);
    b1.show();
    cin>>c;
    b2.setNum(c);
    b2.show();
    cin>>op;
    if(op=='+') (b1+b2).show();
    if(op=='-') (b1-b2).show();
    return 0;
}
