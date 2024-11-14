void printList(){
printf("The input Applicants list is: \n");
printf( "%-20s %-20s %-20s %-20s %-20s %-20s %-20s \n" , "id","Name","Education", "Experience","Major" , "GPA" , "State");
int m=0;
while(numOfLines>m){
printf( "%-20d %-20s %-20s %-20d %-20s %-20.1f %-20s \n",list[m].id ,list[m].applicant , list[m].education ,list[m].Experience , list[m].major , list[m].GPA , list[m].State);
m++;
}
printf( "-------------\n" ) ; 
printf("The candidate's list is : \n" ) ; 
printf( "%-20s %-20s %-20s %-20s %-20s %-20s\n" , "id","applicant","Education", "Major" , "Points" , "State");
m=0;
while(numOfLines>m){
int r=strcmp(list[m].State , "candidate");
int n=strcmp( list[m].State , "Assigned");
if( r == 0 || n == 0 ) {
printf( "%-20d %-20s %-20s %-20s %-20.2f %-20s \n", list[m].id , list[m].applicant , list[m].education ,list[m].major , list[m].Points , list[m].State);
}
m++;}
printf( "-------------\n" ) ; 
printf( "The Assigned Applicant is : \n" ) ; 
m=0:
while(numOfLines>m) { 
int c=strcmp( list[m].State , "Assigned"):
if( c ) { 
printf( "%-20d %-20s %-20s %-20s %-20.2f %-20s \n",list[m].id , list[m].applicant , list[m].education , list[m].major , list[m].Points , list[m].State);
 break; 
 }
 m++;
}}
//just agbgfgbb