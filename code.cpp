#include <iostream>
#include<cctype>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

// declaring variables
char a; // user
char j; // admin
int l; // student
string i; // roll number
double n; // password
string x; // name
int z;  // sem

int q = 1; // check1


int f; // admin semester

int counter = 0;

void low(char a[]) {
	for (int i = 0; i < 20; i++) {
		a[i] = tolower(a[i]);
	}
}

// function overloading
void low(string a) {
	transform(a.begin(), a.end(), a.begin(), ::tolower);
}

// asking user is admin or student
void user()
{
	cout << "***************************WELCOME***************************\n" << endl;
	cout << "admin(enter a) or student(enter s)??\nEnter.....";
	cin >> a;
	a = tolower(a);
}

class student {
public:
	char student_name[20];
	char roll_no[20];
	double password;

	void input_details() {

		cout << "Enter name of student->"; cin >> student_name;
		low(student_name);

		cout << "Enter roll number->"; cin >> roll_no;
		low(roll_no);

		cout << "Create a password(must contain only digits and '.' )";  cin >> password;
	}

	void display_details() {

		cout << "\nName :: " << student_name << endl;
		cout << "Roll number :: " << roll_no << endl;
	}
};

class sub_marks {
public:
	char Sub_name[20];
	int Sub_credits;
	double Sub_marks;
	double point_;

	void set_marks() {
		cout << "Enter subject name->"; cin >> Sub_name;
		low(Sub_name);

		cout << "Enter subject credits->"; cin >> Sub_credits;
		cout << "Enter marks scored in the subject->"; cin >> Sub_marks;
	}

	void get_marks() {
		cout << Sub_name << "\t\t" << Sub_credits << "\t\t" << Sub_marks << endl;
	}

	void calc() {
		double point;
		if (Sub_marks > 90) {
			point = 10;
		}
		if (Sub_marks > 80 && Sub_marks <= 90) {
			point = 9;
		}
		if (Sub_marks > 70 && Sub_marks <= 80) {
			point = 8;
		}
		if (Sub_marks > 60 && Sub_marks <= 70) {
			point = 7;
		}
		if (Sub_marks > 50 && Sub_marks <= 60) {
			point = 6;
		}
		if (Sub_marks > 40 && Sub_marks <= 50) {
			point = 5;
		}
		if (Sub_marks < 40) {
			point = 4;
		}

		point_ = point * Sub_credits;
	}
};

class semester {
public:
	int k;
	int n;
	sub_marks obj[10];
	double gpa;
	double point_total = 0;
	double sum_credits = 0;

	void set(){
		cout << "Enter the semester number for which you want to enter marks->"; cin >> n;
		cout << "Enter number of subjects in this particular semester->"; cin >> k;
		for (int i = 0; i < k; i++) {
			obj[i].set_marks();
		}
	}

	double gpa_calc() {

		for (int i = 0; i < k; i++) {
			obj[i].calc();
			sum_credits = sum_credits + obj[i].Sub_credits;
			point_total = point_total + obj[i].point_;
		}

		gpa = point_total / sum_credits;
		return gpa;
	}

	void display_gpa() {
		gpa_calc();
		cout << "Gpa scored is->" << gpa << endl;
	}

	void get() {
		cout << "\nsubject name\tcredits\t\tmarks scored\t" << endl;
		for (int i = 0; i < k; i++) {
			obj[i].get_marks();
		}
	}

	void modify() {
		cout << "Enter number of subjects in this particular semester->"; cin >> k;
		for (int i = 0; i < k; i++) {
			obj[i].set_marks();
		}
	}
};


void write_id(string d);
void write_id1();
void display(string d, int b);
void admin_option();
void student_option();

void display_all();
void display_particular(string d);
void modify(string d);
void create_file(string h);
void final();
void display1();
void check(string a, string d, double e);
void check1(string a, string d, double e);
void check_admin(string a, string d);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	user();
	final();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void admin_option() {
	cout << "\n\tMENU";
	cout << "\n\tAFTER CREATING or ENTERING INFO PLEASE EXIT THEN PROCEED";
	cout << "\n\n\t\t1.CREATE NEW STUDENT ID";
	cout << "\n\t\t2.TO ENTER MARKS";
	cout << "\n\t\t3.TO MODIFY MARKS";
	cout << "\n\t\t4.TO DISPLAY LIST OF ALL STUDENTS";
	cout << "\n\t\t5.TO DISPLAY MARKS OF ALL STUDENTS IN A PARTICULAR SEMESTER";
	cout << "\n\t\t6.TO DISPLAY MARKS OF PARTICULAR STUDENT IN ALL SEMESTESTERS COMPLETED BY ENTERING NAME, ROLL NUMBER";
	cout << "\n\t\t7.To EXIT\n";
	cout << "\n\tGive your input.....";
	cin >> j;
}

void student_option() {
	cout << "\n\t1. TO DISPLAY MARKS AND GPA OF A SEMESTER";
	cout << "\n\t2. DISPLAY CGPA";
	cout << "\n\t3. EXIT\n";
	cout << "\nGive your input.....";
	cin >> l;
}

void final() {
	double pass;

	if (a == 'a') {
		cout << "Enter password---";
		cin >> pass;

		if (pass == 123.456) {
			cout << "\n***************************LOGIN SUCCESSFULL***************************\n" << endl;
			admin_option();

			while (j != '7') {
				if (j == '1') {
					write_id1();
					admin_option();
				}

				else if (j == '2') {
					
					cout << "Enter name of student whose marks has to be entered->"; cin >> x;
					cout << "Enter student's roll number ->"; cin >> i;
					low(i);
					low(x);
					write_id(i);
					admin_option();
				}

				else if (j == '3') {
					cout << "Enter name of student whose marks has to be modified->"; cin >> x;
					cout << "Enter student's roll number ->"; cin >> i;
					modify(i);
					admin_option();
				}

				else if (j == '4') {
					display1();
					admin_option();
				}

				else if (j == '5') {
					display_all();
					admin_option();
				}
				else if (j == '6') {
						cout << "Enter name of student->"; cin >> x;
						low(x);

						cout << "Enter roll number->"; cin >> i;
						low(i);
						display_particular(i);
						admin_option();
				}

				else {
					cout << "\nWrong input" << endl;
				}
			}
		}
		else {
			cout << "\nwrong password" << endl;
		}

	}
	else if (a == 's') {

		while (q != 0 && counter <= 2) {
			cout << "Enter your name->"; cin >> x;
			low(x);

			cout << "enter your roll number->"; cin >> i;
			low(i);

			cout << "Enter your password(conatins only digits or '.')->"; cin >> n;
			check1(x, i, n);
			counter++;

			if (counter > 2) {
				cout << "Max number of attempts done" << endl;
				return;
			}
		}

		student_option();

		while (l != 3) {
			if (l == 1) {
				check(x, i, n);
				student_option();
			}

			else if (l = 2) {
				check(x, i, n);
				student_option();
			}
			else {
				cout << "\nWrong input try again...." << endl;
			}
		}
	}

	else {
		cout << "\nWrong input" << endl;
	}


}


void write_id(string a) {
	semester obj;
	ofstream outFile;
	outFile.open(a + ".dat", ios::binary | ios::app);
	obj.set();
	outFile.write((char *)&obj, sizeof(semester));
	outFile.close();
	cout << "\nmarks entered successfully" << endl;
}

void check(string a, string d, double e) {
	student obk;
	bool f = false;
	bool g = false;
	bool h = false;


	ifstream inFile1;
	inFile1.open("txt.dat", ios::binary);
	if (!inFile1)
	{
		cout << "\nFile could not be opened....";
		return;
	}

	while (inFile1.read((char*)&obk, sizeof(student)))
	{
		if (obk.student_name == a) {
			f = true;
			if (obk.roll_no == d) {
				g = true;
				if (obk.password == e) {
					h = true;
					if (l == 1) {
						cout << "\nEnter the semester of which you want to see marks and gpa scored->"; cin >> z;
					}
					display(i, z);
				}
			}
		}
	}

	if (f == false || g == false) {
		cout << "\n\nstudent with this login credetials doesn't exist\nCheck your name and roll number" << endl;
	}
	else if (h == false) {
		cout << "\n\nWrong password" << endl;
	}
}

void display(string d, int b) {
	semester obj;

	double cgpaa;
	double points_total = 0;
	double credits_total = 0;
	bool y = false;

	ifstream inFile;

	inFile.open(d + ".dat", ios::binary);
	if (!inFile)
	{
		cout << "\nFile could not be opened....";
		return;
	}


	while (inFile.read((char*)&obj, sizeof(semester)))
	{
		obj.gpa_calc();
		points_total = points_total + obj.point_total;
		credits_total = credits_total + obj.sum_credits;
		if ((obj.n == b &&l==1 )||(obj.n == b && j == '5'))
		{
			obj.get();
			obj.display_gpa();
			y = true;
		}
	}

	cgpaa = points_total / credits_total;

	if (l == 2) {
		y = true;
		cout << "\nYour cgpa is: " << cgpaa << endl;
	}

	if (y == false) {
		cout << "\nMarks for this semester haven't been uploaded yet\ncheck back later" << endl;
	}
}

void write_id1() {
	student obk;
	ofstream outFile1;
	outFile1.open("txt.dat", ios::binary | ios::app);
	obk.input_details();
	outFile1.write((char*)&obk, sizeof(student));
	outFile1.close();
	cout << "\nID created successfully" << endl;
	create_file(obk.roll_no);
}

void create_file(string h) {
	semester obj;
	ofstream outFile;
	outFile.open(h + ".dat", ios::binary | ios::app);
	outFile.write((char *)&obj, sizeof(semester));
	outFile.close();
}

void display1() {
	student obk;
	ifstream inFile1;
	inFile1.open("txt.dat", ios::binary);
	if (!inFile1)
	{
		cout << "\nFile could not be opened....";
		return;
	}

	while (inFile1.read((char*)&obk, sizeof(student)))
	{
		obk.display_details();
	}
}

void check1(string a, string d, double e) {
	student obk;
	bool f = false;
	bool g = false;
	bool h = false;

	ifstream inFile1;
	inFile1.open("txt.dat", ios::binary);
	if (!inFile1)
	{
		cout << "\nFile could not be opened....";
		return;
	}

	while (inFile1.read((char*)&obk, sizeof(student)))
	{
		if (obk.student_name == a) {
			f = true;
			if (obk.roll_no == d) {
				g = true;
				if (obk.password == e) {
					cout << "***************************LOGIN SUCCESSFULL***************************\n" << endl;
					counter--;
					h = true;
					q = 0;
				}
			}
		}
	}
	if (f == false || g == false) {
		cout << "\n\nstudent with this login credetials doesn't exist\nCheck your name and roll number\n" << 2 - counter << " attempts left \n" << endl;
	}
	else if (h == false) {
		cout << "\n\nWrong password \n" << 2 - counter << " attempts left \n" << endl;
	}
}

void display_all() {
	int u;
	student obk;
	ifstream inFile1;

	cout << "Enter the semester for which marks are to be displayed->"; cin >> u;

	inFile1.open("txt.dat", ios::binary);

	if (!inFile1)
	{
		cout << "\nFile could not be opened....";
		return;
	}

	while (inFile1.read((char*)&obk, sizeof(student)))
	{
		semester obj;
		ifstream inFile;
		string o;
		o = obk.roll_no;
		
		cout << endl;
		obk.display_details();
		display(o, u);
	}
	inFile1.close();          
}

void display_particular(string d) {

	semester obj;
	bool y = false;
	ifstream inFile;

	inFile.open(d + ".dat", ios::binary);
	if (!inFile)
	{
		cout << "\nFile could not be opened....";
		return;
	}

	while (inFile.read((char*)&obj, sizeof(semester)))
	{
		if (obj.n>=1 && obj.n<=8)
		{
			cout << "\n\nSemester:: "<<obj.n;
			obj.get();
			obj.gpa_calc();
			obj.display_gpa();
			y = true;
		}
	}

	if (y == false) {
		cout << "\nMarks for this semester haven't been uploaded yet\ncheck back later" << endl;
	}
}

void modify(string d) {
	int sm;
	f = false;
	cout << "Enter the semester for which you want marks to be modified->"; cin >> sm;

	semester obj;
	fstream file;
	file.open(d + ".dat", ios::binary | ios::in | ios::out);

	while (!file.eof() && f == false)
	{
		file.read((char*)&obj, sizeof(semester));

		if (obj.n == sm) {
			cout << "Current marks" << endl;
			obj.get();

			cout << "\nNow enter the modified marks" << endl;
			obj.modify();
			int pos = (-1)*static_cast<int>(sizeof(semester));
			file.seekp(pos, ios::cur);
			file.write((char*)&obj, sizeof(semester));
			cout << "Marks modified successfully" << endl;
			f = true;
		}
	}
	file.close();
	if (f == false) {
		cout << "Marks of this semester for this student haven't been uploaded yet" << endl;
	}

}
