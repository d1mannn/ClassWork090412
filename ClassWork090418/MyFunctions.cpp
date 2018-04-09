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

void TheOldestStudent(FILE * file, int countOfPeople)
{
	int max = 0, max2 = 0;
	int count = 0, count2 = 0;
	while (!feof(file))
	{
		count++;
		if (count == 5 && count2 == 0)
		{
			fscanf_s(file, "%d", &max);
			count = 0;
			count2++;
		}
		if (count == 5 && count2 != 0)
		{
			fscanf_s(file, "%d", &max2);
			if (max < max2)
				max = max2;
			count = 0;
		}
		printf("%d\n", max);
	}
	printf("\nMAX = %d\n", max);
}
