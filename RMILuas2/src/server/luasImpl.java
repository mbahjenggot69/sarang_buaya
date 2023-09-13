package server;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import luas.luasInterface;

public class luasImpl extends UnicastRemoteObject implements luasInterface{

    public luasImpl()throws RemoteException{}

    @Override
    public String hitungLuas(int angka1, int angka2) throws RemoteException {
        System.out.println("Client meminta hasil luas : ("+angka1+", "+angka2+")");
        double Luas = angka1 * angka2;
        return ">> Luas : " + Luas;
    }
}