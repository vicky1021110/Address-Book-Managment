#include "contact.h"

void listContacts(AddressBook *addressBook)
{
    int count = addressBook->countcontact;

    if (count == 0)
    {
        printf("---> NO contacts are saved <---\n");
        return;
    }

    Contact tempContacts[count];
    for (int i = 0; i < count; i++)
    {
        tempContacts[i] = addressBook->contacts[i];
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (strcasecmp(tempContacts[j].name,tempContacts[j + 1].name) > 0)
            {
                Contact temp = tempContacts[j];
                tempContacts[j] = tempContacts[j + 1];
                tempContacts[j + 1] = temp;
            }
        }
    }
    printf("\n\t\t-------> LIST OF CONTACTS <------\n");
    printf("====================================================================\n");
    printf("|%-5s|%-20s|%-15s|%-30s\n","S.NO", "NAME", "PHONE.NO", "MAIL ID");
    printf("====================================================================\n");

    for (int i = 0; i < count; i++)
    {
        printf("|%-5d|%-20s|%-15s|%-30s\n",i + 1,tempContacts[i].name,tempContacts[i].phone,tempContacts[i].mail);
    }
    printf("====================================================================\n");
}

void initialize(AddressBook *addressBook)
{
    addressBook->countcontact = 0;
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook);
    exit(EXIT_SUCCESS);
}

void createContact(AddressBook *addressBook)
{
    char name[50], phone[20], mail[50];
    int ret;

    do
    {
        printf("Enter the Name: ");
        scanf(" %[^\n]", name);

        ret = validname(name);

        if (ret == 1)
        {
            strcpy(addressBook->contacts[addressBook->countcontact].name,
                   name);
        }
        else
        {
            printf("---> Invalid Name <---\n");
        }
    } while (ret == 0);

    do
    {
        printf("Enter the Phone Number: ");
        scanf(" %[^\n]", phone);

        ret = validphone(addressBook, phone);

        if (ret == 1)
        {
            strcpy(addressBook->contacts[addressBook->countcontact].phone,phone);
        }
        else if (ret == 0)
        {
            printf("---> Invalid Phone Number <---\n");
        }
        else
        {
            printf("---> Phone already exists <---\n");
        }
    } while (ret != 1);

    do
    {
        printf("Enter the Mail ID: ");
        scanf(" %[^\n]", mail);

        ret = validmail(addressBook, mail);

        if (ret == 1)
        {
            strcpy(addressBook->contacts[addressBook->countcontact].mail,mail);
        }
        else if (ret == 0)
        {
            printf("---> Invalid Mail ID <---\n");
        }
        else
        {
            printf("---> Mail already exists <---\n");
        }
    } while (ret != 1);
    addressBook->countcontact++;
    printf("---> Contact added successfully <---\n");
}

int searchContact(AddressBook *addressBook, int mode)
{
    int choice;
    char search[50];
    int count = addressBook->countcontact;
    if (count == 0)
    {
        printf("---> NO contacts are saved <---\n");
        return -1;
    }
    printf("\n-------> Search Contact Menu <-------\n");
    printf("1) By Name\n");
    printf("2) By Phone Number\n");
    printf("3) By Mail ID\n");
    printf("4) Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
        case 1:
            printf("Enter name: ");
            break;

        case 2:
            printf("Enter phone number: ");
            break;

        case 3:
            printf("Enter mail ID: ");
            break;

        case 4:
            return -1;

        default:
            printf("---> Invalid choice <---\n");
            return -1;
    }

    scanf(" %[^\n]", search);

    int matchCount = 0;
    int matchIndices[count];

    for (int i = 0; i < count; i++)
    {
        int match = 0;

        if (choice == 1)
        {
            match =(strcasecmp(addressBook->contacts[i].name,search) == 0);
        }
        else if (choice == 2)
        {
            match =(strcmp(addressBook->contacts[i].phone,search) == 0);
        }
        else if (choice == 3)
        {
            match =(strcasecmp(addressBook->contacts[i].mail,search) == 0);
        }
        if (match)
        {
            matchIndices[matchCount++] = i;
            if (matchCount == 1)
            {
                printf("\n====================================================================\n");
                printf("|%-5s|%-20s|%-15s|%-30s\n","S.NO", "NAME", "PHONE.NO", "MAIL ID");
                printf("====================================================================\n");
            }
            printf("|%-5d|%-20s|%-15s|%-30s|\n",matchCount,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].mail);
        }
    }

    if (matchCount == 0)
    {
        printf("---> No matching contact found <---\n");
        return -1;
    }
    printf("====================================================================\n");
    if (mode == SEARCH_ONLY)
    {
        return -1;
    }
    if (matchCount == 1)
    {
        return matchIndices[0];
    }
    int sno;
    printf("Enter S.NO to select contact: ");
    scanf("%d", &sno);
    if (sno > 0 && sno <= matchCount)
    {
        return matchIndices[sno - 1];
    }
    return -1;
}

void editContact(AddressBook *addressBook)
{
    int targetIndex =searchContact(addressBook, SELECT_ONE);
    if (targetIndex == -1)
    {
        printf("---> Contact not found <---\n");
        return;
    }
    int editChoice;
    char newDetail[100];
    int ret;

    printf("\n1) Edit Name\n");
    printf("2) Edit Phone\n");
    printf("3) Edit Mail\n");
    printf("4) Cancel\n");

    printf("Enter your choice: ");
    scanf("%d", &editChoice);
    getchar();

    switch (editChoice)
    {
        case 1:
            do
            {
                printf("Enter new Name: ");
                scanf(" %[^\n]", newDetail);
                ret = validname(newDetail);
                if (ret == 1)
                {
                    strcpy(addressBook->contacts[targetIndex].name,newDetail);
                    printf("---> Name updated successfully <---\n");
                }
                else
                {
                    printf("---> Invalid Name <---\n");
                }
            } while (ret != 1);

            break;

        case 2:

            do
            {
                printf("Enter new Phone: ");
                scanf(" %[^\n]", newDetail);
                ret = validphone(addressBook, newDetail);
                if (ret == 1)
                {
                    strcpy(addressBook->contacts[targetIndex].phone,newDetail);
                    printf("---> Phone updated successfully <---\n");
                }
                else if (ret == 0)
                {
                    printf("---> Invalid Phone Number <---\n");
                }
                else
                {
                    printf("---> Phone already exists <---\n");
                }

            } while (ret != 1);

            break;

        case 3:

            do
            {
                printf("Enter new Mail: ");
                scanf(" %[^\n]", newDetail);

                ret = validmail(addressBook, newDetail);

                if (ret == 1)
                {
                    strcpy(addressBook->contacts[targetIndex].mail,
                           newDetail);

                    printf("---> Mail updated successfully <---\n");
                }
                else if (ret == 0)
                {
                    printf("---> Invalid Mail ID <---\n");
                }
                else
                {
                    printf("---> Mail already exists <---\n");
                }

            } while (ret != 1);

            break;

        case 4:
            return;

        default:
            printf("---> Invalid choice <---\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
    if (addressBook->countcontact == 0)
    {
        printf("---> No contacts saved <---\n");
        return;
    }

    int targetIndex =
        searchContact(addressBook, SELECT_ONE);

    if (targetIndex == -1)
    {
        printf("---> Contact not found <---\n");
        return;
    }

    char option;

    printf("\nAre you sure you want to delete this contact? (Y/N): ");
    scanf(" %c", &option);

    if (option == 'Y' || option == 'y')
    {
        for (int i = targetIndex;
             i < addressBook->countcontact - 1;
             i++)
        {
            addressBook->contacts[i] =
                addressBook->contacts[i + 1];
        }

        addressBook->countcontact--;

        printf("---> Contact Deleted Successfully <---\n");
    }
    else
    {
        printf("---> Delete Cancelled <---\n");
    }
}

int validname(char name[])
{
    if (name[0] == '\0')
    {
        return 0;
    }

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!(isalpha(name[i]) || isspace(name[i])))
        {
            return 0;
        }
    }

    return 1;
}

int validphone(AddressBook *addressBook, char phone[])
{
    int count = addressBook->countcontact;

    if (strlen(phone) != 10)
    {
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        if (!isdigit(phone[i]))
        {
            return 0;
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(addressBook->contacts[i].phone,
                   phone) == 0)
        {
            return -1;
        }
    }

    return 1;
}

int validmail(AddressBook *addressBook, char mail[])
{
    int count = addressBook->countcontact;

    int len = strlen(mail);

    if (strchr(mail, '@') == NULL)
    {
        return 0;
    }

    if (len < 4 ||
        strcmp(mail + len - 4, ".com") != 0)
    {
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(addressBook->contacts[i].mail,
                   mail) == 0)
        {
            return -1;
        }
    }
    return 1;
}