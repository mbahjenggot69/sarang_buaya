package rmi;

import model.Student;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

public interface StudentRMI extends Remote {
    ArrayList<Student> findStudentByName(String name) throws RemoteException;

    Boolean updateStudent(Student student) throws RemoteException;
}
