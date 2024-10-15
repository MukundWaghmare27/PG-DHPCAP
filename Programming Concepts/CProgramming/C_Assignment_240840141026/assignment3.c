// PRN : 240840141026
// Name : Mukund PW

#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    int marks[3];  // Marks of 3 subjects
    int total;
    float average;
    char grade[10];
};

int main() {
    int n=10;
    struct Student students[n];
    int failCount = 0, gradeBCount = 0, gradeACount = 0, gradeAPlusCount = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter details for 10 students \n");
        
        printf("Enter roll no : ");
        scanf("%d", &students[i].rollno);
        
        printf("Enter name: ");
        scanf(" %s", students[i].name); 
        
        printf("Enter marks of 3 subjects: ");
        students[i].total = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &students[i].marks[j]);
            students[i].total += students[i].marks[j];  
        }
        
        students[i].average = students[i].total / 3.0;  
        
        if (students[i].average < 50) {
            strcpy(students[i].grade, "Fail");
            failCount++;
        } else if (students[i].average >= 50 && students[i].average <= 60) {
            strcpy(students[i].grade, "B");
            gradeBCount++;
        } else if (students[i].average >= 60 && students[i].average < 70) {
            strcpy(students[i].grade, "A");
            gradeACount++;
        } else if (students[i].average >= 70) {
            strcpy(students[i].grade, "A+");
            gradeAPlusCount++;
        }
    }

    printf("\nStudent Data and Grades:\n");
    printf("Roll No\tName\t\tMarks\tTotal\tAverage\tGrade\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t", students[i].rollno, students[i].name);
        for (int j = 0; j < 3; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\t%d\t%.2f\t%s\n", students[i].total, students[i].average, students[i].grade);
    }

    printf("\nGrade Count:\n");
    printf("Fail: %d\n", failCount);
    printf("Grade B: %d\n", gradeBCount);
    printf("Grade A: %d\n", gradeACount);
    printf("Grade A+: %d\n", gradeAPlusCount);

    return 0;
}
