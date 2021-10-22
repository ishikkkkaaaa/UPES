import java.util.Scanner;

public class index {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int a, no;
        double t;
        System.out.println("Enter 1 for ordinary call,2 for urgent call or 3 for lightening call");
        a = sc.nextInt();
        switch (a) {
        case 1:
            System.out.println("Enter the number to which call is to be made");
            no = sc.nextInt();
            Ordinary obj1 = new Ordinary(no, "ordinary call", 3);
            System.out.println("Enter the duration of the call");
            t = sc.nextDouble();
            obj1.charge(t);
            break;
        case 2:
            System.out.println("Enter the number");

            no = sc.nextInt();
            Urgent obj2 = new Urgent(no, "Urgent call", 4);
            System.out.println("Enter the duration of the call");
            t = sc.nextDouble();
            obj2.charge(t);
            break;
        case 3:
            System.out.println("Enter the number");
            no = sc.nextInt();
            Lightening obj3 = new Lightening(no, "Lightening call", 5);
            System.out.println("Enter the duration of the call");
            t = sc.nextDouble();
            obj3.charge(t);
        }

    }
}

class Telephone {
    int callnumber;
    String calltype;

    Telephone(int c, String s) {
        callnumber = c;
        calltype = s;
    }

    void show() {
        System.out.println("call number" + " " + callnumber);
        System.out.println("call type" + " " + calltype);
    }
}

class Ordinary extends Telephone {
    float cost;

    Ordinary(int c, String s, float co) {
        super(c, s);
        this.cost = co;
    }

    void charge(double time) {
        super.show();// calling show() of parent class
        System.out.println("call charges" + " " + cost * time);
    }
}

class Urgent extends Telephone {
    float cost;

    Urgent(int c, String s, float co) {
        super(c, s);
        this.cost = co;
    }

    void charge(double time) {
        super.show();
        System.out.println("call charges" + " " + cost * time);
    }
}

class Lightening extends Telephone {
    float cost;

    Lightening(int c, String s, float co) {
        super(c, s);
        this.cost = co;
    }

    void charge(double time) {
        super.show();
        System.out.println("call charges" + " " + cost * time);
    }
}

