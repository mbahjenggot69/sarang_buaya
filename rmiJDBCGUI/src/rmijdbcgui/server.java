/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package rmijdbcgui;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author yanuar
 */
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
    public String Delete(int nim) throws RemoteException {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/rmiTest", "root", "root");
            Statement st = (Statement) con.createStatement();
            String sql = "delete from student where nim = '"+nim+"'";
            st.executeUpdate(sql);
            return "Record Deleted Succesfully";
            
        } catch (ClassNotFoundException | SQLException e) {
            return(e.toString());
        }
    }

    @Override
    public String Insert(String nama, int nim, String gender, int umur, String fakultas, String angkatan) throws RemoteException {
         try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/rmiTest", "root", "root");
            Statement st = (Statement) con.createStatement();
            String sql = "insert into student values('"+nim+"', '"+nama+"','"+gender+"','"+fakultas+"','"+umur+"','"+angkatan+"')";
            st.executeUpdate(sql);
            return "Record Inserted Succesfully";
            
        } catch (ClassNotFoundException | SQLException e) {
            return(e.toString());
        }
    }

    @Override
    public String Update(String nama, int nim, String gender, int umur, String fakultas, String angkatan) throws RemoteException {
         try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/rmiTest", "root", "root");
            Statement st = (Statement) con.createStatement();
            String sql = "update student set nama = '"+nama+"',gender = '"+gender+"',fakultas = '"+fakultas+"',umur = '"+umur+"',angkatan = '"+angkatan+"' where nim = '"+nim+"'";
            st.executeUpdate(sql);
            return "Record Updated Succesfully";
            
        } catch (ClassNotFoundException | SQLException e) {
            return(e.toString());
        }
    }    
    @Override
    public String Read() throws RemoteException{
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/rmiTest", "root", "root");
            Statement st = (Statement) con.createStatement();
            String sql = "select * from student"; 
            st.executeUpdate(sql);
            
        } catch (ClassNotFoundException | SQLException e) {
            return (e.toString());
        }
        return null;
    }
}
