import java.util.Scanner;
import java.math.BigInteger;

class SimplyfingFracions{
    static BigInteger gcd(BigInteger a, BigInteger b){
        return b.equals(new BigInteger("0")) ? a : gcd(b, a.mod(b));
    }
    public static void main(String[] args){
        int tc, divisonIndex;
        String str,astr,bstr;
        Scanner scan = new Scanner(System.in);
        tc = scan.nextInt();
        str = scan.nextLine();
        while(tc!=0){
            BigInteger a,b,mcd;
            str = scan.nextLine();
			divisonIndex = str.indexOf('/');
			astr = str.substring(0,divisonIndex-1);
			bstr = str.substring(divisonIndex+2); 
            a = new BigInteger(astr);
            b = new BigInteger(bstr);
            mcd = gcd(a, b);
            System.out.println(a.divide(mcd)+" / "+b.divide(mcd));
            tc--;
        }
        
    }
}