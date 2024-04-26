package TCP_Concurrent;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;

public class Client {

    public static void main(String[] args) {

        try {
            Socket socket = new Socket("localhost",8080);

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(),true);

            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            String message;
            
            while((message = userInput.readLine())!= null){

                out.println(message);
                System.out.println("Sent to Server");

            }

            userInput.close();
            in.close();
            out.close();
            socket.close();
        } catch (Exception e) {
            System.out.println(e);
        }
        
    }
    
}
