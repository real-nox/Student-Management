#include <stdio.h>

typedef struct
{
    char nom[20];
    char prenom[20];
    int age;
} student;

student students[10];
int dim = 0;
int last_DELETED_index;

// Functions

void Add_Student();
void Modify_Student(student);
void Delete_Student();
void Show_Students();

main()
{
    int option = -1;

    while (option != 0)
    {
        do
        {
            printf("Welcome to students Program!\n\n[1] : Add Student\n[2] : Modify an existant student\n[3] : Delete student\n[4] : Show all students\n\n[RESPONSE] : ");
            scanf("%d", &option);
            printf("\n\n");
        } while (option > 4 || option < 0);

        switch (option)
        {
        case 1:
            printf("Adding student, fill-in the form\n");
            Add_Student();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("List of current students : \n");
            Show_Students();
            break;

        default:
            break;
        }
    }
};

void Add_Student() {
    printf("%d", dim);
    printf("What's the student's first name?\n - ");
    scanf("%s", students[dim].prenom);
    printf("What's the student's last name?\n - ");
    scanf("%s", students[dim].nom);
    printf("What's the student's age?\n - ");
    scanf("%d", &(students[dim].age));
    printf("\n");

    ++dim;
};

void Show_Students()
{
    for (int i = 0; i < dim; i++) {
        printf("- Student [%d]\n: Full Name : %s %s\n: Age : %d\n\n", i++, students[i].nom, students[i].prenom, students[i].age);
    }
};