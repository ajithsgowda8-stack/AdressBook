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
<<<<<<< HEAD
<<<<<<< HEAD
   
=======
    char search[50];
    loadContactsFromFile(addressBook);
    int serial_no=1;
    int start_index=1;
    // int array[20];
    printf("Enter name or phone number: ");
    scanf("%s", search);
    for(int i=0;i<addressBook->contactCount;i++)
    {
       if(strcasestr(addressBook->contacts[i].name,search)!=NULL||strcasestr(addressBook->contacts[i].phone,search))
       {
            array[start_index]=i;
            printf("%d: %s\n",serial_no,addressBook->contacts[i].name);
            serial_no++;
            start_index++;
            
       }
       
       
    }
    // printf("%d",serial_no);
    if(serial_no==1)
    {
        printf("No possible contact");
    }
    
    
    printf("which one: ");
    int choice;
    scanf("%d",&choice);
    int index=array[choice];
    
    printf("Name  : %s\n", addressBook->contacts[index].name);
    printf("Phone : %s\n", addressBook->contacts[index].phone);
    printf("Email : %s\n", addressBook->contacts[index].email);
    
    return index;
>>>>>>> 91770d6 (first commit)
=======
   
>>>>>>> a4a7d88078546d0a04d37fc4a68914d8e9ba380f
        
}


void editContact(AddressBook *addressBook)
{
    
    
<<<<<<< HEAD
<<<<<<< HEAD
   
=======
   int index= searchContact(addressBook);
    
    char edit[20];
    
    printf("Which u want to edit: ");
    scanf("%s",edit);
    if(strcmp(edit,"phone")==0)
    {
        editPhone(addressBook);
    }
    else if(strcmp(edit,"name")==0)
    {
        editName(addressBook);
    }
    else if(strcmp(edit,"email")==0)
    {
        editEmail(addressBook,index);
    }
    else
    {
        printf("Invalid choice");
    }
    
    
>>>>>>> 91770d6 (first commit)
=======
   
>>>>>>> a4a7d88078546d0a04d37fc4a68914d8e9ba380f
    
}

void deleteContact(AddressBook *addressBook)
{
<<<<<<< HEAD
<<<<<<< HEAD
	
=======
	char search[50];
    loadContactsFromFile(addressBook);
    int serial_no=1;
    int start_index=1;
    // int array[20];
    printf("Enter name or phone number: ");
    scanf("%s", search);
    for(int i=0;i<addressBook->contactCount;i++)
    {
       if(strcasestr(addressBook->contacts[i].name,search)!=NULL||strcasestr(addressBook->contacts[i].phone,search))
       {
            array[start_index]=i;
            printf("%d: %s\n",serial_no,addressBook->contacts[i].name);
            serial_no++;
            start_index++;
            
       }
       
       
    }
    // printf("%d",serial_no);
    if(serial_no==1)
    {
        printf("No possible contact");
    }
    
    
    printf("which one: ");
    int choice;
    scanf("%d",&choice);
    int index=array[choice];
    for(int i=index;i<addressBook->contactCount-1;i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    addressBook->contactCount--;
    printf("deleted successfully");
   
>>>>>>> 91770d6 (first commit)
=======
	
>>>>>>> a4a7d88078546d0a04d37fc4a68914d8e9ba380f
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
<<<<<<< HEAD
<<<<<<< HEAD
=======

void editPhone(AddressBook *addressBook)
{
    char new_no[50];
        // int  choice;
        // int array[20];
    int index;//=array[choice];
        
            while(1)
            {
                int found=1;
            printf("Enter new phone number:");
            
            scanf("%s",new_no);
            // if(validatePhoneNumber(addressBook));
            // {
            //     strcpy(addressBook->contacts[index].phone, new_no);
            // printf("phone number copied");
            // }
            if(strlen(new_no)!=10)
            {
                printf("invlid length.Please enter valid number: ");
                found=0;
                continue;
                // break;
            }
            
            for(int i=0;i<10;i++)
            {
                if(!isdigit(new_no[i]))
                {
                    printf("digit only.Please enter valid number: ");
                    found=0;
                    continue;
                    // break;
                }
            }
            
            if(!found)
                continue;
            if(new_no[0] < '6' || new_no[0] > '9')
            {
                printf("Phone number should start with 6, 7, 8 or 9.\n");
                found=0;
                continue;
                // break;
            }
            
            
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(i!=index&&strcmp(addressBook->contacts[i].phone,new_no)==0)
                {
                    printf("Phone number is already exist,Enter vakid number: ");
                    found=0;
                    // continue;
                    break;
                    
                }
            }
            if(!found)
                continue;
                
            strcpy(addressBook->contacts[index].phone, new_no);
            printf("phone number copied");
            
            break;
            }
            
            
        }
            
        

void editName(AddressBook *addressBook)
{
        char new_name[50];
        // int  choice;
        // int array[20];
    int index;//=array[choice];
    
    
            
            while(1)
            {
                int found=1;
                printf("Enter new name: ");
                scanf("%s",new_name);

                if(strlen(new_name)<2)
                {
                    printf("Atleast 2 letter should be their,please enter valid name: ");
                    found=0;
                    continue;
                }
                if(found==1)
                {
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(i!=index&&strcasecmp(addressBook->contacts[i].name,new_name)==0)
                    {
                        printf("Name is already exist.Please enter valid name: ");
                        found=0;
                        break;
                    }
                }
                }
                if(found==1)
                {
                    for(int i=0;i<addressBook->contactCount;i++)
                    {
                        if(!isalnum(new_name[i])&&new_name[i]!=' ')
                    {
                        printf("No space between the letters.Please enter valid number: ");
                        found=0;
                        break;
                    }
                    }
                }
                if(found==1)
                {
                    strcpy(addressBook->contacts[index].name,new_name);
                    printf("name copied");
                    break;
                }
            }
        }
void editEmail(AddressBook *addressBook,int index)
{
    char new_email[20];
    // int index;
    int i=addressBook->contactCount;
    while(1)
    {
        int found=1;
        printf("Enter new email: ");
        scanf("%s",new_email);
        int e_length=strlen(new_email);
        for(int j=0;j<e_length;j++)
        {
            if(isupper((unsigned char)new_email[j]))
            {
                printf("Invalid email. Please enter a valid email: ");
                found=0;
                break;
            }
        } 
        if (!found)
            continue;  
        
        // if(addressBook->Contacts[i].email[e_length-4]!='.'||addressBook->Contacts[i].email[e_length-3]!='c'||addressBook->Contacts[i].email[e_length-2]=='o'||addressBook->Contacts[i].email[e_length-1]=='m')
        char *rstc=strstr(new_email,".com");
        if(rstc==NULL)
        {
            printf("email does not contain .com . Please enter a valid email: ");
            found=0;
            continue;
        }
        
        char *rsta=strchr(new_email,'@');
        if(rsta==NULL)
        {
            printf("email does not contain @. Please enter a valid email: ");
            found=0;
            continue;
        }
        if(new_email[0]=='@')
        {
            printf("first letter of email should not contain @. Please enter a valid email: ");
            found=0;
            continue;
        }
        if(rstc <= rsta + 1)
        {
            printf("There must be a character between @ and .com.please enter a valid email: ");
            found = 0;
            continue;
        }
        // check duplicate
        for(int j=0;j<i;j++)
        {
            if(j!=index&&strcmp(addressBook->contacts[j].email,new_email)==0)
            {
                printf("email already exists. Please enter a different email: ");
                found=0;
                break;
            }
        }
        if (!found)
            continue;
        if(found==1)
        {
            strcpy(addressBook->contacts[index].email,new_email);
            printf("email copied");
            break;
        }

    }
                

}
       
        

>>>>>>> 91770d6 (first commit)
=======
>>>>>>> a4a7d88078546d0a04d37fc4a68914d8e9ba380f
