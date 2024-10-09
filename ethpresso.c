//Coffee project lab 

//Pre processing
#include <stdio.h>
#include <math.h>
#include <string.h>

// Variables of different drinks
#define E_beans 8
#define E_water 30
#define E_milk 0
#define E_syrup 0
float E_cost = 3.5;


#define C_beans 8
#define C_water 30
#define C_milk 70
#define C_syrup 0
float C_cost = 4.5;


#define M_beans 8
#define M_water 39
#define M_milk 160
#define M_syrup 30
float M_cost = 5.5;


#define password "Admin123"
float total_amount = 0;


#define threshhold_coffee 20
#define threshhold_water 50
#define threshhold_milk 100
#define threshhold_chocosyrup 50

//Global variables
float available_coffee = 200;
float available_water = 200;
float available_milk = 200;
float available_chocosyrup = 200;

// Function prototypes
int adminMode();
int userMode();

//Main menu
int main(){
    int choice;
    while (1){
        printf("\n\n*MENU*\n");
        printf("1. Order a coffee \n");
        printf("2. Admin Mode \n");
        printf("3. Exit\n");
        printf("Please choose your preference: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Out of service, come back later! \n");
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Shutting down, thank you!...\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

//Coffee Mode 
int Coffee_Choice(){;
while (1){
       printf("\n Choose your coffee:");
       printf("1. Espresso: %.2f aed \n ", E_cost); 
       printf("2. Cappuccino: %.2f aed \n ", C_cost);
       printf("3. Mocha: %.2f aed \n ", M_cost);
       printf("4. Exit ");
       printf("Enter your option: ");
       scanf("%d", &Coffee_Choice);

       switch (Coffee_Choice) {
        case 1: 
        if ( available_coffee >= E_beans && available_water >= E_water){
         printf("Ordering Espresso! Price: %.2f", E_cost);
        break 
        }
        else
        printf("Sorry, we're out of service temporarily ");
        case 2:
        if( )

       }
}



}
// Admin Mode 
int adminMode(){
    char user_pass[50];
    int mode;
    printf("Enter admin password: ");
    scanf("%s", user_pass);

    if (strcmp(user_pass, password) == 0){
        printf("Logged in successfully \n");

        while (1) {
            printf("ADMIN MODE CHOICES\n");
            printf("1. Display quantity and sales \n");
            printf("2. Replenish Ingredients\n");
            printf("3. Change Coffee Price\n");
            printf("4. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &mode);

            switch (mode) {
                case 1:
                    printf("Displaying Quantity and Total Sale\n\n");
                    printf("Current Quantity of Coffee is %.2f g\n", available_coffee);
                    printf("Current Quantity of Water is %.2f ml\n", available_water);
                    printf("Current Quantity of Milk is %.2f ml\n", available_milk);
                    printf("Current Quantity of Chocolate Syrup is %.2f ml\n", available_chocosyrup);
                    printf("The total sales are %.2f dhs\n", total_amount);
                    break;

                case 2: {
                    // Add predefined amounts to each ingredient
                    float added_coffee = 50;        
                    float added_water = 150;        
                    float added_milk = 100;         
                    float added_chocosyrup = 40;    

                    available_coffee += added_coffee;
                    available_water += added_water;
                    available_milk += added_milk;
                    available_chocosyrup += added_chocosyrup;

                    printf("Ingredients have been replenished!\n");
                    printf("Added %.2f g of Coffee Beans\n", added_coffee);
                    printf("Added %.2f ml of Water\n", added_water);
                    printf("Added %.2f ml of Milk\n", added_milk);
                    printf("Added %.2f ml of Chocolate Syrup\n", added_chocosyrup);
                    printf("New Quantity of Coffee: %.2f g\n", available_coffee);
                    printf("New Quantity of Water: %.2f ml\n", available_water);
                    printf("New Quantity of Milk: %.2f ml\n", available_milk);
                    printf("New Quantity of Chocolate Syrup: %.2f ml\n", available_chocosyrup);
                    break;
                }

                case 3: {
                    int change_price_item;
                    float change_price_value;
                    printf("Change Coffee Price\n");
                    printf("Enter 1 to change Espresso price\n");
                    printf("Enter 2 to change Cappuccino price\n");
                    printf("Enter 3 to change Mocha price\n");
                    printf("Enter 0 to exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &change_price_item);

                    switch (change_price_item) {
                        case 1:
                            printf("Changing Espresso Amount\n");
                            printf("Current value of item: %.2f\n", E_cost);
                            printf("Changed value of item: ");
                            scanf("%f", &change_price_value);
                            E_cost = change_price_value;
                            break;
                        case 2:
                            printf("Changing Cappuccino Amount\n");
                            printf("Current value of item: %.2f\n", C_cost);
                            printf("Changed value of item: ");
                            scanf("%f", &change_price_value);
                            C_cost = change_price_value;
                            break;
                        case 3:
                            printf("Changing Mocha Amount\n");
                            printf("Current value of item: %.2f\n", M_cost);
                            printf("Changed value of item: ");
                            scanf("%f", &change_price_value);
                            M_cost = change_price_value;
                            break;
                        case 0:
                            printf("Exiting price change...\n");
                            break;
                        default:
                            printf("Invalid input\n");
                    }
                    break;
                }

                case 4:
                    printf("Exiting admin mode...\n");
                    return 0;  // Exit admin mode
                default:
                    printf("Invalid input\n");
            }
        }
    } else {
        printf("Invalid Password\n");
    }
    return 0;
}
