#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    int id;
    char title[100];
    char showDate[20];
    char showTime[20];
};

struct Ticket {
    int movieNumber;
    char customerName[100];
    int idNumber;
    int seatNumber;
    char phoneNumber[15];
    int addFoodOption;
};

struct Movie movies[100];
struct Ticket bookings[100];
int totalMovies = 0;
int totalBookings = 0;

void adminLogin();
void addMovie();
void listAllMovies();
void cancelBooking();
void searchMovie();
void updateMovie();
void displayMovieAndTicket();
void displayBookingDetails(int bookingIndex);
void bookTicket();

int main() {
    printf("WELCOME TO ZAN CINEMA TICKET BOOKING\n");

    int choice;
    do {
        printf("\n1. Admin Login\n2. Book Ticket\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminLogin();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void adminLogin() {
    char username[20], password[20];
    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    // Hardcoded admin credentials for demonstration purposes
    if (strcmp(username, "admin") == 0 && strcmp(password, "123") == 0) {
        int adminChoice;
        do {
            printf("\nAdmin Menu:\n");
            printf("1. Add Movie\n");
            printf("2. List All Movies\n");
            printf("3. Cancel Booking\n");
            printf("4. Search Movie\n");
            printf("5. Update Movie\n");
            printf("6. Display Movie and Ticket\n");
            printf("7. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &adminChoice);

            switch (adminChoice) {
                case 1:
                    addMovie();
                    break;
                case 2:
                    listAllMovies();
                    break;
                case 3:
                    cancelBooking();
                    break;
                case 4:
                    searchMovie();
                    break;
                case 5:
                    updateMovie();
                    break;
                case 6:
                    displayMovieAndTicket();
                    break;
                case 7:
                    printf("Exiting admin menu.\n");
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (adminChoice != 7);
    } else {
        printf("Invalid credentials. Access denied.\n");
    }
}

void addMovie() {
    if (totalMovies < 100) {
        printf("\nEnter Movie Details:\n");
        printf("Movie ID: ");
        scanf("%d", &movies[totalMovies].id);
        printf("Movie Title: ");
        scanf("%s", movies[totalMovies].title);
        printf("Show Date: ");
        scanf("%s", movies[totalMovies].showDate);
        printf("Show Time: ");
        scanf("%s", movies[totalMovies].showTime);

        totalMovies++;
        printf("Movie added successfully!\n");
    } else {
        printf("Movie database is full. Cannot add more movies.\n");
    }
}

void listAllMovies() {
    if (totalMovies > 0) {
        printf("\nList of All Movies:\n");
        for (int i = 0; i < totalMovies; i++) {
            printf("Movie ID: %d\n", movies[i].id);
            printf("Title: %s\n", movies[i].title);
            printf("Enter Show Date: %s\n", movies[i].showDate);
            printf("Enter Show Time: %s\n\n", movies[i].showTime);
        }
    } else {
        printf("No movies available.\n");
    }
}

void cancelBooking() {
    int bookingId;
    printf("Enter Booking ID to cancel: ");
    scanf("%d", &bookingId);

    if (bookingId >= 1 && bookingId <= totalBookings) {
        // Implement cancellation logic (remove booking from array)
        printf("Booking canceled successfully!\n");
    } else {
        printf("Invalid Booking ID.\n");
    }
}

void searchMovie() {
    char searchTitle[100];
    printf("Enter the movie title to search: ");
    scanf("%s", searchTitle);

    int found = 0;
    for (int i = 0; i < totalMovies; i++) {
        if (strcmp(searchTitle, movies[i].title) == 0) {
            printf("Movie found:\n");
            printf("Movie ID: %d\n", movies[i].id);
            printf("Title: %s\n", movies[i].title);
            printf("Show Date: %s\n", movies[i].showDate);
            printf("Show Time: %s\n", movies[i].showTime);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Movie not found.\n");
    }
}

void updateMovie() {
    int movieId;
    printf("Enter Movie ID to update: ");
    scanf("%d", &movieId);

    if (movieId >= 1 && movieId <= totalMovies) {
        printf("Enter updated details:\n");
        printf("Movie Title: ");
        scanf("%s", movies[movieId - 1].title);
        printf("Show Date: ");
        scanf("%s", movies[movieId - 1].showDate);
        printf("Show Time: ");
        scanf("%s", movies[movieId - 1].showTime);

        printf("Movie updated successfully!\n");
    } else {
        printf("Invalid Movie ID.\n");
    }
}

void displayMovieAndTicket() {
    if (totalBookings > 0) {
        for (int i = 0; i < totalBookings; i++) {
            displayBookingDetails(i);
        }
    } else {
        printf("No bookings available.\n");
    }
}

void displayBookingDetails(int bookingIndex) {
    printf("\nBooking Details:\n");
    printf("Movie Title: %s\n", movies[bookings[bookingIndex].movieNumber - 1].title);
    printf("Customer Name: %s\n", bookings[bookingIndex].customerName);
    printf("ID Number: %d\n", bookings[bookingIndex].idNumber);
    printf("Seat Number: %d\n", bookings[bookingIndex].seatNumber);
    printf("Phone Number: %s\n", bookings[bookingIndex].phoneNumber);

    if (bookings[bookingIndex].addFoodOption == 1) {
        printf("Ubuyu wa Babu\n");
    } else if (bookings[bookingIndex].addFoodOption == 2) {
        printf("Makwaru\n");
    } else {
        printf("No food option selected\n");
    }
}

void bookTicket() {
    if (totalMovies > 0) {
        printf("\nNOW SHOWING:\n");
        for (int i = 0; i < totalMovies; i++) {
            printf("%d. %s\n", i + 1, movies[i].title);
        }

        int movieNumber;
        printf("Enter Movie Number: ");
        scanf("%d", &movieNumber);

        if (movieNumber >= 1 && movieNumber <= totalMovies) {
            struct Movie selectedMovie = movies[movieNumber - 1];

            if (totalBookings < 100) {
                printf("\nEnter Customer Information:\n");
                bookings[totalBookings].movieNumber = movieNumber;
                printf("Customer Name: ");
                scanf("%s", bookings[totalBookings].customerName);

                // Validate and recommend unique ID number
                do {
                    printf("ID Number: ");
                    scanf("%d", &bookings[totalBookings].idNumber);

                    int isUnique = 1;
                    for (int i = 0; i < totalBookings; i++) {
                        if (bookings[i].idNumber == bookings[totalBookings].idNumber) {
                            isUnique = 0;
                            printf("ID Number already taken. Recommended next ID: %d\n", bookings[totalBookings].idNumber + 1);
                            break;
                        }
                    }

                    if (isUnique) {
                        break;
                    }
                } while (1);

                int seatNumber;
                do {
                    printf("Select Available Seat Number (1 to 100): ");
                    scanf("%d", &seatNumber);

                    // Check if the seat is already taken
                    int isSeatTaken = 0;
                    for (int i = 0; i < totalBookings; i++) {
                        if (bookings[i].seatNumber == seatNumber) {
                            isSeatTaken = 1;
                            printf("Seat number %d is already taken. Recommended next seat: %d\n", seatNumber, seatNumber + 1);
                            break;
                        }
                    }

                    if (!isSeatTaken && seatNumber >= 1 && seatNumber <= 100) {
                        bookings[totalBookings].seatNumber = seatNumber;
                        break;
                    } else if (seatNumber > 100) {
                        printf("Seat number is not available. Please enter a valid seat number (1 to 100).\n");
                    } else {
                        printf("Invalid seat number. Please enter a valid seat number (1 to 100).\n");
                    }
                } while (1);

                printf("Phone Number: ");
                scanf("%s", bookings[totalBookings].phoneNumber);

                int addFoodOption;
                printf("Do you want to add food?\n1. Yes\n2. No\nChoose [1/2]: ");
                scanf("%d", &addFoodOption);

                if (addFoodOption == 1) {
                    printf("Food Options:\n");
                    printf("1. Ubuyu wa Babu\n");
                    printf("2. Makwaru\n");
                    printf("Choose [1/2]: ");
                    scanf("%d", &bookings[totalBookings].addFoodOption);
                } else {
                    bookings[totalBookings].addFoodOption = 0;
                }

                totalBookings++;
                printf("Ticket booked successfully!\n");

                // Display booking details
                displayBookingDetails(totalBookings - 1);
            } else {
                printf("Booking limit reached. Cannot book more tickets.\n");
            }
        } else {
            printf("Invalid movie number.\n");
        }
    } else {
        printf("No movies available for booking.\n");
    }
}
