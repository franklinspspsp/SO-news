package g7e1;

class HiloHerencia extends Thread
{
    String palabra;
    long pausa;
    
    public HiloHerencia(String queDecir, long tiempoPausa)
    {
        palabra = queDecir;
        pausa = tiempoPausa;
    }
    
    public void run()
    {
        try
        {
            for(int i = 0; i < 100; i++)
            {
                System.out.println(palabra+"");
                Thread.sleep(pausa);
            }
        }
        catch(InterruptedException e)
        {
            
        }
    }
}