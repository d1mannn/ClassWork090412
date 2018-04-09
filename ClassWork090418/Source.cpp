#include "Header.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int counOfPeople = 10;
	students student[10];
	NameCreation(student, 10);
	DateOfBirht(student, 10);
	Gender(student, 10);
	SubjectsScore(student, 10);
	FILE *file;
	errno_t err = fopen_s(&file, "Students.txt", "w");
	if (err == 0)
	{
		printf("Списки студентов созданы\n");
		FileFilling(file, student, 10);
		fclose(file);
	}
	else
	{
		perror("Ошибка");
	}
	file = fopen("Students.txt", "r");
	if (file != 0)
	{
		//FilePrint(file);
		/*TheOldestStudent(file, 10);*/
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
		fclose(file);
	}
	else
	{
		perror("Ошибка");
	}
}