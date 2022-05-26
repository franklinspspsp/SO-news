package g7e2;

public class p3 extends Thread
{
    public void run()
    {
        try 
        {
            sleep((int) Math.round(500*Math.random()-0.5));
        } 
        catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
        System.out.println("P3");
    }
}