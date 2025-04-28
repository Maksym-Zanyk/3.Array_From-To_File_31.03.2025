#include <iostream>
#include <stdio.h>
#include "func.h"
#define LENGTH 10

void menu(){
    printf("0. Exit\n");
    printf("1. Print an array\n");
    printf("2. Enter numbers to array\n");
    printf("3. Print MIN value\n");
    printf("4. Print MAX value\n");
    printf("5. Print average value\n");
    printf("6. Print median value\n");
    printf("7. Edit number\n");
    printf("8. Save data to file\n");
    printf("9. Load data from file\n\n");



    printf("\tSelect an option: ");

}

int errorCode;

int main() {

    printf("Simple array program\n");

    int numbers[LENGTH] = {0};

    int option;

    do{
        menu();
        scanf("%d", &option);

        switch (option) {
            case 0:
                break;
            case 1:
                PrintTab(numbers);
                break;
            case 2:
                EnterNumbersToTab(numbers);
                break;
            case 3:
                printf("Min= %d \n", SearchMin(numbers));
                break;
            case 4:
                printf("Max= %d \n", SearchMax(numbers));
                break;
            case 5:
                printf("Average= %.2f\n", CalculateAverage(numbers));
                break;
            case 6:
                printf("Median= %.2f\n", SearchMedian(numbers));
                break;
            case 7:
                EditNumberByIndex(numbers);
                break;
            case 8:
                errorCode = SaveArrayToFile(numbers);
                if(errorCode){
                    printf("Something went wrong");
                }
                else{
                    printf("Saved successfuly");
                }
                break;
            case 9:
                errorCode = LoadArrayFromFile(numbers);
                if(errorCode){
                    printf("Something went wrong");
                }
                else{
                    printf("Loaded successfuly");
                }
                break;
            default:
                printf("No such option. Try again\n\n");


        }
        puts("");

    }while(option != 0);


    return 0;

}