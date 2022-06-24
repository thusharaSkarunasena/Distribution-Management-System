#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
*
* Author - Thushara Supun
*
*/

typedef int bool;
#define true 1
#define false 0

const int VEHICLES_ARRAY_SIZE = 100;
const int ITEMS_ARRAY_SIZE = 1000;
const int STOCKS_ARRAY_SIZE = 1000;
const int LOADINGS_ARRAY_SIZE = 1000;
const int UNLOADINGS_ARRAY_SIZE = 1000;

#define VEHICLES_ARRAY_SIZE 100
#define ITEMS_ARRAY_SIZE 1000
#define STOCKS_ARRAY_SIZE 1000
#define LOADINGS_ARRAY_SIZE 1000
#define UNLOADINGS_ARRAY_SIZE 1000

const int VEHICLE_CODE_SIZE = 30;
const int VEHICLE_NUMBER_SIZE = 30;
const int ITEM_CODE_SIZE = 30;
const int ITEM_NAME_SIZE = 60;
const int ITEM_PRICE_SIZE = 10;
const int STOCK_CODE_SIZE = 30;
const int STOCK_QTY_SIZE = 10;
const int LOADING_CODE_SIZE = 30;
const int LOADING_QTY_SIZE = 10;

#define VEHICLE_CODE_SIZE 30
#define VEHICLE_NUMBER_SIZE 30
#define ITEM_CODE_SIZE 30
#define ITEM_NAME_SIZE 60
#define ITEM_PRICE_SIZE 10
#define STOCK_CODE_SIZE 30
#define STOCK_QTY_SIZE 10
#define LOADING_CODE_SIZE 30
#define LOADING_QTY_SIZE 10

const char* ERROR_CODE0000 = "0000";
const char* ERROR_CODE1000 = "1000";
const char* ERROR_CODE2000 = "2000";
const char* ERROR_CODE3000 = "3000";
const char* ERROR_CODE3001 = "3001";
const char* ERROR_CODE4000 = "4000";
const char* ERROR_CODE4001 = "4001";
const char* ERROR_CODE4002 = "4002";
const char* ERROR_CODE4003 = "4003";
const char* ERROR_CODE5000 = "5000";
const char* ERROR_CODE5001 = "5001";

struct vehicle{
    char vehicle_code[VEHICLE_CODE_SIZE];
    char vehicle_number[VEHICLE_NUMBER_SIZE];
};

struct item{
    char item_code[ITEM_CODE_SIZE];
    char item_name[ITEM_NAME_SIZE];
    float item_price;
};

struct stock{
    char stock_code[STOCK_CODE_SIZE];
    char item_code[ITEM_CODE_SIZE];
    int stock_qty;
};

struct loading{
    char loading_code[LOADING_CODE_SIZE];
    char vehicle_code[VEHICLE_CODE_SIZE];
    char stock_code[STOCK_CODE_SIZE];
    int loaded_qty;
};

struct unloading{
    char loading_code[LOADING_CODE_SIZE];
    char vehicle_code[VEHICLE_CODE_SIZE];
    char stock_code[STOCK_CODE_SIZE];
    int loaded_qty;
};

void main();
char runMainMenu();
void runManageVehicles(struct vehicle[VEHICLES_ARRAY_SIZE], int *);
void viewVehicles(struct vehicle[VEHICLES_ARRAY_SIZE], int *);
void addVehicle(struct vehicle[VEHICLES_ARRAY_SIZE], int *);
void updateVehicle(struct vehicle[VEHICLES_ARRAY_SIZE], int *);
void deleteVehicle(struct vehicle[VEHICLES_ARRAY_SIZE], int *);
void runManageItems(struct item[ITEMS_ARRAY_SIZE], int *);
void viewItems(struct item[ITEMS_ARRAY_SIZE], int *);
void addItem(struct item[ITEMS_ARRAY_SIZE], int *);
void updateItem(struct item[ITEMS_ARRAY_SIZE], int *);
void deleteItem(struct item[ITEMS_ARRAY_SIZE], int *);
void runManageStocks(struct stock[STOCKS_ARRAY_SIZE], int *, struct item[ITEMS_ARRAY_SIZE], int *);
void viewStocks(struct stock[STOCKS_ARRAY_SIZE], int *);
void addStock(struct stock[STOCKS_ARRAY_SIZE], int *, struct item[ITEMS_ARRAY_SIZE], int *);
void updateStock(struct stock[STOCKS_ARRAY_SIZE], int *, struct item[ITEMS_ARRAY_SIZE], int *);
void deleteStock(struct stock[STOCKS_ARRAY_SIZE], int *);
void runManageLoadings(struct loading[LOADINGS_ARRAY_SIZE], int *, struct vehicle[VEHICLES_ARRAY_SIZE], int *, struct stock[STOCKS_ARRAY_SIZE], int *);
void viewLoadings(struct loading[LOADINGS_ARRAY_SIZE], int *);
void addLoading(struct loading[LOADINGS_ARRAY_SIZE], int *, struct vehicle[VEHICLES_ARRAY_SIZE], int *, struct stock[STOCKS_ARRAY_SIZE], int *);
void updateLoading(struct loading[LOADINGS_ARRAY_SIZE], int *, struct vehicle[VEHICLES_ARRAY_SIZE], int *, struct stock[STOCKS_ARRAY_SIZE], int *);
void deleteLoading(struct loading[LOADINGS_ARRAY_SIZE], int *);
void runManageUnloadings(struct unloading[UNLOADINGS_ARRAY_SIZE], int *, struct loading[LOADINGS_ARRAY_SIZE], int *);
void viewUnloadings(struct unloading[UNLOADINGS_ARRAY_SIZE], int *);
void addUnloading(struct unloading[UNLOADINGS_ARRAY_SIZE], int *, struct loading[LOADINGS_ARRAY_SIZE], int *);
void updateUnloading(struct unloading[UNLOADINGS_ARRAY_SIZE], int *, struct loading[LOADINGS_ARRAY_SIZE], int *);
void deleteUnloading(struct unloading[UNLOADINGS_ARRAY_SIZE], int *);
void printErrorMessage(char*);

void main(){
    int currentVehicles = 0;
    int currentItems = 0;
    int currentStocks = 0;
    int currentLoadings = 0;
    int currentUnloadings = 0;

    struct vehicle vehicles[VEHICLES_ARRAY_SIZE];
    struct item items[ITEMS_ARRAY_SIZE];
    struct stock stocks[STOCKS_ARRAY_SIZE];
    struct loading loadings[LOADINGS_ARRAY_SIZE];
    struct unloading unloadings[UNLOADINGS_ARRAY_SIZE];

    printf("\n\t <--- WELCOME to XYZ Distribution Management System ---> \t\n");

    while(1){
        char mainMenuResponse = runMainMenu();
        if(mainMenuResponse == '1'){
            runManageVehicles(vehicles, &currentVehicles);
        }else if(mainMenuResponse == '2'){
            runManageItems(items, &currentItems);
        }else if(mainMenuResponse == '3'){
            runManageStocks(stocks, &currentStocks, items, &currentItems);
        }else if(mainMenuResponse == '4'){
            runManageLoadings(loadings, &currentLoadings, vehicles, &currentVehicles, stocks, &currentStocks);
        }else if(mainMenuResponse == '5'){
            runManageUnloadings(unloadings, &currentUnloadings, loadings, &currentLoadings);
        }else{
            printErrorMessage(ERROR_CODE0000);
        }
        printf("\n\n\n");
    };
}

char runMainMenu(){
    char mainMenuResponse;

    printf("\n < Main Menu >");
    printf("\n\t 1 - Manage Vehicles");
    printf("\n\t 2 - Manage Items");
    printf("\n\t 3 - Manage Stocks");
    printf("\n\t 4 - Manage Loadings");
    printf("\n\t 5 - Manage Unloadings");
    printf("\n Enter Your Response : ");

    scanf(" %c", &mainMenuResponse);
    return mainMenuResponse;
}

void runManageVehicles(struct vehicle vehicles[VEHICLES_ARRAY_SIZE], int *currentVehicles){
    char manageVehiclesMenuResponse;

    printf("\n\n < Manage Vehicles Menu >");
    printf("\n\t 1 - View Vehicles");
    printf("\n\t 2 - Add Vehicle");
    printf("\n\t 3 - Update Vehicle");
    printf("\n\t 4 - Delete Vehicle");
    printf("\n Enter Your Response : ");

    scanf(" %c", &manageVehiclesMenuResponse);

    if(manageVehiclesMenuResponse == '1'){
        viewVehicles(vehicles, currentVehicles);
    }else if(manageVehiclesMenuResponse == '2'){
        addVehicle(vehicles, currentVehicles);
    }else if(manageVehiclesMenuResponse == '3'){
        updateVehicle(vehicles, currentVehicles);
    }else if(manageVehiclesMenuResponse == '4'){
        deleteVehicle(vehicles, currentVehicles);
    }else{
        printErrorMessage(ERROR_CODE1000);
    }
}

void viewVehicles(struct vehicle vehicles[VEHICLES_ARRAY_SIZE], int *currentVehicles){
    printf("\n $ Here are All Vehicle Records... \n");

    printf("\n\t  Vehicle Code   |   Vehicle Number  ");

    for(int i=0; i<*currentVehicles; i++){
        printf("\n\t");
        int temp1 = ((16-(strlen(vehicles[i].vehicle_code)))/2) + ((((16-(strlen(vehicles[i].vehicle_code)))%2)+1)/2);
        for(int j=0; j<temp1; j++){
            printf(" ");
        }
        printf("%s", vehicles[i].vehicle_code);
        int temp2 = ((16-(strlen(vehicles[i].vehicle_code)))/2) + ((((16-(strlen(vehicles[i].vehicle_code)))%2)+2)/2);
        for(int j=0; j<temp2; j++){
            printf(" ");
        }
        printf(":");
        int temp3 = (18-(strlen(vehicles[i].vehicle_number)))/2;
        for(int j=0; j<temp3; j++){
            printf(" ");
        }
        printf("%s", vehicles[i].vehicle_number);
        int temp4 = (18-(strlen(vehicles[i].vehicle_number)))/2;
        for(int j=0; j<temp4; j++){
            printf(" ");
        }
    }

    printf("\n\n");
}

void addVehicle(struct vehicle vehicles[VEHICLES_ARRAY_SIZE], int *currentVehicles){
    printf("\n $ Please Fill Following Details to Add a Vehicle... \n");

    printf("\n\t Enter Vehicle Code : ");
    scanf(" %[^\n]", vehicles[*currentVehicles].vehicle_code);
    printf("\n\t Enter Vehicle Number : ");
    scanf(" %[^\n]", vehicles[*currentVehicles].vehicle_number);

    *currentVehicles = *currentVehicles + 1;

    printf("\n * Vehicle has been Saved Successfully. \n");
}

void updateVehicle(struct vehicle vehicles[VEHICLES_ARRAY_SIZE], int *currentVehicles){
    printf("\n * Update Vehicle Function Currently Not Available... \n");
}

void deleteVehicle(struct vehicle vehicles[VEHICLES_ARRAY_SIZE], int *currentVehicles){
    printf("\n * Delete Vehicle Function Currently Not Available... \n");
}

void runManageItems(struct item items[ITEMS_ARRAY_SIZE], int *currentItems){
    char manageItemsMenuResponse;

    printf("\n\n $ Manage Items Menu >");
    printf("\n\t 1 - View Items");
    printf("\n\t 2 - Add Item");
    printf("\n\t 3 - Update Item");
    printf("\n\t 4 - Delete Item");
    printf("\n Enter Your Response : ");

    scanf(" %c", &manageItemsMenuResponse);

    if(manageItemsMenuResponse == '1'){
        viewItems(items, currentItems);
    }else if(manageItemsMenuResponse == '2'){
        addItem(items, currentItems);
    }else if(manageItemsMenuResponse == '3'){
        updateItem(items, currentItems);
    }else if(manageItemsMenuResponse == '4'){
        deleteItem(items, currentItems);
    }else{
        printErrorMessage(ERROR_CODE2000);
    }
}

void viewItems(struct item items[ITEMS_ARRAY_SIZE], int *currentItems){
    printf("\n $ Here are All Item Records... \n");

    printf("\n\t  Item Code   |   Item Name  |  Item Price  ");

    for(int i=0; i<*currentItems; i++){
        printf("\n\t");
        int temp1 = ((13-(strlen(items[i].item_code)))/2) + ((((13-(strlen(items[i].item_code)))%2)+1)/2);
        for(int j=0; j<temp1; j++){
            printf(" ");
        }
        printf("%s", items[i].item_code);
        int temp2 = ((13-(strlen(items[i].item_code)))/2) + ((((13-(strlen(items[i].item_code)))%2)+2)/2);
        for(int j=0; j<temp2; j++){
            printf(" ");
        }
        printf(":");
        int temp3 = ((13-(strlen(items[i].item_name)))/2) + ((((13-(strlen(items[i].item_name)))%2)+1)/2);
        for(int j=0; j<temp3; j++){
            printf(" ");
        }
        printf("%s", items[i].item_name);
        int temp4 = ((13-(strlen(items[i].item_name)))/2) + ((((13-(strlen(items[i].item_name)))%2)+2)/2);
        for(int j=0; j<temp4; j++){
            printf(" ");
        }
        printf(":");
        int temp5 = (14-(floor(log10(abs((int)items[i].item_price))) - 2 ))/2;
        for(int j=0; j<temp3; j++){
            printf(" ");
        }
        printf("%.2f", items[i].item_price);
        int temp6 = (14-(floor(log10(abs((int)items[i].item_price))) - 2))/2;
        for(int j=0; j<temp6; j++){
            printf(" ");
        }
    }

    printf("\n\n");
}

void addItem(struct item items[ITEMS_ARRAY_SIZE], int *currentItems){
    printf("\n $ Please Fill Following Details to Add a Item... \n");

    char itemPrice [ITEM_PRICE_SIZE];

    printf("\n\t Enter Item Code : ");
    scanf(" %[^\n]", items[*currentItems].item_code);
    printf("\n\t Enter Item Name : ");
    scanf(" %[^\n]", items[*currentItems].item_name);
    printf("\n\t Enter Item Price : ");
    scanf(" %s", itemPrice);

    items[*currentItems].item_price = atof(itemPrice);

    *currentItems = *currentItems + 1;

    printf("\n * Item has been Saved Successfully. \n");
}

void updateItem(struct item items[ITEMS_ARRAY_SIZE], int *currentItems){
    printf("\n * Update Item Function Currently Not Available... \n");
}

void deleteItem(struct item items[ITEMS_ARRAY_SIZE], int *currentItems){
    printf("\n * Delete Item Function Currently Not Available... \n");
}

void runManageStocks(struct stock stocks[STOCKS_ARRAY_SIZE], int *currentStocks, struct item items[ITEMS_ARRAY_SIZE], int *currentItems){
    char manageStocksMenuResponse;

    printf("\n\n $ Manage Stocks Menu >");
    printf("\n\t 1 - View Stocks");
    printf("\n\t 2 - Add Stock");
    printf("\n\t 3 - Update Stock");
    printf("\n\t 4 - Delete Stock");
    printf("\n Enter Your Response : ");

    scanf(" %c", &manageStocksMenuResponse);

    if(manageStocksMenuResponse == '1'){
        viewStocks(stocks, currentStocks);
    }else if(manageStocksMenuResponse == '2'){
        addStock(stocks, currentStocks, items, currentItems);
    }else if(manageStocksMenuResponse == '3'){
         updateStock(stocks, currentStocks, items, currentItems);
    }else if(manageStocksMenuResponse == '4'){
         deleteStock(stocks, currentStocks);
    }else{
        printErrorMessage(ERROR_CODE3000);
    }
}

void viewStocks(struct stock stocks[STOCKS_ARRAY_SIZE], int *currentStocks){
    printf("\n $ Here are All Stock Records... \n");

    printf("\n\t  Stock Code  |  Item Code  |  Stock Quantity  ");

    for(int i=0; i<*currentStocks; i++){
        printf("\n\t");
        int temp1 = ((14-(strlen(stocks[i].stock_code)))/2) + ((((14-(strlen(stocks[i].stock_code)))%2)+1)/2);
        for(int j=0; j<temp1; j++){
            printf(" ");
        }
        printf("%s", stocks[i].stock_code);
        int temp2 = ((14-(strlen(stocks[i].stock_code)))/2) + ((((14-(strlen(stocks[i].stock_code)))%2)+2)/2);
        for(int j=0; j<temp2; j++){
            printf(" ");
        }
        printf(":");
        int temp3 = ((13-(strlen(stocks[i].item_code)))/2) + ((((13-(strlen(stocks[i].item_code)))%2)+1)/2);
        for(int j=0; j<temp3; j++){
            printf(" ");
        }
        printf("%s", stocks[i].item_code);
        int temp4 = ((13-(strlen(stocks[i].item_code)))/2) + ((((13-(strlen(stocks[i].item_code)))%2)+2)/2);
        for(int j=0; j<temp4; j++){
            printf(" ");
        }
        printf(":");
        int temp5 = (18-(floor(log10(abs(stocks[i].stock_qty))) + 1))/2;
        for(int j=0; j<temp5; j++){
            printf(" ");
        }
        printf("%d", stocks[i].stock_qty);
        int temp6 = (18-(floor(log10(abs(stocks[i].stock_qty))) + 1))/2;
        for(int j=0; j<temp6; j++){
            printf(" ");
        }
    }

    printf("\n\n");
}

void addStock(struct stock stocks[STOCKS_ARRAY_SIZE], int *currentStocks, struct item items[ITEMS_ARRAY_SIZE], int *currentItems){
    printf("\n $ Please Fill Following Details to Add a Stock... \n");

    char stockCode [STOCK_CODE_SIZE];
    char itemCode [ITEM_CODE_SIZE];
    char stockQty [STOCK_QTY_SIZE];

    bool ifExistItemCode = false;

    printf("\n\t Enter Stock Code : ");
    scanf(" %[^\n]", stockCode);

    printf("\n\t Enter Item Code : ");
    scanf(" %[^\n]", itemCode);

    for(int i=0; i<*currentItems; i++){
        if(strcmp(items[i].item_code, itemCode)== 0){
            ifExistItemCode = true;
        }
    }

    if(ifExistItemCode){
        for(int i=0; i<strlen(stockCode); i++){
            stocks[*currentStocks].stock_code[i] = stockCode[i];
        }

        for(int i=0; i<strlen(itemCode); i++){
            stocks[*currentStocks].item_code[i] = itemCode[i];
        }

        printf("\n\t Enter Stock Quantity : ");
        scanf("%s", stockQty);
        stocks[*currentStocks].stock_qty = atoi(stockQty);

        *currentStocks = *currentStocks + 1;

        printf("\n * Stock has been Saved Successfully. \n");
    }else{
        printErrorMessage(ERROR_CODE3001);
    }
}

void updateStock(struct stock stocks[STOCKS_ARRAY_SIZE], int *currentStocks, struct item items[ITEMS_ARRAY_SIZE], int *currentItems){
    printf("\n * Update Stock Function Currently Not Available... \n");
}

void deleteStock(struct stock stocks[STOCKS_ARRAY_SIZE], int *currentStocks){
    printf("\n * Delete Stock Function Currently Not Available... \n");
}

void runManageLoadings(
                       struct loading loadings[LOADINGS_ARRAY_SIZE], int *currentLoadings,
                       struct vehicle vehicles[VEHICLES_ARRAY_SIZE], int *currentVehicles,
                       struct stock stocks[STOCKS_ARRAY_SIZE], int *currentStocks
                       ){
    char manageLoadingssMenuResponse;

    printf("\n\n $ Manage Loadings Menu >");
    printf("\n\t 1 - View Loadings");
    printf("\n\t 2 - Add Loading");
    printf("\n\t 3 - Update Loading");
    printf("\n\t 4 - Delete Loading");
    printf("\n Enter Your Response : ");

    scanf(" %c", &manageLoadingssMenuResponse);

    if(manageLoadingssMenuResponse == '1'){
        viewLoadings(loadings, currentLoadings);
    }else if(manageLoadingssMenuResponse == '2'){
        addLoading(loadings, currentLoadings, vehicles, currentVehicles, stocks, currentStocks);
    }else if(manageLoadingssMenuResponse == '3'){
        updateLoading(loadings, currentLoadings, vehicles, currentVehicles, stocks, currentStocks);
    }else if(manageLoadingssMenuResponse == '4'){
        deleteLoading(loadings, currentLoadings);
    }else{
        printErrorMessage(ERROR_CODE4000);
    }
}

void viewLoadings(struct loading loadings[LOADINGS_ARRAY_SIZE], int *currentLoadings){
    printf("\n $ Here are All Loading Records... \n");

    printf("\n\t  Loading Code  |  Vehicle Code  |  Stock Code  |  Loaded Quantity  ");

    for(int i=0; i<*currentLoadings; i++){
        printf("\n\t");
        int temp1 = ((16-(strlen(loadings[i].loading_code)))/2) + ((((16-(strlen(loadings[i].loading_code)))%2)+1)/2);
        for(int j=0; j<temp1; j++){
            printf(" ");
        }
        printf("%s", loadings[i].loading_code);
        int temp2 = ((16-(strlen(loadings[i].loading_code)))/2) + ((((16-(strlen(loadings[i].loading_code)))%2)+2)/2);
        for(int j=0; j<temp2; j++){
            printf(" ");
        }
        printf(":");
        int temp3 = ((16-(strlen(loadings[i].vehicle_code)))/2) + ((((16-(strlen(loadings[i].vehicle_code)))%2)+1)/2);
        for(int j=0; j<temp3; j++){
            printf(" ");
        }
        printf("%s", loadings[i].vehicle_code);
        int temp4 = ((16-(strlen(loadings[i].vehicle_code)))/2) + ((((16-(strlen(loadings[i].vehicle_code)))%2)+2)/2);
        for(int j=0; j<temp4; j++){
            printf(" ");
        }
        printf(":");
        int temp5 = ((14-(strlen(loadings[i].stock_code)))/2) + ((((14-(strlen(loadings[i].stock_code)))%2)+1)/2);
        for(int j=0; j<temp5; j++){
            printf(" ");
        }
        printf("%s", loadings[i].stock_code);
        int temp6 = ((14-(strlen(loadings[i].stock_code)))/2) + ((((14-(strlen(loadings[i].stock_code)))%2)+2)/2);
        for(int j=0; j<temp6; j++){
            printf(" ");
        }
        printf(":");
        int temp7 = (19-(floor(log10(abs(loadings[i].loaded_qty))) + 1))/2;
        for(int j=0; j<temp7; j++){
            printf(" ");
        }
        printf("%d", loadings[i].loaded_qty);
        int temp8 = (19-(floor(log10(abs(loadings[i].loaded_qty))) + 1))/2;
        for(int j=0; j<temp8; j++){
            printf(" ");
        }
    }

    printf("\n\n");
}

void addLoading(
                struct loading loadings[LOADINGS_ARRAY_SIZE], int *currentLoadings,
                struct vehicle vehicles[VEHICLES_ARRAY_SIZE], int *currentVehicles,
                struct stock stocks[STOCKS_ARRAY_SIZE], int *currentStocks
                ){
    printf("\n $ Please Fill Following Details to Add a Loading... \n");

    char loadingCode [LOADING_CODE_SIZE];
    char vehicleCode [VEHICLE_CODE_SIZE];
    char stockCode [STOCK_CODE_SIZE];
    char loadedQty [LOADING_QTY_SIZE];

    bool ifExistVehicleCode = false;
    bool ifExistStockCode = false;

    int count = 0;

    printf("\n\t Enter Loading Code : ");
    scanf(" %[^\n]", loadingCode);

    printf("\n\t Enter Vehicle Code : ");
    scanf(" %[^\n]", vehicleCode);


    for(int i=0; i<*currentVehicles; i++){
        if(strcmp(vehicles[i].vehicle_code, vehicleCode)== 0){
            ifExistVehicleCode = true;
        }
    }

    if(ifExistVehicleCode){
        printf("\n\t Enter Stock Code : ");
        scanf(" %[^\n]", stockCode);

        for(int i=0; i<*currentStocks; i++){
            if(strcmp(stocks[i].stock_code, stockCode)== 0){
                ifExistStockCode = true;
                count = i;
            }
        }

        if(ifExistStockCode){
            printf("\n\t Enter Loaded Quantity : ");
            scanf("%s", loadedQty);

            if(stocks[count].stock_qty >= atoi(loadedQty)){
                for(int i=0; i<strlen(loadingCode); i++){
                    loadings[*currentLoadings].loading_code[i] = loadingCode[i];
                }

                for(int i=0; i<strlen(vehicleCode); i++){
                    loadings[*currentLoadings].vehicle_code[i] = vehicleCode[i];
                }

                for(int i=0; i<strlen(stockCode); i++){
                    loadings[*currentLoadings].stock_code[i] = stockCode[i];
                }

                loadings[*currentLoadings].loaded_qty = atoi(loadedQty);

                stocks[count].stock_qty = stocks[count].stock_qty - atoi(loadedQty);

                *currentLoadings = *currentLoadings + 1;

                printf("\n * Loading has been Saved Successfully. \n");
            }else{
                printErrorMessage(ERROR_CODE4003);
            }
        }else{
            printErrorMessage(ERROR_CODE4002);
        }
    }else{
        printErrorMessage(ERROR_CODE4001);
    }
}

void updateLoading(
                    struct loading loadings[LOADINGS_ARRAY_SIZE], int *currentLoadings,
                    struct vehicle vehicles[VEHICLES_ARRAY_SIZE], int *currentVehicles,
                    struct stock stocks[STOCKS_ARRAY_SIZE], int *currentStocks
                   ){
    printf("\n * Update Loading Function Currently Not Available... \n");
}

void deleteLoading(struct loading loadings[LOADINGS_ARRAY_SIZE], int *currentLoadings){
    printf("\n * Delete Loading Function Currently Not Available... \n");
}

void runManageUnloadings(struct unloading unloadings[LOADINGS_ARRAY_SIZE], int *currentUnloadings, struct loading loadings[LOADINGS_ARRAY_SIZE], int *currentLoadings){
    char manageUnloadingssMenuResponse;

    printf("\n\n $ Manage Unloadings Menu >");
    printf("\n\t 1 - View Unloadings");
    printf("\n\t 2 - Add Unloading");
    printf("\n\t 3 - Update Unloading");
    printf("\n\t 4 - Delete Unloading");
    printf("\n Enter Your Response : ");

    scanf(" %c", &manageUnloadingssMenuResponse);

    if(manageUnloadingssMenuResponse == '1'){
        viewUnloadings(unloadings, currentUnloadings);
    }else if(manageUnloadingssMenuResponse == '2'){
        addUnloading(unloadings, currentUnloadings, loadings, currentLoadings);
    }else if(manageUnloadingssMenuResponse == '3'){
        updateUnloading(unloadings, currentUnloadings, loadings, currentLoadings);
    }else if(manageUnloadingssMenuResponse == '4'){
        deleteUnloading(unloadings, currentUnloadings);
    }else{
        printErrorMessage(ERROR_CODE5000);
    }
}

void viewUnloadings(struct unloading unloadings[LOADINGS_ARRAY_SIZE], int *currentUnloadings){
    printf("\n $ Here are All Unloading Records... \n");

    printf("\n\t  Loading Code  |  Vehicle Code  |  Stock Code  |  Loaded Quantity  ");

    for(int i=0; i<*currentUnloadings; i++){
        printf("\n\t");
        int temp1 = ((16-(strlen(unloadings[i].loading_code)))/2) + ((((16-(strlen(unloadings[i].loading_code)))%2)+1)/2);
        for(int j=0; j<temp1; j++){
            printf(" ");
        }
        printf("%s", unloadings[i].loading_code);
        int temp2 = ((16-(strlen(unloadings[i].loading_code)))/2) + ((((16-(strlen(unloadings[i].loading_code)))%2)+2)/2);
        for(int j=0; j<temp2; j++){
            printf(" ");
        }
        printf(":");
        int temp3 = ((16-(strlen(unloadings[i].vehicle_code)))/2) + ((((16-(strlen(unloadings[i].vehicle_code)))%2)+1)/2);
        for(int j=0; j<temp3; j++){
            printf(" ");
        }
        printf("%s", unloadings[i].vehicle_code);
        int temp4 = ((16-(strlen(unloadings[i].vehicle_code)))/2) + ((((16-(strlen(unloadings[i].vehicle_code)))%2)+2)/2);
        for(int j=0; j<temp4; j++){
            printf(" ");
        }
        printf(":");
        int temp5 = ((14-(strlen(unloadings[i].stock_code)))/2) + ((((14-(strlen(unloadings[i].stock_code)))%2)+1)/2);
        for(int j=0; j<temp5; j++){
            printf(" ");
        }
        printf("%s", unloadings[i].stock_code);
        int temp6 = ((14-(strlen(unloadings[i].stock_code)))/2) + ((((14-(strlen(unloadings[i].stock_code)))%2)+2)/2);
        for(int j=0; j<temp6; j++){
            printf(" ");
        }
        printf(":");
        int temp7 = (19-(floor(log10(abs(unloadings[i].loaded_qty))) + 1))/2;
        for(int j=0; j<temp7; j++){
            printf(" ");
        }
        printf("%d", unloadings[i].loaded_qty);
        int temp8 = (19-(floor(log10(abs(unloadings[i].loaded_qty))) + 1))/2;
        for(int j=0; j<temp8; j++){
            printf(" ");
        }
    }

    printf("\n\n");
}

void addUnloading(struct unloading unloadings[LOADINGS_ARRAY_SIZE], int *currentUnloadings, struct loading loadings[LOADINGS_ARRAY_SIZE], int *currentLoadings){
    printf("\n $ Please Fill Following Details to Add a Unloading... \n");

    char loadingCode [LOADING_CODE_SIZE];

    bool ifExistLoadingCode = false;

    int count = 0;

    printf("\n\t Enter Loading Code : ");
    scanf(" %[^\n]", loadingCode);


    for(int i=0; i<*currentLoadings; i++){
        if(strcmp(loadings[i].loading_code, loadingCode)== 0){
            ifExistLoadingCode = true;
            count = i;
        }
    }

    if(ifExistLoadingCode){

        for(int i=0; i<strlen(loadings[count].loading_code); i++){
            unloadings[*currentUnloadings].loading_code[i] = loadings[count].loading_code[i];
        }

        for(int i=0; i<strlen(loadings[count].vehicle_code); i++){
            unloadings[*currentUnloadings].vehicle_code[i] = loadings[count].vehicle_code[i];
        }

        for(int i=0; i<strlen(loadings[count].stock_code); i++){
            unloadings[*currentUnloadings].stock_code[i] = loadings[count].stock_code[i];
        }

        unloadings[*currentUnloadings].loaded_qty = loadings[count].loaded_qty;

        *currentUnloadings = *currentUnloadings + 1;

        printf("\n * Loading has been Unloaded Successfully. \n");
    }else{
        printErrorMessage(ERROR_CODE5001);
    }
}

void updateUnloading(struct unloading unloadings[LOADINGS_ARRAY_SIZE], int *currentUnloadings, struct loading loadings[LOADINGS_ARRAY_SIZE], int *currentLoadings){
    printf("\n * Update Unloading Function Currently Not Available... \n");
}

void deleteUnloading(struct unloading unloadings[LOADINGS_ARRAY_SIZE], int *currentUnloadings){
    printf("\n * Delete Unloading Function Currently Not Available... \n");
}

void printErrorMessage(char* errorCode){
    if(errorCode == ERROR_CODE0000){
        printf("\n # Error!, The Response that You have Entered for Main Menu is Incorrect. \n");
    }else if(errorCode == ERROR_CODE1000){
        printf("\n # Error!, The Response that You have Entered for Manage Vehicles Menu is Incorrect. \n");
    }else if(errorCode == ERROR_CODE2000){
        printf("\n # Error!, The Response that You have Entered for Manage Items Menu is Incorrect. \n");
    }else if(errorCode == ERROR_CODE3000){
        printf("\n # Error!, The Response that You have Entered for Manage Stocks Menu is Incorrect. \n");
    }else if(errorCode == ERROR_CODE3001){
        printf("\n # Error!, The Item Code You have Entered does not Exist. \n");
    }else if(errorCode == ERROR_CODE4000){
        printf("\n # Error!, The Response that You have Entered for Manage Loadings Menu is Incorrect. \n");
    }else if(errorCode == ERROR_CODE4001){
        printf("\n # Error!, The Vehicle Code You have Entered does not Exist. \n");
    }else if(errorCode == ERROR_CODE4002){
        printf("\n # Error!, The Stock Code You have Entered does not Exist. \n");
    }else if(errorCode == ERROR_CODE4003){
        printf("\n # Error!, The Loaded Quantity You have Entered is Greater than Stock Quantity. \n");
    }else if(errorCode == ERROR_CODE5000){
        printf("\n # Error!, The Response that You have Entered for Manage Unloadings Menu is Incorrect. \n");
    }else if(errorCode == ERROR_CODE5001){
        printf("\n # Error!, The Loading Code You have Entered does not Exist. \n");
    }
}
