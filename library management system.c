#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include<ctype.h>  //for time
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
#define RETURNTIME 15

void main_window(void);
void Password();
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void addbooks(void);
  void deletebooks(void);
void editbooks(void);
void viewstudent(void);
 void searchbooks(void);
  void addstudent(void);
void issuebooks(void);
void displayrecords(void);
 void viewooks(void);
void closeapplication(void);
                                 int getdatas();
                                 int checkstudentid(int);
                                 
                                 int  getdata(); //to make easy in add book function used add book information store in get data
                                  
								 int  checkid(int);                                

                     int t(void);

                    void issuedrecord();
                    
                    void returnfunc();
                    int s;
       char findbook;
       char password[10]={"pass"};


                    
                    struct meroDate//it's for date
                 {
                 	int mm,dd,yy;
                 };

                 struct books
                 {
                  int id,stid;
                  char stname[20];
                  char st[20];
                  char name[20];
                  char author[20];
                  char cat[20];
                  int quantity;
                  float Price;
                  int count;
                  
                  int rackno;
                  struct meroDate issued;//for issued date

                  struct meroDate duedate;
                 };
struct books a;
	struct student
		{
  		char name[30],facul[30],sem[30];
  		int unq_id;
		};
		struct student p;
FILE *fp,*ft,*fs,*fl;
int s;
char findbook;//it's for find book
                                     //@@@@@@@@    for  Anamation    Windows  
                                               
											   
											      void SetColor(int ForgC)//for anamation color
            {
                                                  WORD wColor;
                                                 ///We will need this handle to get the current background attribute
                                                 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                                                 CONSOLE_SCREEN_BUFFER_INFO csbi;

                                                  ///We use csbi for the wAttributes word.
                                                    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
                   {
                                                      ///Mask out all but the background attribute, and add in the forgournd color
                                                   wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
                                                   SetConsoleTextAttribute(hStdOut, wColor);
                    }
                                                     return;
           }

                                                  void ClearConsoleToColors(int ForgC, int BackC)
{
                                             WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
                                             ///Get the handle to the current output buffer...
                                                HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                                                 ///This is used to reset the carat/cursor to the top left.
                                                COORD coord = {0, 0};
                                               ///A return value... indicating how many chars were written
                                               ///   not used but we need to capture this since it will be
                                                ///   written anyway (passing NULL causes an access violation).
                                                DWORD count;
                                         ///This is a structure containing all of the console info
                                          /// it is used here to find the size of the console.
                                           CONSOLE_SCREEN_BUFFER_INFO csbi;
                                           ///Here we will set the current color
                                      SetConsoleTextAttribute(hStdOut, wColor);
                                     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                                        ///This fills the buffer with a given character (in this case 32=space).
                                      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
                                           FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                                         ///This will set our cursor position for the next print statement.
                                           SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

                                        void SetColorAndBackground(int ForgC, int BackC)
                    {
                                       WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
                                   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
                                  return;
                        }

                             COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
                             
                             
                             
                            void gotoxy(int x, int y){
                                    coord.X = x; coord.Y = y; /// X and Y coordinates
                              SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                                     }

                            
                         void clearWindow(){
                              int i,j;
                           for(i = 37; i < 78; i++){
                              for(j = 7; j < 25; j++){
                            gotoxy(i,j);printf(" ");
           }
                }
                                return;
                   }

                          




// NOW MAIN WINDOWS IS OPEN



void main_window()
{
	int i;
	//loaderanim();
	
	system("cls");			//    textbackground(13);
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	//    show_mouse();
	SetColor(20);
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Add students");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Issue Books");
	gotoxy(20,15);
	
	printf("\xDB\xDB\xDB\xDB\xB2 6. Display records");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Edit Book's Record");
	gotoxy(20,19);
	printf("\xDB\xDB\xDB\xDB\xB2 8. Close Application");
	gotoxy(20,21);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,22);
	t();
	SetColor(17);
	gotoxy(20,23);
	
	printf("Enter your choice:");
	switch(getch())
	{
		case '1':
			addbooks();
		break;
			case '2':
		deletebooks();
		break;
		case '3':
			searchbooks();
		break;
		case '4':
			addstudent();
			case '5':
			issuebooks();
		break;
		case '6':
			displayrecords();
		break;
		case '7':
			editbooks();
		break;
		case '8':
			system("cls");
			
			printf("\n\n\t\t\tLibrary Management System");
			
			printf("\n\t\t\tMini Project in C");
			
			printf("\n\t\t\tis brought to you by");
			
			printf("\n\t\t\tCode with a team :");
			printf("\n\t\t\t1.Bp Bhatta");
			printf("\n\t\t\t2.Roshan Deuba");
			printf("\n\t\t\t3.Bhagrathi Joshi");
			printf("\n\n\n\t\tExiting in 3 second...........>");
			//flushall();
			Sleep(3000);
			exit(0);
			break;
		default:
			printf("\n\aWrong Entry!!Please re-entered correct option");
			if(getch())
			main_window();
	
	}
}


void addbooks(void)
{
	

        
	   system ("cls");
	   	{
	gotoxy(20,5);
printf("Press ESC to return to main menu");
gotoxy(20,8);
printf("press any key to continue");

}

if(getch()==27) //allow only use of esc
main_window();
else
goto a;

		 a:	
		 system("cls");
	   
        fp=fopen("library.txt","ab+");
        if (getdata()==1)
         {
         	
            fseek(fp,0,SEEK_END);
            fwrite(&a,sizeof(a),1,fp);
             fclose(fp);
          
         gotoxy(10,18);
          printf("The record is sucessfully saved");
          gotoxy(10,20);
		  printf(" Save any more record ? \n\t\t\t\t\t(y/n)");
            if (getch()=='n')
              main_window();
              else
              system("cls");
                 addbooks();
        
        
     
        
              }
              	
			
 
               }
void deletebooks(void)
{
	a:
	system("cls");
	
	int bn;
		gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Delete Book \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	
	SetColor(20);
	gotoxy(10,6);
		printf(" Enter the book no. which you want to delete:   ");
				scanf("%d",&bn);
				
	fp=fopen("library.txt","rb");
	ft=fopen("newook.txt","wb");
	if(fp==NULL || ft==NULL)
	{
		printf("\n\aFile Operation failed\a");
	}
	else
	{
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(bn==a.id)
			{
				continue;
			}
			else
			{
				fwrite(&a,sizeof(a),1,ft);
			}
		}
		fclose(fp);
		fclose(ft);
		remove("library.txt");
		rename("newook.txt","library.txt");
		printf("\n\nThe record has been successfully deleted from the data file");
	}
	printf("\n Do you want to delete any more(y/n)");
	if(getch()=='y')
    goto	a;
	else
	main_window();
}
	


void searchbooks(void) //3.Searchbooks 
{
	system("cls");
	int d;
	printf("\t\t\t\xDB\xDB\xDB\xB2\xB2 Search Books\xDB\xDB\xDB\xB2\xB2 ");
	printf("\n\xDB\xDB\xDB\xB2 1. Enter by ID ");
	
	printf("\n\n\xDB\xDB\xDB\xB2 2. Enter by Name");
	printf("\n\n\xDB\xDB\xDB\xB2 3. Back");
	printf("\n\nEnter a choice:");
	fp=fopen("library.txt","rb+");
	rewind(fp);
	switch(getch())
	{
		case '1':
			{
			
			system("cls");
			gotoxy(23,2);
			printf("\xDB\xDB\xDB\xB2\xB2 Search by Book ID.\xDB\xDB\xDB\xB2\xB2 ");
			gotoxy(5,4);
			printf("Enter a book id:");
			scanf("%d",&d);
		
			
			printf("\nSearching................................");
			getch();
				system("cls");
			
			while(fread(&a,sizeof(a),1,fp)==1)
			{
			if	(a.id==d)
			
			{
				Sleep(2);
				
				printf("\n\tThe Book is availale");
				printf("\n\n\t ID:%d",a.id);
				printf("\n\t Name:%s",a.name);
				printf("\n\t Author:%s",a.author);
				printf("\n\t price:%f",a.Price);
				printf("\n\t Rack no:%d",a.rackno);
				findbook='t';
				
			}
			}
					if(findbook!='t') 
		      	{
			        system("cls");
		        	printf("\n\n\tThe book is not availale");
	              	}
			     	printf("\n\n\t Try another search(y/n)");
			     	if(getch()=='y')
			     	searchbooks();
			     	else
			     	main_window();
			     	break;
			
	            	}
			        case '2':
			        	{
			        	
			        	system("cls");
			        	char s[15];
			        	printf("\xDB\xDB\xDB\xB2\xB2 Search Book by Name:\xDB\xDB\xDB\xB2\xB2 ");
			        	printf("\n Enter Book  Name: ");
			        	fflush(stdin);
			        	gets(s);
			        	printf("Searching...");
			        	int d=0;
			        	while(fread(&a,sizeof(a),1,fp)==1)
			        	{
			        	if(strcmpi(a.name,(s))==0)////comparison both past and new value (if there is  record found) 
			        		{
			        			
			        		     	printf("\nThe Book is availale ");
			        				printf("\n ID:%d",a.id);
			                       	printf("\n Name:%s",a.name);
			                    	printf("\n Author:%s",a.author);
			                     	printf("\n price:%f",a.Price);
			                    	printf("\n Rack no:%d",a.rackno);
			        			
			        		}
			        	}
			        		if(strcmp(a.name,(s))!=0)///comparison both past and new value (if there is no record found) 
			        		
			        		{
			        			printf("\n The Book is not avaible");
			        		}
			        		
			        	
			        	
			        	
			        		printf("\n Try another search(y/n)");
			     	if(getch()=='y')
			     	searchbooks();
			     	else
			     	main_window();
			     	break;
			        }
			    
			       case '3': 
				   main_window();	
			        default:
				if(getch())
					 searchbooks ();
						
			        	
				        }
				        fclose(fp);
				        }
			
		 void addstudent()

      {
        system ("cls");
	   	{
	gotoxy(20,5);
printf("Press ESC to return to main menu");
gotoxy(20,8);
printf("press any key to continue");

}

if(getch()==27) //allow only use of esc
main_window();
else
goto a;

		 a:	
		 system("cls");


        fl=fopen("stu.txt","ab+");

    		
    		       if (getdatas()==1)
         {
         	
            fseek(fl,0,SEEK_END);

      
      
      
      fwrite(&p,sizeof(p),1,fl);
      gotoxy(20,16);
      fclose(fl);
      
  		printf("New student's information has been Added Successfully...");
      gotoxy(15,18);fflush(stdin);
    	printf("\aWant to add another record.........( y / n ) :-  ");

      fflush(stdin);
      char tryagain;
      tryagain=getche();
      if(tryagain=='y'||tryagain=='Y')
      {
      getche();
     	addstudent();
      }
      else
      main_window();
      
      getche();
  }
      }
void displayrecords()
{
	system("cls");
	gotoxy(20,3);
	        	printf("\xDB\xDB\xDB\xB2\xB2 Display Records:\xDB\xDB\xDB\xB2\xB2 ");
	        	gotoxy(5,6);
	printf("\xDB\xDB\xDB\xB2\xB2 1.Display Books records");
	gotoxy(5,8);
	
	printf("\xDB\xDB\xDB\xB2\xB2 2.Display Students records");
	gotoxy(5,10);
	printf("\xDB\xDB\xDB\xB2\xB2 3.Back");
	gotoxy(5,12);
	SetColor(20);
		
	printf("Enter your choice:");
	SetColor(17);
	switch(getch())
	{
		case '1': 
		viewooks();
		break;
		case '2':
		viewstudent();
		break;
		case '3':
		main_window();
		break;
		default:
			printf("\n wrong choic");
			displayrecords();
}
		}
			 void viewstudent()

{
	      int i=0,j,count=0;
      system("cls");
      
      fl=fopen("stu.txt","ab+");
      if(fl==NULL)
      printf("\n\n\n\tThe file is Empty");
      else
      {
      
      gotoxy(15,1);
      printf("!!!!!!!!!!Student's INFO!!!!!!!!!!");
      gotoxy(2,2);
      printf("  NAME                    Unique ID         PROGRAM         SEMESTER");
      j=4;
      while(fread(&p,sizeof(p),1,fl)==1)
       {
       gotoxy(3,j);
        printf("%s",p.name);
        gotoxy(33,j);
      printf("%d",p.unq_id);
      gotoxy(48,j);
      printf("%s",p.facul);
      gotoxy(65,j);
      printf("%s",p.sem);
      printf("\n");
      j++;
      count++;
      gotoxy(3,25);
printf("Total Students= %d",count);

        }
		gotoxy(35,25); printf("press any key to return on menu");
        }
      fclose(fl);
      getch();
      displayrecords();

}	
void issuebooks(void)
{
	int t;
	
	system("cls");
	gotoxy(10,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Issue Section\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(10,5);
printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book");
gotoxy(10,7);
printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book");
gotoxy(10,9);
printf("\xDB\xDB\xDB\xDb\xB2 3.  Remove Issued Book");
gotoxy(10,11);
printf("\xDB\xDB\xDB\xDb\xB2 4. Back");
gotoxy(10,14);
printf("Enter a Choice:");
	switch(getch())
	{
		case '1':

				{
				system("cls");
				int r,m;
					fp=fopen("library.txt","rb+");
				fl=fopen("stu.txt","rb+");
				
				fs=fopen("issue.txt","ab+");
				   
				gotoxy(25,2);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Issue a Book section\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				
				gotoxy(30,5);
				printf("\n\t\t\t Enter a Book ID:");
				scanf("%d",&t);
					 while(fread(&a,sizeof(a),1,fs)==1)
			
					if(a.stid==t)
					{
					printf("\n\t\t\t Issued by another students");
					getch();
                    main_window();
                  	}
			    	if(checkid(t)==0)
					{
							SetColor(20);
					gotoxy(3,8);
						
					printf("The Book %d is available",a.id);
					gotoxy(3,10);
				
					printf("The name of book is %s ",a.name);
					SetColor(17);
					gotoxy(32,8);
				
						
				   printf("Again enter same book id ");
					scanf("%d",&a.stid);
				
				    gotoxy(35,12);
				    printf("student id:");
					scanf("%d",&r);
					
					if(checkstudentid(r)==0)
					{
			
			        SetColor(20);
					gotoxy(3,15);
					printf("Student Name: %s",p.name);
					gotoxy(3,16);
					printf("faculty: %s",p.facul);
					SetColor(17);
					gotoxy(35,15);
					printf("Enter same student name :");
					 fflush(stdin);
					gets(a.stname);
					gotoxy(35,16);
					
					printf("Enter same faculty :");
					 fflush(stdin);
					gets(a.cat);
					   
					  int t; //for time
                      {
                       time_t t;
                       time(&t);
                       SetColor(20);
                        gotoxy(10,18);
                        printf("Date and time\n:  %s\t\n\t\t\n",ctime(&t));

                       } 
                       SetColor(17);
					   
					gotoxy(35,19);
				   
					printf("Enter this date for Issue \n\t\t\t\t\t\t=(dd-mm-yy)");
					scanf("%d%d%d",&a.issued.dd,&a.issued.mm,&a.issued.yy);
					gotoxy(25,21);
					printf("The book of ID %d is issued",a.id);
					gotoxy(25,22);
					printf("There is %d unissued Books in library",a.quantity=0);
					
					
					a.duedate.dd=a.issued.dd+RETURNTIME; //FOR RETURN DATE   
					a.duedate.mm=a.issued.mm;
					a.duedate.yy=a.issued.yy;
					if(a.duedate.dd>30)
					{ 
					a.duedate.mm+=a.duedate.dd/30;
					a.duedate.dd-=30;
					}
					if(a.duedate.mm>12)
					{
						a.duedate.yy+=a.duedate.mm/12;
						a.duedate.mm-=12;
					}
					gotoxy(25,24);
					printf("To be return in %d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
					fseek(fs,sizeof(a),SEEK_END);
                fwrite(&a,sizeof(a),1,fs);
                
					
					
					fclose(fs);
					
					
		
			
		      	}
		      }
		      	if(checkstudentid(r)!=0)
		      	{
		      		printf("\n Wrond id");
		      	}
				if(checkid(t)!=0)
				{
					
					printf("\n No record found");
				}
				
				printf("\nIssue any more(y/n):");
				if(getch()=='y')
				issuebooks();
				else
				main_window();
			
				fclose(fp);
				fclose(fl);
					break;
			
			}
			
			case '2'://issue book list
		{
system("cls");
int j=4;
 SetColor(17);

printf("*******************************Issued book list*******************************\n");
gotoxy(2,2);
printf("STUDENT NAME    CATEGORY   Book ID    BOOK NAME       ISSUED DATE  RETURN DATE");
fs=fopen("issue.txt","rb");
while(fread(&a,sizeof(a),1,fs)==1)
{
	 SetColor(20);

gotoxy(2,j);
printf("%s",a.stname);
gotoxy(20,j);
printf("%s",a.cat);
gotoxy(30,j);
printf("%d",a.id);
gotoxy(36,j);
printf("%s",a.name);
gotoxy(55,j);
printf("%d%d%d",a.issued.dd,a.issued.mm,a.issued.yy );
gotoxy(69,j);
printf("%d%d%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
gotoxy(50,25);
j++;

}
fclose(fs);
gotoxy(1,25);
returnfunc();
}
break;	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				
		  case '3'://removed issued book  by id
		    
					  
					
		a:			
					
					{
	system("cls");
	FILE *fg;
	
	int b;
		gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Remove Book \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	
	SetColor(20);
	gotoxy(10,8);
		printf("\n Enter the book id which you want to remove from issue:   ");
				scanf("%d",&b);
				
	fs=fopen("issue.txt","rb+");
	fg=fopen("temp.txt","wb+");
	if(fs==NULL || fg==NULL)
	{
		printf("\nFile Operation failed");
	}
	else
	{
		while(fread(&a,sizeof(a),1,fs)==1)
		{
			if(b==a.id)
			{
				continue;
	 	}
			else
			{
				fwrite(&a,sizeof(a),1,fg);
			}
		}
		fclose(fs);
		fclose(fg);
		remove("issue.txt");
		rename("temp.txt","issue.txt");
		printf("\n\nThe issued Book has been Successfully removed.....");
	}
	gotoxy(20,20);
	printf("Do you want to remove any more : (y/n)");
	if(getch()=='y')
	goto a;
	else
	main_window();
}
	



							  case '4':
		  	main_window();
		  	
	}
}





void viewooks(void)

{
int i=0,j,count=0;
system("cls");
gotoxy(1,1);
printf("*********************************Book List*****************************");
gotoxy(2,2);
printf("ID     BOOK NAME             AUTHOR              PRICE        RackNo ");
j=4;
fp=fopen("library.txt","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{


gotoxy(3,j);
printf("%d",a.id);
gotoxy(10,j);
printf("%s",a.name);
gotoxy(32,j);
printf("%s",a.author);
gotoxy(52,j);


printf("%.2f",a.Price);
gotoxy(67,j);

printf("%d",a.rackno);
printf("\n\n");
j++;
count++;
}
gotoxy(3,25);
printf("Total Books = %d",count);
fclose(fp);
gotoxy(35,25);
returnfunc();
}
void editbooks(void)  //edit information aout book
{
system("cls");
int c=0;
int d,e;
gotoxy(20,4);
printf("****Edit Books Section****");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Book Id to be edited:");
scanf("%d",&d);
fp=fopen("library.txt","rb+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(checkid(d)==0)
{
gotoxy(15,7);
printf("The book is availble");
gotoxy(15,8);
printf("The Book ID:%d",a.id);
gotoxy(15,9);
printf("Book name :%s",a.name);
gotoxy(15,10);
printf("Author:%s",a.author);
gotoxy(15,11);
printf("Price:%f",a.Price);
gotoxy(15,12);
printf("Rack:%d",a.rackno);


gotoxy(15,13);
printf("Enter new name:");scanf("%s",a.name);
gotoxy(15,14);
printf("Enter new Author:");scanf("%s",a.author);
gotoxy(15,15);
printf("Enter new price:");scanf("%f",&a.Price);
gotoxy(15,16);
printf("Enter new rackno:");scanf("%d",&a.rackno);
gotoxy(15,17);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,12);
printf("No record found");
}
}
gotoxy(15,20);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
returnfunc();
}
void returnfunc(void)
{
{
	gotoxy(20,20);
printf(" Press ESC to return to main menu");

}
a:
if(getch()==27) //allow only use of esc
main_window();
else
goto a;
}



int getdata()
{


	int t,i;

gotoxy(25,2); printf("\xB2\xB2\xB2\xB2 Add Books\xB2\xB2\xB2\xB2");

gotoxy(20,4);printf("Enter the Information Below");
gotoxy(20,5);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(55,5);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(55,6);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(55,7);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(55,8);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(55,9);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(55,10);printf("\xB2");
gotoxy(20,12);
printf("\xB2");gotoxy(55,11);printf("\xB2");
gotoxy(20,13);printf("\xB2");gotoxy(55,12);printf("\xB2");
gotoxy(20,13);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


gotoxy(31,5);

gotoxy(21,6);
printf("Book ID:\t");
gotoxy(30,6);
scanf("%d",&t);
if(checkid(t) == 0)
{
gotoxy(21,20);
printf("\aThe book id already exists\a");
getch();
main_window();
return 0;
}
a.id=t;
gotoxy(21,7);
printf("Book Name:");gotoxy(33,7);
fflush(stdin);
gets(a.name);
gotoxy(21,8);
printf("Author:");gotoxy(30,8);
fflush(stdin);
gets(a.author);
gotoxy(21,9);






printf("Price:");gotoxy(28,9);
scanf("%f",&a.Price);
gotoxy(21,10);
printf("Rack No:");gotoxy(30,10);
scanf("%d",&a.rackno);
return 1;
	
	
	
	
	
}
int getdatas()
{
int r,i;

gotoxy(25,2); printf("\xB2\xB2\xB2\xB2 Add Students\xB2\xB2\xB2\xB2");

gotoxy(20,4);printf("Enter the Information Below");

gotoxy(21,6);
printf("Student ID:\t");
gotoxy(32,6);
scanf("%d",&r);
if(checkstudentid(r) == 0)
{
gotoxy(21,13);
printf("\aThe student id already exists\a");
getch();
main_window();
return 0;
}
p.unq_id=r;
gotoxy(4,11);
      printf("STUDENT NAME");
   
      gotoxy(46,11);
    	printf("PROGRAM");
      gotoxy(67,11);
      printf("SEMESTER");
      gotoxy(5,13);
       fflush(stdin);
      gets(p.name);
    
       fflush(stdin);
      
      gotoxy(47,13);
       fflush(stdin);
      gets(p.facul);
      gotoxy(68,13);
      fflush(stdin);
      gets(p.sem);
      fflush(stdin);
      
return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}
int checkstudentid(int r)
{
	rewind(fl);
	while(fread(&p,sizeof(p),1,fl)==1)
	if(p.unq_id==r)
	return 0;
	return 1;
}

int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

}


	void main(){
    ClearConsoleToColors(17,15);
    SetConsoleTitle("Welcome- Library management system");
    
    Password();
   // main_window();
    //use_pass_field();
    
    getch();
}
void Password(void) //for password option
{

   system("cls");
   char d[25]=" Password Protected";
   char ch,pass[10];
   int i=0,j;
   //textbackground(WHITE);
   //textcolor(RED);
    gotoxy(33,15);
   printf("Developed by:");
   gotoxy(33,16);
   printf("Roshan Deuba");
   gotoxy(33,17);
   printf("Balkrishna Bhatta");
   gotoxy(33,18);
   printf("Bagrathi Joshi");
   gotoxy(25,2);
   printf("DHANGADHI ENGINEERING COLLEGE (NAST) ");
   gotoxy(25,4);
   printf("Library Management System");
    gotoxy(10,6);
    for(j=0;j<20;j++)
    {
    delay(50);
    SetColor(80);
    printf("\xB2");
    
    }
    for(j=0;j<20;j++)
   {
   delay(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
   delay(50);
    SetColor(80);
   printf("\xB2");
   }
   gotoxy(10,10);
   gotoxy(15,8);
   
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	gotoxy(15,10);
	//textcolor(BLINK);
	printf("Password matched");
	gotoxy(15,11);
	
	printf("Press enter any key to continue.....");
	getch();
	
	system("cls");
	gotoxy(17,11);
	printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM");
	gotoxy(17,15);
	printf("Press enter any key to continue.....");
	getch();
	main_window();
   }
   else
   {
	 gotoxy(25,20);
	 SetColor(20);
	 printf("\aWarning!! Incorrect Password\a");
	 SetColor(17);
	 getch();
	 Password();
   }
}








