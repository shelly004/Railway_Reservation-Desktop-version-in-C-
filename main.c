#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rylres.h"
int main()
{
     add_trains();
     textcolor(LIGHTMAGENTA);
     Passenger *ptr;
     int op;
     int *tarr;
     char *pmob_no;
     int ticket_no;
     char* ptrain_no;
     int cancel;
     while(1)
     {
         op=enterchoice();
         if(op==9)
            break;
         else
         {
             switch(op)
             {
             case 1:
                clrscr();
                view_trains();
                break;
             case 2:
                ptr=get_passenger_details();
                if(ptr==NULL)
                    {
                        clrscr();
                        textcolor(BROWN);
                        printf("Thankyou for Visiting us!\nBooking cancelled Successfully ");
                        getch();
                        gotoxy(1,25);
                        printf("\t\t\t\t\t\t");
                        textcolor(YELLOW);
                        clrscr();
                    }
              else
                    {
                        ticket_no=book_ticket(*ptr);
                        if(ticket_no==-1)
                           {
                               textcolor(RED);
                               printf("Sorry! Booking failed!");
                               textcolor(WHITE);
                               printf("\n\n\n\nPress any key to go back to the main screen");
                               getch();
                               textcolor(YELLOW);
                               clrscr();
                           }
                        else{
                            textcolor(MAGENTA);
                            printf("Ticket Successfully Booked!");
                            textcolor(WHITE);
                            printf("\n\n\n\nPress any key to go back to the main screen");
                            getch();
                            textcolor(YELLOW);
                            clrscr();
                        }
                    }
               break;
             case 3:
                 clrscr();
                  ticket_no=accept_ticket_no();
                  if(ticket_no!=0)
                  view_ticket(ticket_no);
                  textcolor(WHITE);
                  printf("\nPress any key to go back to the main screen");
                  textcolor(YELLOW);
                  getch();
                  clrscr();
                  break;
             case 4:
                 clrscr();
                 pmob_no=accept_mob_no();
                 if(pmob_no!=NULL)
                 {
                    tarr =get_ticket_no(pmob_no);
                    view_all_tickets(pmob_no,tarr);
                 }
                 clrscr();
                break;
             case 5:
                 clrscr();
                 view_all_bookings();
                break;
             case 6:
                 clrscr();
                 ptrain_no=accept_train_no();
                 if(ptrain_no!=NULL)
                        view_booking(ptrain_no);
                clrscr();
                break;
             case 7:
                 clrscr();
                 ticket_no=accept_ticket_no();
                 if(ticket_no!=0)
                 {
                    cancel=cancel_ticket(ticket_no);
                    if(cancel==0)
                       {
                           textcolor(RED);
                           printf("\n\nSorry! No tickets booked against the ticket number");
                       }
                    else
                        printf("Ticket successfully cancelled");
                 }
                  textcolor(WHITE);
                  printf("\n\nPress any key to go back to the main screen");
                  textcolor(YELLOW);
                getch();
                clrscr();
                break;
             case 8:
                 clrscr();
                 ptrain_no=accept_train_no();
                  if(ptrain_no!=NULL)
                  {
                     cancel=cancel_train(ptrain_no);
                      if(cancel==0)
                        printf("Sorry! No such train number exist");
                    else
                        printf("Train successfully cancelled!");
                  }
                getch();
                clrscr();
                break;
             default:
                 textcolor(LIGHTRED);
                 printf("\nWrong choice...Please try again\n\n");
                 textcolor(YELLOW);
                 getch();
                 clrscr();
             }
         }
     }
    return 0;
}
