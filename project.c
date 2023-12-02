#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>

void file_to_linklist();
void adminmenu();
void doctormenu();
void studentmenu();
void addnewPatient();
void newpatient();
void searchPatient();
void updatePatient();
void deletePatient();
void displayPatient();
void displaymedicine_list();
void displayappoinment_list();
void displayemergency_list();
void viewdoctor();
void onlineappointment();
void ordermedicine();
void emergency();
void viewstudentall();
void viewmypatients();
void updatemypatient();



struct doctor
{
    char name[20];
    int age;
    char specialization[40];
    char degree[10];
    char time[20];
    char days[10];
};

struct Patient
{
    char name[50];
    char id[15];
    char age[10];
    char gender[10];
    char height[10];
    char weight[10];
    char bloodgroup[5];
    char department[50];
    char number[20];
    char address[30];
    char past_medical_treatment[40];
    char roomNo[5];
    char status[20];
    char diagnosis[40];
    struct Patient *link;
};
struct Patient *head = NULL;
typedef struct Patient patient;

int main()
{
    int userInput;
    patient *head = NULL;
    //This is a function for transfering all the data from File to LINKLIST......
    file_to_linklist();
    system("cls");
    system("color 9");
    printf("\n\n");
    printf("\t\t\t=========================================================\n");
    printf("\t\t\t            Medical Center Management System         \n");
    printf("\t\t\t=========================================================\n");
    printf("\t\t\t||\t\t1. ADMIN SECTION-->                    ||\n");
    printf("\t\t\t||\t\t2. DOCTOR SECTION-->                   ||\n");
    printf("\t\t\t||\t\t3. STUDENT SECTION-->                  ||\n");
    printf("\t\t\t||\t\t4. EXIT-->                             ||\n");
    printf("\t\t\t=========================================================\n");
    printf("\n");
    printf("\t\t\t\tEnter Your Choice --->");
    scanf("%d", &userInput);


    switch (userInput)
    {
    case 1:
        adminmenu();
        break;
    case 2:
        doctormenu();
        break;
    case 3:
        studentmenu();
    case 4:
        return;
    }
}
void adminmenu()
{
    while(1)
    {
        int userInput;
        system("cls");
        system("color 9");
        printf("\n\n");
        printf("\t\t\t=========================================================\n");
        printf("\t\t\t            Medical Center Management System         \n");
        printf("\t\t\t=========================================================\n");
        printf("\n\t\t\t\t ADMIN MENU: \n");
        printf("\n\t\t\t\t 1.Add Patient ");
        printf("\n\t\t\t\t 2.Search Patient ");
        printf("\n\t\t\t\t 3.Update Patient details ");
        printf("\n\t\t\t\t 4.Delete Patient details");
        printf("\n\t\t\t\t 5.Display Patient details");
        printf("\n\t\t\t\t 6.Display Ordered Medicine details");
        printf("\n\t\t\t\t 7.Display Appoinment list details");
        printf("\n\t\t\t\t 8.Display emergency Service details");
        printf("\n\t\t\t\t 9.Exit To Main Menu");
        printf("\n");
        printf("\t\t\t\tEnter Your Choice --->");
        scanf("%d", &userInput);
        printf("\n\t\t\t*********************************************************\n");
        switch (userInput)
        {
        case 1:
            // This is the add patient Section......
            addnewPatient();
            getchar();
            break;
        case 2:
            // This is the search patient Section......
            searchPatient();
            getchar();
            break;
        case 3:
            // This is the Update Patient Section...
            updatePatient();
            getchar();
            break;
        case 4:
            // This is the Delete Patient Section...
            deletePatient();
            getchar();
            break;
        case 5:
            // This is the section for Display all patient details......
            displayPatient();
            getchar();
            break;
        case 6:
            // This is the section for ordered medicine list....
            displaymedicine_list();
            getchar();
            break;
        case 7:
            // This is the Section for Appoinment List....
            displayappoinment_list();
            getchar();
            break;
        case 8:
            // This is the Emergency Service details list....
            displayemergency_list();
            getchar();
            break;
        case 9:
            // Exit the student menu
            main();
            return;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
void doctormenu()
{
    while(1)
    {
        int userInput;
        system("cls");
        system("color 9");
        printf("\n\n");
        printf("\t\t\t=========================================================\n");
        printf("\t\t\t            Medical Center Management System         \n");
        printf("\t\t\t=========================================================\n");
        printf("\n\t\t\t\t DOCTOR MENU: \n");
        printf("\n\t\t\t\t 1.View Student all Records ");
        printf("\n\t\t\t\t 2.View My all Patients ");
        printf("\n\t\t\t\t 3.Update Patient details ");
        printf("\n\t\t\t\t 4.Exit To Main Menu");
        printf("\n");
        printf("\t\t\t\tEnter Your Choice --->");
        scanf("%d", &userInput);
        printf("\n\t\t\t*********************************************************\n");
        switch (userInput)
        {
        case 1:
            //This is the section for Viewing the Student Record.....
            viewstudentall();
            getchar();
            break;
        case 2:
            // This is the section for Viewing Doctors all Patient Records.....
            viewmypatients();
            getchar();
            break;
        case 3:
            // This is the section for update patient Diagnosis....
            updatemypatient();
            break;
        case 4:
            main();
            return;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
void studentmenu()
{
    while(1)
    {
        int userInput;
        system("cls");
        system("color 9");
        printf("\n\n");
        printf("\t\t\t=========================================================\n");
        printf("\t\t\t            Medical Center Management System         \n");
        printf("\t\t\t=========================================================\n");
        printf("\n\t\t\t\t Student MENU: \n");
        printf("\n\t\t\t\t 1.View Doctor Details ");
        printf("\n\t\t\t\t 2.Online Appointment ");
        printf("\n\t\t\t\t 3.Medicine Order ");
        printf("\n\t\t\t\t 4.Emergency Service ");
        printf("\n\t\t\t\t 5.Exit To Main Menu");
        printf("\n");
        printf("\t\t\t\tEnter Your Choice --->");
        scanf("%d", &userInput);
        printf("\n\t\t\t*********************************************************\n");
        switch (userInput)
        {
        case 1:
            //This is the sector for viewing all doctors details.....
            viewdoctor();
            getchar();
            break;
        case 2:
            //This is the section for Online Appointment....
            onlineappointment();
            getchar();
            break;
        case 3:
            //This is the section for ordering Medicine....
            ordermedicine();
            getchar();
            break;
        case 4:
            //This is the emergency Service section...
            emergency();
            break;
        case 5:
            //This is the emergency Service section...
            main();
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
//This is the section of view all doctor details.....
void viewdoctor()
{
    system("cls");
    FILE *fp;
    struct doctor d;

    fp = fopen("alldoctors.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%s   %d  %s   %s %s  %s", d.name, &d.age, d.specialization, d.degree, d.time, d.days) != EOF)
    {
        printf("Name: %s\nAge: %d\nSpecialization: %s\nDegree: %s\nTime: %s\nDays: %s\n", d.name, d.age, d.specialization, d.degree, d.time, d.days);
        printf("\n");
    }

    fclose(fp);
    getchar();
}

//This is the section for Online Appointment....
void onlineappointment()
{
    FILE *fp;
    char name[20], age[10], specialization[20], date[20], time[10];

    fp = fopen("appointments.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    fflush(stdin);
    printf("Enter your name: \n");
    gets(name);

    printf("Enter your age: \n");
    gets(age);

    printf("Enter your desired specialization: \n");
    gets(specialization);

    printf("Enter your preferred date: \n");
    gets(date);

    printf("Enter your preferred time: \n");
    gets(time);

    fprintf(fp, "%s %s %s %s %s", name, age, specialization, date, time);
    fprintf(fp,"\n");

    fclose(fp);

    printf("Appointment booked successfully!\n");
    getchar();
}

//This is the section for ordering Medicine....
void ordermedicine()
{
    FILE *fp;
    char name[20], id[20], medicine[30], payment_method[10],quantity[10],amount[10];
    int choice;

    fp = fopen("medicineorders.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    fflush(stdin);
    printf("Enter your name: ");
    gets(name);

    printf("Enter your ID: ");
    gets(id);

    printf("Enter the name of the medicine: ");
    gets(medicine);

    printf("Enter the quantity: ");
    scanf("%s", quantity);

    printf("Choose a payment method: ");
    printf("\n1. Cash");
    printf("\n2. Card(Visa/1Card)");
    printf("\n3. Online(Rocket/Bkash/Nagad)");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        strcpy(payment_method,"Cash");
        break;
    case 2:
        strcpy(payment_method,"Card");
        break;
    case 3:
        strcpy(payment_method,"Online");
        break;
    default:
        printf("Invalid payment method.\n");
        return 1;
    }

    printf("Enter the amount: ");
    scanf("%s", amount);

    fprintf(fp, "%s %s %s %s %s %s\n", name, id, medicine,  quantity, payment_method, amount);
    fprintf(fp,"\n");

    fclose(fp);

    printf("Order placed successfully!\n");
    getchar();
}

//This is the emergency Service section...
void emergency()
{
    FILE *fp;
    char name[20], id[10], address[50], number[15];
    fp = fopen("ambulance_requests.txt", "a+");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    fflush(stdin);
    printf("Enter your name: ");
    gets(name);

    printf("Enter your ID: ");
    gets(id);

    printf("Enter your address: ");
    gets(address);

    printf("Enter your phone number: ");
    gets(number);

    fprintf(fp, "%s %s %s %s\n", name, id, address, number);
    fprintf(fp,"\n");

    fclose(fp);

    printf("Ambulance request sent successfully!....\n");
    getchar();

}

//From here the doctor Panel Functions start....
//This is ViewStudent record Section.....
void viewstudentall()
{
    FILE *fp;
    char patient_id[15];
    patient patient;
    printf("Enter the patient ID: ");
    scanf("%s", patient_id);

    // Open the patient file....
    fp = fopen("student-all-details.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
int f=0;
    // Find the patient record with the specified ID.
    while (fscanf (fp, "%s %s %s %s %s %s %s %s %s\n", patient.name, patient.id, patient.age, patient.gender, patient.height, patient.weight,  patient.number, patient.address, patient.past_medical_treatment) != EOF)
    {
        if (strcmp(patient.id, patient_id) == 0)
        {
            f=1;
            break;
        }
    }
    fclose(fp);
if(f==1){
    printf("Patient ID: %s\n", patient.id);
    printf("Name: %s\n", patient.name);
    printf("Age: %s\n", patient.age);
    printf("Gender: %s\n", patient.gender);
    printf("Height: %s\n", patient.height);
    printf("Weight: %s\n", patient.weight);
    printf("Phone Number: %s\n", patient.number);
    printf("Address: %s\n", patient.address);
    printf("Past medical treatment: %s\n", patient.past_medical_treatment);}
    else printf("Patient Not Found...");
    getchar();
}
//This is the
void viewmypatients()
{
    FILE *fp;
    patient patient;
    fp = fopen("viewmypatients.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Find the patient record with the specified ID.
    while (fscanf (fp, "%s %s %s %s %s %s %s %s %s", patient.name, patient.id, patient.age, patient.gender, patient.height, patient.weight,  patient.number, patient.address, patient.diagnosis) != EOF)
    {
        printf("Patient ID: %s\n", patient.id);
        printf("Name: %s\n", patient.name);
        printf("Age: %s\n", patient.age);
        printf("Gender: %s\n", patient.gender);
        printf("Height: %s\n", patient.height);
        printf("Weight: %s\n", patient.weight);
        printf("Phone Number: %s\n", patient.number);
        printf("Address: %s\n", patient.address);
        printf("Diagnosis : %s\n\n", patient.diagnosis);
    }
    fclose(fp);
    getchar();
}
void updatemypatient()
{
    FILE *fp;
    char new_diagnosis[40];
    char search_id[15];
    patient patient;

    fp = fopen("viewmypatients.txt", "r+");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter the patient ID: ");
    scanf("%s", search_id);
    fflush(stdin);
    printf("Enter new Verdict for the patient: ");
    fgets(new_diagnosis, sizeof(new_diagnosis), stdin);
    fflush(stdin);

    // Create a temporary file to store updated data....
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        printf("Error opening temporary file.\n");
        fclose(fp);
        return;
    }

    // Find the patient record with the specified ID and update the diagnosis
    while (fscanf(fp, "%s %s %s %s %s %s %s %s %s\n", patient.name, patient.id, patient.age, patient.gender, patient.height, patient.weight, patient.number, patient.address, patient.diagnosis) != EOF)
    {
        if (strcmp(patient.id, search_id) == 0)
        {
            strcpy(patient.diagnosis, new_diagnosis);
        }
        fprintf(tempFile, "%s %s %s %s %s %s %s %s %s\n", patient.name, patient.id, patient.age, patient.gender, patient.height, patient.weight, patient.number, patient.address, patient.diagnosis);
    }

    fclose(fp);
    fclose(tempFile);

    // Remove the old file and rename the temporary file.....
    remove("viewmypatients.txt");
    rename("temp.txt", "viewmypatients.txt");

    printf("Patient diagnosis updated successfully!\n");
    getchar();
}

//From here the Admin panel functions Start.......
//This is the function for tranfering data from FILE to LINKLIST.....
void file_to_linklist()
{
    FILE *fp;
    char name[50];
    char id[15];
    char age[10];
    char gender[10];
    char height[10];
    char weight[10];
    char bloodgroup[5];
    char department[50];
    char number[20];
    char address[30];
    fp = fopen("allpatients.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the data from the file and create a new node for each patient record.
    while(fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", id,name,age,gender,height,weight,department,number,address,bloodgroup) != EOF)
    {
        newpatient(id,name,age,gender,height,weight,department,number,address,bloodgroup);
    }
    fclose(fp);
}

//This is the function for Add New Patient...In here User Input all details....
void addnewPatient()
{
    char name[50],id[15], age[10],gender[10],height[10],weight[10], department[50],number[20],address[30],bloodgroup[5];
    printf("Enter ID: ");
    scanf("%s", id);
    printf("Enter Name: ");
    getchar();
    gets(name);
    printf("Enter Age: ");
    scanf("%s", age);
    printf("Enter Gender: ");
    scanf("%s", gender);
    printf("Enter Blood Group: ");
    scanf("%s", bloodgroup);
    printf("Enter Height: ");
    scanf("%s", height);
    printf("Enter Weight: ");
    scanf("%s", weight);
    printf("Enter Department ");
    scanf("%s", department);
    printf("Enter Number ");
    scanf("%s", number);
    printf("Enter Address ");
    scanf("%s", address);
    newpatient(id, name, age, gender,height,weight,department,number,address,bloodgroup);
    printf("New student added successfully...!\n\n");
    getchar();
}
//This is for add patient section.....In here newnode creating and connecting.....
void newpatient(char *id, char *name, char *age, char *gender, char *height,char *weight,char *department,char *number,char *address,char *bloodgroup)
{

    patient *newnode = (patient*)malloc(sizeof(patient));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newnode->id, id);
    strcpy(newnode->name, name);
    strcpy(newnode->age, age);
    strcpy(newnode->gender, gender);
    strcpy(newnode->height, height);
    strcpy(newnode->weight, weight);
    strcpy(newnode->department, department);
    strcpy(newnode->number, number);
    strcpy(newnode->address, address);
    strcpy(newnode->bloodgroup, bloodgroup);
    newnode->link = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        patient *current = head;
        while (current->link != NULL)
        {
            current = current->link;
        }
        current->link = newnode;
    }
}
void displayPatient()
{
    patient *c=head;
    while(c!=NULL)
    {
        printf("Patient ID: %s\n", c->id);
        printf("Name: %s\n", c->name);
        printf("Age: %s\n", c->age);
        printf("Gender: %s\n", c->gender);
        printf("Height: %s\n", c->height);
        printf("Weight: %s\n", c->weight);
        printf("Department: %s\n", c->department);
        printf("Phone Number: %s\n", c->number);
        printf("Address: %s\n", c->address);
        printf("Blood Group : %s\n\n", c->bloodgroup);
        printf("\n");
        c=c->link;
    }
    getchar();
}
// This is for Search based Display....Here search by ID, NAME, BLOOD.....
void display(patient *c)
{
    printf("Patient ID: %s\n", c->id);
    printf("Name: %s\n", c->name);
    printf("Age: %s\n", c->age);
    printf("Gender: %s\n", c->gender);
    printf("Height: %s\n", c->height);
    printf("Weight: %s\n", c->weight);
    printf("Department: %s\n", c->department);
    printf("Phone Number: %s\n", c->number);
    printf("Address: %s\n", c->address);
    printf("Blood Group : %s\n\n", c->bloodgroup);
    printf("\n");
}
//This is for search by id function....
void searchid(char *id)
{
    patient *current = head;
    int c = 0;
    while (current != NULL)
    {
        if (strcmp(current->id, id) == 0)
        {
            if (c != 1)
            {
                printf("\nPatient Found:\n");
            }
            display(current);
            c = 1;
        }
        current = current->link;
    }
    if (c == 0)
    {
        printf("\nPatient information Not Found\n");
    }
}
//This is for search by Name function....
void searchname(char *name)
{
    patient *current = head;
    int c = 0;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (c != 1)
            {
                printf("\nPatient Found:\n");
            }
            display(current);
            c = 1;
        }
        current = current->link;
    }
    if (c == 0)
    {
        printf("\nPatient information Not Found\n");
    }
}
//This is for search by blood function....
void searchblood(char *bloodgroup)
{
    patient *current = head;
    int c = 0;
    while (current != NULL)
    {
        if (strcmp(current->bloodgroup, bloodgroup) == 0)
        {
            if (c != 1)
            {
                printf("\nStudent Found:\n");
            }
            display(current);
            c = 1;
        }
        current = current->link;
    }
    if (c == 0)
    {
        printf("\nStudent information Not Found\n");
    }
}
//This is the main Search Function.....
void searchPatient()
{
    while (1)
    {
        system("cls");
        printf("Search Patient Information\n");
        printf("=============================================\n");
        printf("1.Search By ID\n2.Search By Name\n3.Search By Blood\n4.Back TO Main Menu\n\n");
        printf("Enter your choice: ");
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            printf("Enter the ID: ");
            char id[15];
            scanf("%s", &id);
            system("cls");
            searchid(id);
        }
        else if (x == 2)
        {
            printf("Enter the Name: ");
            char name[30];
            getchar();
            gets(name);
            system("cls");
            searchname(name);
        }
        else if (x == 3)
        {
            printf("Enter the Blood Group: ");
            char blood[5];
            scanf("%s", blood);
            system("cls");
            searchblood(blood);
        }
        else
            return;
        printf("Press Enter to continue...");
        getchar();
        getchar();
    }
}
void updatePatient()
{
    char name[50];
    char id[15];
    char age[10];
    char gender[10];
    char height[10];
    char weight[10];
    char bloodgroup[5];
    char department[50];
    char number[20];
    char address[30];
    printf("Enter the Patient ID to update: ");
    scanf("%s", id);
    patient *c = head;
    while (c != NULL)
    {
        if (strcmp(c->id, id) == 0)
        {
            printf("\nEnter the updated information for Patient %s:\n", id);
            printf("Enter Name: ");
            getchar();
            gets(name);
            strcpy(c->name, name);
            printf("Enter Age: ");
            scanf("%s", age);
            strcpy(c->age, age);
            printf("Enter Gender: ");
            scanf("%s", gender);
            strcpy(c->gender, gender);
            printf("Enter Blood Group: ");
            scanf("%s", bloodgroup);
            strcpy(c->bloodgroup, bloodgroup);
            printf("Enter Height: ");
            scanf("%s", height);
            strcpy(c->height, height);
            printf("Enter Weight: ");
            scanf("%s", weight);
            strcpy(c->weight, weight);
            printf("Enter Department ");
            scanf("%s", department);
            strcpy(c->department, department);
            printf("Enter Number ");
            scanf("%s", number);
            strcpy(c->number, number);
            printf("Enter Address ");
            scanf("%s", address);
            strcpy(c->address, address);
            printf("Patient %s updated successfully!\n\n", id);
            return;
        }
        c = c->link;
    }
    printf("Patient with ID %s not found.\n\n", id);
    getchar();
}

void deletePatient()
{
    char id[15];
    printf("Enter the Patient ID to delete: ");
    scanf("%s", id);
    patient *current = head;
    patient *prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->id, id) == 0)
        {
            if (prev == NULL)
            {
                head = current->link;
            }
            else
            {
                prev->link = current->link;
            }
            free(current);
            printf("Patient with ID %s deleted successfully!\n\n", id);
            return;
        }
        prev = current;
        current = current->link;
    }
    printf("Patient with ID %s not found.\n\n", id);
    getchar();
}
//This is the section for Display Ordered Medicine List....
void displaymedicine_list()
{
    char name[20], id[20], medicine[30], payment_method[10],quantity[10],amount[10];
    FILE *fp;
    fp = fopen("medicineorders.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %s %s %s %s\n", name, id, medicine,  quantity, payment_method, amount) != EOF)
    {
        printf("Name: %s\nID: %s\nMedicine: %s\nQuantity: %s\nPayment Method: %s\nAmount: %s\n", name, id, medicine,  quantity, payment_method, amount);
        printf("\n");
    }

    fclose(fp);
    getchar();
}
//This is the section for Display Appoinment list.....
void displayappoinment_list()
{
    FILE *fp;
    char name[20], age[10], specialization[20], date[20], time[10];

    fp = fopen("appointments.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(fp, "%s %s %s %s %s", name, age, specialization, date, time) != EOF)
    {
        printf("Name: %s\nAge: %s\nSpecilization: %s\nDate: %s\nTime: %s\n\n", name, age, specialization, date, time);
        printf("\n");
    }

    fclose(fp);
    getchar();
}
//This is the section for Display Emergency list...
void displayemergency_list()
{
    FILE *fp;
    char name[20], id[10], address[50], number[15];
    fp = fopen("ambulance_requests.txt", "a+");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    while (fscanf(fp, "%s %s %s %s\n", name, id, address, number) != EOF)
    {
        printf("Name: %s\nID: %s\nAddress: %s\nNumber: %s\n", name, id, address, number);
        printf("\n");
    }

    fclose(fp);
    getchar();

}



