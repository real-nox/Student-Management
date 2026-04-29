#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nom[20];
    char *prenom;
    int age;
} student;

typedef struct
{
    student *eleve;
    int position;
} eleve_position;

student students[10];

int dim = 0;
int compteur = 0;
int last_DELETED_index;

// Functions

void Add_Student();
void Modify_Student();
void Delete_Student();
void Show_Students();

main()
{
    int option;

    do
    {
        do
        {
            printf("Welcome to students Program!\n\n[1] : Add Student\n[2] : Modify an existant student\n[3] : Delete student\n[4] : Show all students\n\n[RESPONSE] : ");
            scanf("%d", &option);
            printf("\n\n");
        } while (option > 4 || option < -1);

        switch (option)
        {
        case 1:
            printf("Adding student, fill-in the form\n");
            Add_Student();
            break;
        case 2:
            Modify_Student();
            break;
        case 3:
            Delete_Student();
            break;
        case 4:
            printf("List of current students : \n");
            Show_Students();
            break;

        default:
            break;
        }
    } while (option != -1);
};

void Add_Student()
{
    student e;

    e.prenom = (char *)malloc(20 * sizeof(char));
    printf("\nWhat's the student's first name?\t - ");
    scanf("%s", e.prenom);
    printf("What's the student's last name?\t - ");
    scanf("%s", e.nom);
    printf("What's the student's age?\t - ");
    scanf("%d", &(e.age));
    printf("\n");

    e.id = compteur;

    compteur += 1;
    printf("%d", compteur);
    students[dim++] = e;
};

void Show_Students()
{
    for (int i = 0; i < dim; i++)
    {
        printf("- ID : %d\n: Full Name : %s %s\n: Age : %d\n\n", students[i].age, students[i].nom, students[i].prenom, students[i].age);
    }
};

eleve_position trouver_etudiant(int id)
{
    eleve_position el_pos;

    for (int i = 0; i < dim; i++)
    {
        printf("%d %d", students[i].id, id);
        if (students[i].id == id)
        {
            el_pos.eleve = &students[i];
            el_pos.position = i;

            printf("%d", el_pos.position);
            return el_pos;
        }

        el_pos.position = -1;
    }
    return el_pos;
}

void Modify_Student()
{
    int id, pos;
    student *etudi;
    Show_Students();

    do
    {
        printf("Entrer ID\t");
        scanf("%d", &id);
    } while (id > dim || id < 0);

    etudi = trouver_etudiant(id).eleve;
    pos = trouver_etudiant(id).position;

    if (pos == -1)
    {
        printf("L'etudiant est introuvable");
        return;
    }

    char op;
    do
    {
        printf("\nEntrer votre choix\na Age\tn Nom\tp Prenom\n");
        scanf(" %c", &op);

        switch (op)
        {
        case 'a':
            printf("Entrer age\n");
            scanf("%d", &(etudi->age));
            break;
        case 'n':
            printf("Entrer age\n");
            scanf("%d", etudi->nom);
            break;
        case 'p':
            printf("Entrer age\n");
            scanf("%d", etudi->prenom);
            break;

        default:
            break;
        }
    } while (op != 'x');
}

void Delete_Student()
{
    int id, pos;
    student *etudi;
    char op;

    do
    {
        printf("Entrer le ID de l'etudiant\t");
        scanf("%d", &id);
    } while (id > compteur || id < 0);

    etudi = trouver_etudiant(id).eleve;
    pos = trouver_etudiant(id).position;

    if (pos == -1)
    {
        printf("L'etudiant est introuvable\n\n");
        return;
    }

    /*if (pos == dim - 1)
        etudi = NULL;
    else
    {
    }*/

    printf("%d\n\n", etudi->age);
    printf("%s\n\n", etudi->nom);
    printf("%s\n\n", etudi->prenom);
    students[pos] = etudi;
    printf("%d\n\n", pos);
}