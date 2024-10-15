// Coffee project lab 

// Preprocessing
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>  // For rand() and srand()
#include <time.h>    // For seeding the random function

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

// Global variables
float available_coffee = 200;
float available_water = 200;
float available_milk = 200;
float available_chocosyrup = 200;

// Function prototypes
int adminMode();
int userMode();
void replenishIngredients(); // Replenish ingredients with random values
void handlePayment(float cost); // Handles user payments

// Main menu
int main() {
    srand(time(0)); // Seed the random function
    int choice;
    while (1) {
        printf("\n\n*MENU*\n");
        printf("1. Order a coffee \n");
        printf("2. Admin Mode \n");
        printf("3. Exit\n");
        printf("Please choose your preference: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                userMode();
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

// User Mode
int userMode() {
    int coffee_choice;
    while (1) {
        printf("\nChoose your coffee:\n");
        printf("1. Espresso: %.2f AED \n", E_cost);
        printf("2. Cappuccino: %.2f AED \n", C_cost);
        printf("3. Mocha: %.2f AED \n", M_cost);
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &coffee_choice);

        switch (coffee_choice) {
            case 1: 
                if (available_coffee >= E_beans && available_water >= E_water) {
                    printf("Ordering Espresso! Price: %.2f AED\n", E_cost);
                    handlePayment(E_cost);
                    available_coffee -= E_beans;
                    available_water -= E_water;
                    break;
                } else {
                    printf("Sorry, not enough ingredients to make Espresso.\n");
                }
                break;
                
            case 2:
                if (available_coffee >= C_beans && available_water >= C_water && available_milk >= C_milk) {
                    printf("Ordering Cappuccino! Price: %.2f AED\n", C_cost);
                    handlePayment(C_cost);
                    available_coffee -= C_beans;
                    available_water -= C_water;
                    available_milk -= C_milk;
                    break;
                } else {
                    printf("Sorry, not enough ingredients to make Cappuccino.\n");
                }
                break;

            case 3:
                if (available_coffee >= M_beans && available_water >= M_water && available_milk >= M_milk && available_chocosyrup >= M_syrup) {
                    printf("Ordering Mocha! Price: %.2f AED\n", M_cost);
                    handlePayment(M_cost);
                    available_coffee -= M_beans;
                    available_water -= M_water;
                    available_milk -= M_milk;
                    available_chocosyrup -= M_syrup;
                    break;
                } else {
                    printf("Sorry, not enough ingredients to make Mocha.\n");
                }
                break;

            case 4:
                return 0; // Exit user mode

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Handles user payments
void handlePayment(float cost) {
    float paid = 0;
    float amount;

    while (paid < cost) {
        printf("Please insert money (1 AED or 0.5 AED): ");
        scanf("%f", &amount);

        if (amount == 1 || amount == 0.5) {
            paid += amount;
            printf("You have inserted: %.2f AED\n", paid);
        } else {
            printf("Invalid coin. Please insert 1 AED or 0.5 AED only.\n");
        }
    }

    if (paid > cost) {
        printf("Here's your change: %.2f AED\n", paid - cost);
    }
    total_amount += cost;
    printf("Payment successful! Enjoy your coffee.\n");
}

// Admin Mode
int adminMode() {
    char user_pass[50];
    int mode;
    printf("Enter admin password: ");
    scanf("%s", user_pass);

    if (strcmp(user_pass, password) == 0) {
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
                    printf("Current Quantity of Coffee: %.2f g\n", available_coffee);
                    printf("Current Quantity of Water: %.2f ml\n", available_water);
                    printf("Current Quantity of Milk: %.2f ml\n", available_milk);
                    printf("Current Quantity of Chocolate Syrup: %.2f ml\n", available_chocosyrup);
                    printf("The total sales are %.2f AED\n", total_amount);
                    break;

                case 2:
                    replenishIngredients(); // Call the replenishment function
                    break;

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
                            printf("Current price: %.2f\n", E_cost);
                            printf("New price: ");
                            scanf("%f", &change_price_value);
                            E_cost = change_price_value;
                            break;
                        case 2:
                            printf("Changing Cappuccino Amount\n");
                            printf("Current price: %.2f\n", C_cost);
                            printf("New price: ");
                            scanf("%f", &change_price_value);
                            C_cost = change_price_value;
                            break;
                        case 3:
                            printf("Changing Mocha Amount\n");
                            printf("Current price: %.2f\n", M_cost);
                            printf("New price: ");
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

// Function to automatically replenish ingredients
void replenishIngredients() {
    available_coffee += rand() % 50 + 10; // Adds between 10 and 59 grams
    available_water += rand() % 200 + 50; // Adds between 50 and 249 ml
    available_milk += rand() % 150 + 50;  // Adds between 50 and 199 ml
    available_chocosyrup += rand() % 50 + 20; // Adds between 20 and 69 ml

    printf("Ingredients have been replenished automatically!\n");
    printf("New Quantity of Coffee: %.2f g\n", available_coffee);
    printf("New Quantity of Water: %.2f ml\n", available_water);
    printf("New Quantity of Milk: %.2f ml\n", available_milk);
    printf("New Quantity of Chocolate Syrup: %.2f ml\n", available_chocosyrup);
}
