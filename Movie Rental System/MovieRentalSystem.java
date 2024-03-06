package RefactoredMovieCode;

import java.util.Scanner;

public class MovieRentalSystem {
	public static void main(String[] args) {
		 Scanner scanner = new Scanner(System.in);
        Customer customer = new Customer("Hashir Ahmad");

        int choice;
        do {
            System.out.println("\n===== Movie Rental System Menu =====");
            System.out.println("1. Rent a Movie");
            System.out.println("2. View Rental Statement");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");

            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    rentMovie(customer);
                    break;
                case 2:
                    viewRentalStatement(customer);
                    break;
                case 3:
                    System.out.println("Exiting Movie Rental System. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 3);
    }

    private static void rentMovie(Customer customer) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n===== Available Movies =====");
        System.out.println("1. Regular Movie");
        System.out.println("2. New Release");
        System.out.println("3. Children's Movie");
        System.out.print("Enter movie type (1-3): ");
        int movieType = scanner.nextInt();

        System.out.print("Enter movie title: ");
        scanner.nextLine(); // Consume newline character
        String title = scanner.nextLine();

        System.out.print("Enter number of days to rent: ");
        int daysRented = scanner.nextInt();

        Movie movie;
        switch (movieType) {
            case 1:
                movie = new Movie(title, Movie.REGULAR);
                break;
            case 2:
                movie = new Movie(title, Movie.NEW_RELEASE);
                break;
            case 3:
                movie = new Movie(title, Movie.CHILDRENS);
                break;
            default:
                System.out.println("Invalid movie type. Rental canceled.");
                return;
        }

        Rental rental = new Rental(movie, daysRented);
        customer.addRental(rental);
        System.out.println("Movie rented successfully!");
    }

    private static void viewRentalStatement(Customer customer) {
        System.out.println("\n===== Rental Statement =====");
        System.out.println(customer.statement());
    }

}

