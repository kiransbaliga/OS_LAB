#include <stdio.h>
#include <stdlib.h>



void isort(int arr[], int n, int dir)
{
    int i, key, j;
    if(dir==1)
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    else
    for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] < arr[j+1])
             {
                 int temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]= temp;}
}

void fCFS()
{
    int head, n;
    int arr[30];
    printf("\nFCFS\nEnter the current position...\n");
    scanf("%d", &head);
    printf("Enter the number of requests...\n");
    scanf("%d", &n);
    printf("Enter the requests...\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

printf("Order = %d %d",head,arr[0]);
    int time = abs(arr[0] - head);
    for (int i = 1; i < n; i++)
        {time += abs(arr[i] - arr[i - 1]);
        
printf("%d ",arr[i]);}
    printf("\nSeek Time = %d\n\n", time);
}

void sSTF()
{

    int head, n;
    int arr[30];
    printf("\nSSTF\nEnter the current position...\n");
    scanf("%d", &head);
    printf("Enter the number of requests...\n");
    scanf("%d", &n);
    printf("Enter the requests...\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

int ind=-1,time=0;
printf("Order = %d ",head);
while(1)
{int min=INT_MAX;
for (int i = 0; i < n; i++)
{
if (abs(arr[i] - head) < min && ind!=i &&arr[i]!=-1 )
{
min =abs(arr[i] - head) ;
ind=i;
}
}
if(min==INT_MAX)
break;
time+=abs(arr[ind] - head);
head=arr[ind];
printf("%d ",head);
arr[ind]=-1;
}
printf("\nSeek Time = %d",time);
}

void scan()
{
    int head,prev, n , siz;
    int arr[30];
    printf("\nSCAN\nEnter the size...\n");
    scanf("%d", &siz);
    printf("Enter the current position...\n");
    scanf("%d", &head);
    printf("\nEnter the previous position...\n");
    scanf("%d", &prev);
    printf("Enter the number of requests...\n");
    scanf("%d", &n);
    printf("Enter the requests...\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int dir=1;
    if(prev>head)
    dir = -1;

    int ar1[30], ar2[30],n1=0,n2=0;
    if(dir==1)
    {ar1[0] =siz -1;
    n1 = 1;}
    else
    {ar2[0] = 0;
    n2 = 1;}
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > head)
        {
            ar1[n1++] = arr[i];
        }
        else
        {
            ar2[n2++] = arr[i];
        }
    }
    isort(ar1,n1,-1);
    isort(ar2,n2,1);
   
    int ans = 0;
    printf("SCAN ORDER IS:\n");
    n2--;
    n1--;
    printf("%d ",head);
    if(dir==-1)
    {while (n2 >= 0)
    {
        ans+=abs(head-ar2[n2]);
        printf("%d ", ar2[n2]);
        head=ar2[n2--];
    }
    while (n1 >= 0)
    {
        ans+=abs(head-ar1[n1]);
        printf("%d ", ar1[n1]);
        head=ar1[n1--];
    }}
    else
    {while (n1 >= 0)
    {
        ans+=abs(head-ar1[n1]);
        printf("%d ", ar1[n1]);
        head=ar1[n1--];
    }while (n2 >= 0)
    {
        ans+=abs(head-ar2[n2]);
        printf("%d ", ar2[n2]);
        head=ar2[n2--];
    }}
    printf("\n");
    printf("Seek Time = %d\n\n\n\n", ans);
}
void cscan()
{
    int head,prev, n , siz;
    int arr[30];
    printf("\nCSCAN\nEnter the size...\n");
    scanf("%d", &siz);
    printf("Enter the current position...\n");
    scanf("%d", &head);
    printf("\nEnter the previous position...\n");
    scanf("%d", &prev);
    printf("Enter the number of requests...\n");
    scanf("%d", &n);
    printf("Enter the requests...\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int dir=1;
    if(prev>head)
    dir = -1;

    int ar1[30], ar2[30],n1=0,n2=0;
    ar1[0] =siz -1;
    n1 = 1;
    ar2[0] = 0;
    n2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > head)
        {
            ar1[n1++] = arr[i];
        }
        else
        {
            ar2[n2++] = arr[i];
        }
    }
    isort(ar1,n1,-1);
    isort(ar2,n2,1);
   
    int ans = 0;
    printf("CSCAN ORDER IS:\n");
    printf("%d ",head);
    if(dir==-1)
    {
    n2--;while (n2 >= 0)
    {
        ans+=abs(head-ar2[n2]);
        printf("%d ", ar2[n2]);
        head=ar2[n2--];
    }
    for(int i=0;i<n1;i++)
    {
        ans+=abs(head-ar1[i]);
        printf("%d ", ar1[i]);
        head=ar1[i];
    }}
    else
    {
    n1--;while (n1 >= 0)
    {
        ans+=abs(head-ar1[n1]);
        printf("%d ", ar1[n1]);
        head=ar1[n1--];
    }for(int i=0;i<n2;i++)
    {
        ans+=abs(head-ar2[i]);
        printf("%d ", ar2[i]);
        head=ar2[i];
    }}
    printf("\n");
    printf("Seek Time = %d\n\n", ans);
}
void look()
{
    int head,prev, n , siz;
    int arr[30];
    printf("LOOK\nEnter the current position...\n");
    scanf("%d", &head);
    printf("\nEnter the previous position...\n");
    scanf("%d", &prev);
    printf("Enter the number of requests...\n");
    scanf("%d", &n);
    printf("Enter the requests...\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int dir=1;
    if(prev>head)
    dir = -1;

    int ar1[30], ar2[30],n1=0,n2=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > head)
        {
            ar1[n1++] = arr[i];
        }
        else
        {
            ar2[n2++] = arr[i];
        }
    }
    isort(ar1,n1,-1);
    isort(ar2,n2,1);
   
    int ans = 0;
    printf("LOOK ORDER IS:\n");
    n2--;
    n1--;
    printf("%d ",head);
    if(dir==-1)
    {while (n2 >= 0)
    {
        ans+=abs(head-ar2[n2]);
        printf("%d ", ar2[n2]);
        head=ar2[n2--];
    }
    while (n1 >= 0)
    {
        ans+=abs(head-ar1[n1]);
        printf("%d ", ar1[n1]);
        head=ar1[n1--];
    }}
    else
    {while (n1 >= 0)
    {
        ans+=abs(head-ar1[n1]);
        printf("%d ", ar1[n1]);
        head=ar1[n1--];
    }while (n2 >= 0)
    {
        ans+=abs(head-ar2[n2]);
        printf("%d ", ar2[n2]);
        head=ar2[n2--];
    }}
    printf("\n");
    printf("Seek Time: %d\n\n", ans);
}
void clook()
{
    int head,prev, n , siz;
    int arr[30];
    printf("\nCLOOK\nEnter the current position...\n");
    scanf("%d", &head);
    printf("\nEnter the previous position...\n");
    scanf("%d", &prev);
    printf("Enter the number of requests...\n");
    scanf("%d", &n);
    printf("Enter the requests...\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int dir=1;
    if(prev>head)
    dir = -1;

    int ar1[30], ar2[30],n1=0,n2=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > head)
        {
            ar1[n1++] = arr[i];
        }
        else
        {
            ar2[n2++] = arr[i];
        }
    }
    isort(ar1,n1,-1);
    isort(ar2,n2,1);
   
    int ans = 0;
    printf("CLOOK ORDER IS:\n");
    printf("%d ",head);
    if(dir==-1)
    {
    n2--;while (n2 >= 0)
    {
        ans+=abs(head-ar2[n2]);
        printf("%d ", ar2[n2]);
        head=ar2[n2--];
    }
    for(int i=0;i<n1;i++)
    {
        ans+=abs(head-ar1[i]);
        printf("%d ", ar1[i]);
        head=ar1[i];
    }}
    else
    {
    n1--;while (n1 >= 0)
    {
        ans+=abs(head-ar1[n1]);
        printf("%d ", ar1[n1]);
        head=ar1[n1--];
    }for(int i=0;i<n2;i++)
    {
        ans+=abs(head-ar2[i]);
        printf("%d ", ar2[i]);
        head=ar2[i];
    }}
    printf("\n");
    printf("Seek Time = %d\n\n\n\n", ans);
}

int main()
{
    printf("DISK SCHEDULING ALGORITHMS");
    int op = 0;
    while (op != 7)
    {
        printf("\n\nEnter your option...\n1. FCFS\n2. SSTF\n3. SCAN\n4. CSCAN\n5. LOOK\n6. CLOOK\n7. Exit\n\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fCFS();
            break;
        case 2:
            sSTF();
            break;
        case 3:
            scan();
            break;
        case 4:
            cscan();
            break;
        case 5:
            look();
            break;
        case 6:
            clook();
            break;
        }
    }
}