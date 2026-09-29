#include <stdio.h>
#include<stdlib.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr=fopen("contacts.csv","w");
        // fprintf(fptr,"\n=========================CONTACT-LISTS================================\n");
        // fprintf(fptr,"----------------------------------------------------------------------\n");
        // fprintf(fptr,"%-10s %-20s %-30s %-40s\n","SN","name","phone_number","email");
        fprintf(fptr,"#%d\n",addressBook->contactCount);

        for(int i=0;i<addressBook->contactCount;i++)
        {
            fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        // fprintf(fptr,"------------------------------------------------------------------\n");
        fclose(fptr);
        
}


void loadContactsFromFile(AddressBook *addressBook) {
    FILE *lptr=fopen("contacts.csv","r");
    if(lptr==NULL)
    {
        printf("file doesnot contain any details.\n");
        // return 0;
    }
    else
    {
        fscanf(lptr,"#%d\n",&addressBook->contactCount);

        for(int i=0;i<addressBook->contactCount;i++)
        {
        fscanf(lptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        // addressBook->contactCount++;
        }
        fclose(lptr);
    }
}
