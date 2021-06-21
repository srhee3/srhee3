#include <stdio.h>
#include <stdbool.h>

// function declarations:
double askForIncome();
int testForTaxBracket(double income);
double remainingIncome(double income, int taxBracket);
double totalTaxes(double income, int taxBracket);
double remainingTaxes(double leftoverIncome, int taxBracket);
void printForBracket(double income, int taxBracket);
void printTaxes(double leftoverIncome, int taxBracket, double taxes);
double calcFlatTax(double income, double taxes);

double askForIncome() {  // asks user for their yearly income
    double userIncome;
    printf("Enter your income for the year: ");
    scanf("%lf", &userIncome);
    return userIncome;
}

int testForTaxBracket(double income) {
    /* 
       finds the highest tax bracket that the user is eligible for.

       i.e.: if the user earns $10,000, the function would return
       12 because since the first tax bracket would be $987.50, we would need
       to calculate the rest of the tax under the 12% bracket since the user
       does not earn more than $40,125.
    */

  if (income <= 9875) {
       return 10;
  } else if (income <= 40125) {
       return 12;
  } else if (income <= 85525) {
       return 22;
  } else if (income <= 163300) {
       return 24;
  } else if (income <= 207350) {
       return 32;
  } else if (income <= 518400) {
       return 35;
  } else {
       return 37;
  }
}

double remainingIncome(double income, int taxBracket) {
    // calculates the amount of income that has to be taxed in the highest tax bracket
      switch (taxBracket) {
        case 10:
            return income;
        case 12:
            return income - 9875;
        case 22:
            return income - 40125;
        case 24:
            return income - 85525;
        case 32:
            return income - 163300;
        case 35:
            return income - 207350;
        case 37:
            return income - 518400;
        default:
            return 0;   // should never reach default case
      }
}

double totalTaxes(double income, int taxBracket) {
    // calculates the total taxes the user owes
    double remainingIncome;  // amount of money that has to be paid in highest tax bracket
    switch (taxBracket) {
        case 10:
            return (income * 0.1);
        case 12:
            remainingIncome = income - 9875;
            return totalTaxes(9875, 10) + (remainingIncome * 0.12);
        case 22:
            remainingIncome = income - 40125;
            return totalTaxes(40125, 12) + (remainingIncome * 0.22);
        case 24:
            remainingIncome = income - 85525;
            return totalTaxes(85525, 22) + (remainingIncome * 0.24);
        case 32:
            remainingIncome = income - 163300;
            return totalTaxes(163300, 24) + (remainingIncome * 0.32);
        case 35:
            remainingIncome = income - 207350;
            return totalTaxes(207350, 32) + (remainingIncome * 0.35);
        case 37:
            remainingIncome = income - 518400;
            return totalTaxes(518400, 35) + (remainingIncome * 0.37);
        default:   // case default should never be run
            return 0;
    }
}

double remainingTaxes(double leftoverIncome, int taxBracket) {
    // used for printTaxes(), calculates amount of tax to be paid for the highest tax bracket
    // the user is eligible for

    switch (taxBracket) {
        case 10:
            return (leftoverIncome * 0.1);
        case 12:
            return (leftoverIncome * 0.12);
        case 22:
            return (leftoverIncome * 0.22);
        case 24:
            return (leftoverIncome * 0.24);
        case 32:
            return (leftoverIncome * 0.32);
        case 35:
            return (leftoverIncome * 0.35);
        case 37:
            return (leftoverIncome * 0.37);
        default:   // case default should never be run
            return 0;
    }
}

void printForBracket(double income, int taxBracket) {
    // prints the amount of taxes to paid for a specific bracket

    if (taxBracket == 10) {
        printf("You were taxed 10.00%% on the first $%.2lf you made which is $%.2lf.\n",
               income, remainingTaxes(income, 10));
    } else if (taxBracket == 12) {
        printf("You were taxed 12.00%% on the next $%.2lf you made which is $%.2lf.\n",
               income, remainingTaxes(income, 12));
    } else if (taxBracket == 22) {
        printf("You were taxed 22.00%% on the next $%.2lf you made which is $%.2lf.\n",
               income, remainingTaxes(income, 22));
    } else if (taxBracket == 24) {
        printf("You were taxed 24.00%% on the next $%.2lf you made which is $%.2lf.\n",
               income, remainingTaxes(income, 24));
    } else if (taxBracket == 32) {
        printf("You were taxed 32.00%% on the next $%.2lf you made which is $%.2lf.\n",
               income, remainingTaxes(income, 32));
    } else if (taxBracket == 35) {
        printf("You were taxed 35.00%% on the next $%.2lf you made which is $%.2lf.\n",
               income, remainingTaxes(income, 35));
    } else if (taxBracket == 37) {
        printf("You were taxed 37.00%% on the next $%.2lf you made which is $%.2lf.\n",
               income, remainingTaxes(income, 37));
    } else {
        printf("ERROR");
    }
}

void printTaxes(double income, int taxBracket, double taxes) {
    // prints to user the all of the taxes that they owe and how it is calculated
    double leftoverIncome;   // the money left over after you subtract from the bracket(s) above

    if (taxBracket >= 10) {
        if (income <= 9875) {
            printForBracket(income, taxBracket);
        }
        else {
            printForBracket(9875, 10);
        }
    }
    if (taxBracket >= 12) {
        leftoverIncome = remainingIncome(income, 12);
        if (income <= 40125) {
            printForBracket(leftoverIncome, taxBracket);
        }
        else {
            printForBracket(40125-9875, 12);
        }
    }
    if (taxBracket >= 22) {
        leftoverIncome = remainingIncome(income, 22);
        if (income <= 85525) {
            printForBracket(leftoverIncome, taxBracket);
        }
        else {
            printForBracket(85525-40125, 22);
        }
    }
    if (taxBracket >= 24) {
        leftoverIncome = remainingIncome(income, 24);
        if (income <= 163300) {
            printForBracket(leftoverIncome, taxBracket);
        }
        else {
            printForBracket(163300-85525, 24);
        }
    }
    if (taxBracket >= 32) {
        leftoverIncome = remainingIncome(income, 32);
        if (income <= 207350) {
            printForBracket(leftoverIncome, taxBracket);
        }
        else {
            printForBracket(207350-163300, 32);
        }
    }
    if (taxBracket >= 35) {
        leftoverIncome = remainingIncome(income, 35);
        if (income <= 518400) {
            printForBracket(leftoverIncome, taxBracket);
        }
        else {
            printForBracket(518400-207350, 35);
        }
    }
    if (taxBracket == 37) {
        leftoverIncome = remainingIncome(income, 37);
        printForBracket(leftoverIncome, taxBracket);
    }

    // print statement with total taxes:
    printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n",
           taxes, income);
}

double calcFlatTax(double income, double taxes) {   // calculates total flat tax
    return (taxes/income) * 100;
}

int main() {
    double income = askForIncome();
    int taxBracket = testForTaxBracket(income);
    double taxes = totalTaxes(income, taxBracket);
    printTaxes(income, taxBracket, taxes);

    double flatTax = calcFlatTax(income, taxes);
    printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n",
           flatTax);
    return 0;
}