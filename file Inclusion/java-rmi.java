import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import lab.example.rmi.interfaces.RemoteService;

public class ExampleClient {

  private static final String remoteHost = "172.17.0.2";
  private static final String boundName = "remote-service";

  public static void main(String[] args)
  {
    try {
      Registry registry = LocateRegistry.getRegistry(remoteHost);     // Connect to the RMI registry
      RemoteService ref = (RemoteService)registry.lookup(boundName);  // Lookup the desired bound name
      String response = ref.remoteMethod();                           // Call a remote method

    } catch( Exception e) {
      e.printStackTrace();
    }
  }
}
