#include <stdio.h>
int main()
{
    int age;
    char eyesight_test;
    char written_test;

    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter eyesight test result (Pass=P/Fail=F): ");
    scanf(" %c", &eyesight_test);
    printf("Enter written test result (Pass=P/Fail=F): ");
    scanf(" %c", &written_test);

    if (age >= 18 && age < 60 && eyesight_test == 'P' && written_test == 'P')
    {
        printf("You are eligible for the driving license.\n");
        return 0;
    }
    if (age >= 60 && eyesight_test == 'P' && written_test == 'P')
    {
       char medical_certificate;
       
       printf("You are above 60 years old. Do you have a medical certificate? (Yes=Y/No=N): ");
       scanf(" %c", &medical_certificate);

         if (medical_certificate == 'Y')
         {
              printf("You are eligible for the driving license.\n");
         }
         else
         {
              printf("You are not eligible for the driving license without a medical certificate.\n");
         }
    }
    else
    {
        printf("You are not eligible for the driving license.\n");
    }

    return 0;
}