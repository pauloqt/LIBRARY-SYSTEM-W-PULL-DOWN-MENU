#include "transactionFunctions.h"

//borrowBook() asks the borrower about all the necessary information on borrowing transaction (transaction attributes).
void borrowBook(){
BOOK *pBook;
BORROWER *pBorrower;
TRANSACTION *pTransaction;
char enteredBookRef[14];
int ch;

    pBorrower=locateTUP_ID(loggedInID);
    pTransaction=headTransaction;

    system("cls");
    dispBorrowBooks();
    gotoxy(40,12);printf("WELCOME %s\n", pBorrower->name);
    gotoxy(40,13);printf("ENTER BOOK REFERENCE NO. : ");
    gotoxy(68,13);scanf("%s", enteredBookRef);

    pBook= locateBook(enteredBookRef);

    if(pBook==NULL){
       gotoxy(40,20);printf("SELECTED BOOK IS NOT AVAILABLE\n"); gotoxy(40,21); system("pause");
    }

    else if(pBook->totalStock - pBook->borrower <=0){
        gotoxy(40,22);printf("SELECTED BOOK IS OUT OF STOCK!\n");gotoxy(40,21); system("pause");
    }

    else{
        displayBook(pBook,0,pBook->nxt);
        system("cls");
        dispBorrowBooks();
        gotoxy(40,15);printf("BOOK REFERENCE NO.: %s", pBook->refNum);
        gotoxy(40,16);printf("BOOK TO BORROW: %s", pBook->title);
        strcpy(infoTransaction.title, pBook->title);
        gotoxy(40,17);printf("BOOK AUTHOR: %s", pBook->author);
        strcpy(infoTransaction.author, pBook->author);
        gotoxy(40,18);printf("BORROWER'S NAME: %s", pBorrower->name);
        strcpy(infoTransaction.borrower, pBorrower->name);
        gotoxy(40,19);printf("TUP ID NO.: %s", pBorrower->TUP_ID);
        strcpy(infoTransaction.TUP_ID, pBorrower->TUP_ID);
        strcpy(infoTransaction.refNum, pBook->refNum);
        gotoxy(40,21);printf("ENTER DATE BORROWED [MM/DD/YY]: ");
        gotoxy(75,21);scanf("%s", infoTransaction.dateBorrowed);
        gotoxy(40,22);printf("ENTER DATE TO RETURN [MM/DD/YY]: ");
        gotoxy(75,22);scanf("%s", infoTransaction.dateToReturn);
        strcpy(infoTransaction.librarian, "MS.YGOT");
        gotoxy(40,23);printf("LIBRARIAN IN CHARGE: MS.YGOT");
        strcpy(infoTransaction.status, "TO RETURN");
        gotoxy(40,26);printf("DO YOU WANT TO PROCEED WITH THE TRANSACTION? : ");
        gotoxy(40,27);printf("[1] YES [2] NO");
        gotoxy(40,28);printf("SELECT OPTION (1-2): ");
        fflush stdin;
        gotoxy(60,28);scanf("%d", &ch);
        if(ch==1){
            addTransaction();
            pBook->borrower+=1;
            saveTransaction();
            saveBook();
            gotoxy(40,30);printf("BORROWING TRANSACTION PROCESSED.");
            gotoxy(40,31);printf("PROCEED TO THE LIBRARIAN TO BORROW THE BOOK.\n");
            gotoxy(40,35);system("pause");
        }
        else{
            return;
        }

    }
}

//The addTransaction() function adds a new node to the transaction linked list in alphabetical order, with the info struct as its data.
int addTransaction(){
TRANSACTION *q, *p, *n;

    n= (TRANSACTION*) malloc(sizeof(TRANSACTION));    //allocates memory to n.
    *n= infoTransaction;                           //copy info of the book to n.

    p=q=headTransaction;                           //point all pointers to head.
    while(p!=NULL && strcmp(n->status, p->status)<0){
        q=p;
        p=p->nxt;
    }

    if(p==headTransaction){    //if to insert at the head.
        headTransaction=n;
    }
    else{           //if to insert in between or at the end.
        q->nxt=n;
    }
    n->nxt=p;  //insert p at the end which contains next node or NULL.
}

////The searchTransaction() function prompts the user to enter a search a string, and then searches the linked list for any transaction whose title, author, or category matches the search term. It displays information about any matching books.
void searchTransaction(){
TRANSACTION *p;
char toSearch[51];
int i, searchCategory=0;
char* categoryPointer;

    while(searchCategory<1 || searchCategory>9){

        system("cls");
        dispSearch();
        gotoxy(30,9);printf("\033[31m ___________________________________________________________________________________________________________________");
        gotoxy(30,10);printf("|   _                                                                                                               |");
        gotoxy(30,11);printf("|  (_)                                                                                                              |");
        gotoxy(30,12);printf("|    \\                                                                                                              |");
        gotoxy(30,13);printf("|___________________________________________________________________________________________________________________|");
        printf("\033[0m");

        gotoxy(76,15);printf("SEARCH BY CATEGORY");
        gotoxy(76,16);printf("[1] Book Title");
        gotoxy(76,17);printf("[2] Author");
        gotoxy(76,18);printf("[3] Reference Number");
        gotoxy(76,19);printf("[4] Borrower");
        gotoxy(76,20);printf("[5] TUP ID");
        gotoxy(76,21);printf("[6] Date Borrowed");
        gotoxy(76,22);printf("[7] Date Return");
        gotoxy(76,23);printf("[8] Librarian In-Charged");
        gotoxy(76,24);printf("[9] Status");
        gotoxy(38,11);printf("\033[31mENTER SEARCH CATEGORY [1-9]: ");
        scanf("%d", &searchCategory);

        if(searchCategory<1 || searchCategory>9){
            gotoxy(30, 16); printf("SELECT FROM 1-9 ONLY!");
            gotoxy(30, 17); system("pause");
        }
    }

    fflush stdin;
    system("cls");

    gotoxy(30,5);printf("\033[31m ___________________________________________________________________________________________________________________");
    gotoxy(30,6);printf("|   _                                                                                                               |");
    gotoxy(30,7);printf("|  (_)  ENTER THE TEXT TO SEARCH:                                                                                   |");
    gotoxy(30,8);printf("|    \\                                                                                                              |");
    gotoxy(30,9);printf("|___________________________________________________________________________________________________________________|");
    printf("\033[0m");
    gotoxy(65,7); scanf("%[^\n]", toSearch);

    gotoxy(2,12);printf("\033[31m _________________________ _____________________ __________________ __________________ ____________ _______________ ________________ ______________ ____________");
    gotoxy(2,13);printf("|         TITLE           |       AUTHOR        | REFERENCE NUMBER |     BORROWER     |   TUP ID   | DATE BORROWED | DATE TO RETURN |  LIBRARIAN   |   STATUS   |");
    gotoxy(2,14);printf("|_________________________|_____________________|__________________|__________________|____________|_______________|________________|______________|____________|");
    printf("\033[0m");


    p=headTransaction;
    for(i=-1; p!=NULL;){
        switch(searchCategory){ // point the pointer to the appropriate search category.
            case 1: categoryPointer= p->title; break;
            case 2: categoryPointer= p->author; break;
            case 3: categoryPointer= p->refNum; break;
            case 4: categoryPointer= p->borrower; break;
            case 5: categoryPointer= p->TUP_ID; break;
            case 6: categoryPointer= p->dateBorrowed; break;
            case 7: categoryPointer= p->dateToReturn; break;
            case 8: categoryPointer= p->librarian; break;
            case 9: categoryPointer= p->status; break;
        }
        if(strstr(categoryPointer, toSearch)!=NULL){  // if the pointed categoryBorrowerPointer contains the substring, print the transaction.
            i++;
              gotoxy(3, 15+i); printf("%d.) ", i+1);
              gotoxy(8,15+i); printf("%s", p->title);
              gotoxy(32,15+i);; printf("%s", p->author);
              gotoxy(54,15+i); printf("%s", p->refNum);
              gotoxy(74,15+i); printf("%s", p->borrower);
              gotoxy(93,15+i); printf("%s", p->TUP_ID);
              gotoxy(107,15+i); printf("%s", p->dateBorrowed);
              gotoxy(122,15+i); printf("%s", p->dateToReturn);
              gotoxy(138,15+i); printf("%s", p->librarian);
              gotoxy(152,15+i); printf("%s", p->status);
        }
        p=p->nxt;
	}
	   gotoxy(2,15+i+1); printf("\033[31m__________________________________________________________________________________________________________________________________________________________\n");
    gotoxy(2,15+i+3); system("pause");
    printf("\033[0m");

    if (i==-1){
    gotoxy(2,12);printf("No transactions found.\n");
    gotoxy(2,12);printf("\033[0m");
    system("pause");
    }
}

//displayAllTransaction() displays all information of all the node in the transaction linked list.
void displayAllTransaction(struct transaction *p, int start, int end){
int i;

    system("cls");
    dispAllBooks();
    gotoxy(2,9);printf("\033[31m _________________________ _____________________ __________________ __________________ ____________ _______________ ________________ ______________ ____________");
    gotoxy(2,10);printf("|         TITLE           |       AUTHOR        | REFERENCE NUMBER |     BORROWER     |   TUP ID   | DATE BORROWED | DATE TO RETURN |  LIBRARIAN   |   STATUS   |");
    gotoxy(2,11);printf("|_________________________|_____________________|__________________|__________________|____________|_______________|________________|______________|____________|");
    printf("\033[0m");

    for(i=start; p!=end; i++){
        gotoxy(3, 12+i); printf("%d.) ", i+1);
        gotoxy(8,12+i); printf("%s", p->title);
        gotoxy(32,12+i);; printf("%s", p->author);
        gotoxy(54,12+i); printf("%s", p->refNum);
        gotoxy(74,12+i); printf("%s", p->borrower);
        gotoxy(93,12+i); printf("%s", p->TUP_ID);
        gotoxy(107,12+i); printf("%s", p->dateBorrowed);
        gotoxy(122,12+i); printf("%s", p->dateToReturn);
        gotoxy(138,12+i); printf("%s", p->librarian);
        gotoxy(152,12+i); printf("%s", p->status);

        p=p->nxt;
    }
    gotoxy(3,12+i+1); printf("\033[31m____________________________________________________________________________________________________________________________________________________\n");
    gotoxy(5,12+i+3); system("pause");
    printf("\033[0m");

}

void saveTransaction(){
FILE *fp= fopen("transactionDetails.txt", "w+");
TRANSACTION *p;

    if(fp==NULL){
        printf("\nTHE FILE ""transactionDetails.txt"" DOES NOT EXIST\n");
        system("pause");
    }

    else{
        p=headTransaction;
        while(p!=NULL){
            fprintf(fp, "%s\n%s\n%s\n%s\n%s %s %s %s\n%s\n\n", p->title, p->author, p->refNum, p->borrower, p->TUP_ID, p->dateBorrowed, p->dateToReturn, p->librarian, p->status);
            p=p->nxt;
        }
        fclose(fp);
    }
}

//saveInfoTransaction() saves the encrypted borrower details in "transactionDetails.txt"
void retrieveTransaction(){
FILE *fp= fopen("transactionDetails.txt", "r+");
TRANSACTION *p;

    if(fp==NULL){
        printf("THE FILE ""transactionDetails.txt"" DOES NOT EXIST\n");
        system("pause");
    }

    else{
        while(1){
            fscanf(fp, "\n%[^\n]\n", &infoTransaction.title);
            fflush stdin;
            fscanf(fp, "%[^\n]\n", &infoTransaction.author);
            fflush stdin;
            fscanf(fp, "%[^\n]\n", &infoTransaction.refNum);
            fflush stdin;
            fscanf(fp, "%[^\n]\n", &infoTransaction.borrower);
            fflush stdin;
            fscanf(fp, "%s %s %s %s\n", infoTransaction.TUP_ID, infoTransaction.dateBorrowed, infoTransaction.dateToReturn, infoTransaction.librarian);
            fscanf(fp, "%[^\n]", &infoTransaction.status);

            if(!feof(fp)){
                addTransaction();
                fflush stdin;
            }
            else{break;}
        }
    }
    fclose(fp);
}

//The locateTransaction() function searches for the transaction node with a given TUP ID and returns a pointer to that node if it is found.
struct transaction *locateTransaction(char TUP_ID[], char refNum[]){
TRANSACTION *p;

    p=headTransaction;
    while(p!=NULL){
        if(strcmp(TUP_ID, p->TUP_ID)==0 && strcmp(refNum, p->refNum)==0){
            return p;
        }
    p=p->nxt;
    }

    return p;

}

//editStatus() asks the admin to enter the transaction's borrower TUPID, and book ref number. Then updates the status of that transaction from "TO RETURN" to "RETURNED"
void editStatus(){
BOOK *pBook;
TRANSACTION *pTransac;
char enteredID[7], enteredReference[14], returned[10]="RETURNED";

    system("cls");
    dispUpdate();
    gotoxy(55,15); printf("TUP ID (Ex. 123456): TUP-M "); scanf("%s", enteredID);
    gotoxy(55,17); printf("ENTER REFERENCE NUMBER: "); scanf("%s", enteredReference);
    pTransac=locateTransaction(enteredID, enteredReference);
    if(pTransac==NULL){
        gotoxy(55,20); printf("TRANSACTION RECORD NOT FOUND!\n"); system("pause");
    }

    else{
        fflush stdin;
        strcpy(pTransac->status, returned);
        gotoxy(55,20); printf("STATUS: %s", pTransac->status);
        pBook=locateBook(enteredReference);
        pBook->borrower-=1;
        gotoxy(55,22); printf("RECORD SUCCESSFULLY EDITED\n"); gotoxy(55,24); system("pause");
    }
}


void borrowMenu(){
char ID[7];
setFontStyle(18);
char Menu[][50] =  {"\n\n\n\n\n\t\t\t\t\t\t\tLOGIN", "\n\n\n\n\n\t\t\t\t\t\t\tREGISTER ", "\n\n\n\n\n\t\t\t\t\t\t\tGO BACK"};
int pointer = 0;
const char ENTER = 13;//ASCII code for ENTER Key
char ch = ' ';
HANDLE  hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while(1){
        system("cls");
        dispBorrowBooks();
        ShowConsoleCursor(0);//SET CURSOR OF

        for(int i=0; i<3; ++i){
            //This will highlight the choice in the menu
            if(i==pointer){
                gotoxy(48,10+i);

                SetConsoleTextAttribute(hConsole, 10);
                printf("%s\n", Menu[i]);
            }else{
                gotoxy(48,10+i);
                SetConsoleTextAttribute(hConsole, 15); // set color of the text to white
                printf("%s\n",Menu[i]);
            }
             SetConsoleTextAttribute(hConsole, 15);
        }
        //This will check the key stroke that is being pressed in keyboard
        while(1){
            if(GetAsyncKeyState(VK_UP) != 0){
                --pointer;

                if(pointer == -1){
                    pointer = 2;
                    }
                break;
            }else if(GetAsyncKeyState(VK_DOWN) != 0){
                ++pointer;
                if(pointer == 3){
                    pointer = 0;
                }

                break;
            }else if((ch = getch()) == ENTER){
                switch(pointer){
                    case 0:
                    {
                        ShowConsoleCursor(1);
                        loginBorrower();
                        if(strcmp(loggedInID, "")!=0){
                            borrowBook();
                        }
                        return;
                        break;
                    }
                    case 1:
                    {
                        ShowConsoleCursor(1);
                        getInfoBorrower();
                        if(strcmp(loggedInID, "")!=0){  //If submitted ang registration
                            loginBorrower();
                        }
                        if(strcmp(loggedInID, "")!=0){  //if naka-log in.
                            borrowBook();
                        }
                        return;
                        break;

                    }

                    case 2:
                    {
                        ShowConsoleCursor(1);
                        return;
                    }
            }
            }
        }
    }
}

void manageBorrowingMenu(){
TRANSACTION *q;


    setFontStyle(18);
    char Menu[][50] =  {"\n\n\n\n\n\t\t\t\t\t\t\tEDIT STATUS  ", "\n\n\n\n\n\t\t\t\t\t\t\tSEARCH BORROWING RECORD ", "\n\n\n\n\n\t\t\t\t\t\t\tDISPLAY ALL RECORDS ", "\n\n\n\n\n\t\t\t\t\t\t\tGO BACK " };
    int pointer = 0;
    const char ENTER = 13;//ASCII code for ENTER Key
    char ch = ' ';
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while(1){
        system("cls");
        dispManageBorrowing();
        ShowConsoleCursor(0);//SET CURSOR OFF

        for(int i=0; i<4; ++i){
            //This will highlight the choice in the menu
            if(i==pointer){
                gotoxy(48,10+i);

                SetConsoleTextAttribute(hConsole, 10);

                printf("%s\n", Menu[i]);
            }else{
                gotoxy(48,10+i);
                SetConsoleTextAttribute(hConsole, 15); // set color of the text to white
                printf("%s\n",Menu[i]);
            }
             SetConsoleTextAttribute(hConsole, 15);
        }
        //This will check the key stroke that is being pressed in keyboard
        while(1){
            if(GetAsyncKeyState(VK_UP) != 0){
                --pointer;

                if(pointer == -1){
                    pointer = 3;
                    }

                break;
            }else if(GetAsyncKeyState(VK_DOWN) != 0){
                ++pointer;
                if(pointer == 4){
                    pointer = 0;
                }

                break;
            }else if((ch = getch()) == ENTER){
                switch(pointer){
                    case 0:
                    {
                        ShowConsoleCursor(1);//SET CURSON ON
                        editStatus();
                        saveBook();
                        saveTransaction();
                        break;
                    }
                    case 1:
                    {
                        ShowConsoleCursor(1);
                        searchTransaction();
                        break;
                    }

                    case 2:
                    {
                       ShowConsoleCursor(1);
                       displayAllTransaction(q=headTransaction, 0, NULL);
                        break;
                    }

                    case 3:
                    {
                        ShowConsoleCursor(1);
                        return;
                        break;
                    }

                  }
                }
                break;
            }
        }
}

