
public class Node {
	Object item;
	Node next;
public static void main(String[] args) {
	Node a =new Node();
	Node b =new Node();
	Node c =new Node();
	a.item = "Fuck in";
	b.item = "Or";
	c.item = "Fuck Out";
	a.next = b;
	b.next = c;
	System.out.println(a);
	
	
	
}
@Override
public String toString() {
	return "Node [item=" + item + ", next=" + next + "]";
}
}
