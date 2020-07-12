#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

void maxheap_bottomup(int h[],int n)
{
   	int i,heap,v,j,k;
   	for(i=n/2;i>0;i--) 
	{
		k=i;
		v=h[k];
		heap=FALSE;
		while(!heap && (2*k)<=n)
		{
			j=2*k;
			if(j<n)
   	  			if(h[j]<h[j+1])
					j=j+1;
      			if(v>=h[j])
				heap=TRUE;
			else
			{
				h[k]=h[j];
				k=j;
			}
		}
		h[k]=v;
	}
}

void heapsort(int h[],int n)
{    
	int i,temp;
	if(n<=1)
      		return;
        else
        {
		maxheap_bottomup(h,n);
		h[n]=h[1]+h[n]-(h[1]=h[n]);
					   
		heapsort(h,n-1);
   	}
}

void main()
{
	int h[20],n,i,tick;
	double clk;
        clock_t starttime,endtime;
	printf("\n Enter the number of resumes\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
            h[i]=rand()%100;

	printf("The candidates ranks are:\n");
	for(i=1;i<=n;i++) 
            printf("%d\t",h[i]);
	
	maxheap_bottomup(h,n);
	printf("\nRanks after contructing maxheap\n");
	for(i=1;i<=n;i++)
	    printf("%d\t",h[i]);
        
          starttime=clock();
	  heapsort(h,n);
          endtime=clock();

	  tick=endtime-starttime;
          clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	  printf("\n The ranks in sorted order: \n");
	  for(i=1;i<=n;i++)
	      printf("%d\t",h[i]);

          printf("\nHeapsort took %d clock ticks and the run time is %f seconds\n",tick,clk);

}