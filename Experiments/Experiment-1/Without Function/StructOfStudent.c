#include <stdio.h>
#define MAX_CHARS 256

struct Student
{
    char name[MAX_CHARS];
    unsigned int rollNo;

    int pythonMarks;
    int dsMarks;
    int coaMarks;
} typedef Student;

int main(void)
{
    Student studentOne, studentTwo, studentThree;

    printf("\nEnter First Student's Name: ");
    scanf(" %[^\n]s", studentOne.name);

    printf("Enter %s's Enrolment: ", studentOne.name);
    scanf("%ul", &studentOne.rollNo);
    printf("Enter %s's Python Marks: ", studentOne.name);
    scanf("%d", &studentOne.pythonMarks);
    printf("Enter %s's DS Marks: ", studentOne.name);
    scanf("%d", &studentOne.dsMarks);
    printf("Enter %s's COA Marks: ", studentOne.name);
    scanf("%d", &studentOne.coaMarks);

    printf("\nEnter Second Student's Name: ");
    scanf(" %[^\n]s", studentTwo.name);

    printf("Enter %s's Enrolment: ", studentTwo.name);
    scanf("%ul", &studentTwo.rollNo);
    printf("Enter %s's Python Marks: ", studentTwo.name);
    scanf("%d", &studentTwo.pythonMarks);
    printf("Enter %s's DS Marks: ", studentTwo.name);
    scanf("%d", &studentTwo.dsMarks);
    printf("Enter %s's COA Marks: ", studentTwo.name);
    scanf("%d", &studentTwo.coaMarks);

    printf("\nEnter Third Student's Name: ");
    scanf(" %[^\n]s", studentThree.name);

    printf("Enter %s's Enrolment: ", studentThree.name);
    scanf("%ul", &studentThree.rollNo);
    printf("Enter %s's Python Marks: ", studentThree.name);
    scanf("%d", &studentThree.pythonMarks);
    printf("Enter %s's DS Marks: ", studentThree.name);
    scanf("%d", &studentThree.dsMarks);
    printf("Enter %s's COA Marks: ", studentThree.name);
    scanf("%d", &studentThree.coaMarks);

    if (studentOne.pythonMarks > studentTwo.pythonMarks && studentOne.pythonMarks > studentThree.pythonMarks)
    {
        printf("\nStudent With Highest Marks in Python: %s, Enrolment: %d, Python Marks: %d", studentOne.name, studentOne.rollNo, studentOne.pythonMarks);
    }
    else if (studentTwo.pythonMarks > studentThree.pythonMarks && studentTwo.pythonMarks > studentOne.pythonMarks)
    {
        printf("\nStudent With Highest Marks in Python: %s, Enrolment: %d, Python Marks: %d", studentTwo.name, studentTwo.rollNo, studentTwo.pythonMarks);
    }
    else
    {
        printf("\nStudent With Highest Marks in Python: %s, Enrolment: %d, Python Marks: %d", studentThree.name, studentThree.rollNo, studentThree.pythonMarks);
    }

    if (studentOne.dsMarks > studentTwo.dsMarks && studentOne.dsMarks > studentThree.dsMarks)
    {
        printf("\nStudent With Highest Marks in DS: %s, Enrolment: %d, DS Marks: %d", studentOne.name, studentOne.rollNo, studentOne.dsMarks);
    }
    else if (studentTwo.dsMarks > studentThree.dsMarks && studentTwo.dsMarks > studentOne.dsMarks)
    {
        printf("\nStudent With Highest Marks in DS: %s, Enrolment: %d, DS Marks: %d", studentTwo.name, studentTwo.rollNo, studentTwo.dsMarks);
    }
    else
    {
        printf("\nStudent With Highest Marks in DS: %s, Enrolment: %d, DS Marks: %d", studentThree.name, studentThree.rollNo, studentThree.dsMarks);
    }

    if (studentOne.coaMarks > studentTwo.coaMarks && studentOne.coaMarks > studentThree.coaMarks)
    {
        printf("\nStudent With Highest Marks in COA: %s, Enrolment: %d, COA Marks: %d", studentOne.name, studentOne.rollNo, studentOne.coaMarks);
    }
    else if (studentTwo.coaMarks > studentThree.coaMarks)
    {
        printf("\nStudent With Highest Marks in COA: %s, Enrolment: %d, COA Marks: %d", studentTwo.name, studentTwo.rollNo, studentTwo.coaMarks);
    }
    else
    {
        printf("\nStudent With Highest Marks in COA: %s, Enrolment: %d, COA Marks: %d", studentThree.name, studentThree.rollNo, studentThree.coaMarks);
    }

    return 0;
}