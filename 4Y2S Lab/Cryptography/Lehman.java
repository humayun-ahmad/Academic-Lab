import java.util.*;

class Lehman{
    
    static long modPow(long a, long b, long c){
        if(b==1) return (long)a;
        long res = modPow(a, b/2, c);
        res = (res * res) % c;
        if(b%2 == 1) res = (res * a) % c;
        return res;
    }

    static boolean lehman(long p, long t){
        Random rand = new Random();
        
        long e = (p-1)/2;

        while(t>0){
            long a = rand.nextLong(p-3)+2;
            //int a=2;
            long result = modPow(a, e, p);
            if(result!=1 && result!=p-1)
                return false;
            t--;
        }
        return true;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the number to be tested: ");
            long p = sc.nextLong();

            System.out.print("Enter the number of tries: ");
            long t = sc.nextLong();

            boolean flag;

            if(p==2)
                flag = true;
            else if(p%2==0 || p==1)
                flag = false;
            else
                flag = lehman(p, t);

            double error = 1/(Math.pow(2.0,t));

            if(flag)
                System.out.println(p+" is maybe prime at the error rate of "+error);
            else
                System.out.println(p+" is surely not prime");
        }

    }
}