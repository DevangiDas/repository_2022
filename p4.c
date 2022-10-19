#include<stdio.h>
#include<math.h>
#include<time.h>

int main()
{
	clock_t start,stop;
	int n;
	double st,end,mid;
	
	printf("Enter a Number: ");
	scanf("%d",&n);
	start=clock();
	st = 0, end = n;
	
	while((end - st)>=0.000001)
    {
		
		mid = (st + end)/2;
		
		if(mid*mid < n)
			st = mid;
		if(mid*mid >= n)
			end = mid;
		
	}
	
	printf("Square Root of %d is %f",n,mid);
    stop=clock();
    printf("\nExecution time= %f seconds",((double)stop-start)/CLOCKS_PER_SEC);
}
