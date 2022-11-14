import java.util.Scanner;
public class Main{
  public static void main(String[] args) {
    Scanner a = new Scanner(System.in);
    String s;
    String[] d;
    while(true){
      try{
        s = a.nextLine();
      }catch (Exception e){
        break;
      }
      d = s.split("/");
      if(d.length<2)
        break;
      if(Integer.parseInt(d[2])>=74)
        System.out.print(d[0]+"/"+d[1]+"/"+"19"+d[2]+"\n");
      else
        System.out.print(d[0]+"/"+d[1]+"/"+"20"+d[2]+"\n");
    }
  }
}
