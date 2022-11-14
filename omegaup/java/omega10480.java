import java.io.*;
import java.util.Scanner;
public class Main{
  public static void main(String[] args){
      Scanner myObj = new Scanner(System.in);
      int i = myObj.nextInt();
      if(i%2 != 0)
        i++;
      int r = myObj.nextInt();
      for(int j = i; j <= r; j+=2){
        System.out.println(j);
      }
  }
}
