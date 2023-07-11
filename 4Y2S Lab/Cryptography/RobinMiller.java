import java.util.*;

public class RobinMiller {

    static long modPow(long a, long b, long c){
        if(b==1) return (long)a;
        long res = modPow(a, b/2, c);
        res = (res * res) % c;
        if(b%2 == 1) res = (res * a) % c;
        return res;
    }
    
    static boolean isprime(long p, long t){
        Random rand = new Random();
        long m = p-1, j=0, k=0;
        while(m%2==0){
            m/=2;
            k++;
        }
        for(int i=0; i<t; i++){
            long a = rand.nextLong(p-3)+2;
            long z = modPow(a, m ,p);
            if(z==1 || z==p-1)
                continue;
            j=k;
            while(j>0){
                z=(z*z)%p;
                if(z==1)
                    return false;
                if(z==p-1)
                    break;
                j--;
            }
            if(j==0)
                return false;
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
                flag = isprime(p, t);
            
            if(flag)
                System.out.println(p+" is maybe prime");
            else
                System.out.println(p+" is surely not prime");
        }
    }
}