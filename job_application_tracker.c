#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void addApplicant();
void calculatePoints();
void setApplicantState(char* majorRequirements);
void writeAssignedApplicants();
void printList();

struct Applicant{
    int id ;
    char applicant[20] ;
    char education[20] ;
    char major[5] ;
    int Experience ;
    float GPA ;
    float Points;
    char State[10] ;
  
};

int numOfApplicant ;

struct Applicant *list ;


void  addApplicant(){

FILE *File1;
File1= fopen("C:\\c programs\\Applicants1.txt","r");
if (File1 == NULL){
printf("The file  %s can not open #Error \n ","Applicants1.txt");
return  ;}

numOfApplicant = 0 ;

 int i;
 while( (i = getc(File1))  != EOF )
 if (i=='\n')
    numOfApplicant++;

 numOfApplicant=numOfApplicant-2;
fclose(File1);


FILE *ApplicantFile;
ApplicantFile= fopen("C:\\c programs\\Applicants1.txt","r");

if (ApplicantFile == NULL){
printf("The file  %s can not open #Error \n ","Applicants.txt");
return ; }

list=( struct Applicant *)calloc(numOfApplicant,sizeof(struct Applicant));

if(list==NULL){
printf("Memory allocation failed\n");
fclose(ApplicantFile);
return ; }

int k ;
for(k=0 ;k<=1 ; k++)
while ( (i = getc(ApplicantFile) ) != '\n' );
int c ;
    for(c=0; c < numOfApplicant;c++){
    fscanf(ApplicantFile,"%d %s %s %d %s %f %s ",&list[c].id,list[c].applicant,list[c].education,&list[c].Experience,list[c].major,&list[c].GPA,list[c].State);
    list[c].Points=0;
            }
    fclose(ApplicantFile);
    

}


void calculatePoints(){
int i;
for (i=0;i<numOfApplicant;i++){
    if(strcmp(list[i].education,"MSc")==0)
list[i].Points=list[i].GPA+list[i].Experience+10;
    else 
list[i].Points=list[i].GPA+list[i].Experience;

}
 
}

void setApplicantState(char* majorRequirements) {
    int i, assignedIndex = -1;
    float maxPoints = 0.0;
    
    for (i = 0; i < numOfApplicant; i++) {
        if (strstr(majorRequirements, list[i].major) != NULL) {
            strcpy(list[i].State, "candidate");

            if (list[i].Points > maxPoints) {
                maxPoints = list[i].Points;
                assignedIndex = i;
            }
        }
    }

    if (assignedIndex != -1) {
        strcpy(list[assignedIndex].State, "Assigned");
    }
    
    }

void writeAssignedApplicants(){   

FILE *Fpo = fopen("Output_Applicants.txt","w");
if (Fpo == NULL){
printf("something went wrong \n"); 
return ; 
}
 
fprintf(Fpo ,"The input Applicant list is : \n");
fprintf(Fpo , "%-15s %-20s %-20s %-20s %-15s %-15s %-20s \n" , "id","Name","Education", "Experience","Major" , "GPA" , "State");
 int i ; 
for( i = 0 ; i < numOfApplicant ; i++ ) { 
if( strcmp( list[i].State , "Assigned") == 0 )  

fprintf(Fpo , "%-15d %-20s %-20s %-20d %-15s %-15.1f %-20s \n",list[i].id , list[i].applicant , list[i].education ,list[i].Experience , (list[i].major) , list[i].GPA , list[i].State);
 else
 fprintf(Fpo , "%-15d %-20s %-20s %-20d %-15s %-15.1f %-20s \n",list[i].id , list[i].applicant , list[i].education ,list[i].Experience , (list[i].major) , list[i].GPA , "OWL");
}
 
fprintf(Fpo , "-------------\n" ) ; 
fprintf(Fpo , "The candidate's list is : \n" ) ; 
fprintf(Fpo , "%-15s %-20s %-20s %-20s %-15s %-20s\n" ,"id","applicant","Education", "Major" , "Points" , "State");
for( i = 0 ; i < numOfApplicant ; i++ ) { 
if( strcmp( list[i].State , "candidate") == 0  || strcmp( list[i].State , "Assigned") == 0 )  
fprintf(Fpo , "%-15d %-20s %-20s %-20s %-15.2f %-20s \n",(list[i].id) , list[i].applicant , list[i].education ,(list[i].major) , list[i].Points , list[i].State);
 
} 

fprintf(Fpo , "-------------\n" ) ; 
fprintf(Fpo , "The Assigned Applicant is  : \n" ) ; 
for( i = 0 ; i < numOfApplicant ; i++ ) { 
if( strcmp( list[i].State , "Assigned") == 0 ){  
fprintf(Fpo , "%-15d %-20s %-20s %-20s %-15.2f %-20s \n",(list[i].id) , list[i].applicant , list[i].education ,(list[i].major) , list[i].Points , list[i].State);
  break; 
  }
 
} 


fclose(Fpo);

}


void printList(){
  
printf("The input Applicants list is: \n");
printf( "%-20s %-20s %-20s %-20s %-20s %-20s %-20s \n" , "id","Name","Education", "Experience","Major" , "GPA" , "State");
int m;
for (m=0 ; m<numOfApplicant ; m++){
printf( "%-20d %-20s %-20s %-20d %-20s %-20.1f %-20s \n",list[m].id ,list[m].applicant , list[m].education ,list[m].Experience , list[m].major , list[m].GPA , list[m].State);
}

printf( "-------------\n" ) ; 
printf("The candidate's list is : \n" ) ; 
printf( "%-20s %-20s %-20s %-20s %-20s %-20s\n" , "id","applicant","Education", "Major" , "Points" , "State");

for (m=0 ; m<numOfApplicant ; m++){
if (strcmp(list[m].State , "candidate") == 0 || strcmp( list[m].State , "Assigned") == 0)
printf( "%-20d %-20s %-20s %-20s %-20.2f %-20s \n", list[m].id , list[m].applicant , list[m].education ,list[m].major , list[m].Points , list[m].State);
}

printf( "-------------\n" ) ; 
printf( "The Assigned Applicant is : \n" ) ; 

for (m=0 ; m < numOfApplicant ; m++){
if( strcmp( list[m].State , "Assigned") == 0){
printf( "%-20d %-20s %-20s %-20s %-20.2f %-20s \n", list[m].id , list[m].applicant , list[m].education , list[m].major , list[m].Points , list[m].State);
 break; }
 
 }
 
}
int main(){
 addApplicant();
 calculatePoints();
 setApplicantState("CSC,InS,SWE,CEN");
 writeAssignedApplicants();
 printList();
 free(list);
 return 0 ;

}

