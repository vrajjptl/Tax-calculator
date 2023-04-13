//This is a C program to check your eligibility to pay tax , calculate your personal income tax and save maximum tax legally
//This C program is a part of mini project done by :-
//Abhijit Zende
//Viraj Patil
//Vaibhav Patil
//Shreyas Patil
//Disclaimer :-
//We are not a qualified professionals and we don't have a CA or relevant degree below program is completely made
//by consulting information available at Income Tax department of India although our program is very reliable but proceed
//with your own risk
//This program was made in compliance of rules present up-to date 29 June 2021

//References :
//Income Tax Department of India        https://incometaxindia.gov.in/Pages/default.aspx
//ET Money                              https://www.etmoney.com/tools-and-calculators/income-tax-calculator
//Income Tax Act of India               https://www.incometaxindia.gov.in/pages/acts/index.aspx

#include<stdio.h>
#include<string.h>

long int annual_salary=0;           //Variable to save individual annual salary
long int net_salary=0;              //Net salary is amount you get after reducing exemptions from your annual salary
long int net_annual_income=0;       //net annual income is the amount on which you will pay tax . It is also net taxable income after some deductions
long int total_exemption=0;         //This the amount of total exemptions you get in a year
long int total_tax=0;               //This is the amount of tax you will pay in the financial year
int choice=0;
char eligibile[3];

void eligibility();                 //Function to determine your eligibility to pay tax
void t_exemption();                 //Function to calculate total exemption you get on on your annual salary and net annual salary
void n_annual_income();             //Function to calculate net annual income i.e. net annual salary + other source of income
void t_tax();                       //Function to calculate total tax of the financial year

int main()
{
    char user_name[10];

    printf("\n****************************************************\n\n");
    printf("\n\nPlease enter your name : \n");
    scanf("%s",&user_name);
    printf("\n     ................................................................................................\n");
    printf("     ..                                                                                            ..\n");
    printf("     ..                                                                                            ..");
    printf("\n     ..            Welcome to our program '%s' , hope you are doing well                      ..\n",user_name);
    printf("     ..                                                                                            ..\n");
    printf("     ..    This program will determine your eligibility , total tax and max out your tax savings   ..\n");
    printf("     ..                                                                                            ..\n");
    printf("     ................................................................................................\n");

    eligibility();

    if(choice == 0)
    {
        t_exemption();
        n_annual_income();
        t_tax();

        if(net_annual_income < 500000)
        {
            printf("\n\nAs your net taxable income is less than 5 Lahk you can avail a rebate of Rs. 12500!\n");
            printf("\n..............................................................................................\n");

        }
        else
        {
            printf("\n\nAs your net taxable income is greater than 5 Lakh you cannot avail the rebate!\n");
        }

    }

    printf("\nThank you using our program!\n\n");

    printf("\n****************************************************\n\n");

    printf("\n\n\n----------> HOW TO SAVE MORE TAX LEGALLY ? <----------");
    printf("\n\n# A] Tax deduction under section 80 of IT act :  \n");
    printf("\n a] Deduction of upto 1.5 Lakh under section 80C by investing in following schemes : \n");
    printf("  1. Public Provident Fund (PPF) \n");
    printf("  2. Equity Saving Schemes (ELSS) \n");
    printf("  3. Sukanya Samriddhi Yojana (SSY) \n");
    printf("  4. Premium paid for term insurance \n");
    printf("  5. Payment towards principal home loan \n");

    printf("\n b] Deduction of upto Rs.50k under section 80CCD by investing in NPS \n");

    printf("\n c] Deduction of upto Rs.10k under section 80TTA by the interest earned from saving accounts \n");

    printf("\n\n#B] You also can get deduction on interest paid on Education loan \n");

    printf("\n\n#C] Deduction of upto Rs.2Lakh under section 24 by the interest paid on home loan in the financial year.\n\n");

    printf("\n------------------> END OF PROGRAM <------------------");


    printf("\n\n\n****************************************************\n");
    printf("****************************************************\n\n");


}

void eligibility()
{
    int ch1=0;

    do
    {
        printf("\n\n\n##### ---> If your are eligible for any of the following conditions enter 'YES' if not then enter 'NO' : <--- ####\n\n");
        printf("-------> 1)Your gross annual income is less than 2.5 lakh\n");
        printf("-------> 2)Your annual total income comes directly or indirectly only from agriculture\n");
        printf("-------> 3)Non resident foreign national\n");
        printf("-------> 4)Disability pension of all armed forces\n");
        printf("-------> 5)Any income received from working in Indian Institution like embassy, legation etc.\n");
        printf("\nEnter your input ( if eligible for any condition enter 'YES' or else 'NO' ) \n");
        //scanf("%d",&choice);
        scanf("%s",&eligibile);

        if(strcmp(eligibile , "YES")==0)
        {
            printf("\n---->Congratulations you don't have to pay taxes!<----\n");
            ch1 = 1;
            choice = 1;
            printf("\n..............................................................................................\n");
            return;
        }
        else if(strcmp(eligibile , "NO")==0)
        {
            printf("\n####--->You are eligible to pay tax!<---####\n");
            ch1 = 1;
            printf("\n..............................................................................................\n");
            return;
        }
        else
        {
            printf("\nInvalid input!\n");
            printf("Enter either 'NO' if not eligible for any condition or 'YES' if eligible for even single condition\n");
        }
    } while (ch1==0);

}


void t_exemption()
{
    int ch2 = 2;
    long int hra,lta;
    char rent[3];

    printf("\nEnter your annual salary : \n");
    scanf("%d",&annual_salary);

    printf("\nYour annual salary is :  %d",annual_salary);

    do
    {
        printf("\n\nDo you live in a rented house or not : \n");
        printf("Enter 'YES' if Yes and 'NO' if not\n");
        //scanf("%d",&ch2);
        scanf("%s",&rent);



        if(strcmp(rent , "YES")==0)
        {
            ch2 = 0;

            printf("\nEnter your actual HRA received this year : \n");
            scanf("%d",&hra);
            printf("\nEnter your annual LTA \n");
            scanf("%d",&lta);
            printf("\nYour total exemption is HRA + LTA + Standard Deduction(Rs.50 k) \n");

            total_exemption = hra + lta + 50000;

            printf("\n####----> Total exemption = %d <----####\n",total_exemption);

            printf("\nYour net salary is = Annual salary - Exemption - Standard Deduction \n");

            net_salary = annual_salary - total_exemption ;

            printf("\n####---->Your net salary is %d<----####\n",net_salary);
            printf("\n..............................................................................................\n");
        }

        else if(strcmp(rent , "NO")==0)
        {
            ch2 = 0;
            printf("\nYour total exemption = Standard Deduction(Rs.50 k) \n");

            total_exemption = 50000;

            printf("\n###---> Total exemption = %d <---###\n",total_exemption);

            printf("\nYour net salary is = Annual salary - Standard Deduction \n");

            net_salary = annual_salary - total_exemption ;

            printf("\n###--->Your net salary is %d<---###\n",net_salary);
            printf("\n..............................................................................................\n");
        }

        else
        {
            printf("\nInvalid Input!");
        }

        }while(ch2 > 1);

}


void n_annual_income()
{
    long int other_source=0;

    printf("\n\n---->Now we will calculate your net annual income\n");
    printf("\nInput the amount of sum of all other sources you obtained this financial year\n");
    printf("This includes sources like Rent , Capital gains , etc.\n");
    printf("\nInput your amount : ");
    scanf("%d",&other_source);
    printf("\nYour income from other sources is %d in this financial year!",other_source);
    printf("\n\nNet annual Income = Net annual Salary + Other sources of income");

    net_annual_income = net_salary + other_source;

    printf("\n\n---->Your net annual income is %d !<----\n",net_annual_income);
    printf("\n..............................................................................................\n");
}


void t_tax()
{
    long int temp_tax;

    printf("\nNow we have arrived at most crucial step of calculating your total tax of this financial year using new tax slab!\n\n");

    if(net_annual_income <= 250000)
    {
        printf("\nDue to tax exemptions and reductions you are not eligible to pay tax!\n");
        printf("\n..............................................................................................\n");
    }

    else if(net_annual_income > 250000 && net_annual_income <= 500000)
    {
        printf("\nAccording to the new tax slab rates you will be charged 5 percent of the income from Rs. 2.5 Lakh to Rs. 5 Lakh \n");

        temp_tax = net_annual_income - 250000;

        total_tax = ((temp_tax*5)/100);

        printf("\n     ...............................................................................");
        printf("\n     .                                                                             .");
        printf("\n     .   ###----->>> You will pay Rs %d tax this financial year! <<<-----###    .",total_tax);
        printf("\n     .                                                                             .");
        printf("\n     ...............................................................................");
        printf("\n\n\n\n..............................................................................................\n");

    }

    else if(net_annual_income > 500000 && net_annual_income <= 750000)
    {
        printf("\nAccording to the new tax slab rates you will be charged Rs.12500 and 10 percent of the amount you earned between RS.5 Lakh to Rs.7.5 Lakh\n");

        temp_tax = net_annual_income - 500000;

        total_tax = ((temp_tax*10)/100) + 12500;

        printf("\n     ...............................................................................");
        printf("\n     .                                                                             .");
        printf("\n     .   ###----->>> You will pay Rs %d tax this financial year! <<<-----###    .",total_tax);
        printf("\n     .                                                                             .");
        printf("\n     ...............................................................................");
        printf("\n\n\n\n..............................................................................................\n");
    }

    else if(net_annual_income > 750000 && net_annual_income <= 1000000)
    {
        printf("\nAccording to the new tax slab rates you will be charged Rs.37500 and 15 percent of the amount you earned between RS.7.5 Lakh to Rs.10 Lakh\n");

        temp_tax = net_annual_income - 750000;

        total_tax = ((temp_tax*15)/100) + 37500;

        printf("\n      ...............................................................................");
        printf("\n      .                                                                             .");
        printf("\n      .   ###----->>> You will pay Rs %d tax this financial year! <<<-----###    .",total_tax);
        printf("\n      .                                                                             .");
        printf("\n      ...............................................................................");
        printf("\n\n\n\n..............................................................................................\n");
    }

    else if(net_annual_income > 1000000 && net_annual_income <= 1250000)
    {
        printf("\nAccording to the new tax slab rates you will be charged Rs.75000 and 20 percent of the amount you earned between RS.10 Lakh to Rs.12.5 Lakh\n");

        temp_tax = net_annual_income - 1000000;

        total_tax = ((temp_tax*20)/100) + 75000;

        printf("\n      ...............................................................................");
        printf("\n      .                                                                             .");
        printf("\n      .   ###----->>> You will pay Rs %d tax this financial year! <<<-----###    .",total_tax);
        printf("\n      .                                                                             .");
        printf("\n      ...............................................................................");
        printf("\n\n\n\n..............................................................................................\n");
    }

    else if(net_annual_income > 1250000 && net_annual_income <= 1500000)
    {
        printf("\nAccording to the new tax slab rates you will be charged Rs.125000 and 25 percent of the amount you earned between RS.12.5 Lakh to Rs.15 Lakh\n");

        temp_tax = net_annual_income - 1250000;

        total_tax = ((temp_tax*25)/100) + 125000;

        printf("\n      ...............................................................................");
        printf("\n      .                                                                             .");
        printf("\n      .   ###----->>> You will pay Rs %d tax this financial year! <<<-----###    .",total_tax);
        printf("\n      .                                                                             .");
        printf("\n      ...............................................................................");
        printf("\n\n\n\n..............................................................................................\n");
    }

    else if(net_annual_income > 1500000)
    {
        printf("\nAccording to the new tax slab rates you will be charged Rs.187500 and 30 percent of the amount you earned after 15 Lakh\n");

        temp_tax = net_annual_income - 1500000;

        total_tax = ((temp_tax*30)/100) + 187500;

        printf("\n      ...............................................................................");
        printf("\n      .                                                                             .");
        printf("\n      .   ###----->>> You will pay Rs %d tax this financial year! <<<-----###    .",total_tax);
        printf("\n      .                                                                             .");
        printf("\n      ...............................................................................");
        printf("\n\n\n\n..............................................................................................\n");
    }

    else
    {
        printf("\n\nInvalid Inputs!");
    }
}
