#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int random_number() {
	char fd = open("/dev/random", O_RDONLY);

	int * buff = malloc(sizeof(int));

	read(fd, buff, sizeof(int));

	int ans = *buff;

	free(buff);

	return ans;
}

int main() {

	//create a new random array
	printf("\nGenerating Numbers:\n\n");	
	int * arr1 = malloc(sizeof(int)*10);

	int i = 0;
	for (;i-10;i++) {
		arr1[i] = random_number();
		printf("     Random Number %d: %d\n", i, arr1[i]);
	}

	//open the file called RandomNumbers.txt
	int file = open("RandomNumbers.txt", O_WRONLY | O_CREAT);

	//write the numbers into the file
	printf("\nWriting Numbers to File...\n");
	write(file, arr1, sizeof(int)*10);

	//free the first array
	free(arr1);

	//create a new empty array
	int * arr2 = calloc(sizeof(int),10);

	close(file);
	file = open("RandomNumbers.txt", O_RDONLY);

	//write from the file into the new array
	printf("\nReading Numbers from File...\n");
	read(file, arr2, sizeof(int)*10);

	//need to verify the read/write
	printf("\nVerification that Written Values are the same:\n\n");
	
	i = 0;
	for (;i-10;i++) {
		printf("     Random Number %d: %d\n", i, arr2[i]);
	}

	printf("\n");

	//free the last array
	free(arr2);

	//close the file
	close(file);

	return 0;
}