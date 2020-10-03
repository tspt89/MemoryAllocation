#include <stdio.h>
#include <stdlib.h>

int size, indx = 0;

struct pet {
	char header[30];
	char animal[30];
	char name[30];
	int age;
};

struct pet *array;

void insertPet(struct pet *array, int i);
void deletePet(struct pet *array);
void printPets(struct pet *array);

int main(int argc, char const *argv[]){
	char option = '0';

	while (size <= 0){
		printf("Enter the array size: ");
		scanf(" %d",&size);

		if (size <= 0){
			printf("Sorry, size not valid.\n");
		}
	}

	array = (struct pet *) malloc(size * sizeof(struct pet));

	if (array == NULL){
		printf("Error: Memory not allocated\n");
		exit(0);
	}

	else {

		while(option != 'e'){

			printf("\nPlease select an option:\n");
			printf("Press 1 to insert a new pet.\n");
			printf("Press 2 to delete a pet.\n");
			printf("Press 3 to print all pets.\n");
			printf("Press e to exit.\n");
			
			printf("Option: ");
			scanf(" %c", &option);
			printf("\n");

			switch(option){
				case '1':
					insertPet(array, indx);
					break;
				case '2':
					deletePet(array);
					break;
				case '3':
					printPets(array);
					break;
				case 'e': 
					free(array);
					exit(1);
				default: printf("Not a valid option\n");
			}
		}
		free(array);
	}
	return 0;
}

void insertPet(struct pet * array, int i){
	
	printf("Enter animal:");
	scanf(" %s", array[i].animal);

	printf("Enter name:");
	scanf(" %s", array[i].name);

	printf("Enter age:");
	scanf(" %d", &array[i].age);
	printf("\n");

	indx++;
	
	if (indx >= size){
		size++;
		array = realloc(array, size * sizeof(struct pet));
		//printf("%ld\n", size * sizeof(struct pet));
		printf("Re-allocated the array to size: %d\n", size);
	}
}

void deletePet(struct pet * array){
	int pos = 0;
	printf("Select pet number to delete\n");
	scanf(" %d", &pos);
	if ((pos >= size) || (indx <= 0) || (pos <= 0)){
		printf("Deletion not possible.\n");
	}
	else {
		for (int i = pos - 1; i < size - 1; i++){
			array[i] = array[i+1];
		}
		size--;
		indx--;
		array = realloc(array, size * sizeof(struct pet));
		// printf("%ld\n", size * sizeof(struct pet));
		printf("Re-allocated the array to size: %d\n", size);
	}
}

void printPets(struct pet * array){

	if (indx <= 0){
		printf("NO PETS\n");
	}
	else{
		for (int i = 0; i < indx; i++){
			printf("Animal: %s \n", array[i].animal);
			printf("Name: %s \n", array[i].name);
			printf("Age: %d \n", array[i].age);
			printf("\n");
		}
	}
}