#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int unsorted[], int lb, int ub){
    int pivot = unsorted[lb];
    int index = lb;
    int p = lb;
    int q = ub;
    while(p<=q){
        if(unsorted[p]<=pivot){
            p++;
        }
        if(unsorted[q]>=pivot){
            q--;
        }
        if(p<q){
            swap(unsorted[p],unsorted[q]);
        }
    }
    swap(unsorted[index],unsorted[q]);
    return q;

}

void quick_sort(int unsorted[],int lb, int ub){
    if(lb<ub){
        int loc = partition(unsorted,lb,ub);
        quick_sort(unsorted,lb,loc-1);
        quick_sort(unsorted,loc+1,ub);
    }
    
}

int main()
{
    int n,i,j;
    cout<<"Enter Number of elements you want to insert: ";
    cin>>n;
    
    int *unsorted = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n;i++) {
        //unsorted[i] = rand()%100;
        cin>>unsorted[i];
    }
    time_t start,end;
    start=clock();
    quick_sort(unsorted,0,n-1);
    double tc;
    end=clock();
    tc=(difftime(end,start)/CLOCKS_PER_SEC);
    printf("time efficiency is %lf",tc);
    cout<<"\n\nSorted Array:";
    for (i = 0; i < n; i++) {
        cout<<unsorted[i]<<" ";
    }
    return 0;
}
