import java.util.ArrayList;
import java.util.Arrays;

public class Dijkstra_Algorithm {
	int[] key = {100,100,100,100,100,100,100,100,100};
	int[] pi = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
	ArrayList<Integer> a = new ArrayList<>(Arrays.asList(0,1,2,3,4,5,6,7,8));
	void min_heapify(ArrayList<Integer> a,int i)
	{
		int l = 2*i;
		int r = 2*i+1;
		int smallest;
		if(l<a.size() && key[a.get(l)]<key[a.get(i)])
			smallest = l;
		else 
			smallest = i;
		if(r<a.size() && key[a.get(r)]<key[a.get(smallest)])
			smallest = r;
		if(smallest!=i)
		{
			int temp = a.get(smallest);
			a.set(smallest, a.get(i));
			a.set(i, temp);
			min_heapify(a,smallest);
		}
	}
	void build_heap(ArrayList<Integer> a)
	{
		for(int i=a.size()/2;i>=0;i--)
			min_heapify(a,i);
	}
	int heap_extract_min(ArrayList<Integer> a)
	{
		if(a.size()<1)
		{
			System.out.println("heap underflow");
		}
		int min = a.get(0);
		a.set(0,a.get(a.size()-1));
		a.remove(a.size()-1);
		min_heapify(a,1);
		return min;
	}
	void dijkstra(int[][] graph,int stv)
	{
		key[stv] = 0;
		build_heap(a);
		while(a.isEmpty()==false)
		{
			int v = heap_extract_min(a);
			for(int j=0;j<9;j++)
			{
				if(graph[v][j]!=0 && (key[v]+graph[v][j]<key[j]) && a.contains(j))
				{
					key[j] = key[v] + graph[v][j];
					pi[j] = v;
					build_heap(a);
				}
			}
		}
	}
	void display()
	{
		System.out.println("path : weight");
		for(int i=0;i<9;i++)
		{
			if(key[i]!=0)
				System.out.print("starting vertex"+"<--------->"+i+" : "+key[i]+"\n");
		}
		System.out.println();
	}
	public static void main(String[] args) {
	int[][] graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	Dijkstra_Algorithm instance = new Dijkstra_Algorithm();
	instance.dijkstra(graph,0);
	instance.display();
	}

}
