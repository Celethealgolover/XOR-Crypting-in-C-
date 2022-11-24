#include <iostream>
#include <fstream>
#include <cstring>
#define max_size 10001
using namespace std;
struct student {
unsigned int student_id;
unsigned int bit_number;
char name[30];
}v[max_size];
int n,primary,secondary;
void read()
{
    cout<<"Insert the number of students of this data base:";
    cin>>n;
    cout<<"Insert the primary encoding key:";
    cin>>primary;
    cout<<"Insert the secondary encoding key:";
    cin>>secondary;
    for(int i=1;i<=n;i+=1)
    {
        cout<<"Student nr "<<i<<" id:";
        cin>>v[i].student_id;
        cout<<"Student nr "<<i<<" name:";
        cin.get();
        cin.get(v[i].name,30);
        cin.get();
    }
    return;
}
void encode_name(char*s)
{
   char p[30];
   int dim=strlen(s);
   for(int i=0;i<dim;i++)
      p[i]=s[dim-1-i];
   p[dim]=NULL;
   strcpy(s,p);
   return;
}
void encode_id(unsigned int&x,int primary_key,int secondary_key,int poz)
{
   int copy=x,nr=0;
   while(copy)
   {
       nr++;
       copy>>=1;
   }
   v[poz].bit_number=nr;
   for(int i=1;i<=primary_key;i++)
   {
       if(x&1)
       {
           x>>=1;
           x+=(1<<(nr-1));
       }
       else x>>=1;
   }
   x^=secondary_key;
   return;
}
void encode_data(student v[],int primary_key,int secondary_key)
{
   for(int i=1;i<=n;i++)
    {
        encode_name(v[i].name);
        encode_id(v[i].student_id,primary_key,secondary_key,i);
    }
   return;
}
void write_encoded_data()
{
    ofstream g;
    g.open("encoded_data",ios::out);
    for(int i=1;i<=n;i++)
    {
        g<<v[i].name<<"x"<<v[i].student_id*1000+primary*100+secondary*10+v[i].bit_number<<'\n';
    }
    g.close();
    return;
}
void decode_id(int &x,int primary_key,int secondary_key,int nr)
{
    x^=secondary_key;
    for(int i=1;i<=primary_key;i++)
    {
       if(x&(1<<(nr-1)))
         {
            x-=(1<<(nr-1));
            x<<=1;
            x++;
         }
       else x<<=1;
    }
    return;
}
void decode_name(char*s)
{
   char p[30];
   int dim=strlen(s);
   for(int i=0;i<dim;i++)
      p[i]=s[dim-1-i];
   p[dim]=NULL;
   strcpy(s,p);
   return;
}
void decode_data()
{
    n=2;
    ifstream f;
    ofstream g;
    char s[30];
    int x,primarry,secondarry,bits,nr;
    f.open("encoded_data",ios::in);
    g.open("decoded_data",ios::out);
    for(int i=1;i<=n;i+=1)
    {
        f.get(s,30,'x');
        f.get();
        f>>x;
        nr=x/1000;
        primarry=x/100%10;
        secondarry=x/10%10;
        bits=x%10;
        decode_id(nr,primarry,secondarry,bits);
        decode_name(s);
        g<<nr<<" "<<s<<'\n';
    }
}
int main()
{

    /*read();
    encode_data(v,primary,secondary);
    write_encoded_data();*/
    decode_data();
    return 0;
}
