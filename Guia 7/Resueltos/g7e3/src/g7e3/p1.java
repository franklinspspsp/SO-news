package g7e3;

import java.util.concurrent.Semaphore;

public class p1 extends Thread
{
    protected Semaphore oFinP1;
    
    public p1(Semaphore oFinP1)
    {
        this.oFinP1=oFinP1;
    }

    public void run()
    {
        try 
        {
            sleep((int)Math.round(500*Math.random()-0.5));
        } catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
        System.out.println("P1");
        this.oFinP1.release(2);
    }
}