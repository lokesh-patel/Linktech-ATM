#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    system("color 1F");
    int pin = 7890, option, enteredPin, count = 0, amount = 1;
    float balance = 5000;
    int continueTransaction = 1;

    time_t now;
    time(&now);
    // printf("%s\n",ctime(&now));
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t    %s", ctime(&now));
    printf("\n\t\t\t----------------------------*WELCOME TO LINKTECH ATM*----------------------------");

    while (pin != enteredPin)
    {
        printf("\nPlease Enter Your Pin : ");
        scanf("%d", &enteredPin);
        if (enteredPin != pin)
        {
            Beep(610, 500);
            printf("Invalid Pin !!");
        }
        count++;
        if (count == 3 && pin != enteredPin)
        {
            exit(0);
        }
    }

    while (continueTransaction != 0)
    {
        printf("\n\t\t\t----------------------------#Available Transsactions#----------------------------");
        printf("\n\n\t\t (1) Withdrawl");
        printf("\n\n\t\t (2) Deposit");
        printf("\n\n\t\t (3) Check Balance");
        printf("\n\n\t\t (4) Passbook");
        printf("\n\n\t\t (5) Cheque Book");
        printf("\n\n\t\t (6) Your Information");

        printf("\n\n\t Please Select The Option :");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            while (amount % 500 != 0)
            {
                printf("\n\t\t Enter The Amount :");
                scanf("%d", &amount);
                if (amount % 500 != 0)
                    printf("\n\t The amount should be multiple of 500");
            }
            if (balance < amount)
            {
                printf("\n\t Sorry Insufficient Balance");
                amount = 1;
                break;
            }
            else
            {
                balance -= amount;
                printf("\n\t\tYou Have Withdrawn Rs %d. So Your New Balance Is %.4f", amount, balance);
                printf("\n\t\t\t--------------------------THANK YOU FOR BANKING WITH US--------------------------");

                amount = 1;
                break;
            }
        case 2:
            printf("\n\t\t Please Enter The Amount : ");
            scanf("%d", &amount);
            balance += amount;
            printf("\n\t\t You Have Deposited Rs %d. So Your New Balance Is %.4f", amount, balance);
            printf("\n\t\t\t--------------------------THANK YOU FOR BANKING WITH US--------------------------");
            amount = 1;
            break;

        case 3:
            printf("\n\t\t Your Balance Is Rs %.4f", balance);
            printf("\n\t\t\t--------------------------THANK YOU FOR BANKING WITH US--------------------------");
            break;

        case 4:
            printf("\n\t\t Please Enter Your Pin Code :");
            scanf("%d", &pin);
            if (pin == 7890)
            {
                printf("Your Wish For Issuing Passbook Has been Successfully Granted Within 2 Days Your Passbook Is Going To Be Deliver In Your Doorstep.");
            }
            else
            {
                printf("Invalid Pin ! Please try again");
            }

            printf("\n\t\t\t--------------------------THANK YOU FOR BANKING WITH US--------------------------");
            break;

        case 5:
            printf("\n\t\t Please Enter Your Pin Code :");
            scanf("%d", &pin);
            if (pin == 7890)
            {
                printf("Your Wish For Issuing Cheque Book Has been Successfully Granted Within 2 Days Cheque Book Your Is Going To Be Deliver In Your Doorstep.");
            }
            else
            {
                printf("Invalid Pin ! Please try again");
            }

            printf("\n\t\t\t--------------------------THANK YOU FOR BANKING WITH US--------------------------");
            break;

        case 6:
            printf("\n\t\t Please Enter Your Pin Code :");
            scanf("%d", &pin);
            if (pin == 7890)
            {
                printf("\n\t\t\ttCard Owner Name : Linktech\n\t\t\tIFSC Code : BKID0000000\n\t\t\tCustomer Id : ###########\n\t\t\tAccount No : 8700101111111111");
            }
            else
            {
                printf("Invalid Pin ! Please try again");
            }

            printf("\n\t\t\t--------------------------THANK YOU FOR BANKING WITH US--------------------------");
            break;

        default:
            Beep(610, 500);
            printf("\n\t\tInvalid Option !!");
        }
        printf("\n\t\tDo You Wish To Perform Another Transaction ? Press 1[Yes], 0[No]\n");
        scanf("%d", &continueTransaction);
    }

    return 0;
}