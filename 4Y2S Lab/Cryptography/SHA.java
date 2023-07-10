import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class SHA{
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the input string: ");
            String input = sc.nextLine();

            // Create SHA-256 hash instance
            MessageDigest md = MessageDigest.getInstance("SHA-256");

            // Convert input string to bytes
            byte[] inputBytes = input.getBytes();

            // Calculate the SHA-256 hash
            byte[] hashBytes = md.digest(inputBytes);

            // Convert hash bytes to hexadecimal representation
            StringBuilder hashString = new StringBuilder();
            for (byte b : hashBytes) {
                hashString.append(String.format("%02x", b));
            }

            // Print the SHA-256 hash
            System.out.println("SHA-256 Hash: " + hashString.toString());
        } catch (NoSuchAlgorithmException e) {
            System.out.println("SHA-256 algorithm not available.");
        }
    }
}
