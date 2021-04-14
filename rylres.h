#ifndef RYLRES_H_INCLUDED
#define RYLRES_H_INCLUDED

struct Train
{
    char train_no[20];
    char from[20];
    char to[20];
    int fac_fare;
    int sac_fare;
};

struct Passenger
{
   char p_name[20];
   char gender;
   char train_no[20];
   char address[20];
   int age;
   int ticket_no;
   char mob_no[12];
   char p_class;
};

typedef struct Passenger Passenger;
typedef struct Train  Train;

int enterchoice();
void add_trains();
void view_trains();
void view_all_bookings();
void view_booking(char*);
int cancel_train(char*);
int accept_ticket_no();

Passenger * get_passenger_details();
int check_train_no(char *);
int get_booked_ticket_count(char *,char);
int last_ticket_no();
int book_ticket(Passenger);

char* accept_mob_no();
int check_mob_no(char *);
int* get_ticket_no(char *);
void view_all_tickets(char*,int*);

char*accept_train_no();
void view_ticket(int);

int cancel_ticket(int);
#endif // RYLRES_H_INCLUDED
