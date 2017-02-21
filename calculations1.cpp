// This program generates 20 random integers from 60 to 100, each time it executes. And prints out each number along with 
// the minimum and maximum number, average of all 20 numbers, the smallest gap between 2 numbers, and the sum of total gaps 
// between all the numbers.
// @Noushin Iqra

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int findMax(int a[], int cap) {
    int ans=a[0];
    for (int e=0; e<cap; e++)
        if (a[e]>ans)
        ans = a[e];
    return ans;
}//findMax: return highest number

int findMin(int a[], int cap) {
    int ans=a[0];
    for (int e=0; e<cap; e++)
        if (a[e]<ans)
        ans = a[e];
    return ans;
}//findMin: return lowest number

double findAverage(int a[], int cap) {
    int total=0;
    for (int e=0; e<cap; e++)
        total = total+a[e];
    return total/((double)cap);
}//findAverage: return average of total numbers

int findMinGap(int a[], int cap) {
    int gap=0, count=1, mingap=(a[0]-a[1]);
    if (mingap<0)
        mingap=(mingap*(-1));
    for (int e=0; e<cap-1; e++) {
        gap=(a[e]-a[count]);
        if (gap<0) {
            gap=-gap;
        }
        if (gap<mingap)
        mingap=gap;
        count++;
    }
    return mingap;
}//findMinGap: return smallest gap between 2 numbers

int findGapSum(int a[], int c) {
    int gap, count=1, sum=0;
    for (int e=0; e<c-1; e++) {
        gap=(a[e]-a[count]);
        if (gap<0) {
            gap=-gap;
        }
        count++;
        sum=sum+gap;
    }
    return sum;
}//findGapsum: return sum of total gaps between all numbers

int main()
{
	    srand(time(0));
    		int x[20];
    		for (int e=0; e<20; e++) {
        		x[e]= rand()%41+60;
    		}//generate 20 random numbers and store in an array
	
    			for (int e=0; e<20; e++) {
        			cout << x[e] << " ";
    			}//print each number in the array
	
			cout << endl; 
   				cout << "The largest # of the array is: " << findMax(x,20) << endl;
   				cout << "The smallest # of the array is: " << findMin(x,20) << endl;
   				cout << "The average of the #s of the array is: " << findAverage(x,20) << endl;
				cout << "The smallest gap between the adjacent entries of the array is: " << findMinGap(x,20) << endl;
				cout << "The sum of the gaps between the adjacent entries of the array: " << findGapSum(x,20) << endl;
   return 0;
}

