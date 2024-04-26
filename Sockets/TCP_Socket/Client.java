package TCP_Socket;

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        try {
           Socket sockt = new Socket("localhost",8080);
           System.out.println("Client Connected");
           

           BufferedReader in = new BufferedReader(new InputStreamReader(sockt.getInputStream()));
           PrintWriter out = new PrintWriter(sockt.getOutputStream(),true);

           System.out.println("enter message to be sent to server");
           BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
           String message;
           while ((message = userInput.readLine()) != null) {
               out.println(message);
           }
           userInput.close();
           in.close();
           out.close();
           sockt.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
