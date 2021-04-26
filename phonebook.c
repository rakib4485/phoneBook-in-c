#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char firstName[30];
    char lastName[30];
    char number[30];
    char email[30];
    struct node *next;
};

struct node *head;


void insert()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("****  Add To Contact       *****\n");

    printf(" First Name : ");
    getchar();
    gets(temp->firstName);
    printf("Last Name : ");
    //getchar();
    gets(temp->lastName);
    printf("Number : ");
    gets(temp->number);
    printf("Email : ");
    gets(temp->email);
    system("cls");
    printf("Contact add Successfully\n");
    temp->next = NULL;

    if(head==NULL){
        head = temp;
        return;
    }
    else{
        temp->next = head;
        head = temp;
        return;
    }

}

void deleteContact()
{
    printf("****  Remove Contact       *****\n");

    char number[30];
    printf("Enter your Number: ");
    getchar();
    gets(number);
    struct node *temp = head;
    struct node *pretemp;
    if(strcmp(temp->number, number)==0){
        head = temp->next;
        free(temp);
        system("cls");
        printf("Contact Delete Successfully\n");
        return;
    }
    while(temp!=NULL){
        if(strcmp(temp->number, number)==0){
            break;
        }
        pretemp = temp;
        temp = temp->next;
    }
    pretemp->next = temp->next;
    free(temp);
    system("cls");
    printf("Contact Delete Successfully\n");
    return;
}

void display()
{
    printf("**** Contact  List        *****\n");
    struct node *temp = head;
    while(temp != NULL){
        printf("Name : %s %s\n", temp->firstName, temp->lastName);
        printf("Number : %s\n", temp->number);
        printf("Email : %s\n", temp->email);
        printf("\n\n");
        temp = temp->next;
    }
}

void searchByFirstName()
{
    printf("****  Search Contact       *****\n");
    int i= 0;
    char firstName[30];
    printf("Enter your First Name: ");
    getchar();
    gets(firstName);
    system("cls");
    printf("****  Search Results       *****\n");
    struct node *temp = head;
    while(temp!=NULL){
                if(strcmp(temp->firstName, firstName)==0){
                    printf("Name : %s %s\n", temp->firstName,temp->lastName);
                    printf("Number : %s\n", temp->number);
                    printf("Email : %s\n", temp->email);
                    printf("\n\n\n");

            }
            temp = temp->next;
        }
}

void searchByLastName()
{
    printf("****  Search Contact       *****\n");
    int i= 0;
    char lastName[30];
    printf("Enter your Last Name: ");
    getchar();
    gets(lastName);
    system("cls");
    printf("****  Search Results       *****\n");
    struct node *temp = head;
    while(temp!=NULL){
                if(strcmp(temp->lastName, lastName)==0){
                    printf("Name : %s %s\n", temp->firstName,temp->lastName);
                    printf("Number : %s\n", temp->number);
                    printf("Email : %s\n", temp->email);
                    printf("\n\n\n");

            }
            temp = temp->next;
        }
}

void searchByNumber()
{
    printf("****  Search Contact       *****\n");

    char number[30];
    printf("Enter your Number: ");
    getchar();
    gets(number);
    system("cls");
    printf("****  Search Results       *****\n");
    struct node *temp = head;
    while(temp!=NULL){
        if(strcmp(temp->number, number)==0){
            printf("Name : %s %s\n", temp->firstName, temp->lastName);
            printf("Number : %s\n", temp->number);
            printf("Email : %s\n", temp->email);
            printf("\n\n\n");
            //temp = temp->next;
        }
        temp = temp->next;

    }

}

void update()
{
    printf("\t****  Update Contact       *****\n");

    char number[30];
    printf("Enter your Number: ");
    getchar();
    gets(number);
    system("cls");
    struct node *temp = head;
    while(temp!=NULL){
        if(strcmp(temp->number, number)==0){
            break;
        }
        temp = temp->next;
    }
    printf("Old Name: %s %s\n",temp->firstName, temp->lastName);
    printf("Old Email: %s\n",temp->email);
    printf("New Data\n");
    printf(" First Name : ");
    gets(temp->firstName);
    printf(" Last Name : ");
    gets(temp->lastName);
    printf("Email: ");
    gets(temp->email);
    system("cls");
    printf("Contact Update successfully\n\n");
    return;
}

int main()
{
    system("color 3f");
    //system("color 5");
    while(1)
    {
        int n;
    printf("\n\n\n\t**********************************\n");
    printf("\t**** 1. Add To Contact       *****\n");
    printf("\t**** 2. Remove Contact       *****\n");
    printf("\t**** 3. Search By First Name *****\n");
    printf("\t**** 4. Search By Last Name  *****\n");
    printf("\t**** 5. Search By Number     *****\n");
    printf("\t**** 6. Update Contact       *****\n");
    printf("\t**** 7. View Contact         *****\n");
    printf("\t**** 8. Exit                 *****\n");
    printf("\t**********************************\n");
    printf("\tReplay: ");
    scanf("%d", &n);

    switch(n)
    {
    case 1:
        system("cls");
        insert();
        break;

    case 2:
        system("cls");
        deleteContact();
        break;

    case 3:
        system("cls");
        searchByFirstName();
        break;

    case 4:
        system("cls");
        searchByLastName();
        break;

    case 5:
        system("cls");
        searchByNumber();
        break;

    case 6:
        system("cls");
        update();
        break;

    case 7:
        system("cls");
        display();
        break;

    case 8:
        return 0;
        break;

    default :
        system("cls");
        printf("\nInvalide Inpute");
        printf("\nYou Must Input 1 to 8\n");
    }
    }

}
