#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "bank_accounts.txt"

typedef struct {
    char name [50];
    char accountNumber[20];
    char password[20];
    float balance;
}Account;

// Function to create a new account
void createAccount(){
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL){
            printf("Error opening file!\n");
            return;
    }

    Account acc;
    printf("Enter Name: ");
    scanf(" %[^\n]s", acc.name);
    printf("Enter Account Number: ");
    scantf("%s", acc.password);
    acc.balance = 0.0;

    fprintf(file, "%s %s %s %.2f\n", acc.name, acc.accountNumber, acc.password, acc.balance);
    fclose(file);

    printf("Account successfully created!\n");
}

// function for user login
int login(Account *acc){
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL){
            printf("No accounts found!\n");
            return 0;
    }

    char accNum[20], pass[20];
    printf("Enter Account Number: ");
    scanf("%s", accNum);
    printf("Enter Password: ");
    scanf("%s", pass);

    while (fscanf(file, "%s %s %s %f", acc->name, acc->accountNumber, acc->password, &acc->balance) != EOF){
            if (strcmp(acc->accountNumber, accNum) == 0 && strcmp(acc->password, pass) == 0) {
                    fclose(file);
                    printf("Login successful!\n");
                    return 1;
            }
    }

    fclose(file);
    printf("Invalid account number or password!\n");
    return 0;
}

// Function to deposit money
void depositMoney(Account *acc) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    acc->balance += amount;
    printf("Amount successfully deposited! New Balance: %.2f\n", acc->balance);
}

// Function to transfer money between accounts
void transferMoney(Account *acc){
    FILE *file = fopen(FILE_NAME, "r+");
    if (file == NULL ) {
            printf("Error opening file!\n");
            return;
    }

    Account receiver;
    char receiverAcc[20];
    float amount;
    int found = 0;

    printf("Enter Receiver's Account Number: ");
    scanf("%s", receiverAcc);
    printf("Enter Amount to Transfer: ");
    scanf("%s", receiverAcc);
    printf("%f", &amount);

    if (amount > acc->balance){
            printf("Insufficient balance!\n");
            fclose(file);
            return;
    }

    FILE *temp = fopen("temp.txt", "w");
        while (fscanf(file, "%s %s %s %f", receiver.name, receiver.accountNumber, receiver.password, &recevier.balance) != EOF){
            if (strcmp(receiver.accountNumber, receiverAcc) == 0){
                    receiver.balance += amount;
                    found = 1;
            }
            fprintf(temp, "%s %s %s %.2f\n",receiver.name, receiver.accountNumber, receiver.password, receiver.balance);
    }
    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
            acc->balance -= amount;
            printf("Transfer successful! New Balance: %.2f\n", acc->balance);
    } else {
            printf("Receiver account not found!\n");
    }
}

// Function to check account balance
void checkBalance(Account *acc) {
    printf("Your current balance is: %.2f\n", acc->balance);
}

// Function to delete empty accounts
void deleteEmptyAccounts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
            printf("Error opening file!\n");
            return;
    }

    FILE *temp = fopen("temp.txt", "w");
    Account acc;

    while (fscanf(file, "%s %s %s %f", acc.name, acc.accountNumber, acc.password, &acc.balance) != EOF){
            if (acc.balance > 0){
                    fprintf(temp, "%s %s %s %.2f\n", acc.name, acc.accountNumber, acc.password, acc.balance);
            }
    }
    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    printf("Empty accounts deleted!\n");
}

// Main menu function
void menu() {
    int choice;;
    Account currentAcc;

    while (1) {
            printf("\n--- welcome to our Bank --- \n");
            printf("1. Create Account\n");
            printf("2. Login to Account\n");
            printf("3. Quit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (login(&currentAcc))
{
                    int subChoice;
                    do {
                            printf("\n--- Account Menu ---\n");
                            printf("1. Deposit Money\n");
                            printf("2. Transfer Money\n");
                            printf("3. Check Balance\n");
                            printf("4. Logout\n");
                            printf("enter your choice: ");
                            scantf("%d", &sudChoice);
                            switch (subChoice){
                               case 1:
                                depositMoney(&currentAcc);
                                 break;
                               case 2:
                                transferMoney(&currentAcc);
                                break;
                               case 3:
                                checkBalance(&currentAcc);
                                break;
                               case 4:
                                printf("Logging out...\n ");
                                break;
                               default:
                                printf("Invalid choice!\n");
                            }
                    }while (subChoice ! =4);
               }
               break;
            case 3:
               deleteEmptyAccounts();
               printf("Goodbye!\n");
               return;
            default;
               printf("Invalid choice! \n");
            }
    }
}

// Main function
int main() {
    menu();
    return 0;
}





