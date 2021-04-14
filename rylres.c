#include<stdio.h>
#include "rylres.h"
#include<string.h>
#include"conio2.h"
#include<ctype.h>
#include<stdlib.h>
int enterchoice()
{
    int i;
    gotoxy(26,1);
    textcolor(BROWN);
    printf("RAILWAY RESERVATION  SYSTEM\n");
    for(i=0;i<80;i++)
          printf("-");
          textcolor(LIGHTCYAN);
     printf("\nSelect an option");
     printf("\n 1- View Trains\n 2- Book Tickets\n 3- View Ticket\n 4- Search Ticket No\n 5- View All Bookings\n 6- View All Train Bookings\n 7- Cancel Ticket\n 8- Cancel Train\n 9- Quit\n");
     int choice;
     printf("\nEnter the choice:");
     scanf("%d",&choice);
     return choice;
}

void add_trains()
{
        Train alltrains[4]={
              {"123","BPL","GWA",2100,1500},
              {"546","BPL","DEL",3500,2240},
              {"345","HBJ","AGR",1560,1135},
              {"896","HBJ","MUM",4500,3360},
        };
        FILE *fp=fopen("d:\\fileHP\\alltrains.txt","rb");
          if(fp==NULL)
        {
            fp=fopen("d:\\fileHP\\alltrains.txt","wb");
            fwrite(alltrains,4*sizeof(Train),1,fp);
          //  printf("File Saved ");

        }
        else
        //printf("File Already Present ");
        fclose(fp);
}

void view_trains()
    {
        int i;
        textcolor(LIGHTMAGENTA);
        printf("TRAIN NO.\t FROM\t TO\t  FIRST AC FAIR\t SECOND AC FAIR\n");
        for(i=1;i<=80;i++)
            printf("-");
        FILE *fp=fopen("d:\\fileHP\\alltrains.txt","rb");
        Train tr;
        while(fread(&tr,sizeof(tr),1,fp)==1)
        {
            textcolor(LIGHTCYAN);
            printf("\n%s\t\t  %s\t %s\t\t %d\t\t %d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
        }

        printf("\n\n\n\n");
        textcolor(WHITE);
        printf("PRESS any key to go back to the main screen");
        textcolor(YELLOW);
        fclose(fp);
        _getch();
        clrscr();
    }

int check_train_no(char* trainno)
    {
       FILE *fp=fopen("d:\\fileHP\\alltrains.txt","rb");

       Train tr;
       while(fread(&tr,sizeof(tr),1,fp)==1)
       {
           if(strcmp(tr.train_no,trainno)==0)
             {
                 fclose(fp);
                 return 1;
             }
        }
       fclose(fp);
       return 0;
    }
    int check_mob_no(char *m)
   {

       if(strlen(m)!=10)
          return 0;
      while(*m!='\0')
           {
                if(isdigit(*m)==0)
                    return 0;
                m++;
           }
       return 1;
   }


Passenger * get_passenger_details()
{
            clrscr();
            char *pos;
             int t;
            gotoxy(65,1);
            textcolor(GREEN);
            printf("Press 0 to Exit");
            textcolor(CYAN);
            gotoxy(1,1);
            static Passenger psn;
            printf("Enter Passenger's name:");
            fflush(stdin);
            fgets(psn.p_name,20,stdin);
            pos=strchr(psn.p_name,'\n');
           *pos='\0';
            if(psn.p_name[0]=='0')
              return NULL;
            gotoxy(1,2);
            printf("Enter gender(M/F):");
            while(1)
            {
             scanf("%c",&psn.gender);
             fflush(stdin);
             if(psn.gender=='0')
                return NULL;
             else if(psn.gender=='M'||psn.gender=='F')
                        break;
              else
             {
                 gotoxy(1,25);
                 textcolor(RED);
                 printf("Error! Gender should be M or F (in uppercase)");
                 getch();
                 gotoxy(19,2);
                 printf("\t\t\t\t\t\t\t\t");
                 textcolor(CYAN);
                 gotoxy(19,2);
             }
        }
          gotoxy(1,25);
          printf("\t\t\t\t\t\t\t");
          fflush(stdin);
          gotoxy(1,3);
          printf("Enter the train number:");
          fflush(stdin);
          fgets(psn.train_no,20,stdin);
          pos=strchr(psn.train_no,'\n');
         *pos='\0';
          while(1)
          {
          t=check_train_no(psn.train_no);
          if(strcmp(psn.train_no,"0")==0)
            return NULL;
          else if(t==1)
                 break;
          else
          {
          gotoxy(1,25);
          textcolor(RED);
          printf("Error! Invalid train No");
          getch();
          gotoxy(24,3);
          printf("\t\t\t\t\t\t\t");
          textcolor(CYAN);
          gotoxy(24,3);
          fflush(stdin);
          fgets(psn.train_no,20,stdin);
          char *pos;
          pos=strchr(psn.train_no,'\n');
          *pos='\0';
          fflush(stdin);
        }
     }
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        fflush(stdin);
        gotoxy(1,4);
        printf("Enter the traveling class (First AC - F and Second AC- S):");
        while(1)
        {
        scanf("%c",&psn.p_class);
         if(psn.p_class=='0')
               return NULL;
         else if(psn.p_class =='F' || psn.p_class=='S')
                break;
         else
            {
                 gotoxy(1,25);
                 textcolor(RED);
                 printf("Error! Invalid class Use F/S");
                 getch();
                 gotoxy(59,4);
                 printf("\t\t\t\t\t\t\t\t");
                 textcolor(CYAN);
                 gotoxy(59,4);
                 textcolor(CYAN);
            }
         }
            gotoxy(1,25);
            printf("\t\t\t\t");
            fflush(stdin);
            gotoxy(1,5);
            printf("Enter the address:");
            fgets(psn.address,20,stdin);
            pos=strchr(psn.address,'\n');
           *pos='\0';
            if(psn.address[0]=='0')
                return NULL;
            gotoxy(1,6);
            printf("Enter the age: ");
            while(1)
            {
            scanf("%d",&psn.age);
             if(psn.age==0)
                return NULL;
             else if(psn.age<1)
             {
                 gotoxy(1,25);
                 textcolor(RED);
                 printf("Error! Age cannot be negative");
                 getch();
                 gotoxy(15,6);
                 printf("\t\t\t\t\t\t\t\t");
                 textcolor(CYAN);
                 gotoxy(15,6);
             }
             else
                break;
            }

            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,7);
            printf("Enter the mobile no:");
            while(1)
            {
            fflush(stdin);
            fgets(psn.mob_no,12,stdin);
            pos=strchr(psn.mob_no,'\n');
           *pos='\0';
            int x=check_mob_no(psn.mob_no) ;
            if(strcmp(psn.mob_no,"0")==0)
                 return NULL;
            if(x==1)
                break;
               fflush(stdin);
               textcolor(LIGHTRED);
               gotoxy(1,25);
               printf("Error! Invalid Mobile No");
               getch();
               gotoxy(21,7);
               printf("\t\t\t\t\t\t\t\t");
               gotoxy(21,7);
               textcolor(CYAN);
        }
            clrscr();
            return &psn;
}

int get_booked_ticket_count(char *train_no,char c)
{
    FILE*fp=fopen("d:\\fileHP\\allbookings.txt","rb");
    if(fp==NULL)
        return 0;
    Passenger p;
    int count=0;
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if((strcmp(p.train_no,train_no)==0)&&(p.p_class==c))
            count++;
    }
    fclose(fp);
    return count;
}

int last_ticket_no()
{

    FILE*fp=fopen("d:\\fileHP\\allbookings.txt","rb");
    if(fp==NULL)
        return 0;
    Passenger p;
    fseek(fp,-1*sizeof(p),SEEK_END);
    fread(&p,sizeof(p),1,fp);
    fclose(fp);
    return p.ticket_no;
}

int book_ticket(Passenger p)
{
    int x=get_booked_ticket_count(p.train_no,p.p_class);
    if(x==30)
    {
        textcolor(LIGHTRED);
        printf("All seats full in train %s in class %c",p.train_no,p.p_class);
        getch();
        textcolor(YELLOW);
        clrscr();
        return -1;
    }
    int y=last_ticket_no()+1;
    p.ticket_no=y;
    FILE *fp=fopen("d:\\fileHP\\allbookings.txt","ab");
    if(fp==NULL)
    {
        printf("File cannot be opened");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return y;
}


int accept_ticket_no()
{
    int ticket_no;
    gotoxy(66,1);
    textcolor(GREEN);
    printf("Press 0 to exit");
    textcolor(BROWN);
    gotoxy(1,1);
    printf("Enter a valid Ticket no:");
    while(1)
    {
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
          gotoxy(1,24);
          textcolor(RED);
          printf("Cancelling Input.....!");
          getch();
          gotoxy(1,27);
          printf("\t\t\t\t\t\t\t");
          gotoxy(1,27);
          textcolor(YELLOW);
          return 0;
        }
        else if(ticket_no<0)
        {
          gotoxy(1,25);
          textcolor(RED);
          printf("Error! ticket No cannot be negative!");
          getch();
          gotoxy(25,1);
          printf("\t\t\t\t\t\t\t\t");
          textcolor(YELLOW);
          gotoxy(25,1);
        }
        else
            break;
    }
        return ticket_no;
}

void view_ticket(int ticket_no)
{
    Passenger pr;
    int c=0;
    FILE *fp=fopen("d:\\fileHP\\allbookings.txt","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo Bookings Done Yet!");
        return ;
    }
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
       if(pr.ticket_no==ticket_no)
         {
             textcolor(LIGHTCYAN);
       printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS: %c\nADDRRESS: %s\nAGE: %d\nMOBILE NO: %s\nTICKET NO: %d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticket_no);
       printf("\n\n");
       c=1;
       break;
         }
    }
   if(c==0)
   {
        textcolor(LIGHTRED);
        printf("\nNo details of ticket no %d found!",ticket_no);
    }
   fclose(fp);
}

char* accept_mob_no()
{
    static char mob_no[12];
    char *pos;
    gotoxy(66,1);
    textcolor(GREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(MAGENTA);
    printf("Enter a valid mobile number:");
    while(1)
    {
            fflush(stdin);
            fgets(mob_no,13,stdin);
            pos=strchr(mob_no,'\n');
           *pos='\0';
            int x=check_mob_no(mob_no) ;
            if(strcmp(mob_no,"0")==0)
                 {
                     printf("\t\t\t\t\t\t\t\t");
                     gotoxy(1,25);
                     textcolor(LIGHTRED);
                     gotoxy(1,25);
                     printf("Cancelling Input......... ");
                     textcolor(MAGENTA);
                     getch();
                     return NULL;
                 }
            if(x==1)
            {
                gotoxy(1,25);
                printf("\t\t\t\t\t\t\t\t");
                break;
            }
               fflush(stdin);
               textcolor(LIGHTRED);
               gotoxy(1,25);
               printf("Error! Invalid Mobile No");
               getch();
               gotoxy(29,1);
               printf("\t\t\t\t\t");
               gotoxy(29,1);
               textcolor(MAGENTA);
    }
    return mob_no;
}

int* get_ticket_no(char *p_mob_no)
{
    Passenger ps;
    int count =0;
    FILE *fp=fopen("d:\\fileHP\\allbookings.txt","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        printf("Sorry file cannot be opened!");
        return NULL;
    }
    while(fread(&ps,sizeof(ps),1,fp)==1)
    {
        if(strcmp(ps.mob_no,p_mob_no)==0)
           {
               count++;
           }
    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
        rewind(fp);
        int *p=(int*)malloc((count+1)*sizeof(int));
        int i=0;
        while(fread(&ps,sizeof(ps),1,fp)==1)
    {
      if(strcmp(ps.mob_no,p_mob_no)==0)
      {
          *(p+i)=ps.ticket_no;
            i++;
      }
    }
      *(p+i)=-1;
       fclose(fp);
       return p;
}


void view_all_tickets(char *pmob_no,int * pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",pmob_no);
        textcolor(WHITE);
        printf("\n\nPress any key to go back to the main screen");
        textcolor(YELLOW);
        getch();
        return;
    }

    clrscr();
    gotoxy(1,1);
    textcolor(BROWN);
    printf("\nFollowing are tickets booked for mobile no %s",pmob_no);
    int i;
    textcolor(LIGHTBLUE);
    printf("\n\nTicket NO\n");
    textcolor(BROWN);
    for(int i=1;i<=80;i++)
    printf("-");
    for(i=0;*(pticket_no+i)!=-1;i++)
    {
        textcolor(RED);
        printf("\n%d",*(pticket_no+i));
    }
    textcolor(WHITE);
    printf("\n\nPress any key to go back to the main screen");
    textcolor(YELLOW);
    getch();
    free(pticket_no);
}


char* accept_train_no()
{
          static  char train_no[20];
          char *pos;
          int t;
          gotoxy(66,1);
          textcolor(GREEN);
          printf("Press 0 to exit");
          textcolor(YELLOW);
          gotoxy(1,1);
          printf("Enter the train no:");
          while(1)
          {
          fflush(stdin);
          fgets(train_no,20,stdin);
          pos=strchr(train_no,'\n');
         *pos='\0';
          t=check_train_no(train_no);
          if(strcmp(train_no,"0")==0)
            {
                printf("\t\t\t\t\t\t\t\t");
                gotoxy(1,25);
                textcolor(RED);
                printf("Cancelling Input.........");
                textcolor(YELLOW);
                getch();
                return NULL;
            }
           if(t==1)
                 break;
          gotoxy(1,25);
          textcolor(RED);
          printf("Error! Invalid train No");
          getch();
          gotoxy(20,1);
          printf("\t\t\t\t");
          textcolor(YELLOW);
          gotoxy(20,1);
          fflush(stdin);
      }
      clrscr();
      return train_no;
}

void view_all_bookings()
{
    Passenger p;
    FILE *fp=fopen("d:\\fileHP\\allbookings.txt","rb");
    if(fp==NULL)
    {
        printf("File is not present!");
        return;
    }
   textcolor(CYAN);
   printf("TICKET NO\t CLASS\t NAME\t\t GENDER\t AGE\t MOBILE NO\n");
   for(int i=1;i<=80;i++)
       printf("-");
    textcolor(YELLOW);
    int row=3;
    while(fread(&p,sizeof(p),1,fp)==1)
    {
            printf("%d\t\t%c\t%s",p.ticket_no,p.p_class,p.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",p.gender,p.age,p.mob_no);
            row++;
    }
    textcolor(WHITE);
    printf("\n\n\nPress any key to back to the main Screen");
    getch();
    clrscr();
    textcolor(YELLOW);
    fclose(fp);
}


void view_booking(char* train_no)
{
    Passenger p;
    int c=0;
    FILE *fp=fopen("d:\\fileHP\\allbookings.txt","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("No bookings done yet !");
        return ;
    }
    textcolor(LIGHTMAGENTA);
    printf("TICKET NO\t CLASS\t NAME\t\t GENDER\t AGE\t MOBILE NO\n");
    for(int i=1;i<=80;i++)
        printf("-");
    int row=3;
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if(strcmp(p.train_no,train_no)==0)
        {
            textcolor(BROWN);
            printf("%d\t\t%c\t%s",p.ticket_no,p.p_class,p.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",p.gender,p.age,p.mob_no);
            row++;
            c=1;
        }
    }
    if(c==0)
    {
        textcolor(RED);
        printf("\n\n\nNo details of the train %s found",train_no);
        fclose(fp);
        getch();
        return;
    }
    textcolor(WHITE);
    printf("\n\n\nPress any key to back to the main Screen");
    getch();
    textcolor(YELLOW);
    fclose(fp);
}


int cancel_ticket(int pticket_no)
{
    Passenger pr;
    int found=0;
    FILE *fp=fopen("d:\\fileHP\\allbookings.txt","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        printf("No Bookings Done Yet!");
        return -1;
    }
    FILE *ft=fopen("d:\\fileHP\\temp.txt","wb");
    if(ft==NULL)
    {
        printf("Not created Yet!");
        return 1;
    }
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticket_no==pticket_no)
        {
            found=1;
        }
        else
         {
             fwrite(&pr,sizeof(pr),1,ft);
         }
    }
    fclose(fp);
    fclose(ft);
    if(found==0)
        remove("d:\\fileHP\\temp.txt");
    else
    {
        remove("d:\\fileHP\\allbookings.txt");
        rename("d:\\fileHP\\temp.txt","d:\\fileHP\\allbookings.txt");
    }
    return found;
}

int cancel_train(char* train_no)
{
    Passenger pr;
    int found=0;
    FILE *fp=fopen("d:\\fileHP\\allbookings.txt","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        printf("No Trains availableYet!");
        textcolor(YELLOW);
        return -1;
    }
    FILE *ft=fopen("d:\\fileHP\\temp.txt","wb");
    if(ft==NULL)
    {
        printf("Not created Yet!");
        return 1;
    }
     while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
            found=1;
        else
             fwrite(&pr,sizeof(pr),1,ft);
    }
    fclose(fp);
    fclose(ft);
    if(found==0)
        remove("d:\\fileHP\\temp.txt");
    else
    {
        remove("d:\\fileHP\\allbookings.txt");
        rename("d:\\fileHP\\temp.txt","d:\\fileHP\\allbookings.txt");
    }
    return found;
}
