#include "Header.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int counOfPeople = 10;
	students student[10];
	students *student2;
	NameCreation(student, 10);
	DateOfBirht(student, 10);
	Gender(student, 10);
	SubjectsScore(student, 10);
	FILE *file;
	errno_t err = fopen_s(&file, "Students.txt", "wb");
	if (err == 0)
	{
		printf("Списки студентов созданы\n");
		//FileFilling(file, student, 10);
		fwrite(student, 10, sizeof(students), file);
		fclose(file);
	}
	else
	{
		perror("Ошибка");
	}
	err = fopen_s(&file, "Students.txt", "rb");
	students * value = NULL;
	if (err == 0)
	{	
		int count = 0;
		fseek(file, 0, SEEK_END); // устанавливаем позицию в конец файла
		long lSize = ftell(file); // получаем размер в байтах
		rewind(file); // устанавливаем указатель в конец файла
		student2 = (students*)calloc(lSize * 2, sizeof(students));
		while (fread(student2, sizeof(students), 1, file))
		{
			count++;
			/*student2 = (students*)realloc(value, count * sizeof(students));
			if (count != 0)
				value = student2;*/
		}
		printf("%d\n", count);
		//fseek(file, 0, SEEK_END); // устанавливаем позицию в конец файла
	
		rewind(file);
		//student2 = (students*)calloc(10, sizeof(students));
		fread(student2, sizeof(students), count, file);
		
		fclose(file);

		for (int i = 0; i < count; i++)
		{
			printf("%d)\t%s %s %s (%s)\n", i + 1, student2[i].Name.lName, student2[i].Name.mName, student2[i].Name.fName, student2[i].gender);
			printf("\t%d\n", student2[i].date.year);
			printf("\tMath: %d\tPhys: %d\tIT: %d\n\n", student2[i].subjects.Math, student2[i].subjects.Physic, student2[i].subjects.IT);
		}
		int index;
		TheOldestStudent(student2, count, &index);
	}
	else
	{
		perror("Ошибка");
	}
	free(student2);
}