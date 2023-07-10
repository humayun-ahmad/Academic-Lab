import java.util.*;

class DiffieHellman{
    static long modPow(long a, long b, long c){
        if(b==1) return (long)a;
        long res = modPow(a, b/2, c);
        res = (res * res) % c;
        if(b%2 == 1) res = (res * a) % c;
        return res;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            //the prime number p and it's primitive root a
            long p = 23, a = 9;
            System.out.print("Enter the Alice's secret key: ");
            long Xa = sc.nextInt();
            System.out.print("Enter the Bob's secret key: ");
            long Xb = sc.nextInt();

            long Ya = modPow(a, Xa, p);
            long Yb = modPow(a, Xb, p);

            long Ka = modPow(Yb, Xa, p);
            long Kb = modPow(Ya, Xb, p);

            System.out.println("Alice's key: "+Ka);
            System.out.println("Bob's key: "+Kb);
        }
    }
}