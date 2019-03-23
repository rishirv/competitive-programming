//BigInteger
//Probably Prime
//Java
import java.io.*;
import java.util.*;
import java.math.BigDecimal;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int r = s.nextInt();
    String str;
    for(int i=0; i<r; i++){
      BigDecimal b = new BigDecimal(0);
      while(!(str = s.next()).equals("0")){
        b = b.add(new BigDecimal(str));
      }
      System.out.println(b.stripTrailingZeros().toPlainString());
    }
  }
}