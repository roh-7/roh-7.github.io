import java.net.*;
import java.io.*;
class ClientSock
{
 public static void main(String args[]) throws IOException
 {
  if(args.length<1)
  {
   System.out.println("usage:seversocketsystem.exir(0) ; <server IP>");
   System.exit(0);
  }
  System.out.println("connecting to server :"+args[0]+ "on port 4444");
  Socket mySocket=null;
  try
  {
   mySocket=new Socket(args[0],4444);
  }
  catch(IOException e)
  {
   System.out.println("unbale to connect to server on 4444,aborting....");
   System.exit(0);
  }
  BufferedReader in=null;
  PrintWriter out=null;
  try
  {
   in= new BufferedReader(new InputStreamReader(mySocket.getInputStream()));
   out= new PrintWriter(mySocket.getOutputStream(),true);
  }
  catch(IOException e)
  {
   System.out.println("unknown errors opening input & output buffers:");
   System.exit(0);
  }
  System.out.println(in.readLine());
  System.out.println(in.readLine());
  System.out.println(in.readLine());
  BufferedReader CursorInp=new BufferedReader(new InputStreamReader(System.in));
  String userInp;
  String serverInp;
  System.out.println("you:");
  while((userInp=CursorInp.readLine())!=null)
  {
   out.println(userInp);
   System.out.println("server:");
   System.out.println(serverInp=in.readLine());
   if(serverInp.charAt(0)=='x')
   break;
   System.out.println("you:");
  }
  System.out.println("connection closed with sever");
  out.close();
  in.close();
 }
}

/*
siesgst@siesgst-OptiPlex-380:~/Desktop/Hey$ java ClientSock 127.0.0.1
connecting to server :127.0.0.1on port 4444
Hello client! Sever here!
This is arithmetic server. You can perform any calculation
Enter c to clear or x to quit. Start with operator.
you:
4
server:
Total=4.0
you:
+ 
server:
Total=4.0+
you:
9    
server:
Total=13.0
you:
*/