import java.sql.*;
import java.io.IOException;

class DB
{
 Connection conn;
 Statement stmt;

 DB() throws ClassNotFoundException, SQLException
 {
  String driver;//for communication with database
  String uri;//location of the target database
  String username;//for authentication 
  String password;//for authentication 

  driver = "oracle.jdbc.OracleDriver";
  uri = "jdbc:oracle:thin:@//localhost:1521/xe";
  username = "system";
  password = "manager";
  
  //load the driver in memory
  Class.forName(driver);
  //make a connection
  conn = DriverManager.getConnection(uri, username, password);

  //form a Statement
  stmt = conn.createStatement(); 
  
 }//DB

 void close()throws SQLException
 {
   stmt.close();
   conn.close();
 }

 static String getString()
 {
  try
  {
    byte arr[] = new byte[512];
    int x;
    x = System.in.read(arr);
    return new String(arr, 0, x-2);
  }
  catch(IOException ex)
  {
    return "exit";
  }
 }//getString()

 void executeSelect(String sql) throws SQLException
 {//statement that returns data
   ResultSet rs;
   rs = stmt.executeQuery(sql);
   
   ResultSetMetaData rsmd;
   rsmd = rs.getMetaData();
   
   int i, size;
   size = rsmd.getColumnCount();

   //ROW HEADER
    System.out.println();//line change
    for(i = 1; i<= size; i++)
    {
       System.out.print(rsmd.getColumnName(i) + "   "); 
    }  	 


   //traverse it (forward only)
   while(rs.next()) //for data rows
   {
    System.out.println();//line change
    //column traversal
    for(i = 1; i<= size; i++)
    {
       System.out.print(rs.getString(i) + "   "); //fetch data of current row and col i in String form
    }  	 
   }   

   //close the ResultSet  
   rs.close();
 }
  
 void executeNonSelect(String sql) throws SQLException
 {//statements that do not return data
   stmt.executeUpdate(sql);
 }

 public static void main(String args[]) 
 {
  try
  {
    DB db = new DB();
    boolean flag = true;
    String str;

    do
    {
     try
     {
       System.out.print("\nSQL> ");
       str = getString();
 
       if(str.equalsIgnoreCase("exit"))
       {
         flag = false;
         continue;
       }
       else if(str.startsWith("select"))
         db.executeSelect(str);
       else
         db.executeNonSelect(str);

     }
     catch(SQLException ex)
     {
       System.out.println(ex);
     }
    }while(flag);

    db.close();
  }
  catch(ClassNotFoundException ex)
  {
   System.out.println("Database drivers not found");
  }
  catch(SQLException ex)
  {
   System.out.println(ex);
  }
 }//main
}//DB