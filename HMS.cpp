#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
using namespace std;

struct patient
{
    long long ID;
    string firstname;
    string lastname;
    int age;
    char blood[5];
    char gender;
    patient* next;
};
class linkedqueue
{
    patient* head, * last;
public:
    linkedqueue() //constructor
    {
        head = NULL;
        last = NULL;
    }
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void listofpatients();
    int search(int);
    char departmentname[50];
};

int linkedqueue::search(int item)
{
    if (head == NULL)
        return false;
    else
    {
        int flag = 0;
        patient* p = new patient();
        p = head;

        while (p->next != NULL && p->ID != item)
        {
            p = p->next;
        }
        if (p->ID == item)
        {
            flag = 1;
            return true;
        }
        {if (flag == 0)
            return false;}
    }
}

int readnumber()
{
    char b[20];
    cin.getline(b, sizeof(b));
    return atoi(b);
}

patient linkedqueue::input()
{
    int flag = 0;
    patient* p = new patient();
    cout << "\n   Please enter data for patient\n";
    cout << "\n   First name     : ";
    ofstream file;
    file.open("Patient.txt", ios::out | ios::app);
    getline(cin, p->firstname);
    file << "First Name : " << p->firstname<<endl;
    cout << "   Last name      : ";
    getline(cin, p->lastname);
    file <<"Last Name : " << p->lastname<<endl;
again:
    cout << "   Blood Group    : ";
    cin >> p->blood;
    file <<"Blood Group : "<< p->blood<<endl;
    if ((strcmp(p->blood, "A+") == 0) || (strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "A-") == 0) || (strcmp(p->blood, "a-") == 0) ||
        (strcmp(p->blood, "B+") == 0) || (strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "B-") == 0) || (strcmp(p->blood, "b-") == 0) ||
        (strcmp(p->blood, "O+") == 0) || (strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "O-") == 0) || (strcmp(p->blood, "o-") == 0) ||
        (strcmp(p->blood, "AB+") == 0) || (strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "AB-") == 0) || (strcmp(p->blood, "ab-") == 0))
        flag = 1;
    if (flag == 0)
    {
        cout << "\n   Invalid Blood Group Try Again..\n\n";
        goto again;

    }
    cout << "   Gender(m/f)    : ";
    cin >> p->gender;
    file <<"Gender(m/f): "<< p->gender << endl;
    cout << "   Age            : ";
    cin >> p->age;
    file <<"Age: "<< p->age<<endl;
    cout << "   Mobile number  : +880";
    cin >> p->ID;
    file <<"Mobile number: +880"<<p->ID<<endl;
    file <<"\n"<<endl;
    file.close();

    if (search(p->ID))
    {
        p->ID = 0;
        cout << "\n   Data not valid. Operation cancelled.";
    }
    return *p;
}

void queue_history(){
    system("cls");
    string line;
    ifstream file("Patient.txt");
    while(getline(file,line)){
        cout << line << endl;
    }
    file.close();
}

void output(patient* p)
{
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n   Patient data:\n";
    cout << "\n   First Name         : " << p->firstname;
    cout << "\n   Last Name          : " << p->lastname;
    cout << "\n   Gender             : " << p->gender;
    cout << "\n   Age                : " << p->age;
    cout << "\n   Blood Group        : " << p->blood;
    cout << "\n   Mobile Number      : " << p->ID;
    cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}
void linkedqueue::insertatbeg()
{
    patient* p = new patient();
    *p = input();
    if (p->ID == 0)
        return;

    if (head == NULL)

    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = head;
        head = p;
    }
    system("cls");
    cout << "\n\tPatient added:";
    output(p);
}
void linkedqueue::insertatend()
{
    patient* p = new patient();
    *p = input();
    if (p->ID == 0)
        return;

    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = NULL;
        last->next = p;
        last = p;
    }
    system("cls");
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  |-- Pirate HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\n  ----------PATIENT ADDED-----------";
    output(p);
}
void linkedqueue::getpatientout()
{
    system("cls");
    if (head == NULL)
    {
        cout << "\n  No Patient to operate";
    }
    else
    {
        patient* p = new patient();
        p = head;
        head = head->next;
        cout << "\n  Patient to operate:";
        output(p);
    }
}

void linkedqueue::listofpatients()
{
    if (head == NULL)
    {
        cout << "\n  No patient";
    }
    system("cls");
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n  |-- Pirate HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    patient* p = new patient;
    p = head;
    while (p != NULL)
    {
        cout << "\n   Patient data:\n";
        cout << "\n   First Name       : " << p->firstname;
        cout << "\n   Last Name        : " << p->lastname;
        cout << "\n   Gender           : " << p->gender;
        cout << "\n   Age              : " << p->age;
        cout << "\n   Blood Group      : " << p->blood;
        cout << "\n   Mobile Number    : " << p->ID;
        cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        p = p->next;
    }
    cout << "\n";
}


void departmentmenu(linkedqueue* q)
{
    int choice = 0, success;
    patient p;
    while (choice != 5)
    {
        system("cls");
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n  |-- Pirate HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n\n   " << q->departmentname;
        cout << "\n   [1] Add normal patient\n";
        cout << "   [2] Add critically ill patient\n";
        cout << "   [3] Take patient to Doctor\n";
        cout << "   [4] Display list\n";
        cout << "   [5] Change department or exit\n";
        cout << "\n   Please enter your choice : ";
        choice = readnumber();
        cout << "  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

        switch (choice)
        {
        case 1:	q->insertatend();
            cout << "\n   Press any key";
            getch();
            break;

        case 2:	q->insertatbeg();
            cout << "\n   Press any key";
            getch();
            break;

        case 3:	q->getpatientout();
            cout << "\n   Press any key";
            getch();
            break;

        case 4:	system("cls");
            q->listofpatients();
            cout << "\n   Press any key";
            getch();
            break;
        }
    }
}

int main()
{
    int i, choice = 0;
    linkedqueue departments[5];

    while (choice != 6)
    {
        strcpy(departments[0].departmentname, "GENERAL CLINIC\n");
        strcpy(departments[1].departmentname, "HEART CLINIC\n");
        strcpy(departments[2].departmentname, "LUNG CLINIC\n");
        strcpy(departments[3].departmentname, "EYE CLINIC\n");
        strcpy(departments[4].departmentname, "PLASTIC SURGERY\n");
        system("cls");
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n  |-- Pirate HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
        cout << "   Main Menu\n\n";
        for (i = 0; i < 5; i++)
        {
            cout << "   " << (i + 1) << ": " << departments[i].departmentname;
        }
        cout << "   6: EXIT";
        cout << "\n\n   Please enter your choice : ";
        choice = readnumber();
        if (choice >= 1 && choice <= 5)
        {
            departmentmenu(&departments[choice - 1]);
        }
        system("cls");
    }
    if (choice == 6){
        cout << "\n\t\tThank you! \n";
        cout <<"\n\tProject Done by the Pirates!\n"<< endl;}
    exit(0);
}