#include <iostream> 
#include <fstream>
#include <stdlib.h>

using namespace std;

void printsort(int array[], int tam){

	for (int i = 0; i < tam; ++i)
	{
		cout << "Order: " << i+1 << " - Number: " << array[i] << endl;
		
	}

}



void countingSort(int arr[], int n, int e)
{
    int output[n];
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[(arr[i]/e)%10]++;
 

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/e)%10 ] - 1] = arr[i];
        count[ (arr[i]/e)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

int maxvalue(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void radixsort(int arr[], int n)
{
    int m = maxvalue(arr, n);
 
    for (int e = 1; m/e > 0; e =e*10)
        countingSort(arr, n, e);
}





int main() {

	char casodeteste[20]; 
	cout << "Digite um caso de teste: " << endl;
	cin >> casodeteste;
	int RANGE = 100000;
	int array[100000]; 
	int linhas = 0; 

	 ifstream myReadFile;
	 myReadFile.open(casodeteste);
	 char output[1000];
	 if (myReadFile.is_open()) {
	 while (!myReadFile.eof()) {

	    myReadFile >> output;
	    array[linhas] = atoi(output);
	   	linhas++;

	 }
	}
	myReadFile.close();


	radixsort(array, linhas);
	printsort(array, linhas);
	return 0;
}