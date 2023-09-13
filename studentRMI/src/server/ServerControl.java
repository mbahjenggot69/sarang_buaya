package server;

import model.Student;
import rmi.StudentRMI;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

public class ServerControl extends UnicastRemoteObject implements StudentRMI {
    private int serverPort = 5555;
    private Registry registry;
    private String rmiService = "StudentService";
    private final StudentDao dao = new StudentDao();

    protected ServerControl() throws RemoteException {
        registry = LocateRegistry.createRegistry(serverPort);
        registry.rebind(rmiService, this);
    }

    @Override
    public ArrayList<Student> findStudentByName(String name) throws RemoteException {
        return dao.findStudentByName(name);
    }

    @Override
    public Boolean updateStudent(Student student) throws RemoteException {
        return dao.updateStudent(student);
    }
}
