#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store crop data
typedef struct {
    char name[30];
    float min_pH, max_pH;
    float min_temp, max_temp;
} Crop;

// Structure to store bug tracking information
typedef struct {
    char pest_name[30];
    char pesticide[50];
} PestControl;

// Function to recommend crops based on soil conditions
void recommendCrops(float pH, float temp) {
    Crop crops[] = {
        {"Wheat", 5.5, 7.0, 10, 25},
        {"Rice", 6.0, 7.5, 20, 35},
        {"Maize", 5.8, 7.2, 18, 30},
        {"Cotton", 6.2, 8.0, 20, 35}
    };
    
    int found = 0;
    printf("\nRecommended Crops:\n");
    for (int i = 0; i < 4; i++) {
        if (pH >= crops[i].min_pH && pH <= crops[i].max_pH &&
            temp >= crops[i].min_temp && temp <= crops[i].max_temp) {
            printf("- %s\n", crops[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No suitable crops found for the given conditions.\n");
    }
}

// Function to check irrigation requirement
void checkIrrigation(float moisture) {
    if (moisture < 30) {
        printf("Soil is dry! Start irrigation.\n");
    } else {
        printf("Soil moisture is sufficient. No irrigation needed.\n");
    }
}

// Function for pest control
void recommendPesticide(char pest[]) {
    PestControl pests[] = {
        {"Aphid", "Use Neem Oil"},
        {"Caterpillar", "Use Bacillus Thuringiensis"},
        {"Grasshopper", "Use Malathion"}
    };

    for (int i = 0; i < 3; i++) {
        if (strcmp(pest, pests[i].pest_name) == 0) {
            printf("Recommended pesticide: %s\n", pests[i].pesticide);
            return;
        }
    }
    printf("No specific pesticide recommendation for this pest.\n");
}

// Function to calculate farm profit
void calculateProfit(float revenue, float expenses) {
    float profit = revenue - expenses;
    if (profit > 0) {
        printf("Profit: $%.2f\n", profit);
    } else if (profit < 0) {
        printf("Loss: $%.2f\n", -profit);
    } else {
        printf("No profit, no loss.\n");
    }
}

// Main Menu
int main() {
    int choice;
    while (1) {
        printf("\n====== AGRICULTURE MANAGEMENT SYSTEM ======\n");
        printf("1. Crop Recommendation\n");
        printf("2. Smart Irrigation\n");
        printf("3. Pest Control\n");
        printf("4. Farm Profit Calculation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program...\n");
            break;
        }

        switch (choice) {
            case 1: {
                float pH, temp;
                printf("Enter soil pH level: ");
                scanf("%f", &pH);
                printf("Enter temperature (°C): ");
                scanf("%f", &temp);
                recommendCrops(pH, temp);
                break;
            }
            case 2: {
                float moisture;
                printf("Enter soil moisture level (0-100%%): ");
                scanf("%f", &moisture);
                checkIrrigation(moisture);
                break;
            }
            case 3: {
                char pest[30];
                printf("Enter detected pest name: ");
                scanf("%s", pest);
                recommendPesticide(pest);
                break;
            }
            case 4: {
                float revenue, expenses;
                printf("Enter total revenue (USD): ");
                scanf("%f", &revenue);
                printf("Enter total expenses (USD): ");
                scanf("%f", &expenses);
                calculateProfit(revenue, expenses);
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
