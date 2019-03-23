//BigInteger
//Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String args[]){
    BigInteger[] arr = new BigInteger[1001];
    arr[0] = BigInteger.valueOf(1);
    arr[1] = BigInteger.valueOf(2);
    for(int i=2; i<=1000; i++){
      arr[i] = arr[i-2].add(arr[i-1]);
    }
    Scanner s = new Scanner(System.in);
    while(s.hasNextInt()){
      System.out.println(arr[s.nextInt()].toString());
    }
  }
}