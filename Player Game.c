#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct player{
    char *Name;
    int Number;
    char place;
    struct player *next;
}player ;

player *New_Player (char *Name,int Number,char place){
    player*new_node;
    new_node=(player*)malloc(sizeof(player));
    new_node->Name=strdup(Name);
    new_node->Number= Number;
    new_node->place= place;
    new_node->next=NULL;
    return new_node;
}

player *Creat_Team (char *Name,int Number,player *head){
    player*new_node;
    new_node=(player*)malloc(sizeof(player));
    new_node->Name=strdup(Name);
    new_node->Number= Number;
    new_node->place= 'G' ;
    new_node->next= head;
    head = new_node;    
    return head;
}
player *insert_first(char *Name,int Number,char place,player *head){
    player*new_node;
    new_node=(player*)malloc(sizeof(player));
    new_node->Name=strdup(Name);
    new_node->Number= Number;
    new_node->place= place ;
    new_node->next= head;
    head = new_node;    
    return head;
}
player *insert_last(char *Name,int Number,char place, player *head){
	player *new_node,*curr;
    new_node = (player *) malloc(sizeof(player));
    curr = head;
    new_node-> Name= strdup(Name);
    new_node-> Number= Number;
    new_node-> place= place;
    while (curr->next!=NULL)
        curr=curr->next;
	curr->next = new_node;
	new_node->next = NULL;
	curr = new_node;
    return head;
}   
 player * insert_at(char *Name,int Number,char place, player *head)
{
    // it should be at least one player in the team have the place 'D' or 'M' 
    // cus the loop stop when the current pointer equale the player position 'D' or 'M' ....     
    player *new_node = (player *) malloc(sizeof(player));
    player *p = (player *) malloc(sizeof(player));
    new_node-> Name= strdup(Name);
    new_node-> Number= Number;
    new_node-> place= place;
    player *current = head;
    while (current->place!=place ){
            current=current->next;
        }
    new_node->next=current->next;
    current->next=new_node;
    return head;
}
player *remov_player(int Number, player *head) {
    player *current_node = head;
    player *prev_node;
    while ( current_node != NULL) {
        if (current_node->Number== Number) {
            if (current_node == head) {
                head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
return head ;
}

player *Exchange (player *p1 ,int Number,player *head){
    // when u change a 'D' all the players after this player will get removed 
    player *current = head;
    while (current->Number!=Number)
        current=current->next;
    current->Name=p1->Name;
    current->Number=p1->Number;
    current->next=p1->next;
    return head;
}
// this function return 0 if the number already exist , if not it return 1
int test_number(int Number,player *head){
    player *current = head;
    while (current!=NULL){
        if(current->Number==Number)
            return 0;//number already exist in the Team 
        current=current->next;}
    return 1;//number not exist in the Team 
}

// this function return 1 if the team contain the place 'D' or 'M' , if not it return 0
int test_place(char place,player *head){
    player *current = head;
    while (current!=NULL){
        if(current->place==place)
            return 1;
        current=current->next;}
    return 0;
}

void display(player *head) {
    player *current_node = head;
    int counter=0;
    while(current_node != NULL) {
        printf("%s %d '%c' ->", current_node->Name,current_node->Number,current_node->place);
        current_node = current_node->next;
        counter++;
    }
    printf("NULL\n ");
    printf("\nthere are a '%d' player in your team ",counter);
    printf("\n");
}
int main(){
    printf("\n ..Game of Creating a Team.. \t \n");
    printf("THE ROLES : \n");
    printf("1- Try not to impliment a two players with the same Name or the same Number \n");
    printf("2- do not remove a player 'D' or 'M' if it was the only one in the team!!!  \n");
    printf("3- the place should be one of these characters : 'G' : GoalKeeper ,'D' : Dfender ,'M' : Milieu ,'T': Attack \n");
    printf("\t Or The Programme wille not work ._. \n");
    printf("\n Press any key to continue... ");
    getch();
    char Name[20];
    int Number;
    char place;

    int num;  //the Number of the player who gonne be removed or exchanged    
    int Test; //Test if the player Number or place already exist in the team
    
    player *head = NULL;//initiale the head with NULL
    player *curr=head;
    player *p;
    head = Creat_Team("Ederson",1,head);//add the Goolkeeper to the Team 

    /*in this part we will impliment a 2 players to the team wich have a the difirent 
      Two positions : 'D' and 'M' */
    player *p1,*p2;
    p1=p2=(player *) malloc(sizeof(player));
    p1 = New_Player("Van",4,'D');
    p2 = New_Player("Tony",8,'M');
    head->next=p1;
    p1->next=p2;
    p2->next=NULL;

    printf("\n the List of players before Start implimenting : \n");
    display(head);
    printf("\n Press any key to continue... ");
    getch();

    int option;
    while(1) {
        printf("\n ******************************************\n");
        printf("\n *  Linked list operations:               *\n");
        printf("\n *    1. Add Player                       *\n");
        printf("\n *    2. Remove PLayer                    *\n");
        printf("\n *    3. Exchange PLayer                  *\n");
        printf("\n *    4. Test existe of number            *\n");
        printf("\n *    5. Test existe of place             *\n");
        printf("\n *    6. display                          *\n");
        printf("\n *    7. Quit                             *\n");
        printf("\n ******************************************\n");
        printf("\n Choose an option [1-7] : ");
        scanf("%d", &option);
        switch (option) {
            case 1:        /* Add player*/
                printf("Enter the informetions of the player : \n");
                printf("The Name : ");
                scanf("%s", &Name);
                printf("the Number :");
                scanf("%d", &Number) ;
                printf("the Place :");
                scanf(" %c", &place);
                if (test_number(Number,head)){//test if the player number does not exist in the team 
                    if (place=='G'){
                        head = insert_first(Name,Number,place,head);
                        printf("the player '%s' is now added to the list\n ", Name);}
                    else if(place=='A'){
                        head = insert_last(Name,Number,place,head);
                        printf("the player '%s' is now added to the list\n ", Name);}
                    else if (place== 'D' || place=='M'){
                        if (test_place(place,head)){//test if the team contain the place 'D' or 'M'
                            head = insert_at(Name,Number,place,head);
                            printf("the player '%s' is now added to the list\n ", Name);}
                        else{//the team does not contain any 'D' or 'M'
                            printf("Erore : cannot impliment player \n There is no player '%c' ...\n",place);
                            // p=New_Player(Name,Number,place);
                            // while (curr->place!=place)
                            // {
                            //     curr=curr->next;
                            // }
                            // p->next=curr->next;
                            // curr->next=p;
                        }
                        }
                    else{
                        printf("invalide Potition\n ");
                        printf("\nthe place should be one of these characters : 'G' : GoalKeeper ,'D' : Dfender ,'M' : Milieu ,'T': Attack ...\n");
                    }}
                else 
                    printf("player Number alredy exist...\n can not impliment two Players with the same Number");
                printf("\n Press any key to continue... ");
                getch();
                break;
            case 2:        // remove player 
                printf("Enter the Number of the Player that you Want To Remove : ");
                scanf("%d",&num);
                Test = test_number(num,head);
                if (!Test){//test if the player number already exist in the team
                    remov_player(num,head);
                    printf("the player with the Number '%d' has been removed. \n",num); 
                }
                else 
                    printf("the player Number does not exist in the team ...\n");
                    
                printf("\n Press any key to continue... ");
                getch();
                break;
            case 3:       // excahnge player
                printf("Enter the information of the new Player : \n");
                printf(" the Name : ");
                scanf("%s",Name);
                printf("the Number : ");
                scanf("%d",&Number);
                player *p1 = New_Player(Name,Number,place);
                printf("Enter the numberof the player that you want to Exchange : ");
                scanf("%d",&num);
                Exchange(p1,num,head);
                printf("\n Done... \n The player '%d' has been changed with the player '%d'",num,Number);
                printf("\n Press any key to continue... ");
                getch();
                break;
            case 4:
                printf("enter the informetions you want to test : \n");
                printf("Number = ");
                scanf("%d",&Number);
                Test = test_number(Number,head);
                if (Test == 0)
                    printf("player Number already exist...\n");
                else 
                    printf("this Number haven't yet utilised...\n");
                printf("\n Press any key to continue... ");
                getch();
                break;
            case 5:
                printf("enter the informetions you want to test : \n");
                printf("place = ");
                scanf(" %c",&place);
                Test = test_place(place,head);
                if (Test)
                    printf("your team has at least one '%c' ...\n",place);
                else 
                    printf("your team has no '%c'...\n",place);
                printf("\n Press any key to continue... ");
                getch();
                break;
            case 6:
                display(head);
                printf("\n Press any key to continue... ");
                getch();
                break;
            case 7:
                printf(" \t see u °-°");
                return 0;
                break;
            default:
                printf("Invalid Option. Please Try again.\n");
                getch();
        }
    }
    return 0;
}
