//BigInteger
//Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int n, a;
    while(s.hasNextInt()){
      n = s.nextInt();
      a = s.nextInt();
      BigInteger A = BigInteger.valueOf(a);
      BigInteger b = BigInteger.ZERO;
      for(int i=1; i<=n; i++){
        b = b.add(BigInteger.valueOf(i).multiply(A.pow(i)));
      }
      System.out.println(b);
    }
  }
}