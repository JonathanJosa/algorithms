import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args) {
    int a = (new Scanner(System.in)).nextInt();
    String[] arr = new String[a];
    for(int i = 0; i < a; i++){
      Arrays.fill(arr, " ");
      arr[i] = arr[a-i-1] = "@";
      System.out.println(String.join("",arr));
    }
  }
}
