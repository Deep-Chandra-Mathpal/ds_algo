package Other;

import java.util.*;

public class BFS_Graph {
	String vertex;
	HashMap<String,LinkedList<String>> gmap = new HashMap<>();
	void add_vertex(String label)
	{
		this.gmap.putIfAbsent(label,new LinkedList<>());
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
	void BFS_Traversal(String root_vertex)
	{
		Queue<String> queue = new LinkedList<>();
		ArrayList<String> visited = new ArrayList<>();
		LinkedList<String> adj_edges;
		visited.add(root_vertex);
		queue.add(root_vertex);
		while(!queue.isEmpty())
		{
			String u = queue.remove();
			adj_edges = gmap.get(u);
			for(String s : adj_edges)
			{
				if(!visited.contains(s))
				{
					visited.add(s);
					queue.add(s);
				}
			}
		}
		System.out.println("BFS Traversal : " + visited);
	}
	public static void main(String args[])
	{
		BFS_Graph g = new BFS_Graph();
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
		g.add_edge("D", "A");
		g.add_edge("E", "F");
		g.add_edge("F", "C");
		g.remove_edge("E", "B");
		g.remove_vertex("G");
		System.out.println(g.gmap.entrySet());
		System.out.println();
		g.BFS_Traversal("A");
	}
}
