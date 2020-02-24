#include <iostream>

using namespace std;


void Merge(int *a, int lowest, int highest, int middle)
{

	int i, j, k, temp[highest-lowest+1];
	i = lowest;
	k = 0;
	j = middle + 1;


	while (i <= middle && j <= highest)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}


	while (i <= middle)
	{
		temp[k] = a[i];
		k++;
		i++;
	}


	while (j <= highest)
	{
		temp[k] = a[j];
		k++;
		j++;
	}



	for (i = lowest; i <= highest; i++)
	{
		a[i] = temp[i-lowest];
	}
}

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

int main()
{
	int array_size;

	cout<<endl <<"Enter the size of the array:  "<<endl;
	cin>>array_size;

	int my_array[array_size];
	for(int i = 0; i < array_size; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>my_array[i];
	}

	MergeSort(my_array, 0, array_size-1);


	cout<<"\nSorted Elements";

	for (int i = 0; i < array_size; i++)
        cout<<"->"<<my_array[i];

	return 0;
}
