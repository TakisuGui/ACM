import java.util.ArrayList;

public class dp_树型dp_找到二叉树中的最大搜索二叉子树 {

public static int longestPath(int[] parent, String str) {
		int n = parent.length;
		char[] s = str.toCharArray();
		ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			graph.add(new ArrayList<>());
		}
		for (int i = 1; i < n; i++) {
			graph.get(parent[i]).add(i);
		}
		return f(s, graph, 0).maxPath;
	}

	public static class Info {
		public int maxPathFromHead; // 一定要从头节点出发的情况下，相邻字符不等的最长路径长度
		public int maxPath; // 整棵树上，相邻字符不等的最长路径长度

		public Info(int a, int b) {
			maxPathFromHead = a;
			maxPath = b;
		}
	}

	public static Info f(char[] s, ArrayList<ArrayList<Integer>> graph, int u) {
		if (graph.get(u).isEmpty()) {
			// u节点是叶
			return new Info(1, 1);
		}
		int max1 = 0; // 下方最长链
		int max2 = 0; // 下方次长链
		int maxPath = 1;
		for (int v : graph.get(u)) {
			Info nextInfo = f(s, graph, v);
			maxPath = Math.max(maxPath, nextInfo.maxPath);
			if (s[u] != s[v]) {
				if (nextInfo.maxPathFromHead > max1) {
					max2 = max1;
					max1 = nextInfo.maxPathFromHead;
				} else if (nextInfo.maxPathFromHead > max2) {
					max2 = nextInfo.maxPathFromHead;
				}
			}
		}
		int maxPathFromHead = max1 + 1;
		maxPath = Math.max(maxPath, max1 + max2 + 1);
		return new Info(maxPathFromHead, maxPath);
	}

}