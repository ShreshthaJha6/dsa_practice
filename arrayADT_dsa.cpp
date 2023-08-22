#include <iostream>
#include <stdlib.h>
using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};  

void display(struct Array arr){
    int i;
    cout<<"elements are : "<<endl;
    for(i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
} 
void append(struct Array *arr,int element){
    if(arr->length<arr->size) //to check if the length is not equal to the size
    {
        arr->A[arr->length++]=element;
    }
}
void insert(struct Array *arr,int index, int element){
    if(index>=0 && index <=arr->length)//to check the validity of index
    {
        //if true then shift the elements and provide new space for elements
        int i;
        for(i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=element;
        arr->length++;
    }
    
}
int Delete(struct Array *arr, int index){
    //delete element at the index and left shift the elements to the right by one.
    int x=0,i;
    if(index>=0 && index<=arr->length){
        x=arr->A[index];//saved the deleted value in a variable.
        for(i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return -1;//in case of invalid index
}
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
};

int LinearSearch(struct Array *arr, int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
    }
    return -1;
    //to improve linear search, use transposition,i.e
    //we swap the searched element with the previous element.
}

int BinarySearch(struct Array arr, int key){
    int low,mid,high;
    low=0;
    high=arr.length-1;
    while(low<=high){
        mid=(low+high)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int RBinSearch(struct Array arr, int low, int high, int key){
    int mid;
    if(low<=high){
        mid=(low+high)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            return RBinSearch(arr,low,mid-1,key);
        }
        else {
            return RBinSearch(arr,mid+1,high,key);
        }
    }
    return -1;
}
int get(struct Array arr, int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}
void set(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->length){
        arr->A[index]=x;
    }
}
int max(struct Array arr){
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}
int min(struct Array arr){
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
    }
    return min;
}
int sum(struct Array arr){
    int sum=0;
    int i=0;
    for(;i<arr.length;i++){
        sum=sum+arr.A[i];
    }
    return sum;
}
float avg(struct Array arr){
    return (float)sum(arr)/arr.length;//typecasting avg as float
    
}
void reverse(struct Array *arr){
    int *B;//introduction of a new array
    int i,j;
    B= new int; arr->length*sizeof(int);
    for(i=arr->length-1,j=0;i>=0;i--,j++){
        B[j]= arr->A[i];
    }
    for(i=0;i<arr->length;i++){
        arr->A[i]=B[i];
    }
}
void reverse2(struct Array *arr){
    //we reverse without introducing a new array
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}
void left_shift(struct Array *arr){
    int i;
    for(i=0;i<arr->length;i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=0;
}
void rotate_left(struct Array *arr){
    int i,x;
    x=arr->A[0];
    for(i=0;i<arr->length;i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1]=x;
}
void InsertSort(struct Array *arr, int x){
    int i=arr->length-1;
    if(arr->length == arr->size){
        //to check the validity 
        return;
    }
    while(i>=0 && arr->A[i]>x){
        //to right-shift every element greater than x by 1 
        //to accomodate x
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
int IsSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}
void ReArrange(struct Array *arr){
    //to keep -ves on left and +ves on right
    int i,j;
    i=0;j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j++;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}
struct Array* Merge(struct Array *A,struct Array *B){
    int i=0; int j=0; int k=0;
    Array *arr3= new Array;
    while(i<A->length && j<B->length){
        if(A->A[i]<B->A[j]){
            arr3->A[k++]=A->A[i++];
        }
        else{
            arr3->A[k++]=B->A[j++];
        }
    }
    for(;i<A->length;i++){
        arr3->A[k++]=A->A[i];
    }
    for(;j<B->length;j++){
        arr3->A[k++]=B->A[j];
    }
    arr3->length= A->length+B->length;
    arr3->size=10;
    return arr3;
}
struct Array* Union(struct Array *A,struct Array *B){
    int i=0; int j=0; int k=0;
    Array *arr3= new Array;
    while(i<A->length && j<B->length){
        if(A->A[i]<B->A[j]){
            arr3->A[k++]=A->A[i++];
        }
        else if(A->A[i]>B->A[j]){
            arr3->A[k++]=B->A[j++];
        }
        else{
            arr3->A[k++]=B->A[j++];i++;
        }
    }
    for(;i<A->length;i++){
        arr3->A[k++]=A->A[i];
    }
    for(;j<B->length;j++){
        arr3->A[k++]=B->A[j];
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}
struct Array* Intersection(struct Array *A,struct Array *B){
    int i=0; int j=0; int k=0;
    Array *arr3= new Array;
    while(i<A->length && j<B->length){
        if(A->A[i]<B->A[j]){
            i++;
        }
        else if(A->A[i]>B->A[j]){
            j++;
        }
        else{//A->A[i]==B->A[j]
            arr3->A[k++]=B->A[j++];i++;
        }
    }
    
    arr3->length=k;
    arr3->size=10;
    return arr3;
}
struct Array* Difference(struct Array *A,struct Array *B){
    int i=0; int j=0; int k=0;
    Array *arr3= new Array;
    while(i<A->length && j<B->length){
        if(A->A[i]<B->A[j]){
            arr3->A[k++]=A->A[i++];
        }
        else if(A->A[i]>B->A[j]){
            j++;
        }
        else{
            j++;i++;
        }
    }
    for(;i<A->length;i++){
        arr3->A[k++]=A->A[i];
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}
int main(){
    //menu driven program to use all array functions
    struct Array arr1;
    cout<<"enter the size of the array: "<<endl;
    cin>>arr1.size;
    arr1 = *new Array;

    int ch;
    int x, index;

    do{

    cout<<"MENU \n"<<endl;
    cout<<"1. Insert \n";
    cout<<"2. Delete \n";
    cout<<"3. Search \n";
    cout<<"4. Sum \n";
    cout<<"5. Display \n";
    cout<<"6. Exit \n";

    cout<<"enter your choice: "<<endl;
    cin>>ch;

    switch(ch){
        case 1: cout<<"enter an element and index: "<<endl;
        cin>>x>>index;
        insert(&arr1,index,x);
        break;

        case 2: cout<<"enter the index: "<<endl;
        cin>>index;
        x=Delete(&arr1,index);
        cout<<"the deleted element is : "<<x;
        break;

        case 3: cout<<"enter the element to search: "<<endl;
        cin>>x;
        index=LinearSearch(&arr1,x);
        cout<<"the index of the element is : "<<index;
        break;

        case 4: cout<<"sum of the array is : "<<sum(arr1);
        break;

        case 5: display(arr1);

    }
    }while(ch<6);
    
    return 0;
}
