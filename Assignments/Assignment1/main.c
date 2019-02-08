/* Assignment 1:
 * The purpose of Assignment 1 is to create a 'C' program, based on the spreadsheet given in the assignment document.
 * Determine the variables and calculations needed to recreate the example given.
 * Created by: Andrew Parisee.
 */
#include <stdio.h>
#include <math.h>

int main() {

    // Variables
    double hoursWorked = 0;
    double hourlyWage = 0;
    double grossPay = 0;
    int paysInAYear = 26;
    double vacationPay;
    double totalIncome;
    double federalTax;
    double provincialTax;
    double totalTax;
    double cppAmount;
    double eiAmount;
    double netPay;
    double annualIncome;
    double annualCPP;
    double annualEI;

    // Prompt User
    printf("Assignment 1 - Pay Cheque\n");
    printf("-------------------------\n");
    printf("\nPlease enter the number of hours worked: ");
    scanf(" %lf", &hoursWorked);
    printf("Please enter the wage per hour: ");
    scanf(" %lf", &hourlyWage);

    // Calculations
    grossPay = hourlyWage * hoursWorked;
    vacationPay = grossPay * 0.04;
    totalIncome = vacationPay + grossPay;
    federalTax = totalIncome * 0.0176344;
    provincialTax = totalIncome * 0.018842;
    totalTax = federalTax + provincialTax;
    cppAmount = totalIncome * 0.038478;
    eiAmount = totalIncome * 0.0166;
    netPay = totalIncome - totalTax - cppAmount - eiAmount;
    annualIncome = totalIncome * paysInAYear;
    annualCPP = cppAmount * paysInAYear;
    annualEI = eiAmount * paysInAYear;


    // Results
    printf("\nGross Pay: $%.02lf\n", grossPay);
    printf("Vacation: $%.02lf\n", vacationPay);
    printf("Total Income: $%.02lf\n", totalIncome);

    printf("\nAnnual Income: $%0.2lf\n", annualIncome);
    printf("Annual CPP: $%0.2lf\n", annualCPP);
    printf("Annual EI: $%0.2lf\n", annualEI);

    printf("\nFederal Tax: $%.02lf\n", federalTax);
    printf("Provincial Tax: $%.02lf\n", provincialTax);
    printf("Total Tax: $%.02lf\n", totalTax);

    printf("\nCPP: $%.02lf\n", cppAmount);
    printf("EI: $%.02lf\n", eiAmount);

    printf("\nNet Pay = $%.02lf", netPay);


    return 0;
}