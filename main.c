#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FOOD_NAME 30
#define MAX_SPECIFFIC_FOOD_NAME 30
#define MAX_LINE 100
#define MAX_DRINK_NAME 30

void readLine(char * line, char * name, double *price);


int main() {

    int noOfFoods;
    printf("Please input number of food types\n");
    scanf("%d",&noOfFoods);
    printf("Please input food types (each on a new line, may contain spaces)\n");
    char ** foods;
    foods = (char**)malloc(noOfFoods * sizeof(char*));
    for(int i=0;i<noOfFoods;i++) {
        foods[i] = (char*)malloc(MAX_FOOD_NAME * sizeof(char));
        scanf("%s",foods[i]);
    }

    int * noOfSpecifficFoods = (int*)malloc(noOfFoods * sizeof(int));
    char *** specifficFoods = (char***)malloc(noOfFoods * sizeof(char**));
    double ** prices = (double**)malloc(noOfFoods * sizeof(double*));
    for(int i=0;i<noOfFoods;i++)
    {
        printf("Please input no of speciffic foods for food \"%s\" \n",foods[i]);
        scanf("%d",&noOfSpecifficFoods[i]);
        getchar();

        specifficFoods[i] = (char**)malloc(noOfSpecifficFoods[i] * sizeof(char*));
        prices[i] = (double*)malloc(noOfSpecifficFoods[i] * sizeof(double));
        printf("Please input \"%s\" speciffic foods & prices: each line in the format <speciffic food> (price):\n", foods[i]);
        for(int j=0; j < noOfSpecifficFoods[i]; j++)
        {
            specifficFoods[i][j] = (char*)malloc(MAX_SPECIFFIC_FOOD_NAME * sizeof(char));
            //char * line = (char*)calloc(MAX_LINE , sizeof(char));
            char line[MAX_LINE];
            for(int k=0; k<MAX_LINE; k++)
                line[k] = '\0';
            gets(line);
            readLine(line, specifficFoods[i][j], &prices[i][j]);
        }
    }
    //read number of drinks
    printf("Please input no of drinks\n");
    int  noOfDrinks;
    scanf("%d", &noOfDrinks);
    getchar();
    printf("Please input the drinks: each line in the format <drink> (price):\n");
    char ** drinks = (char**)malloc(noOfDrinks * sizeof(char*));
    double * drinksPrices = (double*)malloc(noOfDrinks * sizeof(double));
    for(int i=0; i<noOfDrinks; i++)
    {
        //read drinks
        drinks[i] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
        char line[MAX_LINE];
        for(int k=0; k<MAX_LINE; k++)
            line[k] = '\0';
        gets(line);
        readLine(line, drinks[i], &drinksPrices[i]);
    }
    //display food data
    printf("The food data is:\n");
    for(int i=0;i<noOfFoods;i++) {
        printf("%s: ", foods[i]);
        for(int j=0; j < noOfSpecifficFoods[i]; j++) {
            printf("(%s- %.2lf) ", specifficFoods[i][j], prices[i][j]);
        }
        printf("\n");
    }
    //display drinks data
    printf("The drinks data is:\n");
    printf("drinks: ");
    for(int i=0; i < noOfDrinks - 1; i++) {
        printf("%s, ", drinks[i]);
    }
    printf("%s\n", drinks[noOfDrinks - 1]);

    printf("prices: ");
    for(int i=0; i < noOfDrinks - 1; i++) {
        printf("%0.lf, ", drinksPrices[i]);
    }
    printf("%.0lf", drinksPrices[noOfDrinks - 1]);
    //free memory
    for(int i=0;i<noOfFoods;i++) {
        for(int j=0; j < noOfSpecifficFoods[i]; j++) {
            free(specifficFoods[i][j]);
        }
        free(specifficFoods[i]);
        free(prices[i]);
        free(foods[i]);
    }
    free(specifficFoods);
    free(prices);
    free(foods);
    free(noOfSpecifficFoods);
    free(drinks);

    return 0;
}

void readLine(char * line, char * name, double * price)
{
    int i=0;
    *price = 0;
    while(line[i] != '(' && i<strlen(line))
    {
        name[i] = line[i];
        i++;
    }
    name[i-1] = '\0';
    printf("%s\n",name);
    i++;
    while(line[i]<='9' && line[i]>='0')
    {
        *price = *price * 10 + (double)(line[i]-'0');
        i++;
    }
}