package g7e3;

import java.util.concurrent.Semaphore;

public class G7e3 
{
    protected static Semaphore oFinP1, oFinP3;
    
    public static void main(String[] args) 
    {
        oFinP1=new Semaphore(0,true);
        oFinP3=new Semaphore(0,true);
        (new Thread(new p1(oFinP1))).start();
        (new Thread(new p2(oFinP1,oFinP3))).start();
        (new Thread(new p3(oFinP3))).start();
        (new Thread(new p4(oFinP1,oFinP3))).start();
    }
}