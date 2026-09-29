#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
void validateName(AddressBook *addressBook);
void validatePhoneNumber(AddressBook *addressBook);
void validateEmail(AddressBook *addressBook);
void sortName(AddressBook *addressBook);
void sortPhone(AddressBook *addressBook);
void sortEmail(AddressBook *addressBook);
void editPhone(AddressBook *addressBook);
void editName(AddressBook *addressBook);
void editEmail(AddressBook *addressBook,int index);



#endif
