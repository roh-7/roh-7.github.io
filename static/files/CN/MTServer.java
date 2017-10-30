import java.io.*;
import java.net.*;
class MTServer
{
public static void main(String arg[]) throws IOException
{
 ServerSocket serversocket = null;
try
{
serversocket = new ServerSocket(4444);
}
catch(IOException e)
{
System.out.println("Could not listen to port 4444");
System.exit(0);
}

while(true)
{
ClientWorker1 w;
try
{
w=new ClientWorker1(serversocket.accept());
Thread t= new Thread(w);
t.start();
}
catch(IOException e)
{
System.out.println("Accept Failed");
System.exit(-1);
}
}
}
}

/*
siesgst@siesgst-OptiPlex-380:~/Desktop/Hey$ java MTServer 127.0.0.1
Operand identified:4
Total=4.0
1
operator identified :+
Operand identified:9
Total=13.0
*/