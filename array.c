#include<stdio.h>
#include<stdlib.h>
struct array
{
    int A[20];
    int size;
    int length;

};
void swap (int *x, int *y)
{
   int temp =  *x;
     *x =  *y;
     *y = temp;
}

void display(struct array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d\n",arr.A[i]);
    }
}
int get (struct array arr, int index)
{
    if (index >= 0 && index <= arr.length)
    {
        return arr.A[index];
    }
}
int set (struct array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        arr->A[index] = x;
        return arr->A[index];
    }
}
int max (struct array arr)
{
    int max = arr.A[0];
     int i;
    for (i = 1; i < arr.length; i++)
    {
        if (max < arr.A[i])
        {
            max = arr.A[i];

        }
    }
    return max;
}
int min (struct array arr)
{
    int min = arr.A[0];
     int i;
    for (i = 1; i < arr.length; i++)
    {

        if (min > arr.A[i])
        {
            min = arr.A[i];

        }
    }
    return min;
}
int sum (struct array arr)
{
    int total = 0;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        total = total + arr.A[i];

    }
    return total;
}
int reverse (struct array *arr)
{
    int i,j;
    for (i = 0,j =arr->length -1; i <= j; i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}
int rotate (struct array *arr)
{
    int i;
    int temp = arr->A[0];
    for(i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i+1];

    }
    arr->A[arr->length-1] = temp;

    return arr->A[i];
}

struct array* merge(struct array *arr1,struct array *arr2)
{
    int i,j,k;
    i = j = k = 0;
    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        arr3->A[k++] = arr2->A[j++];
    }
    for (;i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

struct array* u(struct array *arr1,struct array *arr2)
{
    int i,j,k;
    i = j = k = 0;
    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr1->A[i] > arr2->A[j])
        {
          arr3->A[k++] = arr2->A[j++];
        }
        else
            arr3->A[k++] = arr1->A[i++];
        j++;
    }
    for (;i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
struct array* i(struct array *arr1,struct array *arr2)
{
    int i,j,k;
    i = j = k = 0;
    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr1->A[i] > arr2->A[j])
        {
          j++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
struct array* di(struct array *arr1,struct array *arr2)
{
    int i,j,k;
    i = j = k = 0;
    struct array *arr3 = (struct array*)malloc(sizeof(struct array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];

        }
        else if(arr1->A[i] > arr2->A[j])
        {
          j++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            i++;
        j++;
        }
    }
     for (;i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
int main()
{
    struct array arr = {{2,9,21,28,35},10,5};
    struct array arr1 = {{2,3,16,18,28},10,5};
    struct array *arr3;
   /* arr3 = merge(&arr,&arr1);*/
   /*arr3 = u(&arr,&arr1);*/
    /*arr3 = i(&arr,&arr1);*/
    arr3 = di(&arr,&arr1);


   /* printf("%d\n",get(arr,2));*/
    /*set(&arr,1,4);*/
   /*printf("%d\n", max(arr));*/
  /* printf("%d\n", min(arr));*/
   /*printf("%d\n",sum(arr));*/
  /* reverse(&arr);*/
  /*rotate (&arr);*/

    display(*arr3);

}
