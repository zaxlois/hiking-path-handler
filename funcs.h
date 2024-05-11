#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct route
{
    char start[50],finish[50];
    int length,up,down,maxAlt,minAlt;
};

void readString(char s[],int length)
{
    fgets(s,length,stdin);
    s[strcspn(s,"\n")]='\0';

}

struct route *readFromInput(int *k)
{
    struct route *a;
    int num;
    scanf("%d",&num);
    a = malloc(num * sizeof(struct route));
    for (int i=0;i<num;i++)
    {
        scanf(" ");
        readString(a[i].start,50);
        scanf("%d %d %d %d %d",&a[i].length,&a[i].up,&a[i].down,&a[i].maxAlt,&a[i].minAlt);
        scanf(" ");
        readString(a[i].finish,50);
    }
    *k=num;
    return a;
}

void printData(struct route a[],int k)
{
    int i;
    int bs[40000],estGo[k],estBack[k];

    for (i=0;i<40000;i++)
        bs[i]=-1;

    for (i=0;i<k;i++)
        bs[a[i].length]=i;

    for (i=0;i<k;i++)
    {
        estGo[i]=round(a[i].length/65.0+a[i].up/10.0);
        if (strcmp(a[i].start,a[i].finish)==0)
            estBack[i]=0;
        else
            estBack[i]= round(a[i].length/65.0+a[i].down/10.0);
    }

    for (i=39999;i>=0;i--)
    {
        if (strcmp(a[bs[i]].start,a[bs[i]].finish)==0 && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
        else if (bs[i]!=-1)
        {
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
        }
    }
}

void findShort(struct route a[],int k)
{
    int num;
    scanf("%d",&num);

    int i,bs[40000],estGo[k],estBack[k];

    for (i=0;i<40000;i++)
        bs[i]=-1;

    for (i=0;i<k;i++)
        if (a[i].length<=num)
            bs[a[i].length]=i;

    for (i=0;i<k;i++)
    {
        estGo[i]=round(a[i].length/65.0+a[i].up/10.0);
        if (strcmp(a[i].start,a[i].finish)==0)
            estBack[i]=0;
        else
            estBack[i]= round(a[i].length/65.0+a[i].down/10.0);
    }

    for (i=39999;i>=0;i--)
    {
        if (strcmp(a[bs[i]].start,a[bs[i]].finish)==0 && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
        else if (bs[i]!=-1)
        {
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
        }
    }
}

void findLocation(struct route a[],int k)
{
    char name[50];
    fgets(name,50,stdin);
    name[strcspn(name,"\n")]='\0';

    int i,bs[40000],estGo[k],estBack[k];

    for (i=0;i<40000;i++)
        bs[i]=-1;

    for (i=0;i<k;i++)
        bs[a[i].length]=i;

    for (i=0;i<k;i++)
    {
        estGo[i]=round(a[i].length/65.0+a[i].up/10.0);
        if (strcmp(a[i].start,a[i].finish)==0)
            estBack[i]=0;
        else
            estBack[i]= round(a[i].length/65.0+a[i].down/10.0);
    }

    for (i=39999;i>=0;i--)
    {
        if (strcmp(a[bs[i]].start,name)==0 && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
        else if (strcmp(a[bs[i]].finish,name)==0 && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
    }
}

void findUpHill(struct route a[],int k)
{
    int i,bs[40000],estGo[k],estBack[k];

    for (i=0;i<40000;i++)
        bs[i]=-1;

    for (i=0;i<k;i++)
        bs[a[i].length]=i;

    for (i=0;i<k;i++)
    {
        estGo[i]=round(a[i].length/65.0+a[i].up/10.0);
        if (strcmp(a[i].start,a[i].finish)==0)
            estBack[i]=0;
        else
            estBack[i]= round(a[i].length/65.0+a[i].down/10.0);
    }

    for (i=39999;i>=0;i--)
    {
        if (a[bs[i]].up>a[bs[i]].down && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
        else if (a[bs[i]].down>a[bs[i]].up && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
    }
}

void findDownHill(struct route a[],int k)
{
    int i,bs[40000],estGo[k],estBack[k];

    for (i=0;i<40000;i++)
        bs[i]=-1;

    for (i=0;i<k;i++)
        bs[a[i].length]=i;

    for (i=0;i<k;i++)
    {
        estGo[i]=round(a[i].length/65.0+a[i].up/10.0);
        if (strcmp(a[i].start,a[i].finish)==0)
            estBack[i]=0;
        else
            estBack[i]= round(a[i].length/65.0+a[i].down/10.0);
    }

    for (i=39999;i>=0;i--)
    {
        if (a[bs[i]].down>a[bs[i]].up && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
        else if (a[bs[i]].up>a[bs[i]].down && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
    }
}

void findAltitude(struct route a[],int k)
{
    int m,M;
    scanf("%d %d",&m,&M);

    int i,bs[40000],estGo[k],estBack[k];

    for (i=0;i<40000;i++)
        bs[i]=-1;

    for (i=0;i<k;i++)
        bs[a[i].length]=i;

    for (i=0;i<k;i++)
    {
        estGo[i]=round(a[i].length/65.0+a[i].up/10.0);
        if (strcmp(a[i].start,a[i].finish)==0)
            estBack[i]=0;
        else
            estBack[i]= round(a[i].length/65.0+a[i].down/10.0);
    }

    for (i=39999;i>=0;i--)
    {
        if (a[bs[i]].minAlt>=m && a[bs[i]].maxAlt<=M)
        {
            if (strcmp(a[bs[i]].start,a[bs[i]].finish)==0 && bs[i]!=-1)
                printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
            else if (bs[i]!=-1)
            {
                printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
                printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
            }
        }
    }
}

void findTimely(struct route a[],int k)
{
    int time;
    scanf("%d",&time);

    int i,bs[40000];
    float estGo[k],estBack[k];

    for (i=0;i<40000;i++)
        bs[i]=-1;

    for (i=0;i<k;i++)
        bs[a[i].length]=i;

    for (i=0;i<k;i++)
    {
        estGo[i]=a[i].length/65.0+a[i].up/10.0;
        if (strcmp(a[i].start,a[i].finish)==0)
            estBack[i]=0;
        else
            estBack[i]= a[i].length/65.0+a[i].down/10.0;
    }

    for (i=39999;i>=0;i--)
    {
        if (estGo[bs[i]] <= (float) time && estBack[bs[i]] <= (float) time && strcmp(a[bs[i]].start,a[bs[i]].finish)!=0 && bs[i] != -1)
        {
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %.0f min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %.0f min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
        }
        else if (estGo[bs[i]]<=(float)time && estBack[bs[i]]>(float)time && strcmp(a[bs[i]].start,a[bs[i]].finish)!=0 && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %.0f min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
        else if (estGo[bs[i]]>(float)time && estBack[bs[i]]<=(float)time && strcmp(a[bs[i]].start,a[bs[i]].finish)!=0 && bs[i]!=-1)
            printf("From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %.0f min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
    }
}

struct route *readFromFile(int *num)
{
    FILE *fp;
    int i,k;
    struct route *a;
    char name[50];
    scanf(" ");
    readString(name,50);

    fp = fopen(name,"r");
    fscanf(fp,"%d",&k);
    a = malloc(k * sizeof(struct route));
    for (i=0;i<k && !feof(fp);i++)
    {
        fscanf(fp," ");
        fgets(a[i].start,50,fp);
        a[i].start[strcspn(a[i].start,"\n")]='\0';
        fscanf(fp,"%d %d %d %d %d",&a[i].length,&a[i].up,&a[i].down,&a[i].maxAlt,&a[i].minAlt);
        fscanf(fp," ");
        fgets(a[i].finish,50,fp);
        a[i].finish[strcspn(a[i].finish,"\n")]='\0';
    }
    fclose(fp);
    *num=k;
    return a;
}

void saveData(struct route a[],int k)
{
    int i,bs[40000],estGo[k],estBack[k];

    for (i=0;i<40000;i++)
        bs[i]=-1;

    for (i=0;i<k;i++)
        bs[a[i].length]=i;

    for (i=0;i<k;i++)
    {
        estGo[i] = round(a[i].length / 65.0 + a[i].up / 10.0);
        if (strcmp(a[i].start, a[i].finish) == 0)
            estBack[i] = 0;
        else
            estBack[i] = round(a[i].length / 65.0 + a[i].down / 10.0);
    }

    FILE *fw;
    char name[50];
    readString(name,50);
    fw = fopen(name,"w");
    if (fw != NULL)
    {
        for (i=39999;i>=0;i--)
        {
            if (strcmp(a[bs[i]].start,a[bs[i]].finish)==0 && bs[i]!=-1)
                fprintf(fw,"From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
            else if (strcmp(a[bs[i]].start,a[bs[i]].finish)!=0 && bs[i]!=-1)
            {
                fprintf(fw,"From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].start,a[bs[i]].finish,a[bs[i]].up,a[bs[i]].down,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estGo[bs[i]]);
                fprintf(fw,"From %s to %s\nUphill %d, Downhill %d\nMax altitude %d, Min altitude %d\nLength %d, Estimated time %d min\n\n",a[bs[i]].finish,a[bs[i]].start,a[bs[i]].down,a[bs[i]].up,a[bs[i]].maxAlt,a[bs[i]].minAlt,a[bs[i]].length,estBack[bs[i]]);
            }
        }
        fclose(fw);
    }
}
