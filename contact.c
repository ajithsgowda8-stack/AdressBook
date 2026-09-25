#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>
// #include "populate.h"

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
    validateName(addressBook);
    validatePhoneNumber(addressBook);
    validateEmail(addressBook);
    
    
}


// validate name
void validateName(AddressBook *addressBook)
{
    int i=addressBook->contactCount;
    int valid;
    
    do
    {
        
        valid=1;
        scanf(" %[^\n]", addressBook->contacts[i].name);
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
                continue;
            }
        }
        
        for(int j=0;addressBook->contacts[i].name[j]!='\0';j++)
        {
            if(!isalnum(addressBook->contacts[i].name[j])&& addressBook->contacts[i].name[j+1]!=' ')
            {
                printf("should not contain space between character. Please enter again: ");
                valid=0;
                continue;
            }
        }
        

    }while(!valid);

    if(valid==1)

    {
        printf("valid name\n");
    }
}
    // printf("Enter phone number: ");
    // scanf("%[^\n]", addressBook->contacts[i].phone);
    // int phoneLength = strlen(addressBook->contacts[i].phone);
    

    // validate phone number
    void validatePhoneNumber(AddressBook *addressBook)
{
    int i=addressBook->contactCount;
    int valid;
    do
    {
        // printf("Enter phone number: ");
        scanf(" %[^\n]", addressBook->contacts[i].phone);
        int phoneLength = strlen(addressBook->contacts[i].phone);
        valid=1;
        if (phoneLength < 10||phoneLength>10) {
            printf("Invalid phone number length. ");
            valid=0;
            // scanf("%[^\n]", addressBook->contacts[i].phone);
            continue;
        }
        for(int j = 0; j < phoneLength; j++) {
            if (!isdigit(addressBook->contacts[i].phone[j])) {
                printf("Invalid phone number. Please enter a valid phone number ");
                valid=0;
                // scanf("%s", addressBook->contacts[i].phone);
                continue;
            }
        }
        if(addressBook->contacts[i].phone[0]<'6'||addressBook->contacts[i].phone[0]>'9')
            {
                printf("Invalid phone number. Please enter a valid phone number: ");
                valid=0;
                // scanf("%s", addressBook->contacts[i].phone);
                continue;
            }
        
        
    }while(!valid);
    if(valid==1)

    {
        printf("valid phone number\n");
    }
}
void validateEmail(AddressBook *addressBook)
{
    int i=addressBook->contactCount;
    int valid;
    printf("Enter email id: ");
    do{
        scanf(" %[^\n]", addressBook->contacts[i].email);
        int e_length=strlen(addressBook->contacts[i].email);
        valid=1;
        for(int j=0;j<e_length;j++)
        {
            if(isupper(addressBook->contacts[i].email[j]))
            {
                printf("Invalid email. Please enter a valid email: ");
                valid=0;
                continue;
            }
        }   
        
        // if(addressBook->Contacts[i].email[e_length-4]!='.'||addressBook->Contacts[i].email[e_length-3]!='c'||addressBook->Contacts[i].email[e_length-2]=='o'||addressBook->Contacts[i].email[e_length-1]=='m')
        char *rstc=strstr(addressBook->contacts[i].email,".com");
        if(rstc==NULL)
        {
            printf("email does not contain .com . Please enter a valid email: ");
            valid=0;
            continue;
        }
        char *rsta=strchr(addressBook->contacts[i].email,'@');
        if(rsta==NULL)
        {
            printf("email does not contain @. Please enter a valid email: ");
            valid=0;
            continue;
        }
        if(addressBook->contacts[i].email[0]=='@')
        {
            printf("first letter of email should not contain @. Please enter a valid email: ");
            valid=0;
            continue;
        }
        if(rstc <= rsta + 1)
        {
            printf("There must be a character between @ and .com.please enter a valid email: ");
            valid = 0;
            continue;
        }
        for(int j=0;j<i;j++)
        {
            if(strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email)==0)
            {
                printf("email already exists. Please enter a different email: ");
                valid=0;
                continue;
            }
        }
    }while(!valid);
    if(valid==1)
    {
        printf("valid email");
    }
    

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
