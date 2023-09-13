/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/WebServices/GenericResource.java to edit this template
 */
package latihanku;

import java.util.ArrayList;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

/**
 * REST Web Service
 *
 * @author yanua
 */

@Path("testController")
public class TestController {
    
    @GET
    @Path("/getdata")
    @Produces(MediaType.APPLICATION_JSON)
    
    public ArrayList<testModel> getData() throws ClassNotFoundException {
        ArrayList<testModel> tmn = new ArrayList<>();
        int[] id = {1,2};
        String[] nama = {"Sastro", "Sembronowati"};
        
        for(int i = 0; i<nama.length; i++){
            testModel tm = new testModel();
            tm.setId(id[i]);
            tm.setNama(nama[i]);
            tmn.add(tm);
        }
        return tmn;
    }
    
    @POST
    @Path("/postData")
    @Produces(MediaType.APPLICATION_JSON)
    
    public Response createProductInJSON(testModel tm){
        String result = "data sudah masuk: " +tm.getNama()+ "(ID: "+tm.getId()+")";
        return Response.status(201).entity(result).build();
        
    }
    @POST
    @Path("/cekLogin")
    @Produces(MediaType.APPLICATION_JSON)
    
    public String cekLogin(testModel tm){
        if (tm.getNim().equals(672020053) && tm.getNama().equals("paijo")){
            return "SUKSES LOGIN";
        } else {
            return "GAGAL LOGIN";
        }
    }
}
