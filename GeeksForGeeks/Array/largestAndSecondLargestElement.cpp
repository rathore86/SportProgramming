/*
 *Find the largest and second largest element in an array
 *If duplicate entry present then both numbers are treated different
 *If want to find unique numbers than change equality to strict inequality at line 27 35 47
 *Time=O(n) & space O(1) & comparisons=3n/2
 *
 */
#include <cstdio>
#include <algorithm>
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)
using namespace std;
int *array;
void function(int n){
	int max=array[0],second_max=array[1];
	/* count comparisons */
	if(array[0]<array[1]){
		//comparison=1
		max=array[1];
		second_max=array[0];
	}
	int i=2;	//loop variable
	/* count comparisons */
	while(i<n-1){
		//comparisons = ((n-2)/2)*3
		if(array[i]<array[i+1]){
			if(max<=array[i+1]){
				second_max=max;
				max=array[i+1];
			}
			if(second_max<array[i])
				second_max=array[i];
		}
		else{
			if(max<=array[i]){
				second_max=max;
				max=array[i];
			}
			if(second_max<array[i+1])
				second_max=array[i+1];
		}
		i+=2;
	}
	/* count comparisons */
	if(i<n){
		//comparisons=2
		if(max<=array[i]){
			second_max=max;
			max=array[i];
		}else if(second_max<array[i])
			second_max=array[i];
	}
	printf("%d %d\n",max,second_max);
}
int main(){
	int i;	// loop variable
	int n;	// no of elements in given array
	IN(n);
	array=new int[n];
	FOR(i,n)
		IN(array[i]);
	function(n);
}
