import java.io.*;
import java.net.*;

class UDPServer{
	public static void main(String[] args) throws IOException{
		DatagramSocket serverSocket = new DatagramSocket(9876);

		
		while(true){
			byte[] receiveData = new byte[1024]; //inside loop to avoid merging
			byte[] sendData = new byte[1024];

			DatagramPacket receivePacket = new DatagramPacket(receiveData,receiveData.length);
			serverSocket.receive(receivePacket);

			String sentence = new String(receivePacket.getData());

			InetAddress IPAddress = receivePacket.getAddress();
			int port = receivePacket.getPort();

			String capatalizedSentence = sentence.toUpperCase();

			sendData = capatalizedSentence.getBytes();

			DatagramPacket sendPacket = new DatagramPacket(sendData,sendData.length,IPAddress,port);

			serverSocket.send(sendPacket);
		}
	}
}