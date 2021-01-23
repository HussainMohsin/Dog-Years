//Dog Years
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dog{
	char name[10];
	char size[10];
	int weight;
	int humanYears;
	int dogYears;
};

void getCustomerInfo(struct Dog [], int );
void calculateSizeAndAge(struct Dog *dogs, int dogNums);
void sortDogs(struct Dog dogs[], int dogNums);
void displayDogs(struct Dog *dogs, int dogNums);
void getCustomerInfoFromFile(struct Dog *dogs);
void generateDogReport(struct Dog *dogs, int dogNums);

int main(){
	int dogNums, inputChoice, outputChoice;
		
	printf("\n(1)Would you like to enter the Dog info or (2) Read from a file: ");
	scanf("%d", &inputChoice);
	do{
		if(inputChoice != 1 && inputChoice !=2){
			printf("\n[ERROR] Must Choose 1 or 2 \n");
		}
			
	}while(inputChoice != 1 && inputChoice !=2);
	
	do{
		printf("\nHow many dogs do you have? ");
		scanf("%d", &dogNums);
		
		if(dogNums <= 0 || dogNums >= 11){
			printf("\n[ERROR] Must Choose 1-10\n");
		}
			
	}while(dogNums <= 0 || dogNums >= 11);
	struct Dog dogs[dogNums];
	
	if (inputChoice ==1)
		getCustomerInfo(dogs, dogNums);
	else if(inputChoice ==2)
		getCustomerInfoFromFile(dogs);
	
	calculateSizeAndAge(dogs, dogNums);
	sortDogs(dogs, dogNums);
		
	printf("\n(1)Would you like output on the screen or (2) output to a file: ");
	scanf("%d", &outputChoice);
	do{
		if(outputChoice != 1 && outputChoice !=2){
			printf("\n[ERROR] Must Choose 1 or 2 \n");
		}
			
	}while(outputChoice != 1 && outputChoice !=2);
	
	if(outputChoice==1)
		displayDogs(dogs, dogNums);
	else if(outputChoice==2)
		generateDogReport(dogs,dogNums);

}

void getCustomerInfo(struct Dog dogs[], int dogNums){
	int x;
	
	for(x=0; x<dogNums; x++){
	
		getchar();
		printf("\nEnter your dog's name: ");
		gets(dogs[x].name);
		
		do{
			printf("Enter your dog's weight: ");
			scanf("%d", &dogs[x].weight);
			
			if(dogs[x].weight <= 4 || dogs[x].weight >= 201){
				printf("\n[ERROR] dog's weight must be between 5-200 pounds\n");
				//used online data for validation
			}	
		}while(dogs[x].weight <= 4 || dogs[x].weight >= 201);
		
		do{
			printf("Enter your dog's age: ");
			scanf("%d", &dogs[x].humanYears);
			
			if(dogs[x].humanYears <= 0 || dogs[x].humanYears >= 16){
				printf("\n[ERROR] dog's age must be between 1-15\n");
				//used online data for validation
			}
		}while(dogs[x].humanYears <= 0 || dogs[x].humanYears >= 16);
	} 
}

void calculateSizeAndAge(struct Dog *dogs, int dogNums){
	int x;
	
	for(x=0; x<dogNums; x++){
		if(dogs->weight >=50){
			strcpy(dogs->size, "large");
		}else if(dogs->weight >=21){
			strcpy(dogs->size, "medium");
		}else if(dogs->weight <= 20){
			strcpy(dogs->size, "small");
		}
		
		if(strcmp(dogs->size, "small")==0){
			if(dogs->humanYears>= 1)
				dogs->dogYears=15;
				
			if(dogs->humanYears>= 2)
				dogs->dogYears+=8;
				
			if(dogs->humanYears>= 3)
				dogs->dogYears+=5;
				
			if(dogs->humanYears>= 4)
				dogs->dogYears+=(dogs->humanYears-3)*4;
				
					
		}else if(strcmp(dogs->size, "medium")==0){
			if(dogs->humanYears>= 1)
				dogs->dogYears=14;
				
			if(dogs->humanYears>= 2)
				dogs->dogYears+=9;
				
			if(dogs->humanYears>= 3)
				dogs->dogYears+=7;
				
			if(dogs->humanYears>= 4)
				dogs->dogYears+=(dogs->humanYears-3)*5;
				
		}else if(strcmp(dogs->size, "large")==0){
			if(dogs->humanYears>= 1)
				dogs->dogYears=12;
				
			if(dogs->humanYears>= 2)
				dogs->dogYears+=9;
				
			if(dogs->humanYears>= 3)
				dogs->dogYears+=8;
				
			if(dogs->humanYears>= 4)
				dogs->dogYears+=(dogs->humanYears-3)*7;
		}	
		dogs++;
	}
}

void sortDogs(struct Dog dogs[], int dogNums){
	
	
	
	char sort;
	int i,j;
	struct Dog temp;
	
	do{
		printf("\nHow would you like to sort your dogs by (N)ame or (S)ize or (A)ge?  ");
		scanf(" %c",&sort);
		
		if(sort != 'N' && sort != 'n' && sort != 'S' && sort != 's' &&sort != 'A' && sort != 'a')
			printf("[ERROR] Must choose N, S, or A");
		
	} while(sort != 'N' && sort != 'n'
		&& sort != 'S' && sort != 's'
		&&sort != 'A' && sort != 'a');

	switch(sort){
		case 'N': case 'n':
			for(i=0; i < dogNums; i++){
				for (j= i + 1; j < dogNums; j++){
					if (strcmp(dogs[i].name,dogs[j].name) > 0){
				
			            temp = dogs[i];
			            dogs[i] = dogs[j];
			            dogs[j] = temp;
			        }
			    } 
			}
			break;
			
		case 'S': case 's':
			for(i=0; i < dogNums; i++){
				for (j= i + 1; j < dogNums; j++){
					if (dogs[i].weight > dogs[j].weight){
						
			            temp = dogs[i];
			            dogs[i] = dogs[j];
			            dogs[j] = temp;
		        	}
		    	} 
			}
			break;
			
		case 'A': case 'a':
			
			for(i=0; i < dogNums; i++){
				for (j= i + 1; j < dogNums; j++){
					if (dogs[i].humanYears > dogs[j].humanYears){
						
			            temp = dogs[i];
			            dogs[i] = dogs[j];
			            dogs[j] = temp;
			        }
			    } 
			}
			break;
	}
}

void displayDogs(struct Dog *dogs, int dogNums){
	int x;
	printf( "\nDog Name		Dog Weight		Years in Human		Years in Dog\n");
	for(x=0; x<dogNums; x++){
		printf("\n%-10s		%s dog		%8d		%8d", dogs->name, dogs->size, dogs->humanYears, dogs->dogYears);
		dogs++;
	}
}

void getCustomerInfoFromFile(struct Dog *dogs){
	char fileName[50];
	FILE *inputFile;
	
	do{

		getchar();
		printf("\nEnter your full file name: ");
		gets(fileName);
		
		inputFile= fopen(fileName, "r");
		
		if(inputFile==NULL){
			printf("[ERROR] File does not exist");
			printf("\n Re-enter file full name");
			exit(0);
		}

	}while(inputFile==NULL);
	
	char *name;
	int weight, humanYears;
	
	char line [100];
	char *sp;
	while(fgets(line,100,inputFile) != NULL){
		sp=strtok(line,",");
		name=sp;
		strcpy(dogs->name,name);
		
		sp=strtok(NULL,",");
		weight=atoi(sp);
		dogs->weight=weight;
		
		sp=strtok(NULL,",");
		humanYears=atoi(sp);
		dogs->humanYears=humanYears;
		
		dogs++;
	}
	fclose(inputFile);	

}

void generateDogReport(struct Dog *dogs, int dogNums){

	char fileName[50];
	FILE *outputFile;
	int x;
	
	getchar();
	printf("\nEnter a file name you would like to save too ");
	gets(fileName);
	strcat(fileName, ".csv");
	

	outputFile=fopen(fileName, "w");
	if(outputFile==NULL){
		printf("[ERROR] Can't Write to File");
		exit(0);
	}

	for(x=0; x<dogNums; x++){
		fprintf(outputFile, "\n%s,%s dog,%d,%d", dogs->name, dogs->size, dogs->humanYears, dogs->dogYears);
		dogs++;
	}
	
	fclose(outputFile);
}


