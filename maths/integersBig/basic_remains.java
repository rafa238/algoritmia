//Uva judge - 10551 - Basic Remains
import java.util.Scanner;
import java.math.BigInteger;

public class basic_remains {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int b= sc.nextInt();
            if(b == 0) break;
            BigInteger p = new BigInteger(sc.next(), b);
            BigInteger m = new BigInteger(sc.next(), b);
            System.out.println((p.mod(m)).toString(b));
        }
    }
}
