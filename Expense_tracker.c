#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_EXPENSES 100
#define MAX_CATEGORY_LENGTH 50


typedef struct {

    float amount;
    char category[MAX_CATEGORY_LENGTH];
    char date[11];

} Expense;


Expense expenses [MAX_EXPENSES];
int numExpenses = 0;


void addExpense()
{
    if(numExpenses >= MAX_EXPENSES)
    {
        printf("Expense Limit Exceeded!\n");
        return; 
    }

    Expense newExpense;
    printf("Enter Amount : ");
    scanf("%f", &newExpense.amount);
    printf("Enter Category : ");
    scanf("%s", newExpense.category);
    printf("Enter Date (DD-MM-YYYY) : ");
    scanf("%s", newExpense.date);

    expenses[numExpenses++] = newExpense;
    printf("Expense added successfully!\n");

}

void displayExpenses()
{
    if(numExpenses == 0)
    {
        printf("No Expenses Recorded\n");
        return;
    }

    printf("Expenses: \n");
    for(int i = 0; i < numExpenses; i++)
    {
        printf("Amount: $%.2f | Category : %s | Date : %s\n", expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

int main()
{
    int choice;

    do
    {
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);


        switch(choice)
        {
            case 1: 
               addExpense();
               break;
            case 2:
               displayExpenses();
               break;
            case 3:
               printf("Exiting...\n");
               break;
            default :
               printf("Invalid Choice, please enter a valid choice\n");

        }
    } while(choice != 3);

    return 0;
}