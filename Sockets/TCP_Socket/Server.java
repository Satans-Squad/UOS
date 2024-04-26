package TCP_Socket;
import java.io.*;
import java.net.*;
public class Server {
    public static void main(String[] args) {
        try {
       
            ServerSocket serverSocket = new ServerSocket(8080);
            System.out.println("Server Running on port 8080");

            Socket client = serverSocket.accept();
            System.out.println("Client Connected "+client);

            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            PrintWriter out = new PrintWriter(client.getOutputStream(),true);

            String message;

            while((message = in.readLine())!= null){
                System.out.println("Recieved from client: "+message);
            }

            in.close();
            out.close();
            client.close();
            serverSocket.close();


        } catch (Exception e) {
            System.out.println(e);
        }
       
    }
}
