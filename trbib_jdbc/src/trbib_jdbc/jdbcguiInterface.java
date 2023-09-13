/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trbib_jdbc;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author yanua
 */
public interface jdbcguiInterface extends Remote {
    public String Read() throws RemoteException;
}
