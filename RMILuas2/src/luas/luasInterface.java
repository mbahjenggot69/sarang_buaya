/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package luas;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author yanua
 */

public interface luasInterface extends Remote{
    public String hitungLuas (int x, int y) 
    throws RemoteException;
}
