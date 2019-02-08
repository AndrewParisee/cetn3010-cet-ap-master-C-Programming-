#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


int main() {
    char gps_string[] = "";
    char gps_time [11];
    strcpy(gps_time,"");
    char gps_active;
    char gps_latitude [10];
    strcpy(gps_latitude,"");
    char gps_north_south;
    char gps_longitude [11];
    strcpy(gps_longitude,"");
    char gps_east_west;
    char gps_speed [5];
    strcpy(gps_speed,"");
    char gps_angle [7];
    strcpy(gps_angle,"");
    char gps_date [7];
    strcpy(gps_date,"");
    char gps_variance [7];
    strcpy(gps_variance, "");
    char gps_variance_direction;

    printf("Assignment 4 - GPS\n");
    printf("------------------\n");
    printf("Incoming GPS DATA.....\n");
    printf("Enter GPS Data: ");
    scanf("%s", gps_string);

    char* token;
    char delim = ',';
    token = strtok(gps_string, delim);


    strcpy(gps_time, strtok(NULL, &delim));
    gps_active = *strtok(NULL, &delim);
    strcpy(gps_latitude, strtok(NULL, &delim));
    gps_north_south = *strtok(NULL, &delim);
    strcpy(gps_longitude, strtok(NULL, delim));
    gps_east_west = *strtok(NULL, &delim);
    strcpy(gps_speed, strtok(NULL, &delim));
    strcpy(gps_angle, strtok(NULL, &delim));
    strcpy(gps_date, strtok(NULL, &delim));
    strcpy(gps_variance, strtok(NULL, &delim));
    gps_variance_direction = *strtok(NULL, &delim);

    printf("Active: %c", gps_active);
    printf("\nDate: %s ", gps_date);
    printf("%s  ", gps_time);
    printf("\nLatitude: %s ",gps_latitude);
    printf("%c  ", gps_north_south); // Direction e.g N,S,W,E
    printf("\nLongitude: %s ", gps_longitude);
    printf("%c  ",gps_east_west); // Direction e.g N,S,W,E
    printf("\nSpeed: %s | ", gps_speed);
    printf("\nAngle: %s | ", gps_angle);
    printf("\nVariance: %s ", gps_variance);
    printf("%c ", gps_variance_direction);
    strcpy(gps_string,"");


    return 0;
}



