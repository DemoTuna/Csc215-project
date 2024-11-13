#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void addApplicant();
void calculatePoints();
void setApplicantState(char* MajorList);
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

int numOfApplicant = 0 ;

struct Applicant *list ;


int main(){
 





    return 0 ;
}
void  addApplicant(){
        FILE *File1;
File1= fopen("Applicants.txt","r");
if (File1){
 int i;
 do{
    i=getc(File1);
    if (i=='\n')
    numOfApplicant++;
 }while((i!= EOF));
 numOfApplicant=numOfApplicant-2;
fclose(File1);
}
else 
    printf("The file  %s can not open #Error \n ","Applicants.txt");

//**********************************
    FILE *ApplicantFile;
ApplicantFile= fopen("Applicants.txt","r");
int i;
list=( struct Applicant *)calloc(numOfApplicant,sizeof(struct Applicant));
   if(ApplicantFile) {
    char line1[100];
    char line2[100];

   fgets(line1,sizeof(line1),ApplicantFile);
    fgets(line2,sizeof(line2),ApplicantFile);

    for(i=0;i<numOfApplicant;i++){
        fscanf(ApplicantFile,"%d %s %s %d %s %f %s ",&list[i].id,list[i].applicant,list[i].education,&list[i].Experience,list[i].major,&list[i].GPA,list[i].State);
        list[i].Points=0;
            }
    fclose(ApplicantFile);
   }
   else {
    printf("The file  %s can not open #Error \n ","Applicants.txt");
   }

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



void writeAssignedApplicants(){

FILE *Fpo = fopen("Output_Applicants.txt","w");
if(Fpo == NULL){
printf("Something went wrong with opining the file!!");
return; }

int i;

fprintf(Fpo , "The input applicants list is:\n");
fprintf(Fpo , " %-10s %-10s  %-10s %-10s %-10s %-10s  %-10s\n " ,"id", "Name" , "Education" , "Experience", "Major" , "GPA" , "State" );
for(i = 0 ;i < numOfApplicant ; i++){
    if(strcmp(list[i].State ,"Assigned") == 0)
        fprintf(Fpo,"%-10d %-10s %-10s %-10d %-10s %-10.1f %-10s\n",&list[i].id , list[i].applicant ,list[i].education , &list[i].Experience ,list[i].major , &list[i].GPA , list[i].State );
    else
        fprintf(Fpo,"%-10d %-10s %-10s %-10d %-10s %-10.1f %-10s\n",&list[i].id , list[i].applicant ,list[i].education , &list[i].Experience ,list[i].major , &list[i].GPA , "OWL" );
}

fprintf(Fpo , "\n----------\n");

fprintf(Fpo , "The Candidate's list is:\n");
fprintf(Fpo , " %-10s %-10s  %-10s %-10s %-10s %-10s  %-10s\n " ,"id", "Applicant" , "Education" , "Major" , "Points" , "State" );
for(i = 0 ;i < numOfApplicant ; i++){
    if(strcmp(list[i].State ,"Assigned") == 0 || strcmp(list[i].State ,"Candidate") == 0 )
    fprintf(Fpo,"%-10d %-10s %-10s %-10s %-10.2f %-10s\n",&list[i].id , list[i].applicant ,list[i].education ,list[i].major , &list[i].Points, list[i].State );
}

fprintf(Fpo , "\n----------\n");

fprintf(Fpo , "Assigned Applicant is:\n");
for(i = 0 ;i < numOfApplicant ; i++){
    if(strcmp(list[i].State ,"Assigned") == 0){
    fprintf(Fpo,"%-10d %-10s %-10s %-10s  %-10.2f %-10s\n",&list[i].id , list[i].applicant ,list[i].education ,list[i].major , &list[i].Points, list[i].State );
    break; }
}

}


void printList(){
printf("The input Applicants list is: \n");
printf( "%-20s %-20s %-20s %-20s %-20s %-20s %-20s \n" , "id","Name","Education", "Experience","Major" , "GPA" , "State");
int m=0;
while(numOfApplicant>m){
printf( "%-20d %-20s %-20s %-20d %-20s %-20.1f %-20s \n",list[m].id ,list[m].applicant , list[m].education ,list[m].Experience , list[m].major , list[m].GPA , list[m].State);
m++;
}
printf( "-------------\n" ) ; 
printf("The candidate's list is : \n" ) ; 
printf( "%-20s %-20s %-20s %-20s %-20s %-20s\n" , "id","applicant","Education", "Major" , "Points" , "State");
m=0;
while(numOfApplicant>m){
int r=strcmp(list[m].State , "candidate");
int n=strcmp( list[m].State , "Assigned");
if( r == 0 || n == 0 ) {
printf( "%-20d %-20s %-20s %-20s %-20.2f %-20s \n", list[m].id , list[m].applicant , list[m].education ,list[m].major , list[m].Points , list[m].State);
}
m++;}
printf( "-------------\n" ) ; 
printf( "The Assigned Applicant is : \n" ) ; 
m=0;
while(numOfApplicant>m) { 
int c=strcmp( list[m].State , "Assigned");
if( c ) { 
printf( "%-20d %-20s %-20s %-20s %-20.2f %-20s \n",list[m].id , list[m].applicant , list[m].education , list[m].major , list[m].Points , list[m].State);
 break; 
 }
 m++;
}

}