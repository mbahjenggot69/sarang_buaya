package client;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.rmi.RemoteException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import luas.luasInterface;

/**
 *
 * @author acer_
 */
public class client {
    static String inputan;
    static String Inputan(){
        BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));
        try {
            inputan = dataIn.readLine();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return inputan;
    }

    public static void main(String[] args)throws RemoteException, NotBoundException, MalformedURLException{
        String masukan = "";
        String respon = "";
        int angka1, angka2;
        luasInterface sHello = (luasInterface) Naming.lookup("rmi://localhost:212/Hitung");
        System.out.println("Client berhasil konek");
        System.out.println("Masukkan panjang : ");
        masukan = Inputan();
        angka1 = Integer.parseInt(masukan);
        System.out.println("Masukkan lebar : ");
        masukan = Inputan();
        angka2 = Integer.parseInt(masukan);
        respon = sHello.hitungLuas(angka1, angka2);
        System.out.println(respon);
    }

}