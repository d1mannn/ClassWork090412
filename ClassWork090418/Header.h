#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "Structs.h"


void FromIntToChar(int *from, char * to, int length);
void NameCreation(students * student, int countOfPeope);
void DateOfBirht(students * student, int countOfPeope);
void Gender(students * student, int countOfPeope);
void SubjectsScore(students * student, int countOfPeope);
void FileFilling(FILE * file, students * student, int countOfPeople);
void FilePrint(FILE * file);
void FromFileToStruct(FILE * file, students *student, int countOfPeople);
void TheOldestStudent(students * student, int countOfPeople, int * index);