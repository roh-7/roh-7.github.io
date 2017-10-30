import java.io.*;

class Ipfind
{

	public static void main(String[] args)throws IOException {

		DataInputStream dis = new DataInputStream(System.in);
		System.out.println("Enter IP Address (eg: 192.168.1.1)");
		String ipAddr = dis.readLine();
		String[] ipAddrParts=ipAddr.split("\\.");
		String mask="";

		int firstoctet = Integer.parseInt(ipAddrParts[0]);
		if(firstoctet<=127)
		{
			mask = "255.0.0.0";
			System.out.println("Class A IP Address");
			System.out.println("The Subnet mask is: "+mask);
		}
		else if(firstoctet>=128 && firstoctet<=191)
		{
			mask = "255.255.0.0";
			System.out.println("Class B IP Address");
			System.out.println("The Subnet mask is: "+mask);
		}
		else if(firstoctet>=192 && firstoctet<=223)
		{
			mask = "255.255.255.0";
			System.out.println("Class C IP Address");
			System.out.println("The Subnet mask is: "+mask);
		}
		else if(firstoctet>=224 && firstoctet<=239)
		{
			mask = "255.0.0.0";
			System.out.println("Class D IP Address; Used for multicasting");
		}
		else if(firstoctet>=240 && firstoctet<=254)
		{
			mask = "255.0.0.0";
			System.out.println("Class D IP Address; Experimental Use");
		}

		

		String[] maskParts=mask.split("\\.");
		String firstAddr="";
		String lastAddr="";

		for(int i=0;i<4;i++){
                int x=Integer.parseInt(ipAddrParts[i]);
                int y=Integer.parseInt(maskParts[i]);
                int z=x&y;
                int w=z|(y^255);	//last ip = ipaddress && subnetmask + ~subnetmask
                firstAddr+=z+".";
                lastAddr+=w+".";
            }

        System.out.println("First IP of block: "+firstAddr);
        System.out.println("Last IP of block: "+lastAddr);

	}

}
