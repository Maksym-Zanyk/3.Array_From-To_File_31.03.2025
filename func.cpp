#include <iostream>
#include <stdio.h>
#define LENGTH 10


void EnterNumbersToTab(int *tab) {

    for(int i = 0; i<LENGTH; i++) {

        printf("Enter %d number: ", i+1);
        scanf("%d", tab+i);
    }
    printf("\n");
}

void PrintTab(const int *tab) {

    for(int i = 0; i<10; i++) {
        printf("[%d]=%d\t", i, *(tab+i));
    }
    printf("\n");
}

int SearchMax(const int *tab) {
    int max = *(tab);

    for(int i = 0; i<LENGTH; i++) {
        if(max < *(tab+i)) {
            max = *(tab+i);
        }
    }

    return max;
}

int SearchMin(const int *tab) {
    int min = *(tab);

    for(int i = 0; i<LENGTH; i++) {
        if(min > *(tab+i)) {
            min = *(tab+i);
        }
    }

    return min;
}

float CalculateAverage(const int *tab) {
    int sum = 0;

    for(int i = 0; i<LENGTH; i++) {
        sum += *(tab+i);
    }

    return sum/LENGTH;

}

float SearchMedian(const int *tab) {
    int SortedTab[LENGTH];

    for(int i = 0; i<LENGTH; i++) {
        *(SortedTab+i) = *(tab+i);
    }


    for(int i = 0; i<LENGTH-1; i++) {
        for(int j = 0; j<LENGTH-1-i; j++){
            if(*(SortedTab+j) > *(SortedTab+j+1)) {
                int temp = *(SortedTab+j);
                *(SortedTab+j) = *(SortedTab+j+1);
                *(SortedTab+j+1) = temp;
            }
        }
    }

    float median;

    if(LENGTH % 2 == 0) {
        int index_of_middle_num = (LENGTH/2)-1;
        int first_num = *(SortedTab+index_of_middle_num);
        int second_num = *(SortedTab+index_of_middle_num+1);
        median = ((float)first_num + (float)second_num)/2;
    }
    else {
        median = (float) *(SortedTab + ((LENGTH+1)/2) );
    }

    printf("\n\nSorted tab:\n");
    PrintTab(SortedTab);

    return median;
}

void EditNumberByIndex(int *tab) {
    printf("Index of number: ");

    int ind;
    scanf("%d", &ind);

    if (ind < 0 || ind > 9) {
        printf("ERROR\n");
    }
    else {
        printf("New value: ");
        scanf("%d", tab + ind);
    }
}


int SaveArrayToFile(int *tab){

    FILE *fptr;

    fptr = fopen("..array_data.txt", "w");

    if (fptr == 0)
    {
        printf("ERROR with opening the file\n");
        return 1;
    }
    else{
        for(int i=0; i<LENGTH; i++){
            fprintf(fptr, "%d\n", *(tab+i));
        }

    }

    fclose(fptr);
    return 0;
}

int LoadArrayFromFile(int *tab){
    FILE *fptr;

    fptr = fopen("..array_data.txt", "r");

    if (fptr == 0)
    {
        printf("ERROR with opening the file\n");
        return 1;
    }
    else{

        for(int i=0; i<LENGTH; i++){
            if (fscanf(fptr, "%d",&tab[i]) != 1){
                fclose(fptr);
                return 2;
            }
        }

    }
    fclose(fptr);
    return 0;
}