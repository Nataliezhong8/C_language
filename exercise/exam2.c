//student.c
//yinghong 11/07/2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int id;
	char *name;
	char morf;
};

typedef struct node *Student;

Student create(int id, char *name, char morf) {
	Student student;
	student = (Student)malloc(sizeof(struct node));
	if (student == NULL) {
	    fprintf(stderr,"No memory...\n");
	    exit(1);
	} else {
	    student->name = (char*)malloc(sizeof(char) * (strlen(name)+1));
	    if (student->name == NULL) {
	        fprintf(stderr,"No memory...\n");
	        exit(1);
	    } 
	    student->id = id;
	    //student->name = name; is not correct, because argv name has permanent addr, 
		//it only exists in this function. outside of this function, this addr is a garabge addr, so we should use strcpy()
		strcpy(student->name, name);
	    student->morf = morf;
	}
	return student;
}

void print(Student student) {
	printf("%d %s %c\n",student->id, student->name,student->morf);
	return;
}

void freem(Student student) {
	free(student->name);
	printf("free name,success\n");
	free(student);
	printf("free student,success\n");
	student = NULL;
	return;
}


int main() {
	Student s;
	s = create(1234,"Yang Li", 'm');
	print(s);
	freem(s);
	return 0;
}

