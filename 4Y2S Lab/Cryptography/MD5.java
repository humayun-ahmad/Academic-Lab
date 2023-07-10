import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class MD5 {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the input string: ");
            String input = sc.nextLine();

            // Create MD5 hash instance
            MessageDigest md = MessageDigest.getInstance("MD5");

            // Convert input string to bytes
            byte[] inputBytes = input.getBytes();

            // Calculate the MD5 hash
            byte[] hashBytes = md.digest(inputBytes);

            // Convert hash bytes to hexadecimal representation
            StringBuilder hashString = new StringBuilder();
            for (byte b : hashBytes) {
                hashString.append(String.format("%02x", b));
            }

            // Print the MD5 hash
            System.out.println("MD5 Hash: " + hashString.toString());
        } catch (NoSuchAlgorithmException e) {
            System.out.println("MD5 algorithm not available.");
        }
    }
}
