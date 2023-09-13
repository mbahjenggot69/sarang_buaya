
package trbib_jdbc;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/* @author yanuar*/

public class server extends UnicastRemoteObject implements jdbcguiInterface{
    
    Connection con;
    
    public server() throws  RemoteException{
        super();
    }
    public static void main(String[] args) throws RemoteException {
        Registry reg = LocateRegistry.createRegistry(5555);
        server s  = new server();
        reg.rebind("db", s);
        System.out.println("Server is running now...");       
    }
    
    @Override
    public String Read() throws RemoteException{
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/trbib_webapp", "root", "root");
            Statement st = (Statement) con.createStatement();
            String sql = "SELECT title, director, release_year, rating, duration FROM netflix_raw_data"; 
            st.executeUpdate(sql);
            
        } catch (ClassNotFoundException | SQLException e) {
            return (e.toString());
        }
        return null;
    }
}
