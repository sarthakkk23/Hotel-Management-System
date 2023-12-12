#include<iostream>
#include<ctime> //To print current time
#include<string> //To take feedback
using namespace std;

//Declaring base class
class Hotel{
    public:
        long long int pno;
        char fname[30], lname[30];
        //Default Constructor
        Hotel(){
            cout<<"\n\t\t\t\t\t\tWELCOME TO HOTEL OBEROI'S!"<<endl;
            cout<<"\nOberoi's offers you a privileged experience combining comfort and conviviality."; 
            cout<<"\nWhether you are a backpacker, a solo traveler or with your family, our hotel \nwith top-of-the-range service will meet all your expectations.";
            cout<<"\nMore than just a hotel, Oberoi's offers you a place to live and meet people.\n";
            cout<<"\n\nYOUR FIRST NAME: ";
            cin>>fname;
            cout<<"\nYOUR LAST NAME: ";
            cin>>lname;
            cout<<"\nYOUR PHONE NUMBER: ";
            cin>>pno;
        }
};

//Declaring sub class
class Room:public Hotel{
    protected:
        int bill=0, taxbill;
    public:
        int pref, days, rno, n, c, d, ch, swap, key;
        int roomsavailable[15]={25,26,21,12,15,14,13,22,23,16,18,17,19,24,20};
        int roomsunavailable[11]={3,1,5,4,9,2,11,10,8,6,7};
        char choice[10];
        //Declaring functions   
        void displayrooms();
        void nrooms();
        void getpref();
        void detsin();
        void detdou();
        void detsui();
        void day();
        void costsin();
        void costdou();
        void costsui();
        void billcal();
        void choicee();
        void confirm();
        void allot();
        void bubsortav();
        void displayav();
        void insertionsortunav(int roomsunavailable[], int f);
};

//Function to display the type of rooms
void Room::displayrooms(){
    cout<<"\nThese are the rooms available with us: "<<endl;
    cout<<"1. Single"<<endl;
    cout<<"2. Double"<<endl;
    cout<<"3. Suite"<<endl;
}

//Funtion to take input of number of rooms the guest would like to book
void Room::nrooms(){
    cout<<"\nHow many rooms would you like to book? ";
    cin>>n;
}

//Function to take input of the number of days
void Room::day(){
    cout<<"\nKindly enter the number of days you want to stay for: ";
    cin>>days;
}

//Function to recieve guest's preference
void Room::getpref(){
    cout<<"\nKindly enter your preference: ";
    cin>>pref;
}

//function to display the details of a single bedroom
void Room::detsin(){
    cout<<"SINGLE BEDROOM\n";
    cout<<"COST PER NIGHT: 4000 Rupees\n";
}

//function to display the details of a double bedroom
void Room::detdou(){
    cout<<"DOUBLE BEDROOM\n";
    cout<<"COST PER NIGHT: 7000 Rupees\n";
}

//function to display the details of a suite
void Room::detsui(){
    cout<<"SUITE\n";
    cout<<"COST PER NIGHT: 15000 Rupees\n";
}

//Function to apply tax if the guest opted for a single bedroom
void Room::costsin(){
    bill=bill+4000;
}

//Function to apply tax if the guest opted for a double bedroom
void Room::costdou(){
    bill=bill+7000;
}

//Function to apply tax if the guest opted for a suite
void Room::costsui(){
    bill=bill+15000;
}

//Funtion to calculate bill
void Room::billcal(){
    bill=bill*days;
    cout<<"\nA 5%% tax will be levied on your total bill.";
    //Calculating tax
    taxbill=bill*5/100;
    //Applying tax
    bill=bill+taxbill;
    cout<<"\nA 10% discount has been applied on your total bill";
    //Calculating discount and applying discount
    bill=bill-(bill/10);
    cout<<"\nYour total bill is: $"<<bill;
}

//Function to confirm the stay
void Room::choicee(){
    cout<<"\nWOULD YOU LIKE TO CONFIRM YOUR STAY WITH US?(YES/NO): ";
    cin>>choice;
}

//Function to display the confirmation
void Room::confirm(){
    cout<<"CONGRATS!";
    cout<<"\nYOUR BOOKING HAS BEEN CONFIRMED FOR "<<days<<" DAY/DAYS";
    cout<<"\nTHE BOOKING IS UNDER THE NAME: "<<fname<<" "<<lname;
}

//Function to randomly allot a room between 0-21
void Room::allot(){
    srand(time(NULL));
    rno=rand()%21;
    //To make sure that the room isn't alloted already
    for(c=0;c>11;c++){
        if(rno==roomsunavailable[c]){
            rno++;
        }
    }
}

//Function to sort the array of available rooms using bubble sort
void Room::bubsortav(){
    //Bubble sort
    for(c=0; c<9; c++){
        for(d=0; d<9-c; d++){
            if(roomsavailable[d]>roomsavailable[d+1]){
                swap = roomsavailable[d];
                roomsavailable[d] = roomsavailable[d+1];
                roomsavailable[d+1] = swap;
                }
            }
        }
}

//Function to display the sorted array
void Room::displayav(){
    for(c=0; c<10; c++){
    cout<<roomsavailable[c]<<"  ";
    }
}

//Function to sort the array of unavailable rooms using insertion sort
void Room::insertionsortunav(int roomsunavailable[], int f){
    //Insertion sort
    for(c=0; c<11; c++){
            key=roomsunavailable[c];
            d=c-1;
            while(d>=0 && roomsunavailable[d] > key){
                roomsunavailable[d+1]=roomsunavailable[d];
                d=d-1;
            }
            roomsunavailable[d+1]=key;
        }
}

//Start of main function
int main(){
    int i, j, ch , roomnum, first, last, mid, f=11;
    char sorted[10];
    string fb;
    //Flag set to true for the while loop which is used later on
    bool flag=true, occ=false;
    
    //Generation of current date
    cout<<__DATE__<<endl; 

    //Declaring object
    Room guest; 

    //Starting a while loop
    while(flag=true){
        cout<<"\nWELCOME TO OUR HOTEL, KINDLY CHOOSE THE SERVICE YOU WANT TO PURSUE: ";
        cout<<"\n1. CHECK IN.";
        cout<<"\n2. TAKE A LOOK AT WHAT OUR HOTEL HAS TO OFFER.";
        cout<<"\n3. HELP DESK.";
        cout<<"\n4. TAKE A LOOK AT AVAILABLE ROOMS";
        cout<<"\n5. SEARCH THE DETAILS OF THE ROOMS OCCUPIED: ";
        cout<<"\n6. EXIT.\n";
        cin>>ch;
        //To break the while loop
        if(ch==6){
            cout<<"\nKINDLY SUBMIT A FEEDBACK: "; //Agile implementation (Taking feedback from the guest)
            //Streaming out the whitespace
            cin>>ws;
            //Taking input of a string using the getline function
            getline(cin, fb);
            cout<<"\nTHIS IS THE FEEDBACK YOU HAVE SUBMITTED: "<<fb;  
            cout<<"\nTHANK YOU FOR YOUR RESPONSE!";
            return 0;
            break;
        }

        //Using switch-case to provide user with options
        switch(ch){

            //Case to check in
            case(1): 
                guest.displayrooms(); 
                guest.nrooms();
                guest.day();
                //For loop to get different room preferences from the guest
                for(i=0;i<guest.n;i++){
                    guest.getpref();
                    if(guest.pref==1){
                        guest.detsin();
                    }
                    else if(guest.pref==2){
                        guest.detdou();
                    }
                    else if(guest.pref==3){
                        guest.detsui();
                    }
                    if(guest.pref==1){
                        guest.costsin();
                    }
                    else if(guest.pref==2){
                        guest.costdou();
                    }
                    else if(guest.pref==3){
                        guest.costsui();
                    }
                }
                guest.billcal();
                guest.choicee();
                //Conditional statement to confirm the booking
                if(guest.choice=="YES"||"Yes"||"yes"){
                    guest.confirm();
                    guest.allot();
                    //Alloting the rooms next to each other
                    for(i=0;i<guest.n;i++){
                        cout<<"\nYOUR ROOM NUMBER IS: "<<guest.rno;
                        guest.rno=guest.rno + 1;
                    }
                }
                else{
                    cout<<"\nWE WOULD HAVE LOVED TO HAVE YOU AS A GUEST, KINDLY DROP A FEEDBACK";
                    }
                break;

            //Case to view the facilities available
            case(2):
                cout<<"\nFACILITES AVAILABLE AT OUR HOTEL:";
                cout<<"\n*LUXORIOUS POOL";
                cout<<"\n*FITNESS AREA";
                cout<<"\n*SPA";
                cout<<"\n*MULTIPLE RESTAURANTS";
                cout<<"\n*AND MANY MORE!";
                break;

            //Case for the help desk to contact you
            case(3):
                cout<<"YOU WILL BE CONTACTED SHORTLY ON "<<guest.pno;
                break;

            //Case to display the available rooms
            case(4):
                cout<<"\nTHESE ARE SOME OF THE ROOMS WHICH ARE AVAILABLE WITH US: \n";
                for(j=0;j<10;j++){
                    cout<<guest.roomsavailable[j]<<"  ";
                }
                cout<<"\nWOULD YOU LIKE TO VIEW THE AVAILABLE ROOMS IN A SORTED MANNER? ";
                cin>>sorted;
                if(sorted=="yes"||"YES"||"Yes"){
                    guest.bubsortav();
                    cout<<" \nROOMS AVAILABLE IN A SORTED MANNER: \n";
                    guest.displayav();
                }
                else{
                    for(j=0;j<10;j++){
                    cout<<guest.roomsavailable[j]<<"  ";
                    }
                }
                break;
            
            //Case to display the details of the searched room
            case(5):
                cout<<"\nENTER THE ROOM NUMBER: ";
                cin>>roomnum;
                guest.insertionsortunav(guest.roomsunavailable,f);
                //Binary search
                first=0;
                last=9;
                mid=(first+last)/2;
                while(first<=last){
                    if(guest.roomsunavailable[mid]<roomnum){
                        first = mid+1;
                    }
                    else if(guest.roomsunavailable[mid]==roomnum){
                        occ=true;
                        cout<<"\nROOM FOUND, DISPLAYING THE DETAILS OF THE ROOM: ";
                        break;
                    }
                    else{
                        last=mid-1;
                    }
                    mid=(first+last)/2;
                }
                if(first>last){
                    cout<<"\nROOM IS UNOCCUPIED";
                }
                //Displaying details
                else if(occ==true){
                    if(roomnum==1){
                        cout<<"\nNAME OF THE OCCUPANT: KRISHNA SHAH";
                        cout<<"\nNUMBER OF THE OCCUPANT: 8293174689";
                    }
                    else if(roomnum==2){
                        cout<<"\nNAME OF THE OCCUPANT: MAHAK GUPTA";
                        cout<<"\nNUMBER OF THE OCCUPANT: 9413174689";
                    }
                    else if(roomnum==3){
                        cout<<"\nNAME OF THE OCCUPANT: SEHAJ SALUJA";
                        cout<<"\nNUMBER OF THE OCCUPANT: 7233174689";
                    }
                    else if(roomnum==4){
                        cout<<"\nNAME OF THE OCCUPANT: SARTHAK OBEROI";
                        cout<<"\nNUMBER OF THE OCCUPANT: 9543874689";
                    }
                    else if(roomnum==5){
                        cout<<"\nNAME OF THE OCCUPANT: ADITYA AHUJA";
                        cout<<"\nNUMBER OF THE OCCUPANT: 6323174689";
                    }
                    else if(roomnum==6){
                        cout<<"\nNAME OF THE OCCUPANT: SARTHAK SINGHEE";
                        cout<<"\nNUMBER OF THE OCCUPANT: 9314562789";
                    }
                    else if(roomnum==7){
                        cout<<"\nNAME OF THE OCCUPANT: SHRIYA AGARWAL";
                        cout<<"\nNUMBER OF THE OCCUPANT: 9166820918";
                    }
                    else if(roomnum==8){
                        cout<<"\nNAME OF THE OCCUPANT: ARUSHI JAIPURIA";
                        cout<<"\nNUMBER OF THE OCCUPANT: 8902174689";
                    }
                    else if(roomnum==9){
                        cout<<"\nNAME OF THE OCCUPANT: ARYAMAN SINGHI";
                        cout<<"\nNUMBER OF THE OCCUPANT: 7014674689";
                    }
                    else if(roomnum==10){
                        cout<<"\nNAME OF THE OCCUPANT: MANSI JAIN";
                        cout<<"\nNUMBER OF THE OCCUPANT: 9544904231";
                    }
                    else if(roomnum==11){
                        cout<<"\nNAME OF THE OCCUPANT: KANAV NANDA";
                        cout<<"\nNUMBER OF THE OCCUPANT: 9103474689";
                    }
                }
                break;
                
            //Default case
            default:
                cout<<"KINDLY ENTER A VALID CHOICE.";
                break;
        }
    }
}