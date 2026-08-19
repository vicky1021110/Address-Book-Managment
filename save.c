#include "contact.h"

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contact.csv", "r");

    if (fptr == NULL)
    {
        return;
    }

    fscanf(fptr, "#%d\n", &addressBook->countcontact);

    for (int i = 0; i < addressBook->countcontact; i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].mail);
    }
    fclose(fptr);
}

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contact.csv", "w");

    if (fptr == NULL)
    {
        printf("File open error\n");
        return;
    }

    fprintf(fptr, "#%d\n", addressBook->countcontact);

    for (int i = 0; i < addressBook->countcontact; i++)
    {
        fprintf(fptr,
                "%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].mail);
    }

    fclose(fptr);
}

