#include "Header.h"

void NameCreation(students * student, int countOfPeope)
{	

	for (size_t j = 0; j < countOfPeope; j++)
	{
		int fName[20], lName[20], mName[20];
		int length = 4 + rand() % 4;
		for (size_t i = 0; i < length; i++)
		{
			fName[i] = 97 + rand() % 26;
		}
		FromIntToChar(fName, student[j].Name.fName, length);
		length = 4 + rand() % 4;
		for (size_t i = 0; i < length; i++)
		{
			lName[i] = 97 + rand() % 26;
		}
		FromIntToChar(lName, student[j].Name.lName, length);
		length = 4 + rand() % 4;
		for (size_t i = 0; i < length; i++)
		{
			mName[i] = 97 + rand() % 26;
		}
		FromIntToChar(lName, student[j].Name.mName, length);
	}
	
}

void FromIntToChar(int *from, char * to, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		to[i] = from[i];
	}
	to[0] = toupper(from[0]);
	to[length - 1] = '\0';
}

void DateOfBirht(students * student, int countOfPeope)
{
	for (size_t i = 0; i < countOfPeope; i++)
	{
		student[i].date.date = 1 + rand() % 30;
		student[i].date.month = 1 + rand() % 11;
		student[i].date.year = 1980 + rand() % 10;
	}
}

void Gender(students * student, int countOfPeope)
{
	for (size_t i = 0; i < countOfPeope; i++)
	{
		int n = 0 + rand() % 2;
		switch (n)
		{
		case Male:
		{
			strcpy_s(student[i].gender, "Male");
		}
			break;
		case Female:
		{
			strcpy_s(student[i].gender, "Female");
		}
			break;
		default: printf("ERROR\n");
			break;
		}
	}
}

void SubjectsScore(students * student, int countOfPeope)
{
	for (size_t i = 0; i < countOfPeope; i++)
	{
		student[i].subjects.IT = 5 + rand() % 5;
		student[i].subjects.Math = 5 + rand() % 5;
		student[i].subjects.Physic = 5 + rand() % 5;
	}
}


void FileFilling(FILE * file, students * student, int countOfPeople)
{
	for (size_t i = 0; i < countOfPeople; i++)
	{
		fprintf(file, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n",
			student[i].Name.lName, student[i].Name.fName, student[i].Name.mName, student[i].gender, student[i].date.year,
			student[i].subjects.Math, student[i].subjects.Physic, student[i].subjects.IT);
	}
}

void FilePrint(FILE * file)
{
	fseek(file, 0, SEEK_END); // устанавливаем позицию в конец файла
	long lSize = ftell(file); // получаем размер в байтах
	rewind(file); // устанавливаем указатель в конец файла


	char * buffer = (char*)calloc(lSize, sizeof(char));
	if (buffer == NULL)
	{
		fputs("Ошибка памяти\n", stderr);
		exit(EXIT_FAILURE);
	}

	int result = fread(buffer, 1, lSize, file); // считываем файл в буффер
												/*if (result != lSize)
												{
												fputs("Ошибка чтения", stderr);
												exit(EXIT_FAILURE);
												}*/
												//теперь содержимое в буфере
	printf("\n\n~~~~~~~~~~~~~~~~~\n\n");
	puts(buffer);
	free(buffer);
}

void FromFileToStruct(FILE * file, students *student,  int countOfPeople)
{	
	char test[10];
	for (int i = 0; i < countOfPeople; i++)
	{
		while (!feof(file))
		{	
			fgets(student[i].Name.lName, 20, file);
			fgets(student[i].Name.fName, 20, file);
			fgets(student[i].Name.mName, 20, file);
			fgets(test, 10, file);
			student[i].date.year = (int)test;
			fgets(test, 10, file);
			student[i].subjects.Math = (int)test;
			fgets(test, 10, file);
			student[i].subjects.Physic = (int)test;
			fgets(test, 10, file);
			student[i].subjects.IT = (int)test;
			//fgets(test, 1, file);
			/*fread_s(student[i].Name.fName, sizeof(char), 1, file);
			fscanf_s(file, "%s", &student[i].Name.lName);
			fscanf_s(file, "%s", &student[i].Name.fName);
			fscanf_s(file, "%s", &student[i].Name.mName);
			fscanf_s(file, "%s", &student[i].gender);
			fscanf_s(file, "%d", &student[i].date.year);
			fscanf_s(file, "%d", &student[i].subjects.Math);
			fscanf_s(file, "%d", &student[i].subjects.Physic);
			fscanf_s(file, "%d", &student[i].subjects.IT);*/


		//	printf("%s", student[i].Name.lName);
			printf("%d\n", student[i].date.year);
			printf("%d\n", student[i].subjects.Math);
			printf("%d\n", student[i].subjects.Physic);
			printf("%d\n", student[i].subjects.IT);
			/*printf("%s", student[i].Name.mName);
			printf("%s", student[i].gender);
			printf("%d", student[i].date.year);
			printf("%d", student[i].subjects.Math);
			printf("%d", student[i].subjects.Physic);
			printf("%d", student[i].subjects.IT);*/
		}
	}
	
}

void TheOldestStudent(students *student, int countOfPeople, int * index)
{
	int min = student[0].date.year;
	for (int i = 0; i < countOfPeople; i++)
	{
		if (student[i].date.year < min)
		{	
			min = student[i].date.year;
			*index = i;
		}
	}
	printf("Самый старшний ученик:\n\t %s %s %s (%s)\n\tГод рождения: %d\n",
		student[*index].Name.fName, student[*index].Name.mName, student[*index].Name.lName, student[*index].gender, student[*index].date.year);
}

void TheYoungestStudent(students * student, int countOfPeople, int * index)
{
	int min = student[0].date.year;
	for (int i = 0; i < countOfPeople; i++)
	{
		if (student[i].date.year > min)
		{
			min = student[i].date.year;
			*index = i;
		}
	}
	printf("Самый старшний ученик:\n\t %s %s %s (%s)\n\tГод рождения: %d\n",
		student[*index].Name.fName, student[*index].Name.mName, student[*index].Name.lName, student[*index].gender, student[*index].date.year);
}