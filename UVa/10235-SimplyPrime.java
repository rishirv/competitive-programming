//BigInteger
//Probably Prime
//Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    while(s.hasNext()){
      BigInteger p = new BigInteger(s.next());
      BigInteger e = new BigInteger(new StringBuffer(p.toString()).reverse().toString());
      System.out.print(p.toString() + " ");
      if(!p.isProbablePrime(20)){
        System.out.println("is not prime.");
      } else if(!e.isProbablePrime(20) || e.equals(p)){
        System.out.println("is prime.");
      } else{
        System.out.println("is emirp.");
      }
    }
  }
}