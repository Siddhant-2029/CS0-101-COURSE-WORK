#include <stdio.h>

int passorfail(int mark_maths, int mark_phy, int mark_chem);

int main() {
    int roll1, mark_math1, mark_phy1, mark_chem1;
    int roll2, mark_math2, mark_phy2, mark_chem2;
    float mark_total1, mark_total2;
    char name1[100];
    char name2[100];

    printf("Enter roll number of student 1: ");
    scanf("%d", &roll1);
    printf("Enter roll number of student 2: ");
    scanf("%d", &roll2);

    printf("Enter student name of student 1: \n");
    scanf("%s", name1);
    printf("Enter student name of student 2: \n");
    scanf("%s", name2);

    printf("Enter marks in maths of student 1: \n");
    scanf("%d", &mark_math1);
    printf("Enter marks in maths of student 2: \n");
    scanf("%d", &mark_math2);

    printf("Enter marks in physics of student 1: \n");
    scanf("%d", &mark_phy1);
    printf("Enter marks in physics of student 2: \n");
    scanf("%d", &mark_phy2);

    printf("Enter marks in chemistry of student 1: \n");
    scanf("%d", &mark_chem1);
    printf("Enter marks in chemistry of student 2: \n");
    scanf("%d", &mark_chem2);

    mark_total1 = (mark_chem1 + mark_math1 + mark_phy1) / 3.0;
    mark_total2 = (mark_chem2 + mark_math2 + mark_phy2) / 3.0;

    printf("Roll No- %d\n", roll1);
    printf("Student name- %s\n", name1);
    printf("Physics marks = %d\n", mark_phy1);
    printf("Chemistry marks = %d\n", mark_chem1);
    printf("Maths marks = %d\n", mark_math1);
    printf("Percentage = %.2f\n", mark_total1);
    if (passorfail(mark_math1, mark_chem1, mark_phy1) == 1)
        printf("Result- PASS\n");
    else
        printf("Result- FAIL\n");

    printf("\nRoll No- %d\n", roll2);
    printf("Student name- %s\n", name2);
    printf("Physics marks = %d\n", mark_phy2);
    printf("Chemistry marks = %d\n", mark_chem2);
    printf("Maths marks = %d\n", mark_math2);
    printf("Percentage = %.2f\n", mark_total2);
    if (passorfail(mark_math2, mark_chem2, mark_phy2) == 1)
        printf("Result- PASS\n");
    else
        printf("Result- FAIL\n");

    return 0;
}

int passorfail(int mark_maths, int mark_phy, int mark_chem) {
    int a = 0;
    if (mark_chem < 35) { a++; }
    if (mark_phy < 35) { a++; }
    if (mark_maths < 35) { a++; }
    if (mark_chem + mark_maths + mark_phy < 100) { a++; }

    if (a == 0) return 1;
    else return 0;

}