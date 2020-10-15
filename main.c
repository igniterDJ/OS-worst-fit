#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,wicount=0,wfcount=0,pcount=0,max=0;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    printf("enter number of wholes\n");
    scanf("%d",&m);
    int whole[m][2],process[n],twhole[m][2];
    for(i=0;i<m;i++)
    {
        printf("enter the size of %d whole : \n",i+1);
        scanf("%d",&whole[i][0]);
        wicount+=whole[i][0];
        twhole[i][0]=0;
        twhole[i][1]=0;
        whole[i][1]=0;
    }
    for(i=0;i<n;i++)
    {
        printf("enter %d process size : \n",i+1);
        scanf("%d",&process[i]);
        pcount+=process[i];
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(process[i]<=whole[j][0])
            {
                printf("process %d whole %d \n",process[i],whole[j][0]);
                twhole[j][0]=1;
                twhole[j][1]=whole[j][0]-process[i];
            }
        }

        for(j=0;j<m;j++)
        {
            if(twhole[j][0]==1)
            {
                if(whole[j][1]==0)
                {
                    if(max<twhole[j][1])
                    {
                        max=twhole[j][1];
                    }
                }
            }
        }

        for(j=0;j<m;j++)
        {
            if(max==twhole[j][1])
            {
                if(twhole[j][0]==1)
                {
                    if(whole[j][1]==0)
                    {
                        whole[j][0]-=process[i];
                        process[i]=0;
                        whole[j][1]=1;
                    }
                }
            }
        }

        for(j=0;j<m;j++)
        {
            twhole[j][0]=0;
            twhole[j][1]=0;
            printf("%d\t",whole[j][0]);
        }
        printf("\n");
        max=0;

    }

    for(i=0;i<m;i++)
    {
        wfcount+=whole[i][0];
    }

    if(wfcount+pcount==wicount)
    {
        printf("process can be completer\n");
        for(i=0;i<m;i++)
        {

            printf("%d\t",whole[i][0]);
        }
        printf("\n");
    }
    else
    {
        printf("cannot be completed");
    }

}
