//BigInteger
//Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int b;
    while((b = s.nextInt()) > 0){
      BigInteger p = new BigInteger(s.next(), b);
      BigInteger m = new BigInteger(s.next(), b);
      System.out.println(p.mod(m).toString(b));
    }
  }
}