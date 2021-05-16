package Other;

import java.util.*;

public class DFS_Graph {
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
	void DFS_Traversal(String root_vertex)
	{
		Stack<String> stack = new Stack<>();
		ArrayList<String> visited = new ArrayList<>();
		LinkedList<String> adj_edges;
		visited.add(root_vertex);
		stack.push(root_vertex);
		while(!stack.isEmpty())
		{
			String u = stack.peek();
			adj_edges = gmap.get(u);
			String e = adj_edges.poll();
			if(e!=null&&!visited.contains(e))
			{
				visited.add(e);
				stack.push(e);
			}
			else if(e==null)
				stack.pop();
		}
		System.out.println("DFS Traversal : " + visited);
	}
	public static void main(String args[])
	{
		DFS_Graph g = new DFS_Graph();
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
		g.DFS_Traversal("A");
	}
}
