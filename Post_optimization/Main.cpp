#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <iostream>
#include <cstdlib>

float* loadDataset(int dataSetSize, char *filename, int bufferSize);
void selectionSort(float* ds, int n);
void quickSort(float* ds, int n);
int writeDataset(int dataSetSize, char *filename, float* ds, int bufferSize, float avg, float min, float max);
float average(float* ds, int dataSetSize);
float minvalue(float* ds, int dataSetSize);
float maxvalue(float* ds, int dataSetSize);
void generateDataset(int dataSetSize);
void printDataSet(float* ds, int dataSetSize);

int main(int argc, char* argv[])
{

	int N = 1;
	int bufferSize = 1;

	if(argc > 2){
		N = atoi(argv[1]);			//parameter
		bufferSize = atoi(argv[2]);	//parameter
	}

	srand((unsigned int)time(NULL));

	const int dataSetSize = 102400 * N;
	char inputFileName[] = "values";
	char outputFileName[] = "output";
	
	//generateDataset(dataSetSize);

	// load the dateset in the memory area addressed by ds 
	float* ds = loadDataset(dataSetSize, inputFileName, bufferSize);
	//printDataSet(ds, dataSetSize);

	//sort the dataset and copy it into the memory area pointed by sds 
	quickSort(ds, dataSetSize);

	// compute the average value of the dataset, i.e. sum_of_dataset_values / num_of_dataset_values 
	float avg = average(ds, dataSetSize);

	// find the min value in the dataset 
	float min = minvalue(ds, dataSetSize);

	// find the max value in the dataset 
	float max = maxvalue(ds, dataSetSize);

	//write the sorted array into a new file plus the valies of the average, min and max as the first three records. 
	writeDataset(dataSetSize, outputFileName, ds, bufferSize, avg, min, max);

	//float* tds = loadDataset(dataSetSize, outputFileName);
	//printDataSet(ds, dataSetSize);

	delete ds;
	return 1;
}

float* loadDataset(int dataSetSize, char *filename, int bufferSize)
{
	FILE *fp;
	float* ds = new float[dataSetSize];
	fp = fopen(filename, "rb");

	int limit = dataSetSize / bufferSize;
	int limitCheckInterval = limit/10;	//print every 10%
	int printer = 0;

	for (int i = 0; i < limit; i+= bufferSize)
	{
		if(!(i%limitCheckInterval)){
			std::cout << "loadDataset() " << printer << "%" << std::endl;
			printer += 10;
		}
		
		fread(&ds[i], sizeof(float), bufferSize, fp);
	}

	std::cout << "loadDataset() 100%" << std::endl << std::endl;

	fclose(fp);
	return ds;
}

int cmpfunc(const void * a, const void * b) {

	return (*(int*)a - *(int*)b);
}

void quickSort(float* ds, int n)
{

	std::qsort(ds, n, sizeof(float), cmpfunc);
}

int writeDataset(int dataSetSize, char* filename, float* ds, int bufferSize, float avg, float min, float max)
{
	int limit = dataSetSize / bufferSize;
	int limitCheckInterval = limit/10;	//print every 10%
	int printer = 0;

	FILE *fp = fopen(filename, "wb");
	fwrite(&avg, sizeof(float), 1, fp);
	fwrite(&min, sizeof(float), 1, fp);
	fwrite(&max, sizeof(float), 1, fp);

	//for (int i = 0; i < limit; i+= bufferSize)
	//{
	//	if(!(i%limitCheckInterval)){
	//		std::cout << "writeDataset() " << printer << "%" << std::endl;
	//		printer += 10;
	//	}

	//	fwrite(&ds[i], sizeof(float)* bufferSize, 1, fp);
	//}
	fwrite(&ds[0], sizeof(float), bufferSize, fp);
	fclose(fp);
	
	std::cout << "writeDataset() 100%" << std::endl << std::endl;

	return 1;
}

float average(float * ds, int dataSetSize)
{
	float avg = 0;
	for (int i = 0; i < dataSetSize; ++i)
	{
		avg += ds[i];
	}
	return avg / dataSetSize;
}

float minvalue(float * ds, int dataSetSize)
{
	float min = ds[0];
	for (int i = 1; i < dataSetSize; ++i)
	{
		if (ds[i] < min)
			min = ds[i];
	}
	return min;
}

float maxvalue(float * ds, int dataSetSize)
{
	float max = ds[0];
	for (int i = 1; i < dataSetSize; ++i)
	{
		if (ds[i] > max)
			max = ds[i];
	}
	return max;
}

float generateRand(int rmax) 
{ 
	//Generate a floating point random number between 0 and rmax 
	 //initialize the random number generator 
	return ((float)rand()/(float)(RAND_MAX)) * (rmax - 1) + 1; 
}

void generateDataset(int dataSetSize)
{
	float* ds = new float[dataSetSize]; //you can alternatively dynamically allocate the vector 
	for (int i = 0; i < dataSetSize; ++i) 
	{ 
		ds[i]=generateRand(100);
	} 
	FILE* f = fopen("values", "wb");
	fwrite(ds, sizeof(float), dataSetSize, f);
	fclose(f);
}

void printDataSet(float* ds, int dataSetSize)
{
	std::cout << "\nNew output:\n";
	for (int i = 0; i < 100 && i < dataSetSize; ++i)
	{
		std::cout << ds[i] << "\n";
	}
}