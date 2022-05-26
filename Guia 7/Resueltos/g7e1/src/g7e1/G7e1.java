package g7e1;

public class G7e1 
{
    public static void main(String[] args) 
    {
        HiloHerencia hilo1;
        HiloHerencia hilo2;
        
        hilo1 = new HiloHerencia("Liebre",11);
        hilo2 = new HiloHerencia("Tortuga",33);
        
        hilo1.start();
        hilo2.start();
    }
}