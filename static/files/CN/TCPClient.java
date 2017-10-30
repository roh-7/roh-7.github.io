import java.io.*;
import java.net.*;

class TCPClient{
	public static void main(String[] args) throws IOException {
		String sentence;
		String modifiedSentence;

		Socket clientSocket = new Socket("localhost",6789);

		DataInputStream inFromUser = new DataInputStream(System.in);

		DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());

		DataInputStream inFromServer = new DataInputStream(clientSocket.getInputStream());


		sentence=inFromUser.readLine();
		outToServer.writeBytes(sentence+'\n');

		modifiedSentence=inFromServer.readLine();
		System.out.println("From Server : "+modifiedSentence);

		clientSocket.close();				
	}

}