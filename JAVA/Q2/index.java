public class index {

    public static void main(String args[]) {
        criket_player c = new criket_player("ishika", 20);
        football_player f = new football_player("dibyasom",20);
        hockey_player h = new hockey_player("haaardik",19);
        c.show();
        f.show();
        h.show();
    }
}

class Player {
    String name;
    int age;

    Player(String n, int a) {
        name = n;
        age = a;
    }

    void show() {
        System.out.println("\n");
        System.out.println("Player name : " + name);
        System.out.println("Age : " + age);
    }
}

class criket_player extends Player {

    criket_player(String n, int a) {
        super(n, a);
    }

    public void show() {
        super.show();   
    }
}

class football_player extends Player {
    football_player(String n,int a) {
        super(n, a);
    }

    public void show() {
        super.show();
        
    }
}

class hockey_player extends Player {

    hockey_player(String n, int a) {
        super(n, a);
    }

    public void show() {
        super.show();
    }
}