//============================================================================
// Name        : max-min.cpp
// Author      : pstod
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
void maxmin (int data_array[], int l, int h, int &max, int &min);




int main(){
	int n,max,min;
	cout<<"Enter the size : ";
	cin>>n;
	int arr[n];
	int f1=0,f2=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		if(i > 0){
					if(arr[i-1]>= arr[i])
						f1 = 1;
					else
						f2 = 1;
				}

	}

	// for a sorted array
	if(f1 == 0){

		cout<<"Minimum element in an array: "<<arr[0]<<endl;
		cout<<"Maximum element in an array: "<<arr[n-1]<<endl;
		return 0;
	}
	else if(f2 == 0){

		cout<<"Minimum element in an array: "<<arr[n-1]<<endl;
		cout<<"Maximum element in an array: "<<arr[0]<<endl;
		return 0;
	}


	maxmin(arr,0,n-1,max,min);

	cout<<"Minimum : "<<min<<endl;
	cout<<"Maximum : "<<max<<endl;

	return 0;
}


void maxmin (int data_array[], int l, int h, int &max, int &min)
{
	int min1,min2,max1,max2,mid;
	if(l == h){							// one element in array
		max = data_array[l];
		min = data_array[l];


		return;
	}
	if(h == l+1){						//  two elements in array

		if(data_array[l] > data_array[h]){
			min = data_array[h];
			max = data_array[l];
		}
		else{
			min = data_array[l];
			max = data_array[h];
		}


		return;
	}

	mid = (l+h)/2;								// more than 2 elements in an array
	maxmin(data_array,l,mid,max1,min1);
	maxmin(data_array,mid+1,h,max2,min2);

	if(min1 < min2)		min = min1;
	else				min = min2;

    if(max1 > max2) 	max = max1;

    else				max = max2;
	return ;
}
