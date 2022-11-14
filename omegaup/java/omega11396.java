import java.util.Scanner;
import java.io.*;

public class Main{

  public static void main(String[] args) {
      char[] arr = {'A','E','I','U','O'};
      char[] a = (new Scanner(System.in)).nextLine().toCharArray();
      for(char i: a){
        if(i<65 || i>90) continue;
        if(i==89){
          System.out.print("S ");
          continue;
        }
        if(i==65 || i==69 || i==73 || i==79 || i==85){
          System.out.print("V ");
          continue;
        }
        System.out.print("C ");
      }
  }
}
