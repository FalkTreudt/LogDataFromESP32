import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.*;

public class Datenbank {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//define values for database connection
		String  url = "jdbc:mysql://localhost:3306/esp_test?useJDBCCompliantTimezoneShift=true&useLegacyDatetimeCode=false&serverTimezone=Europe/Berlin";
		String user = "root";
		String passwort = "";
		
		//try to connect to database
		try (Connection conn = DriverManager.getConnection(url,user,passwort)){
			
			//give feedback of connection
			System.out.println("Conenction sucess! ");
			
			//get data from "second_table" table
			String query = "SELECT * FROM second_table ORDER BY time ASC";
			Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery(query);
			
			//get count of columns
			int columns = rs.getMetaData().getColumnCount();
			
			//create table in console with data
			for(int i= 1; i<=columns;i++) 
				System.out.print(String.format("%-15s", rs.getMetaData().getColumnLabel(i)));
				System.out.println();
				System.out.println("----------------------------------------");
			
			while(rs.next()) {
				for(int i= 1; i<=columns;i++) {
					System.out.print(String.format("%-15s", rs.getString(i)));	
					
				}
				System.out.println();
				}
			//close connection
			rs.close();
			stmt.close();
			
		//catch potential errors if connection fails
		}catch(SQLException ex) {
			System.err.println(ex.getMessage());
		}
		
		
	}

}
