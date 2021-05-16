package Other;

import java.util.HashMap;
import java.util.LinkedHashSet;

public class Graph {
	String vertex;
	HashMap<String,LinkedHashSet<String>> gmap = new HashMap<>();
	void add_vertex(String label)
	{
		this.gmap.putIfAbsent(label,new LinkedHashSet<>());
	}
	void remove_vertex(String label)
	{
		this.gmap.remove(label);
	}
	void add_edge(String label1,String label2)
	{
		this.gmap.get(label1).add(label2);
		this.gmap.get(label2).add(label1);
	}
	void remove_edge(String label1,String label2)
	{
		this.gmap.get(label1).remove(label2);
		this.gmap.get(label2).remove(label1);
	}
	public static void main(String args[])
	{
		Graph g = new Graph();
		g.add_vertex("A");
		g.add_vertex("B");
		g.add_vertex("C");
		g.add_vertex("D");
		g.add_vertex("E");
		g.add_vertex("F");
		g.add_vertex("G");
		g.add_edge("A", "B");
		g.add_edge("B", "C");
		g.add_edge("B", "D");
		g.add_edge("B", "E");
		g.add_edge("B", "E");
		g.add_edge("D", "A");
		g.add_edge("F", "C");
		g.remove_edge("E", "B");
		g.remove_vertex("G");
		System.out.println(g.gmap.entrySet());
	}
}