#ifndef CONTACT_H
#define CONTACT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SEARCH_ONLY 0
#define SELECT_ONE 1

typedef struct Contact
{
    char name[20];
    char phone[11];
    char mail[30];
} Contact;

typedef struct AddressBook
{
    Contact contacts[100];
    int countcontact;
} AddressBook;

void createContact(AddressBook *addressBook);
int validname(char name[]);
int validphone(AddressBook *addressBook, char phone[]);
int validmail(AddressBook *addressBook, char mail[]);
int searchContact(AddressBook *addressBook, int mode);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

#endif