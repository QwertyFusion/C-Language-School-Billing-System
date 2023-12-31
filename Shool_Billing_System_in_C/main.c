/* School Billing System Project in C Language
 * Developed by RISHI BANERJEE
 * This Project Simulates a Simple School Billing System, which is programmed in C.
 */

// HEADER FILES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// STRUCTURE DECLARATIONS
struct dateAndTime
{
    int dy, mth;
};

struct student
{
    struct dateAndTime dateRefer;
    float fees, fine, total, advanced, dueFees;
    char name[50];
    int rollNum, classNum;
} std, s;

struct teacher
{
    struct dateAndTime dateRefer;
    char name[50];
    float salary, advanced, total;
    int teacherID, noOfClasses;
} teacher, temp_f;

// METHOD PRE-DECLARATIONS
int CheckClass();                      // check class (1-12)
int CheckingDate(int, int);            // for checking date
void AddingRecords(int);               // for adding records
void UpdateRecords(int);               // for modifying records
void SearchingRecords(int);            // for searching records
void DeletingRecords(int);             // for deleting records
void Salary(int);                      // for the calculation of salary of teacher and staff
void Exits();                          // for exiting
void InputDate();                      // for inputing date from the user
void DisplayDate(int d, int m, int y); // for printing the date onto the screen
void Start();                          // for beginning the menu based operations
void DisplayFormatting();              // for printing \xdb 80 times
FILE *file_store, *file_temp;          // file declaration

// GLOBAL VARIABLE DECLARATIONS
int mm, dd, yyyy; // mm=month, dd=day, yyyy=year

// METHOD OPERATIONS
void main()
{
    int l; // l = Loop Variable
    DisplayFormatting();
    system("color 0b");
    printf(" \n\t ________________________________________________________\n");
    printf("\t|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("\t|                                                        |\n");
    printf("\t|     WELCOME TO SCHOOL BILLING SYSTEM PROJECT IN C      |\n");
    printf("\t|                                                        |\n");
    printf("\t|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n");
    printf("\t|              DEVELOPED BY RISHI BANERJEE               |\n");
    printf("\t|________________________________________________________|\n");
    printf("\t|                                                        |\n");
    printf("\t|    This Project Simulates a Simple School Billing      |\n");
    printf("\t|    System, which is programmed in C.                   |\n");
    printf("\t|________________________________________________________|\n");
    printf("\n\tPLEASE ENTER ANY KEY TO CONTINUE");

    Sleep(500);
    for (l = 0; l < 5; l++)
    {
        printf(".");
        Sleep(500); // after printing one . another comes after 0.5 seconds
    }

    getch();
    system("cls"); // clears the screen
    printf("\n");
    DisplayFormatting();

    system("color 0b");

    printf("\n\n\t\t** WELCOME TO SCHOOL BILLING SYSTEM PROJECT **\n\n");
    DisplayFormatting();

    printf("\n\nPLEASE ENTER ANY KEY TO START\n");

    for (l = 0; l < 5; l++)
    {
        printf(".");
        Sleep(500);
    }

    fflush(stdin);
    getch();
    system("cls");
    system("color 0b"); // 1st is for back ground color and second is for text color

    DisplayFormatting();
    InputDate();
    Start();
}
void Start()
{
    int accountType, userChoice; // accountType is for selection of account type
    system("cls");
    DisplayDate(dd, mm, yyyy);
    DisplayFormatting();
    system("color 0b");
    printf("\n\t\tPLEASE ENTER ACCOUNT TYPE");
    printf("\n\t\t1:: Student");
    printf("\n\t\t2:: Teachers and Staffs");
    printf("\n\t\t3:: Exit");
    printf("\n\t\tAccount Type Choice: ");
    fflush(stdin);
    scanf("%d", &accountType);
    switch (accountType)
    {
    case 3:
        Exits();
    case 1:
    {
        system("cls");
        DisplayDate(dd, mm, yyyy);
        DisplayFormatting();
        system("color 0b");
        printf("\n\t\tPLEASE ENTER THE CHOICE");
        printf("\n\t\t1:: Add Record");
        printf("\n\t\t2:: Search Record");
        printf("\n\t\t3:: Modify Record");
        printf("\n\t\t4:: Delete Record");
        printf("\n\t\t5:: Calculate Fee");
        printf("\n\t\t6:: Exit");
        printf("\n\n Enter Choice: ");
        fflush(stdin);
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 1:
            AddingRecords(accountType); // function call
            Start();                    // function call
        case 2:
            SearchingRecords(accountType);
            Start();
        case 3:
            UpdateRecords(accountType);
            Start();
        case 4:
            DeletingRecords(accountType);
            Start();
        case 5:
            fee(mm);
            Start();
        case 6:
            Exits();
        default:
        {
            MessageBox(0, "Invalid Entry!\nGoing to Account Type", "Error!", 0);
            system("Pause");
            Start();
        }
        }
    }
    case 2:
    {
        system("cls");
        DisplayDate(dd, mm, yyyy);
        DisplayFormatting();
        system("color 0e");
        printf("\n\t\tPLEASE ENTER THE CHOICE");
        printf("\n\t\t1:: Add Record");
        printf("\n\t\t2:: Search Record");
        printf("\n\t\t3:: Modify Record");
        printf("\n\t\t4:: Delete Record");
        printf("\n\t\t5:: Calculate Salary");
        printf("\n\t\t6:: Exit");
        printf("\n\n Enter Choice: ");
        fflush(stdin);
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 1:
            AddingRecords(accountType);
            Start();
        case 2:
            SearchingRecords(accountType);
            Start();
        case 3:
            UpdateRecords(accountType);
            Start();
        case 4:
            DeletingRecords(accountType);
        case 5:
            Salary(mm);
            Start();
        case 6:
            Exits();
        default:
        {
            MessageBox(0, "Invalid Entry!\nGoing to Account Type", "Error!", 0);
            system("Pause");
            Start();
        }
        }
    }
    default:
    {
        MessageBox(0, "Invalid Entry!\nGoing to Account Type", "Error!", 0);
        system("Pause");
        Start();
    }
    }
}

void AddingRecords(int choice)
{
    int dueMonths, LastFeePaidMonth;
    float classDependedFee;
    char userChoice = 'y';

    system("cls");
    DisplayDate(dd, mm, yyyy);
    DisplayFormatting();
    printf("\n\n\t*******************        ADD RECORD         *******************\n");
    printf("\n");
    DisplayFormatting();
    if (choice == 1)
    {
        while (userChoice == 'y' || userChoice == 'Y')
        {
            printf("\n\nEnter the name of student: ");
            fflush(stdin);
            scanf("%[^\n]", std.name);
            printf("\nEnter the class: ");
            fflush(stdin);
            std.classNum = CheckClass();
            printf("\nEnter the Roll No.: ");
            fflush(stdin);
            scanf("%d", &std.rollNum);
            printf("\nEnter month and day till which fee is paid (mmdd): ");
            fflush(stdin);
            scanf("%2d", &LastFeePaidMonth); // last fee month = LastFeePaidMonth
            std.dateRefer.mth = CheckingDate(LastFeePaidMonth, 1);
            if (LastFeePaidMonth < mm)
            {
                classDependedFee = std.classNum / 10.0;   // fee depends on class, i.e. class/10
                std.fees = 1000 * (1 + classDependedFee); // fee of different classes
                dueMonths = mm - std.dateRefer.mth;       // months of fee left to be paid
                std.fine = (dueMonths * std.fees) * 1 / 100;
                std.dueFees = (dueMonths)*std.fees; // fees left to be paid
            }
            else
            {
                classDependedFee = std.classNum / 10.0;   // fee depends on class, i.e. class/10
                std.fees = 1000 * (1 + classDependedFee); // fee of different classes
                dueMonths = mm + 12 - std.dateRefer.mth;  // months of fee left to be paid
                std.fine = (dueMonths * std.fees) * 1 / 100;
                std.dueFees = (dueMonths)*std.fees; // fees left to be paid
            }
            if (dueMonths == 1)
            {
                std.total = std.fees;
                std.fine = 0;
            }
            else
            {
                std.total = std.fine + std.dueFees;
            }                                     // for calculation of total fee
            file_store = fopen("student", "ab+"); // opening a binary file in apend mode
            fwrite(&std, sizeof(std), 1, file_store);
            fclose(file_store);
            printf("\n\nDo you want to continue with the process? (Press Y or N): ");
            scanf("%c", &userChoice);
        }
        getch();
    }
    if (choice == 2)
    {
        while (userChoice == 'y' || userChoice == 'Y')
        {
            printf("\n\nEnter name of teacher/staff:");
            fflush(stdin);
            scanf("%[^\n]", teacher.name);
            printf("\nEnter teacher/staff id: ");
            fflush(stdin);
            scanf("%d", &teacher.teacherID);
            printf("\nEnter number of class/shift per month: ");
            scanf("%d", &teacher.noOfClasses);
            fflush(stdin);
            printf("\nEnter month and day till which salary is paid (mmdd): ");
            scanf("%2d", &LastFeePaidMonth);
            teacher.dateRefer.mth = CheckingDate(LastFeePaidMonth, 1);
            teacher.salary = teacher.noOfClasses * 500;
            if (mm < teacher.dateRefer.mth)
            {
                teacher.advanced = (teacher.dateRefer.mth - mm - 1) * teacher.salary;
            }
            else
            {
                teacher.advanced = 0;
            }
            teacher.total = teacher.salary - teacher.advanced;
            file_temp = fopen("teacher", "ab+");
            fwrite(&teacher, sizeof(teacher), 1, file_temp);
            fclose(file_temp);
            printf("\n\nDo you want to continue with the process? (Press Y or N): ");
            scanf("%c", &userChoice);
        }
        printf("\n\n");
        system("pause");
    }
}

void SearchingRecords(int choice)
{
    char name_s[50], name_t[50];
    int option, flag = 1;
    char userChoice = 'y';
    if (choice == 1)
    {
        while (userChoice == 'y' || userChoice == 'Y')
        {
            flag = 1;
            system("cls");
            DisplayDate(dd, mm, yyyy);
            DisplayFormatting();
            printf("\n\n\t*******************      SEARCH RECORD       *******************\n");
            printf("\n");
            DisplayFormatting();

            printf("\n\n\t\tPLEASE CHOOSE SEARCH TYPE::");
            printf("\n\n\t\t1::Search by Name::");
            printf("\n\n\t\t2::Search by Class::");
            printf("\n\n\t\t3::Search by Roll No::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your Choice:: ");
            fflush(stdin);
            scanf("%d", &option);
            if (option == 1)
            {
                flag = 1;
                printf("\n\nEnter name of student to search: ");
                fflush(stdin);
                scanf("%[^\n]", name_s);
                file_store = fopen("student", "rb");
                while (fread(&std, sizeof(std), 1, file_store) == 1)
                {
                    if (strcmpi(name_s, std.name) == 0)
                    {
                        flag = 0;
                        printf("\nName = %s", std.name);
                        printf("\nClass = %d", std.classNum);
                        printf("\nRoll no = %d", std.rollNum);
                        printf("\nMonthy fee = %.2f", std.fees);
                        if (mm >= std.dateRefer.mth)
                        {
                            int t = mm - std.dateRefer.mth;
                            printf("\nLast fee paid in month = %2d", std.dateRefer.mth);
                            printf("\nDue No of Months = %2d", t);
                        }
                        else
                        {
                            int t = mm + 12 - std.dateRefer.mth;
                            printf("\nLast fee paid in month (last year) = %2d", std.dateRefer.mth);
                            printf("\nDue No of Months = %2d", t);
                        }
                        printf("\nDue= %.2f", std.dueFees);
                        printf("\nFine= %.2f", std.fine);
                        printf("\nTotal= %.2f\n\n", std.total);
                    }
                }
                if (flag == 1)
                {
                    printf("\n\nRECORD NOT FOUND");
                }
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(file_store);
            }
            else if (option == 2)
            {
                int cl;
                flag = 1;
                printf("\n\nEnter class of student to search: ");
                fflush(stdin);
                cl = CheckClass();
                file_store = fopen("student", "rb");
                while (fread(&std, sizeof(std), 1, file_store) == 1)
                {
                    if (std.classNum == cl)
                    {
                        flag = 0;
                        printf("\nName = %s", std.name);
                        printf("\nClass = %d", std.classNum);
                        printf("\nRoll no = %d", std.rollNum);
                        printf("\nMonthy fee = %.2f", std.fees);
                        if (mm >= std.dateRefer.mth)
                        {
                            int t = mm - std.dateRefer.mth;
                            printf("\nLast fee paid in month = %2d", std.dateRefer.mth);
                            printf("\nDue No of Months = %2d", t);
                        }
                        else
                        {
                            int t = mm + 12 - std.dateRefer.mth;
                            printf("\nLast fee paid in month (last year) = %2d", std.dateRefer.mth);
                            printf("\nDue No of Months = %2d", t);
                        }
                        printf("\nDue= %.2f", std.dueFees);
                        printf("\nFine= %.2f", std.fine);
                        printf("\nTotal= %.2f\n\n", std.total);
                    }
                }
                if (flag == 1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(file_store);
            }
            else if (option == 3)
            {
                int rll;
                flag = 1;
                printf("\n\nEnter roll of student to search: ");
                fflush(stdin);
                scanf("%d", &rll);
                file_store = fopen("student", "rb");
                while (fread(&std, sizeof(std), 1, file_store) == 1)
                {
                    if (std.rollNum == rll)
                    {
                        flag = 0;
                        printf("\nName = %s", std.name);
                        printf("\nClass = %d", std.classNum);
                        printf("\nRoll no = %d", std.rollNum);
                        printf("\nMonthy fee = %.2f", std.fees);
                        if (mm >= std.dateRefer.mth)
                        {
                            int t = mm - std.dateRefer.mth;
                            printf("\nLast fee paid in month = %2d", std.dateRefer.mth);
                            printf("\nDue No of Months = %2d", t);
                        }
                        else
                        {
                            int t = mm + 12 - std.dateRefer.mth;
                            printf("\nLast fee paid in month (last year) = %2d", std.dateRefer.mth);
                            printf("\nDue No of Months = %2d", t);
                        }
                        printf("\nDue= %.2f", std.dueFees);
                        printf("\nFine= %.2f", std.fine);
                        printf("\nTotal= %.2f\n\n", std.total);
                    }
                }
                if (flag == 1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                fclose(file_store);
            }
            else if (option == 4)
            {
                Exits();
            }
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                SearchingRecords(1);
            }
            printf("\n\nDo you want to continue with the process? (Press Y or N): ");
            scanf("%c", &userChoice);
        }
        getch();
    }
    if (choice == 2)
    {
        while (userChoice == 'y' || userChoice == 'Y')
        {
            flag = 1;
            printf("\n\nName of teacher/staff to search: ");
            fflush(stdin);
            scanf("%[^\n]", name_t);
            file_temp = fopen("teacher", "rb");
            while (fread(&teacher, sizeof(teacher), 1, file_temp) == 1)
            {
                if (strcmp(name_t, teacher.name) == 0)
                {
                    flag = 0;
                    printf("\nName = %s", teacher.name);
                    printf("\nTeacher/staff id = %d", teacher.teacherID);
                    printf("\nMonth till when salary is paid =%d", teacher.dateRefer.mth);
                    printf("\nMonthly salary = %.2f", teacher.salary);
                    printf("\nAdvance paid = %.2f", teacher.advanced);
                }
            }
            if (flag == 1)
            {
                printf("\n\nRECORD NOT FOUND");
            }
            printf("\n\n");
            system("pause");
            fflush(stdin);
            fclose(file_temp);
            printf("\n\nDo you want to continue with the process? (Press Y or N): ");
            scanf("%c", &userChoice);
        }
        getch();
    }
}

void UpdateRecords(int choice)
{

    char name_s[50];
    int flag = 1, option, cll;
    int roll_no;
    char userChoice = 'y';
    if (choice == 1)
    {
        while (userChoice == 'y' || userChoice == 'Y')
        {
            system("cls");
            DisplayDate(dd, mm, yyyy);
            DisplayFormatting();
            printf("\n\n\t*******************      MODIFY RECORD       *******************\n");
            printf("\n");
            DisplayFormatting();

            printf("\n\n\t\tPLEASE CHOOSE MODIFY TYPE::");
            printf("\n\n\t\t1::Modify by Name::");
            printf("\n\n\t\t2::Modify by Name &Class::");
            printf("\n\n\t\t3::Modify by Name,Class & Roll No::");
            printf("\n\n\t\t4::Exit");
            printf("\n\n\t\t::Enter your Choice:: ");
            fflush(stdin);
            scanf("%d", &option);
            if (option == 1)
            {
                flag = 0;
                printf("\n\nEnter Name of Student to Modify: ");
                fflush(stdin);
                scanf("%[^\n]", name_s);
                file_store = fopen("student", "rb+");
                while (fread(&std, sizeof(std), 1, file_store) == 1)
                {
                    flag = 1;
                    if (strcmpi(name_s, std.name) == 0)
                    {
                        flag = 0;
                        printf("\nEnter New Name of Student: ");
                        fflush(stdin);
                        scanf("%[^\n]", std.name);
                        printf("\nEnter New Class of Student: ");
                        fflush(stdin);
                        std.classNum = CheckClass();
                        printf("\nEnter New Roll of Student: ");
                        fflush(stdin);
                        scanf("%d", &std.rollNum);
                        fseek(file_store, -sizeof(std), SEEK_CUR);
                        fwrite(&std, sizeof(std), 1, file_store);
                        fclose(file_store);
                    }
                }
                if (flag == 1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED!");
                printf("\n\n");
                system("pause");
            }
            else if (option == 2)
            {
                flag = 0;
                printf("\n\nEnter Name of Student to Modify: ");
                fflush(stdin);
                scanf("%[^\n]", name_s);
                printf("\n\nEnter Class of Student to Modify: ");
                fflush(stdin);
                cll = CheckClass();
                file_store = fopen("student", "rb+");
                while (fread(&std, sizeof(std), 1, file_store) == 1)
                {
                    flag = 1;
                    if (strcmpi(name_s, std.name) == 0 && cll == std.classNum)
                    {
                        flag = 0;
                        printf("\nEnter New Name of Student: ");
                        fflush(stdin);
                        scanf("%[^\n]", std.name);
                        printf("\nEnter New Class of Student: ");
                        fflush(stdin);
                        std.classNum = CheckClass();
                        printf("\nEnter New Roll of Student: ");
                        fflush(stdin);
                        scanf("%d", &std.rollNum);
                        fseek(file_store, -sizeof(std), SEEK_CUR);
                        fwrite(&std, sizeof(std), 1, file_store);
                        fclose(file_store);
                    }
                }
                if (flag == 1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED!");
                printf("\n\n");
                system("pause");
            }
            else if (option == 3)
            {
                flag = 0;
                printf("\n\nEnter name of student to modify: ");
                fflush(stdin);
                scanf("%[^\n]", name_s);
                printf("\n\nEnter class of student to modify: ");
                fflush(stdin);
                cll = CheckClass();
                printf("\n\nEnter roll of student to modify: ");
                fflush(stdin);
                scanf("%d", &roll_no);
                file_store = fopen("student", "rb+");
                while (fread(&std, sizeof(std), 1, file_store) == 1)
                {
                    flag = 1;
                    if (strcmpi(name_s, std.name) == 0 && cll == std.classNum && roll_no == std.rollNum)
                    {
                        flag = 0;
                        printf("\nEnter new name of student: ");
                        fflush(stdin);
                        scanf("%[^\n]", std.name);
                        printf("\nEnter new class of student: ");
                        fflush(stdin);
                        std.classNum = CheckClass();
                        printf("\nEnter new roll of student: ");
                        fflush(stdin);
                        scanf("%d", &std.rollNum);
                        fseek(file_store, -sizeof(std), SEEK_CUR);
                        fwrite(&std, sizeof(std), 1, file_store);
                        fclose(file_store);
                    }
                }
                if (flag == 1)
                    printf("\n\nRECORDS NOT FOUND");
                else
                    printf("\n\nRECORDS SUCCESSFULLY  MODIFIED!");
                printf("\n\n");
                system("pause");
            }
            else if (option == 4)
                Exits();
            else
            {
                printf("\n\n\n\t\tINVALID ENTRY!!!!\n\n\t\t");
                system("pause");
                UpdateRecords(1);
            }

            printf("\n\nDo you want to continue with the process? (Press Y or N): ");
            scanf("%c", &userChoice);
        }
        getch();
    }

    if (choice == 2)
    {
        while (userChoice == 'y' || userChoice == 'Y')
        {
            flag = 1;
            printf("Enter name of teacher to modify: ");
            fflush(stdin);
            scanf("%[^\n]", name_s);
            file_temp = fopen("teacher", "rb+");
            while (fread(&teacher, sizeof(teacher), 1, file_temp) == 1)
            {
                if (strcmpi(name_s, teacher.name) == 0)
                {
                    flag = 0;
                    printf("\nEnter new name of teacher: ");
                    fflush(stdin);
                    scanf("%[^\n]", teacher.name);
                    printf("\nEnter new id of teacher: ");
                    fflush(stdin);
                    scanf("%d", &teacher.teacherID);
                    fseek(file_temp, -sizeof(teacher), SEEK_CUR);
                    fwrite(&teacher, sizeof(teacher), 1, file_temp);
                    fclose(file_temp);
                }
            }

            if (flag == 1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  MODIFIED!");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            printf("\n\nDo you want to continue with the process? (Press Y or N): ");
            scanf("%c", &userChoice);
        }
        getch();
    }
}

void DeletingRecords(int choice)
{
    system("cls");
    DisplayDate(dd, mm, yyyy);
    DisplayFormatting();
    printf("\n\n\t*******************       DELETE RECORD       *******************\n");
    printf("\n");
    DisplayFormatting();

    FILE *temporary, *tmp1;
    int flag = 1;
    char name_s[50], userChoice = 'y';
    if (choice == 1)
    {
        while (userChoice == 'y' || userChoice == 'Y')
        {
            flag = 1;
            printf("\n\nEnter name of student to delete: ");
            fflush(stdin);
            scanf("%[^\n]", name_s);
            file_store = fopen("student", "rb");
            temporary = fopen("tempfile", "wb"); // opening of temporary file for deleting process
            while (fread(&std, sizeof(std), 1, file_store) == 1)
            {
                if (strcmp(std.name, name_s) == 0)
                {
                    flag = 0;
                    continue;
                }
                else
                {
                    fwrite(&std, sizeof(std), 1, temporary);
                }
            }

            if (flag == 1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED!");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(file_store);
            fclose(temporary);
            system("del student");           /*all data except the data to be
                       deleted in student were 1st moved to temp and data in student
                       was deleted*/
            system("ren tempfile, student"); // renaming temp to student
            printf("\n\nDo you want to continue with the process? (Press Y or N): ");
            scanf("%c", &userChoice);
        }
        getch();
    }

    if (choice == 2)
    {
        flag = 1;
        char name_t[50];
        while (userChoice == 'y' || userChoice == 'Y')
        {
            printf("\n\nEnter name of teacher to delete record: ");
            fflush(stdin);
            scanf("%[^\n]", name_t);
            file_temp = fopen("teacher", "rb");
            tmp1 = fopen("tempfile1", "wb");
            while (fread(&teacher, sizeof(teacher), 1, file_temp) == 1)
            {
                if (strcmp(teacher.name, name_t) == 0)
                {
                    flag = 0;
                    continue;
                }
                else
                {
                    fwrite(&teacher, sizeof(teacher), 1, tmp1);
                }
            }

            if (flag == 1)
                printf("\n\nRECORD NOT FOUND");
            else
                printf("\n\nRECORD SUCCESSFULLY  DELETED!");
            printf("\n\n");
            system("pause");
            fflush(stdin);

            fclose(file_temp);
            fclose(tmp1);
            system("del teacher");
            system("ren tempfile1, teacher");
            printf("\n\nDo you want to continue with the process? (Press Y or N): ");
            scanf("%c", &userChoice);
        }
        getch();
    }
}
void Salary(int mm)
{
    system("cls");
    DisplayDate(dd, mm, yyyy);
    DisplayFormatting();
    printf("\n\n\t*******************        SALARY         *******************\n");
    printf("\n");
    DisplayFormatting();

    FILE *files, *temp_f;
    int flag = 1, day_s;
    char name_s[50], userChoice = 'y';
    int months, df, ids;
    while (userChoice == 'y' || userChoice == 'Y')
    {
        int flag = 1;
        fflush(stdin);
        printf("\n\nEnter name:: ");
        scanf("%[^\n]", name_s);
        printf("\n\nEnter ID:: ");
        scanf("%d", &ids);
        files = fopen("teacher", "rb+");
        temp_f = fopen("te", "wb+");
        while (fread(&teacher, sizeof(teacher), 1, files) == 1) // file opened
        {
            if (strcmp(teacher.name, name_s) == 0) // name entered is compared to the existing name in file
            {
                float lsal;
                flag = 0;
                printf("\n\nEnter the month till which salary is to be paid:: ");
                fflush(stdin);
                scanf("%d", &months);
                months = CheckingDate(months, day_s);
                teacher.advanced = (months - mm - 1) * teacher.salary;
                if (teacher.advanced < 0)
                    teacher.advanced = 0;
                lsal = mm - teacher.dateRefer.mth; // months of salary left to be paid
                if (lsal < 0)
                    lsal = 0;
                teacher.total = teacher.advanced + teacher.salary * (1 + lsal);
                if (months == teacher.dateRefer.mth)
                    teacher.total = 0;
                printf("\nMonthly salary left to be paid:: %.2f", lsal);
                printf("\nTotal :: %.2f", teacher.total);
                printf("\nAdvance :: %.2f", teacher.advanced);
                teacher.dateRefer.mth = months;
                fwrite(&teacher, sizeof(teacher), 1, temp_f);
                fclose(files);
                fclose(temp_f);

                if (flag == 1)
                    printf("\n\nRECORD NOT FOUND");
                printf("\n\n");
                system("pause");
                fflush(stdin);
                system("del teacher");
                system("ren te, teacher");
            }
        }
        printf("\n\nDo you want to continue with the process? (Press Y or N): ");
        scanf("%c", &userChoice);
    }
    getch();
}

void fee(int mm)
{
    system("cls");
    DisplayDate(dd, mm, yyyy);
    DisplayFormatting();
    printf("\n\n\t*******************        FEE        *******************\n");
    printf("\n");
    DisplayFormatting();

    FILE *files, *temp_f;
    int flag = 0;
    char name_s[50], userChoice = 'y';
    int clss, rollss, monthss, diffs;
    while (userChoice == 'y' || userChoice == 'Y')
    {
        int flag = 1, day = 0;
        fflush(stdin);
        printf("\n\nEnter name:: ");
        scanf("%[^\n]", name_s);
        printf("\n\nEnter class:: ");
        fflush(stdin);
        clss = CheckClass();
        printf("\n\nEnter roll:: ");
        fflush(stdin);
        scanf("%d", &rollss);
        files = fopen("student", "rb+");
        temp_f = fopen("te", "wb");
        while (fread(&std, sizeof(std), 1, files) == 1)
        {
            if (strcmp(std.name, name_s) == 0 && clss == std.classNum && rollss == std.rollNum)
            {
                flag = 0;
                printf("\n\nEnter the month till which fee to be paid:: ");
                fflush(stdin);
                scanf("%d", &monthss);
                monthss = CheckingDate(monthss, day);
                diffs = mm - std.dateRefer.mth;
                std.fine = (diffs * std.fees) * 0.01;
                std.dueFees = (diffs)*std.fees;
                if (std.fine < 0)
                    std.fine = 0;
                if (std.dueFees < 0)
                    std.dueFees = 0;
                if (std.total < 0)
                    std.total = 0;
                std.total = std.fine + std.dueFees + std.advanced;
                printf("\nFine :: %.2f", std.fine);
                printf("\nDue :: %.2f", std.dueFees);
                printf("\nTotal :: %.2f", std.total);
                printf("\nAdvance :: %.2f", std.advanced);
                std.dateRefer.mth = monthss;
                std.total = 0;
                std.fine = 0;
                std.dueFees = 0;
                fwrite(&std, sizeof(std), 1, temp_f);
            }
        }
        if (flag == 1)
            printf("\n\nRECORD NOT FOUND");
        printf("\n\n");
        system("pause");
        fflush(stdin);

        fclose(files);
        fclose(temp_f);
        system("del student");
        system("ren te, student");
        printf("\n\nDo you want to continue with the process? (Press Y or N): ");
        scanf("%c", &userChoice);
    }
    getch();
}
void Exits()
{
    int l;
    system("cls");
    system("color 0c");
    printf("\n\n\t\t  Thank you for using School Billing System Project\n\n");
    printf("\t\tBy Rishi Banerjee\t||\t Project in C Language\n\n");
    system("pause");
    system("cls");
    printf("\n\n\t\t\t\tExiting\n\n");
    for (l = 1; l <= 70; l++)
    {
        Sleep(50);
        printf("*");
    }
    exit(0);
}

int CheckingDate(int mnt, int dnt)
{
    int monthsCD, daysCD;
    if (mnt > 12 || mnt < 1 || dnt < 1 || dnt > 32)
    {
        MessageBox(0, "Invalid Date!\nEnter Again", "Error!", 0);

        fflush(stdin);
        int temp;
        scanf("%d", &temp);
        monthsCD = temp / 100;
        daysCD = temp % 100;
        CheckingDate(monthsCD, daysCD);
    }
    else
    {
        return mnt;
    }
}
int CheckClass()
{
    int cl;
    fflush(stdin);
    scanf("%d", &cl);
    if (cl > 12 || cl < 1)
    {

        MessageBox(0, "Invalid Class!\nEnter Class again", "Error!!", 0);
        fflush(stdin);
        cl = CheckClass();
    }
    else
        return cl;
}

void DisplayDate(int d, int m, int y)
{
    printf("Current Date: ");
    switch (m)
    {
    case 1:
        printf("January ");
        break;
    case 2:
        printf("February ");
        break;
    case 3:
        printf("March ");
        break;
    case 4:
        printf("April ");
        break;
    case 5:
        printf("May ");
        break;
    case 6:
        printf("June ");
        break;
    case 7:
        printf("July ");
        break;
    case 8:
        printf("August ");
        break;
    case 9:
        printf("September ");
        break;
    case 10:
        printf("October ");
        break;
    case 11:
        printf("November ");
        break;
    case 12:
        printf("December ");
        break;
    }
    switch (d)
    {
    case 1:
        printf("%dst, ", d);
        break;
    case 2:
        printf("%dnd, ", d);
        break;
    case 3:
        printf("%drd, ", d);
        break;
    default:
        printf("%dth, ", d);
        break;
    }
    printf("%d", y);

    printf("\t\t||\t\t%d/ %d/ %d\n", d, m, y);
}

void InputDate()
{
    int temp;
    char userChoice;
    printf("\nPLEASE ENTER CURRENT DATE (ddmm):\n");
    scanf("%d", &temp);
    mm = (temp) % 100;
    dd = (temp) / 100;
    printf("\nPLEASE ENTER CURRENT YEAR (yyyy):\n");
    scanf("%d", &yyyy);
    mm = CheckingDate(mm, dd);

    printf("Date:\n");
    DisplayDate(dd, mm, yyyy);
    printf("Date Confirmed? [Y/N] ");
    fflush(stdin);
    scanf("%c", &userChoice);
    if (userChoice == 'N' || userChoice == 'n')
    {
        InputDate();
    }
}

void DisplayFormatting()
{
    for (int l = 0; l < 80; l++)
    {
        printf("\xdb");
    }
}