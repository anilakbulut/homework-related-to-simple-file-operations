#include <stdio.h> /*defining library*/
#define p1 0.5 /* These are global variables */
#define p2 20.0
int main()
{
   FILE *fp,*fy;	/* These are file pointers */
   int i=0,j=0,count=0,k=0,num_chunk=1; 
   float a,b,n,temp;
   float arr[1000][100];
   float avg[100],avg_temp[100];
   float sum=0.0;
   int index[100],x;
   fp = fopen("input.txt","r"); /*Opened with the r command to read the file*/
   fy = fopen("output.txt","w+");/*Opened with the r command to write to the file*/
	while (!feof(fp)) /* The loop will continue unless the file is empty*/
	{
		fscanf(fp,"%f ",&n);	/* With fscanf read the information from the file */
		if(k==0) /* First number directly assigned to array*/ 
		{
			arr[i][j]=n;
			a = n;
			k++;
			count++;
			j++;
		}
		else /* Other numbers are assigned to double-dimensional Array in accordance with the condition. .*/
		{
			b = ((a*count) + n) / (count+1);
			if(!(b > a*(1+p1) || b < a*(1-p1) || a > n*p2 || a < n/p2)) /* If the condition is satisfied, the numbers in the Array are assigned side by side.*/
			{
				arr[i][j] = n;
				a = b;
				j++;
				count++;
			}
			else /*If the condition is not fulfilled, the numbers in the Array are moved to the bottom. */
			{
				index[i]=j;
				j=0;
				i++;
				arr[i][j]=n;
				a = n;
				count=1;
				j++;
				num_chunk++;
			}
		}
	}
	index[i]=j;
	for(i=0;i<=num_chunk;i++) /* Calculating averages for each chunk */
	{
		sum=0.0;
		for(j=0;j<index[i];j++)
		{
			sum+=arr[i][j]; 
		}
		avg[i]=sum/index[i];
	}
	for(i=0;i<=num_chunk;i++) /* The copy of the array of averages */
	{	
		avg_temp[i]=avg[i];
	}
	for(x=0;x<num_chunk;x++) /* sorted from small to big  */
	{
		for(i=0;i<num_chunk;i++)
		{	
			if(avg[i]>avg[i+1])
			{
				temp=avg[i+1];
				avg[i+1]=avg[i];
				avg[i]=temp;
			}
		}
	}
	for(i=0;i<num_chunk;i++) /* Printed the sorted chunks to output file*/
	{
		for(x=0;x<num_chunk;x++)
		{
			if(avg_temp[x]==avg[i])
			{
				for(j=0;j<=index[i];j++)
				{
					if(arr[x][j]!=0)
					{
						fprintf(fy,"%.4f ",arr[x][j]);
					}
				}
				j=0;
				fprintf(fy,"\n");
			}
		}
	}
   fclose(fy); /* Close the output file*/
   fclose(fp); /* Close the input file*/
}
