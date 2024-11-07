#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura de dados
typedef struct {
    char bank_name[20];
    char bank_branch[20];
    char acc_holder_name[30];
    int acc_number;
    char acc_holder_address[100];
    float available_balance;
} AccDetail;

AccDetail accounts[20];  // Array para armazenar as contas
int num_acc = 0;         // Número de contas criadas

// Funções auxiliares
void display_account_info(AccDetail account);
int update_balance(int acc_no, float amount, int is_deposit);
void display_options();
void Create_new_account();
void Cash_Deposit();
void Cash_withdrawal();
void Account_information();
void Log_out();

// Função principal
int main() {
    char option;
    char f2f[50] = "https://www.fresh2refresh.com/";

    while (1) {
        printf("\n***** Welcome to Bank Application *****\n");
        printf("\nThis demo program is brought to you by %s", f2f);
        display_options();
        printf("Please enter an option (1/2/3/4/5/6) to continue: ");

        scanf(" %c", &option);
        printf("%c \n", option);

        switch (option) {
            case '1': Create_new_account(); break;
            case '2': Cash_Deposit(); break;
            case '3': Cash_withdrawal(); break;
            case '4': Account_information(); break;
            case '5': Log_out(); return 0; break;
            case '6': system("cls"); break;
            default:
                printf("Please enter a valid option (1/2/3/4/5/6) to continue\n");
                break;
        }
    }
    return 0;
}

// Função para exibir as opções
void display_options() {
    printf("\n1. Create new account\n");
    printf("2. Cash Deposit\n");
    printf("3. Cash Withdrawal\n");
    printf("4. Account information\n");
    printf("5. Log out\n");
    printf("6. Clear the screen and display available options\n\n");
}

// Função para criar uma nova conta
void Create_new_account() {
    char bank_name[20], bank_branch[20], acc_holder_name[30], acc_holder_address[100];
    int acc_number;
    float available_balance = 0;

    printf("\nEnter the bank name              : ");
    scanf("%s", bank_name);
    printf("Enter the bank branch            : ");
    scanf("%s", bank_branch);
    printf("Enter the account holder name    : ");
    scanf("%s", acc_holder_name);
    printf("Enter the account number (1-20)  : ");
    scanf("%d", &acc_number);
    printf("Enter the account holder address : ");
    scanf(" %99[^\n]", acc_holder_address);  // Para permitir espaço em branco no endereço

    // Validação de número da conta
    if (acc_number < 1 || acc_number > 20) {
        printf("Invalid account number! Please enter a number between 1 and 20.\n");
        return;
    }

    // Armazenando as informações da conta
    strcpy(accounts[acc_number - 1].bank_name, bank_name);
    strcpy(accounts[acc_number - 1].bank_branch, bank_branch);
    strcpy(accounts[acc_number - 1].acc_holder_name, acc_holder_name);
    accounts[acc_number - 1].acc_number = acc_number;
    strcpy(accounts[acc_number - 1].acc_holder_address, acc_holder_address);
    accounts[acc_number - 1].available_balance = available_balance;

    num_acc++;  // Incrementa o número de contas

    printf("\nAccount has been created successfully:\n");
    display_account_info(accounts[acc_number - 1]);
}

// Função para exibir informações de uma conta
void display_account_info(AccDetail account) {
    printf("\nBank name              : %s\n", account.bank_name);
    printf("Bank branch            : %s\n", account.bank_branch);
    printf("Account holder name    : %s\n", account.acc_holder_name);
    printf("Account number         : %d\n", account.acc_number);
    printf("Account holder address : %s\n", account.acc_holder_address);
    printf("Available balance      : %.2f\n\n", account.available_balance);
}

// Função para exibir informações de todas as contas
void Account_information() {
    if (num_acc == 0) {
        printf("No accounts available.\n");
        return;
    }

    for (int i = 0; i < num_acc; i++) {
        display_account_info(accounts[i]);
    }
}

// Função para depósito de dinheiro
void Cash_Deposit() {
    int acc_no;
    float deposit_amount;

    printf("Enter account number to deposit money: ");
    scanf("%d", &acc_no);

    // Validação do número da conta
    if (acc_no < 1 || acc_no > 20 || acc_no > num_acc) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Current balance for account %d is %.2f\n", acc_no, accounts[acc_no - 1].available_balance);
    printf("Enter amount to deposit: ");
    scanf("%f", &deposit_amount);

    // Atualiza o saldo da conta
    if (update_balance(acc_no, deposit_amount, 1)) {
        printf("Deposited successfully! New balance: %.2f\n", accounts[acc_no - 1].available_balance);
    }
}

// Função para saque de dinheiro
void Cash_withdrawal() {
    int acc_no;
    float withdrawal_amount;

    printf("Enter account number to withdraw money: ");
    scanf("%d", &acc_no);

    // Validação do número da conta
    if (acc_no < 1 || acc_no > 20 || acc_no > num_acc) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Current balance for account %d is %.2f\n", acc_no, accounts[acc_no - 1].available_balance);
    printf("Enter amount to withdraw: ");
    scanf("%f", &withdrawal_amount);

    // Atualiza o saldo da conta
    if (update_balance(acc_no, withdrawal_amount, 0)) {
        printf("Withdrawal successful! New balance: %.2f\n", accounts[acc_no - 1].available_balance);
    }
}

// Função para atualizar o saldo (depósito ou saque)
int update_balance(int acc_no, float amount, int is_deposit) {
    if (is_deposit) {
        accounts[acc_no - 1].available_balance += amount;
    } else {
        if (accounts[acc_no - 1].available_balance < amount) {
            printf("Insufficient funds!\n");
            return 0;
        }
        accounts[acc_no - 1].available_balance -= amount;
    }
    return 1;
}

// Função para logout
void Log_out() {
    printf("Logging out...\n");
}

