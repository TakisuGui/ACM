class Main {

    public static class TreeNode {
		public int val;
		public TreeNode left;
		public TreeNode right;
	}




    public static int largestBSTSubtree(TreeNode root)
    {
        return f(root).maxBstSize;
    }

    public static class Info
    {
        public long max;
		public long min;
		public boolean isBst;
		public int maxBstSize;


        public Info(long a, long b, boolean c, int d)
        {
			max=a;
			min=b;
			isBst=c;
			maxBstSize=d;
        }
    }


    public static Info f(TreeNode x)
    {
        if(x==null) return new Info(Long.MIN_VALUE,Long.MAX_VALUE,true,0);

        Info infol=f(x.left);
        Info infor=f(x.right);

        long max=Math.max(x.val,Math.max(infol.max,infor.max));
        long min=Math.min(x.val,Math.min(infol.min,infor.min));

        boolean isBst=(infol.isBst&&infor.isBst)&& (infol.max<x.val && x.val<infor.min);

        int maxBSTSize;
        if(isBst) maxBSTSize=infol.maxBstSize+infor.maxBstSize+1;
        else maxBSTSize=Math.max(infol.maxBstSize,infor.maxBstSize);

        return new Info(max,min,isBst,maxBSTSize);
    }
}