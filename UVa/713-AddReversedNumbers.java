//BigInteger
//Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    for(int i=0; i<n; i++){
      BigInteger a = new BigInteger(new StringBuffer(s.next()).reverse().toString());
      BigInteger b = new BigInteger(new StringBuffer(s.next()).reverse().toString());
      a = a.add(b);
      System.out.println(new BigInteger(new StringBuffer(a.toString()).reverse().toString()).toString());
    }
  }
}