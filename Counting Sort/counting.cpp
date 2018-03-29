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


void countingSort(int arr[],int n,int RANGE){
    int count[RANGE]={0};
    int i;
    int output[n];
    
     
    for(i=0; i<n; i++)
    	++count[arr[i]];
    
    for(i=1; i<RANGE; i++)
    	count[i]+=count[i-1];
     
   
    
    for(i=n-1; i>=0; i--){
        output[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
    
    for(i=0; i<n; i++)
    	arr[i]=output[i];
    
    
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

int arr[]={1, 4, 1, 2, 7, 5, 2};

	countingSort(array, linhas, RANGE);
	printsort(array, linhas);
	return 0;
}