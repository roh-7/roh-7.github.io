import java.io.*;
import java.net.*;
import java.lang.*;

class ClientWorker1 implements Runnable
{
	private Socket client;
	ClientWorker1(Socket client)
	{
		this.client = client;
	}

	public synchronized void run()
	{
		BufferedReader in = null;
		PrintWriter out = null;

		try
		{
			in = new BufferedReader(new InputStreamReader(client.getInputStream()));
			out = new PrintWriter(client.getOutputStream(),true);
		}

		catch(IOException e)
		{
			System.out.println("Unknown errors opening input and output buffer");
			System.exit(0);
		}

		out.println("Hello client! Sever here!");
		out.println("This is arithmetic server. You can perform any calculation");
		out.println("Enter c to clear or x to quit. Start with operator.");

		String clientInp;
		Double dtemp;
		double total,curNum;
		char operator;

		total = 0;
		curNum = 0;
		operator = '?';
		boolean optchance;
		int bankclear;
		optchance = true;
		bankclear = 0;

		while(true)	
		{
			try
			{
				outer: while((clientInp=in.readLine())!=null)
				{
					if(clientInp.charAt(0)=='x')
					{
						out.println("x");
						System.exit(0);
					}
		
					if(clientInp.charAt(0)=='c')
					{
						if(bankclear==0)
						{
							if(optchance==true)
							{
								if(operator!='?')
								{
									optchance=false;
									operator='?';
								}
							}
		
							else
							{
								total=0;
								operator='?';
								optchance=true;
							}// end of optchance
						}// end of bankclear
		
						else
						{
							total=0;
							operator='?';
							optchance=true;
						}
	
						out.println("Total="+total);
						System.out.println("Total="+total);
						bankclear++;
						continue outer;
					}//end of clientInp

					bankclear=0;
				
					if(optchance)
					{
						try
						{
							dtemp=new Double(clientInp);
						}
			
						catch(NumberFormatException e)
						{
							out.println("Invalid numeric value.Re-enter number");
							optchance=true;
							continue outer;
						}
	
						curNum=dtemp.doubleValue();
		
						switch(operator)
						{
		
							case'+' :
								total=total+curNum;
								break;
		
							case'-' :
								total=total-curNum;
								break;
			
							case'/' :
								total=total/curNum;
								break;

							case'*' :
								total=total*curNum;
								break;
	
							case'?' :
								total=curNum;
								break;
						}
	
						operator='?';
						optchance=false;
						System.out.println("Operand identified:"+clientInp);
						System.out.println("Total="+total);
						out.println("Total="+total);
					}

					else
					{
						System.out.println(clientInp.length());
						if(clientInp.length()>1)
						{
							out.println("Error:operatorexpected:+,-,/,*,C,X");
							continue outer;
						}

						if(clientInp.charAt(0)!='+'&&
						   clientInp.charAt(0)!='-'&&
						   clientInp.charAt(0)!='/'&&
						   clientInp.charAt(0)!='*'&&
						   clientInp.charAt(0)!='c'&&
						   clientInp.charAt(0)!='x')
						{	
	
						out.println("Error:operatorexpected:+,-,/,*,C,X");
						continue outer;
						}

						if(clientInp.charAt(0)=='c')
						{
							total=0;
							optchance=false;
							operator='?';
							out.println("Total="+total);
							System.out.println("Total="+total);
							continue outer;
						}

						if(clientInp.charAt(0)=='X')
						{
							System.out.println("Connection  closed by client");
							out.println("x");
							out.close();
							in.close();
							System.exit(0);
						}

						System.out.println("operator identified :"+ clientInp);
						operator=clientInp.charAt(0);
						out.println("Total="+total+operator);
						optchance=true;
					}
				}
			}

			catch(IOException e)
			{}
		}	
	}
}