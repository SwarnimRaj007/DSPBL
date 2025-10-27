#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "route.h"
#include "flight.h"
#include "booking.h"
#include "search.h"

void show_menu() {
    printf("\n===== Flight Booking System =====\n");
    printf("1. Add User\n");
    printf("2. Add Route\n");
    printf("3. Add Flight\n");
    printf("4. Book Flight\n");
    printf("5. List Users\n");
    printf("6. List Routes\n");
    printf("7. List Flights\n");
    printf("8. List Bookings\n");
    printf("9. Search Flights by Route and Date\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    init_users();
    init_routes();
    init_flights();
    init_bookings();

    int choice;
    while (1) {
        show_menu();
        if (scanf("%d", &choice) != 1) break;
        getchar(); // clear newline

        if (choice == 0) {
            printf("Exiting... Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1: {
                char name[NAME_LEN], email[EMAIL_LEN];
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';
                int id = add_user(name, email);
                printf("User added with ID: %d\n", id);
                break;
            }

            case 2: {
                char source[CITY_LEN], dest[CITY_LEN], code[CODE_LEN];
                printf("Enter source city: ");
                fgets(source, sizeof(source), stdin);
                source[strcspn(source, "\n")] = '\0';
                printf("Enter destination city: ");
                fgets(dest, sizeof(dest), stdin);
                dest[strcspn(dest, "\n")] = '\0';
                printf("Enter route code: ");
                fgets(code, sizeof(code), stdin);
                code[strcspn(code, "\n")] = '\0';
                int id = add_route(source, dest, code);
                printf("Route added with ID: %d\n", id);
                break;
            }

            case 3: {
                char flight_no[FLIGHT_ID_LEN], date[DATE_LEN];
                int route_id, seats;
                float fare;
                printf("Enter flight number: ");
                fgets(flight_no, sizeof(flight_no), stdin);
                flight_no[strcspn(flight_no, "\n")] = '\0';
                printf("Enter route ID: ");
                scanf("%d", &route_id);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter fare: ");
                scanf("%f", &fare);
                printf("Enter total seats: ");
                scanf("%d", &seats);
                getchar();
                int id = add_flight(flight_no, route_id, date, fare, seats);
                printf("Flight added with ID: %d\n", id);
                break;
            }

            case 4: {
                int user_id, flight_id, seats;
                printf("Enter user ID: ");
                scanf("%d", &user_id);
                printf("Enter flight ID: ");
                scanf("%d", &flight_id);
                printf("Enter number of seats: ");
                scanf("%d", &seats);
                getchar();
                int result = create_booking(user_id, flight_id, seats);
                if (result > 0)
                    printf("Booking created successfully! Booking ID: %d\n", result);
                else
                    printf("Booking failed (error %d)\n", result);
                break;
            }

            case 5: list_users(); break;
            case 6: list_routes(); break;
            case 7: list_flights(); break;
            case 8: list_bookings(); break;

            case 9: {
                char source[CITY_LEN], dest[CITY_LEN], date[DATE_LEN];
                printf("Enter source city: ");
                scanf("%s", source);
                printf("Enter destination city: ");
                scanf("%s", dest);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                int results[50];
                int found = search_flights_by_route_and_date(source, dest, date, results, 50);
                if (found == 0) printf("No flights found.\n");
                for (int i = 0; i < found; i++)
                    printf("Found flight ID: %d\n", results[i]);
                break;
            }

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
