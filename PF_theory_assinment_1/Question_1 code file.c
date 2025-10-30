#include <stdio.h>
int main()
{
    int transaction_amount;
    int location;
    int number_of_transactions;

    printf("Please enter the transaction amount: ");
    scanf("%d", &transaction_amount);

    printf("Please enter the location (1 for Pakistan, 2 for UK): ");
    scanf(" %d", &location);

    printf("Please enter the number of today's transactions you have made: ");
    scanf("%d", &number_of_transactions);

    // Step 1: Transaction amount check
    // Daily transaction limit is 50000 or less.

    if (transaction_amount > 50000)
    {
        printf("High value transaction detected because it exceeds the daily limit.\n");
        printf("Warning: Potential fraudulent activity detected.\n");
        return 0; // End program because transaction is not allowed
    }
    // Step 2: Number of transactions check
    //transaction allowed locations are Pakistan or UK only.
    else if (location != 1 && location != 2)
    {
        printf("Your location is invalid for this transaction.\n");
        printf("Suspicious transaction detected.\n");
        return 0; // End program because transaction is not allowed
    }
    // Step 3: Number of transactions check
    // Maximum number of transactions per day is 3.
    else if (number_of_transactions > 3)
    {
        printf("You have exceeded the maximum number of transactions allowed for today.\n");
        printf("Warning: Potential fraudulent activity detected.\n");
        return 0; // End program because transaction is not allowed
    }
    else
    {
       if (location == 1){
            printf("Your location is Pakistan and transaction amount is %d which is valid for this transaction.\n", transaction_amount);
        }
        else{
            printf("Your location is UK and transaction amount is %d which is valid for this transaction.\n", transaction_amount);
        }

        printf("Transaction is valid and processed successfully.\n");
    }
    return 0;
}