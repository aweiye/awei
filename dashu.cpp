#include <iostream>  
#include <cstring>  
using namespace std;  
class BigNum  
{  
private:  
    char *num;  
    int length;  
public :  
    BigNum();  
    BigNum(const char *);  
    BigNum(const BigNum & bigNum);  
    int print();  
    BigNum operator + (BigNum);  
    BigNum & operator =(BigNum);  
};  
BigNum & BigNum::operator = (BigNum bigNum)  
{  
    this->length=bigNum.length;  
    delete this->num;  
    this->num=new char[this->length+1];  
    for(int i=0;i<this->length;i++)  
    {  
        this->num[i]=bigNum.num[i];  
    }  
    this->num[length]='\0';  
    return *this;  
}  
BigNum::BigNum()  
{  
    this->length=0;  
}  
BigNum::BigNum(const char *bigNum)  
{  
    this->length=strlen(bigNum);  
    num=new char[length+1];  
    for(int i=0;i<length;i++)  
    {  
        this->num[i]=bigNum[length-1-i];  
    }  
}  
BigNum::BigNum(const BigNum & bigNum)  
{  
    this->length=bigNum.length;  
    this->num=new char[this->length+1];  
    for(int i=0;i<this->length;i++)  
    {  
        this->num[i]=bigNum.num[i];  
    }  
    this->num[length]='\0';  
}  
int BigNum::print()  
{  
    for(int i=length-1;i>=0;i--)  
        cout<<this->num[i];  
    return this->length;  
}  
BigNum BigNum::operator + (BigNum bigNum)  
{  
    char * a;  
    int length=max(this->length,bigNum.length);  
    a=new char[length+2];  
    int car=0;  
    int i;  
    for(i=0;i<length||car!=0;i++)  
    {  
        car=this->num[i]-'0'+bigNum.num[i]-'0'+car;  
        a[i]=car%10+'0';  
        car/=10;  
    }  
    a[i]='\0';  
    delete this->num;  
    this->num=a;  
    return *this;  
     
}  
int main()  
{  
    BigNum bigNum_1("123456");  
    BigNum bigNum_2(bigNum_1);  
    bigNum_1.print();  
    cout<<endl;  
    bigNum_2.print();  
    cout<<endl;  
    bigNum_1=bigNum_2+bigNum_1;  
    bigNum_1.print();  
    return 0;  
}
