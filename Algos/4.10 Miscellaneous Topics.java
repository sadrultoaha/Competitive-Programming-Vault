// OK chkd by SunW
import java.math.BigInteger;


/**


BigInteger abs()
BigInteger add(BigInteger val)
BigInteger and(BigInteger val)
int bitCount()
int compareTo(BigInteger val)
BigInteger divide(BigInteger val)
BigInteger gcd(BigInteger val)
BigInteger max(BigInteger val)
BigInteger min(BigInteger val)
BigInteger mod(BigInteger m)
BigInteger multiply(BigInteger val)
BigInteger xor(BigInteger val)









**/


class bigINT{

	public static int getDigitCount(BigInteger number) 
	{
	    double factor = Math.log(2) / Math.log(10);
	    int digitCount = (int) (factor * number.bitLength() + 1);
	    if (BigInteger.TEN.pow(digitCount - 1).compareTo(number) > 0) {
	        return digitCount - 1;
	    	}
	    return digitCount;
	}
    
    
    public static void main(String [] args)
    {
    	BigInteger SUM;
    	BigInteger X=new BigInteger("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    	BigInteger Y=new BigInteger("79999960000000000000000000000000000000000345634563456345634560000000000000000000000000000000000000000000000000");
    	System.out.println( getDigitCount(X) );
    	SUM=X.max(Y);
    	String ans="ans is "+SUM;
    	System.out.println(ans);
    }
		
}
