public class index {
    public static void main (String arg[])
    {
        Son obj = new Son();
        obj.getData(10,20);
        obj.disp();
    }
}

class Father  //super class
{
    private int a, b;

    void getData(int x, int y)
    {
        a = x;
        b = y;
    }
}

class Son extends Father{
    int add()         //method
    {
        int sum = a+b;
        return sum;
    }

    void disp()      //method
    {
    System.out.println("A is: "+a);
    System.out.println("B is: "+b);
    System.out.println("Sum is: "+add());
    }   

}