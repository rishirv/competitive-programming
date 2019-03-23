//BigInteger
//Catalan Numbers
//Math
//Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    BigInteger[] arr = new BigInteger[301];
    arr[1] = BigInteger.ONE;
    int i;
    for(i=2; i<=300; i++){
      arr[i] = arr[i-1].multiply(BigInteger.valueOf(2*i)).multiply(BigInteger.valueOf(2*i-1)).divide(BigInteger.valueOf(i+1));
    }
    while((i = s.nextInt()) > 0){
      System.out.println(arr[i].toString());
    }
  }
}