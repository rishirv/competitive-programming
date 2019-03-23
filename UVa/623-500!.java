//BigInteger
//Factorial
//Math
//Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int i;
    BigInteger a;
    while(s.hasNextInt()){
      i = s.nextInt();
      a = new BigInteger("1");
      System.out.println(i + "!");
      while(i > 0) a=a.multiply(BigInteger.valueOf(i--));
      System.out.println(a.toString());
    }
  }
}