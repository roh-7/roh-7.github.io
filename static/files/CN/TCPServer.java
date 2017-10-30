import java.io.*;
import java.net.*;

class TCPServer{
	public static void main(String[] args) throws IOException{
		String clientsentence;
		String capitalizedSentence;

		ServerSocket welcomeSocket = new ServerSocket(6789);

		while(true){
			Socket connectionSocket = welcomeSocket.accept();

			DataInputStream inFromClient = new DataInputStream(connectionSocket.getInputStream());

			DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());

			clientsentence = inFromClient.readLine();

			capitalizedSentence = clientsentence.toUpperCase()+'\n';

			outToClient.writeBytes(capitalizedSentence);
		}
	}
}