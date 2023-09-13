package server;
import java.rmi.RemoteException;
import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
/**
 *
 * @author acer_
 */
public class server {
    public static void main(String[] args) throws RemoteException, NotBoundException{
        Registry registry = LocateRegistry.createRegistry(212);
        luasImpl sh = new luasImpl();
        registry.rebind("Hitung", (Remote) sh);
        System.out.println("Server telah berjalan");
    }
}