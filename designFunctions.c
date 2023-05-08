#include "designFunctions.h"

void mainFront(){

    system("cls");

    printf(R"EOF(



                    oooooooooooo  ooooo     ooo ooooooooo.        ooooooooo.  oooooooooooo       .o.       oooooooooo.    .oooooo..o
                    8'  888   `8 `888'     `8' `888   `Y88.      `888   `Y88. `888'     `8      .888.      `888'   `Y8b  d8P'    `Y8
                        888       888       8   888   .d88'       888   .d88'  888             .8\"888.     888      888 Y88bo.
                        888       888       8   888ooo88P'        888ooo88P'   888oooo8       .8' `888.     888      888  `\"Y8888o.
                        888       888       8   888               888`88b.     888    \"     .88ooo8888.    888      888     `\"Y88b
                        888       `88.    .8'   888               888  `88b.   888       o  .8'     `888.   888     d88' oo     .d8P
                       o888o        `YbodP'    o888o             o888o  o888o o888ooooood8 o88o     o8888o o888bood8P'   8\"\"88888P\


                                                    "USE UP OR DOWN ARROW KEYS TO NAVIGATE THROUGH MENU"
        )EOF");
}

void changePass(){

printf(R"EOF(




                                       ___ _  _   _   _  _  ___ ___   ___  _   ___ _____      _____  ___ ___
                                      / __| || | /_\ | \| |/ __| __| | _ \/_\ / __/ __\ \    / / _ \| _ \   \
                                     | (__| __ |/ _ \| .` | (_ | _|  |  _/ _ \\__ \__ \\ \/\/ / (_) |   / |) |
                                      \___|_||_/_/ \_\_|\_|\___|___| |_|/_/ \_\___/___/ \_/\_/ \___/|_|_\___/

 )EOF");
}

void dispRegister(){
printf(R"EOF(



                                                  ___ ___ ___ ___ ___ _____ ___    _ _____ ___ ___  _  _
                                                 | _ \ __/ __|_ _/ __|_   _| _ \  /_\_   _|_ _/ _ \| \| |
                                                 |   / _| (_ || |\__ \ | | |   / / _ \| |  | | (_) | .` |
                                                 |_|_\___\___|___|___/ |_| |_|_\/_/ \_\_| |___\___/|_|\_|

)EOF");}


void dispStudentPortal(){
    gotoxy(10,3);printf(R"EOF(
                               ___  _____  _   _  ___   ___  _  _  _____   ___   ___   ___  _____  _    _
                              / __||_   _|| | | ||   \ | __|| \| ||_   _| | _ \ / _ \ | _ \|_   _|/_\  | |
                              \__ \  | |  | |_| || |) || _| | .` |  | |   |  _/| (_) ||   /  | | / _ \ | |__
                              |___/  |_|   \___/ |___/ |___||_|\_|  |_|   |_|   \___/ |_|_\  |_|/_/ \_\|____|

                  )EOF");
}


void dispAdminPortal(){
      gotoxy(10,3);printf(R"EOF(

                                            _    ___   __  __  ___  _  _   ___   ___   ___  _____  _    _
                                           /_\  |   \ |  \/  ||_ _|| \| | | _ \ / _ \ | _ \|_   _|/_\  | |
                                          / _ \ | |) || |\/| | | | | .` | |  _/| (_) ||   /  | | / _ \ | |__
                                         /_/ \_\|___/ |_|  |_||___||_|\_| |_|   \___/ |_|_\  |_|/_/ \_\|____|

              )EOF");

}

void dispAllBooks(){
      gotoxy(10,3);printf(R"EOF(
                                               ___  ___  ___  ___  _       _ __   __    _    _     _
                                              |   \|_ _|/ __|| _ \| |     /_\\ \ / /   /_\  | |   | |
                                              | |) || | \__ \|  _/| |__  / _ \\ V /   / _ \ | |__ | |__
                                              |___/|___||___/|_|  |____|/_/ \_\|_|   /_/ \_\|____||____|

              )EOF");


 }

void dispSearchBooks(){
printf(R"EOF(



                                                              ___  ___    _    ___   ___  _  _   ___   ___    ___   _  __
                                                             / __|| __|  /_\  | _ \ / __|| || | | _ ) / _ \  / _ \ | |/ /
                                                             \__ \| _|  / _ \ |   /| (__ | __ | | _ \| (_) || (_) || ' <
                                                             |___/|___|/_/ \_\|_|_\ \___||_||_| |___/ \___/  \___/ |_|\_\
                 )EOF");
}

void dispBorrowBooks(){
       gotoxy(10,3);printf(R"EOF(

                                  ___   ___   ___  ___   ___ __      __  ___   ___    ___   _  __
                                 | _ ) / _ \ | _ \| _ \ / _ \\ \    / / | _ ) / _ \  / _ \ | |/ /
                                 | _ \| (_) ||   /|   /| (_) |\ \/\/ /  | _ \| (_) || (_) || ' <
                                 |___/ \___/ |_|_\|_|_\ \___/  \_/\_/   |___/ \___/  \___/ |_|\_\

                 )EOF");
}


void dispLogin(){
       gotoxy(10,3);printf(R"EOF(

                                                         _     ___    ___   ___  _  _
                                                        | |   / _ \  / __| |_ _|| \| |
                                                        | |__| (_) || (_ |  | | | .` |
                                                        |____|\___/  \___| |___||_|\_|

                 )EOF");
}

void dispManageRec(){
  gotoxy(10,3);printf(R"EOF(
                        __  __    _    _  _    _    ___  ___   ___   ___    ___   _  __  ___  ___  ___  ___   ___  ___
                       |  \/  |  /_\  | \| |  /_\  / __|| __| | _ ) / _ \  / _ \ | |/ / | _ \| __|/ __|/ _ \ | _ \|   \
                       | |\/| | / _ \ | .` | / _ \| (_ || _|  | _ \| (_) || (_) || ' <  |   /| _|| (__| (_) ||   /| |) |
                       |_|  |_|/_/ \_\|_|\_|/_/ \_\\___||___| |___/ \___/  \___/ |_|\_\ |_|_\|___|\___|\___/ |_|_\|___/
         )EOF");
}

void dispManageBorrowing(){
      gotoxy(10,3);printf(R"EOF(
             __  __    _    _  _    _    ___  ___   ___   ___   ___  ___   ___ __      __ ___  _  _   ___   ___  ___  ___  ___   ___  ___
            |  \/  |  /_\  | \| |  /_\  / __|| __| | _ ) / _ \ | _ \| _ \ / _ \\ \    / /|_ _|| \| | / __| | _ \| __|/ __|/ _ \ | _ \|   \
            | |\/| | / _ \ | .` | / _ \| (_ || _|  | _ \| (_) ||   /|   /| (_) |\ \/\/ /  | | | .` || (_ | |   /| _|| (__| (_) ||   /| |) |
            |_|  |_|/_/ \_\|_|\_|/_/ \_\\___||___| |___/ \___/ |_|_\|_|_\ \___/  \_/\_/  |___||_|\_| \___| |_|_\|___|\___|\___/ |_|_\|___/

       )EOF");
}


void dispManageBorrowers(){
  gotoxy(10,3);printf(R"EOF(

            __  __    _    _  _    _    ___  ___   ___   ___   ___  ___   ___ __      __ ___  ___   ___  ___  ___  ___   ___  ___
           |  \/  |  /_\  | \| |  /_\  / __|| __| | _ ) / _ \ | _ \| _ \ / _ \\ \    / /| __|| _ \ | _ \| __|/ __|/ _ \ | _ \|   \
           | |\/| | / _ \ | .` | / _ \| (_ || _|  | _ \| (_) ||   /|   /| (_) |\ \/\/ / | _| |   / |   /| _|| (__| (_) ||   /| |) |
           |_|  |_|/_/ \_\|_|\_|/_/ \_\\___||___| |___/ \___/ |_|_\|_|_\ \___/  \_/\_/  |___||_|_\ |_|_\|___|\___|\___/ |_|_\|___/

        )EOF");
}

void dispAdd(){
      gotoxy(10,3);printf(R"EOF(
                                     _    ___   ___    ___  ___  ___  ___   ___  ___   ___
                                    /_\  |   \ |   \  | _ \| __|/ __|/ _ \ | _ \|   \ / __|
                                   / _ \ | |) || |) | |   /| _|| (__| (_) ||   /| |) |\__ \
                                  /_/ \_\|___/ |___/  |_|_\|___|\___|\___/ |_|_\|___/ |___/

)EOF");
}


void dispUpdate(){
     gotoxy(10,3);printf(R"EOF(
                                                           _   _  ___  ___    _  _____  ___
                                                          | | | || _ \|   \  /_\|_   _|| __|
                                                          | |_| ||  _/| |) |/ _ \ | |  | _|
                                                           \___/ |_|  |___//_/ \_\|_|  |___|

                   )EOF");
}
void dispSearch(){
 gotoxy(10,3);printf(R"EOF(
                                             ___  ___    _    ___   ___  _  _    ___   ___  ___  ___  ___   ___  ___
                                            / __|| __|  /_\  | _ \ / __|| || |  | _ \| __|/ __|/ _ \ | _ \|   \ / __|
                                            \__ \| _|  / _ \ |   /| (__ | __ |  |   /| _|| (__| (_) ||   /| |) |\__ \
                                            |___/|___|/_/ \_\|_|_\ \___||_||_|  |_|_\|___|\___|\___/ |_|_\|___/ |___/
            )EOF");
}

void dispDelete(){
 gotoxy(10,3);printf(R"EOF(
                                                  ___   ___  _     ___  _____  ___
                                                 |   \ | __|| |   | __||_   _|| __|
                                                 | |) || _| | |__ | _|   | |  | _|
                                                 |___/ |___||____||___|  |_|  |___|

                   )EOF");
}


