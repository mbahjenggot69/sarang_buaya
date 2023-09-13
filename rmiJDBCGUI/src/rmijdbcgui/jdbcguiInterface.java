/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package rmijdbcgui;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author yanua
 */
public interface jdbcguiInterface extends Remote {
    
    public String Delete(int nim) throws RemoteException;
    public String Insert(String nama, int nim, String gender, int umur, String fakultas, String angkatan) throws RemoteException;
    public String Update(String nama, int nim, String gender, int umur, String fakultas, String angkatan) throws RemoteException;
    public String Read() throws RemoteException;
}
