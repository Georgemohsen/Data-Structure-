#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int parent (int x)
{
	return (x-1) /2 ;
}

int left_child (int x)
{
	return x*2 +1 ;
}

int right_child (int x)
{
	return x*2 + 2;
}
template <class T>
void Swap (T &x , T&y)
{
	T temp ;
	temp=x;
	x=y;
	y=temp;
}

template <class T>
void siftUp (vector<T> &arr ,int index)
{
	while (index !=0 && arr[index] > arr[parent(index)] )
	{
		Swap(arr[index],arr[parent(index)]);
		index=parent(index);
	}
}

template <class T>
void siftDown (vector<T> &arr , int index , int size)
{
	int maxIndex=index;
	int l = left_child(index);
	if (l<size && arr[l]> arr[maxIndex])
		maxIndex=l;
	int r = right_child(index);
	if (r<size && arr[r]>arr[maxIndex])
		maxIndex=r;
	if (index !=maxIndex)
	{
		Swap(arr[index],arr[maxIndex]);
		counter++;
		siftDown(arr,maxIndex,size);
	}
}

template <class T >
void buildHeap (vector<T> & arr)
{
	int size = arr.size();
	for (int i = (size/2) -1 ; i>=0  ; i--)
	{
		siftDown(arr,i,size);
	}
}

template <class T>
T extractMax(vector<T> &arr)
{
	int size = arr.size();
	T result = arr[0];
	arr[0]=arr[size-1];
	size--;
	siftDown(arr,0,size);
	return result;
}

template <class T>
void heapSort(vector<T> &arr)
{
	buildHeap(arr);
	int size = arr.size()-1;
	for (size ; size>=0 ; size--)
	{
		Swap(arr[0],arr[size]);
		counter++;
		siftDown(arr,0,size);
	}
}


int main ()
{
	return 0;
}