#include <fstream>

using namespace std;

ifstream fin("spectacolele.in");
ofstream fout("spectacolele.out");

float start, stop, M[100][2];
int k, n, m=0, numar[100];

void citire()
{
    fin>>start>>stop;
    fin>>n;
    for(int i=1; i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {
            fin>>M[i][j];
        }
        numar[i]=i;
    }
    fin>>k;
    fin.close();
}

void sortare()
{
    int aux, schimb;
    do
    {
        schimb=0;
        for(int i=1;i<n;i++)
            if(M[numar[i]][2]>M[numar[i+1]][2])
            {
                aux=numar[i];
                numar[i]=numar[i+1];
                numar[i+1]=aux;
                schimb=1;
            }
    }
    while (schimb);
}

void compensate(int n, int k)
{
    int ora, mint, a;
    for(int i=1;i<=n;i++)
    {
        a=M[numar[i]][2]*100;
        ora=a/100;
        mint=a%100+k;
        if(mint>=60)
        {
            ora++;
            mint=mint-60;
        }
        a=(ora*100+mint)/(float)100;
        M[numar[i]][2]=a;
    }
}

int rezolvare()
{
    int ultim=0;
    for(int i=1;i<=n;i++)
    {
        if(M[numar[i]][1]>start && M[numar[i]][2]<stop)
        {
            if(M[numar[i]][1]>=M[numar[ultim]][2])
            {
                m++;
                ultim=i;
            }
        }
    }
}

int main()
{
    citire();
    sortare();
    compensate(n, k);
    rezolvare();
    fout<<m;
    fout.close();
    return 0;
}
