package g7e2;

public class G7e2 
{
    public static void main(String[] args) 
    {
        (new Thread(new p1())).start();
        (new Thread(new p2())).start();
        (new Thread(new p3())).start();
        (new Thread(new p4())).start();
    }
}