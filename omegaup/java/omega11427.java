import java.util.Scanner;
public class Main{
  public static void main(String[] args) {
    char[] a = (((new Scanner(System.in)).nextLine()).toUpperCase()).toCharArray();
    int s = a.length, r = 0;
    for (int i=0; i<s; i++) {
      if(a[i]==a[s-1-i]) r += 1;
    }
    System.out.print(r);
  }
}
