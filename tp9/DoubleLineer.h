#ifndef DOUBLELINEER_H_
#define DOUBLELINEER_H_
#define size 20
#define nt 3


typedef struct student
{
    char name[size];
    char surname[size];
    int *nots;
    int *credit;
    char *harfnotu[nt];
    int ort;
    struct student *next;
    struct student *prev;
}Student;
int not_ortalamasi(Student *s);
void load_harfNotu(Student **s);
int *random_credits();
int *random_nots();
void printlist(Student *s);
void new_Student(Student *d);
void createstudent(Student **c);
void insterList(Student **head, Student c);
void printlistByMean(Student *s,int o);
void sifrele(Student *s);
Student *newNode(Student c);
void insert_binary_tr(Student **head, Student c);
void inorder(Student *root);


#endif 