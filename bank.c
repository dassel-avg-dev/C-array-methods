#include <stdio.h>

void display(float amount, float balance, int type) {
    printf((type) ? "\n\t\t\tTransaction: Deposit\n" : "\n\t\t\tTransation: Issuance\n");
    printf("\t\t\tAmount Entered: %.2f\n",amount);
    printf("\t\t\tRemaining Balance: %.2f\n\n",balance);
}

int main() {
    float amount=0.0, balance=0.0;
    
    printf("\t\t\t\tWELCOME TO BANK\n\n");
    do {
        printf("\t\tEnter amount: ");
        scanf("%f",&amount);
        
        if(amount > 0.0) {
            balance += amount;
            display(amount, balance, 1);
        }
        else if(amount < 0.0) {
            amount = -amount;
            if(amount > balance ) {
                printf("\n\t\tInvalid amount, Try again\n\n");
                continue;
            } 
            else {
                balance -= amount;
                display(amount, balance, 0);
            }
        }
        
    }while(amount!=0);
    printf("\n\t\t\t\tTHANK YOU FOR USING OUR SERVICES\n");
    
    return 0;
}