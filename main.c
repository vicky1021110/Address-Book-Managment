/* ====================== main.c ====================== */

#include "contact.h"

int main()
{
    int choice;

    AddressBook addressBook;
    addressBook.countcontact = 0;
    initialize(&addressBook);

    do
    {
        printf("\n--------------------------------------\n");
        printf("      ADDRESS BOOK MENU\n");
        printf("--------------------------------------\n");

        printf("1) Create contact\n");
        printf("2) Search contact\n");
        printf("3) Edit contact\n");
        printf("4) Delete contact\n");
        printf("5) List all contacts\n");
        printf("6) Save and Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createContact(&addressBook);
                break;

            case 2:
                searchContact(&addressBook, SEARCH_ONLY);
                break;

            case 3:
                editContact(&addressBook);
                break;

            case 4:
                deleteContact(&addressBook);
                break;

            case 5:
                listContacts(&addressBook);
                break;

            case 6:
                saveContactsToFile(&addressBook);
                printf("Contacts Saved Successfully\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}
