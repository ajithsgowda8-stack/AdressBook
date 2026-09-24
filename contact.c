#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the choosen criteria
    
    
   
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    if(addressBook->contactCount>=100)
    {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }
    int i=addressBook->contactCount;
    int valid;
    do
    {
        valid=1;
        scanf("%[^\n]", addressBook->contacts[i].name);
        if(strlen(addressBook->contacts[i].name)<2)
        {
            printf("Name should be at least 2 characters long. Please enter again: ");
            valid=0;
            continue;
        }
        for(int j=0;j<i;j++)
        {
            if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)==0)
            {
                printf("Name already exists. Please enter a different name: ");
                valid=0;
                break;
            }
        }
        
        for(int j=0;addressBook->contacts[i].name[j]!='\0';j++)
        {
            if(!isalnum(addressBook->contacts[i].name[j])&& addressBook->contacts[i].name[j+1]!=' ')
            {
                printf("Invalid character!. Please enter again: ");
                valid=0;
                break;
            }
        }
        

    }while(!valid);


    printf("Enter phone number: ");
    scanf("%[^\n]", addressBook->contacts[i].phone);
    int phoneLength = strlen(addressBook->contacts[i].phone);
    do
    {
        valid=1;
    if (phoneLength < 10 || phoneLength > 15) {
        printf("Invalid phone number length. Please enter a valid phone number: ");
        scanf("%[^\n]", addressBook->contacts[i].phone);
    }
    for(int j = 0; j < phoneLength; j++) {
        if (!isdigit(addressBook->contacts[i].phone[j])) {
            printf("Invalid phone number. Please enter a valid phone number: ");
            scanf("%s", addressBook->contacts[i].phone);
            break;
        }
    }
    for(int j=0;j<1;j++)
    {
        if(addressBook->contacts[i].phone[j]>=6||addressBook->contacts[i].phone[j]<=9)
        {
            printf("Invalid phone number. Please enter a valid phone number: ");
            scanf("%s", addressBook->contacts[i].phone);
            break;
        }
        
    }
}while(!valid);

    
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
