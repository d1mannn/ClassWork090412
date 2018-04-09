enum Genders
{
	Male, Female
};

struct DOB
{
	int date;
	int month;
	int year;
};

struct Subjects
{
	int Math;
	int Physic;
	int IT;
};

struct Names
{
	char fName[20];
	char lName[20];
	char mName[20];
};

struct students
{
	Names Name;
	DOB date;
	char gender[10];
	Subjects subjects;
};









