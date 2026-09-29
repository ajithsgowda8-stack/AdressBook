#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include <ctype.h>
// #include "populate.h"
void listContacts(AddressBook *addressBook) 
{
    
    // Sort contacts based on the choosen criteria
    printf("On what basis contacts should sorted: ");
    char basis[1000];
    scanf("%19s",basis);
    if(strcmp(basis,"phone")==0)
    {
        sortPhone(addressBook);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }    
    else if(strcmp(basis,"name")==0)   
    {
        sortName(addressBook);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        
    }
    else if(strcmp(basis,"email")==0)
    {
        sortEmail(addressBook);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
       
            
    }
    else
    {
        printf("Invalid basis");
    }
}


void initialize(AddressBook *addressBook) {
    // addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(0); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("count= %d\n",addressBook->contactCount);
    if(addressBook->contactCount>=100)
    {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }
    
    
    
    validateName(addressBook);
    validatePhoneNumber(addressBook);
    validateEmail(addressBook);
    addressBook->contactCount++;
}
int array[20];


int searchContact(AddressBook *addressBook)
{
   
        
}


void editContact(AddressBook *addressBook)
{
    
    
   
    
}

void deleteContact(AddressBook *addressBook)
{
	
}

void validateName(AddressBook *addressBook)
{
    
    int i=addressBook->contactCount;
    
    int validn;
    printf("Enter name: ");
    
    do
    {
        
        validn=1;
        
        scanf(" %[^\n]", addressBook->contacts[i].name);
        if(strlen(addressBook->contacts[i].name)<2)
        {
            printf("Name should be at least 2 characters long. Please enter again: ");
            validn=0;
            continue;
        }
        for(int j=0;j<i;j++)
        {
            if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)==0)
            {
                printf("Name already exists. Please enter a different name: ");
                validn=0;
                continue;
            }
        }
        
        for(int j=0;addressBook->contacts[i].name[j]!='\0';j++)
        {
            if(!isalnum(addressBook->contacts[i].name[j])&& addressBook->contacts[i].name[j+1]!=' ')
            {
                printf("should not contain space between character. Please enter again: ");
                validn=0;
                continue;
            }
        }
        

    }while(!validn);

    if(validn==1)

    {
        printf("valid name\n");
    }
}
    
void validatePhoneNumber(AddressBook *addressBook)
{
    int i=addressBook->contactCount;
    int validp;
    printf("Enter phone number: ");
    do
    {
        // printf("Enter phone number: ");
        
        scanf(" %[^\n]", addressBook->contacts[i].phone);
        int phoneLength = strlen(addressBook->contacts[i].phone);
        validp=1;
        if (phoneLength < 10||phoneLength>10) {
            printf("Invalid phone number length. Please enter a valid phone number: ");
            validp=0;
            // scanf("%[^\n]", addressBook->contacts[i].phone);
            continue;
        }
        for(int j = 0; j < phoneLength; j++) {
            if (!isdigit(addressBook->contacts[i].phone[j])) {
                printf("No special character. Please enter a valid phone number: ");
                validp=0;
                // scanf("%s", addressBook->contacts[i].phone);
                continue;
            }
        }
        if(addressBook->contacts[i].phone[0]<'6'||addressBook->contacts[i].phone[0]>'9')
            {
                printf("first number should be between 6 and 9. Please enter a valid phone number: ");
                validp=0;
                // scanf("%s", addressBook->contacts[i].phone);
                continue;
            }
        for(int j=0;j<addressBook->contactCount;j++)
        {
            if(strcmp(addressBook->contacts[i].phone,addressBook->contacts[j].phone)==0)
            {
                printf("Phone number is already exit.Please enter valid phone number: ");
                validp=0;
                continue;
            }
        }
        
        
    }while(!validp);
    if(validp==1)

    {
        printf("valid phone number\n");
    }
}
void validateEmail(AddressBook *addressBook)
{
    int i=addressBook->contactCount;
    int valide;
    printf("Enter email id: ");
    do{
        scanf(" %[^\n]", addressBook->contacts[i].email);
        int e_length=strlen(addressBook->contacts[i].email);
        valide=1;
        for(int j=0;j<e_length;j++)
        {
            if(isupper(addressBook->contacts[i].email[j]))
            {
                printf("Invalid email. Please enter a valid email: ");
                valide=0;
                continue;
            }
        }   
        
        // if(addressBook->Contacts[i].email[e_length-4]!='.'||addressBook->Contacts[i].email[e_length-3]!='c'||addressBook->Contacts[i].email[e_length-2]=='o'||addressBook->Contacts[i].email[e_length-1]=='m')
        char *rstc=strstr(addressBook->contacts[i].email,".com");
        if(rstc==NULL)
        {
            printf("email does not contain .com . Please enter a valid email: ");
            valide=0;
            continue;
        }
        char *rsta=strchr(addressBook->contacts[i].email,'@');
        if(rsta==NULL)
        {
            printf("email does not contain @. Please enter a valid email: ");
            valide=0;
            continue;
        }
        if(addressBook->contacts[i].email[0]=='@')
        {
            printf("first letter of email should not contain @. Please enter a valid email: ");
            valide=0;
            continue;
        }
        if(rstc <= rsta + 1)
        {
            printf("There must be a character between @ and .com.please enter a valid email: ");
            valide = 0;
            continue;
        }
        for(int j=0;j<i;j++)
        {
            if(strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email)==0)
            {
                printf("email already exists. Please enter a different email: ");
                valide=0;
                continue;
            }
        }
    }while(!valide);
    if(valide==1)
    {
        printf("valid email");
    }
}
void sortName(AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount-1;i++)
    {
        for(int j=0;j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
            {
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
            // if(isupper(addressBook->contacts[j].name))
            // {
            //     Contact temp=addressBook->contacts[j];
            //     addressBook->contacts[j]=addressBook->contacts[j+1];
            //     addressBook->contacts[j+1]=temp;
            // }
            
        }
        
    } 
    
}
void sortPhone(AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount-1;i++)
    {
        for(int j=0;j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0)
            {
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
        }
    }
   
}
void sortEmail(AddressBook *addressBook)
{
    for(int i=0;i<addressBook->contactCount-1;i++)
    {
        for(int j=0;j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0)
            {
                Contact temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
            
        }
    }
    
}
