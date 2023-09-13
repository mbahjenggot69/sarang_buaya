package client;

import model.Student;
import rmi.StudentRMI;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;

public class ClientControl {
    private String serverHost = "localhost";
    private int serverPost = 5555;
    private StudentRMI studentRMI;
    private Registry registry;
    private String rmiService = "StudentService";

    public ClientControl() {
        try{
            registry = LocateRegistry.getRegistry(serverHost ,serverPost);
            studentRMI = (StudentRMI) registry.lookup(rmiService);
        } catch (RemoteException | NotBoundException e) {
            e.printStackTrace();
        }
    }

    public ArrayList<Student> findStudentByName(String name) throws RemoteException {
        return studentRMI.findStudentByName(name);
    }

    public Boolean updateStudent(Student student) throws RemoteException {
        return studentRMI.updateStudent(student);
    }
}
