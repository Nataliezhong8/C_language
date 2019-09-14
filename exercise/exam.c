#include <stdio.h>
#include <stdlib.h>

struct studenttype {
    int id;
    char *name;
    char morf;
};

typedef struct studenttype *Student;

Student create(int id, char name[], char morf) {
    Student student;
    student = (Student) malloc(sizeof(Student));
    if (student == NULL) {
        fprintf(stderr,"no memory\n");
        exit(1);
    }
    student->id = id;
    student->name = name;
    student->morf = morf;
    return student;
}

void print(Student student) {
    printf ("%d %s %c\n", student->id, student->name, student->morf);
    return;
}

int main() {
    Student s;
    s = create(1234, "Yang LI", 'm');
    print(s);
    return 0;
}
