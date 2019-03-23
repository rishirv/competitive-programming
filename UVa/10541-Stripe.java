//BigInteger
//Combinations
//Java
import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int t = s.nextInt(), n, k;
    BigInteger a;
    for(int i=0; i<t; i++){
      n = s.nextInt();
      k = s.nextInt();
      for(int j=0; j<k; j++) n-=s.nextInt();
      n+=1;
      if(n<k) System.out.println(0);
      else{
        a = BigInteger.valueOf(1);
        if(2*k > n) k = n-k;
        for(int j=0; j<k; j++) a = a.multiply(BigInteger.valueOf(n-j));
        for(int j=1; j<=k; j++) a = a.divide(BigInteger.valueOf(j));
        System.out.println(a.toString());
      }
    }
  }
}