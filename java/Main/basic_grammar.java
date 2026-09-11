package Main;

import java.util.Scanner;
import java.util.Arrays;
import java.util.Random;

// 所有代码必须写在类里；public class 名必须和文件名一致
public class basic_grammar 
{
    static int add(int a,int b)
    {
        return a+b;
    }

    public static void main(String[] args)
    {
        // 1. 输出
        System.out.println("换行输出");
        System.out.print("不换行");
        System.out.printf("%d %.2f %s\n", 10,3.14,"abc");


        // 2. 变量与基本类型
        int a=10;                 // 4 字节
        long b=100L;              // 8 字节，字面量建议加 L
        float c=3.14f;            // 4 字节，float 必须加 f
        double d=3.14;            // 8 字节
        char e='A';               // 2 字节，Unicode
        boolean f=true;           // 只能是 true / false，不能当 0/1 用
        String s="hello";         // 引用类型，首字母大写，不是字符数组


        // 3. 输入（Scanner）
        Scanner sc=new Scanner(System.in);
        // 注意：nextInt() 后接 nextLine() 会读到空行
        // 解决：中间多写一次 sc.nextLine(); 吃掉换行

        int n=sc.nextInt();
        sc.nextLine();
        String line=sc.nextLine(); // 读一整行（含空格）

        // 其他读取方法：
        // sc.nextLong()    读 long
        // sc.nextDouble()  读 double
        // sc.next()        读一个单词（遇空格停）


        // 4. 条件语句
        if(a>0) System.out.println("a>0");
        else if(a<0) System.out.println("a<0");
        else System.out.println("a=0");

        switch (a) 
        {
            case 1:
                System.out.println("one");
                break;
            case 2:
                System.out.println("two");
                break;
            default:
                System.out.println("other");
        }


        // 5. 循环

        for (int i = 0; i < 3; i++) System.out.println("for i = " + i);
        
        int i = 0;
        while (i < 3) i++;
        
        do 
        {
            i++;
        } while (i < 5);

        int[] arr={1,2,3};
        for(int x : arr)  System.out.println("增强for x = " + x);


        // 6. 数组
        int[] arr2=new int[5];          // 默认全 0
        int[] arr3={1,2,3,4,5};         // 声明并初始化
        int[][] mat=new int[3][4];      // 二维数组

        System.out.println(arr3.length);  // .length 是属性，不是函数，没有括号

        // 数组直接打印是地址，要遍历或 Arrays.toString()
        System.out.println(Arrays.toString(arr3));


        // 7. 字符串 String
        String str="hello";
        int len=str.length();             // 方法，有括号
        char ch=str.charAt(0);            // 取字符
        String sub=str.substring(1, 3);   // [1,3)
        boolean eq=str.equals("hello");   // 比较内容,不能用 ==
        String up=str.toUpperCase();
        String[] parts=str.split(","); //按分隔符,把字符串切成字符串数组

        String s1="hi"; String s2="hi";
        System.out.println(s1==s2);        // 可能 true（常量池），不可靠
        System.out.println(s1.equals(s2));   // true，正确写法

        // 字符串拼接
        String concat="a"+1+"b";       // "a1b"


        // 8. 函数（方法）调用
        int r = add(1, 2);
        System.out.println("add = " + r);


        // 9. 数学与随机
        System.out.println(Math.abs(-1));
        System.out.println(Math.max(1, 2));
        System.out.println(Math.min(1, 2));
        System.out.println(Math.pow(2, 10));
        System.out.println(Math.sqrt(16));
        System.out.println(Math.PI);

        int rand1=(int)(Math.random()*10); // Math.random()返回一个 double,范围 [0.0,1.0)
        Random rand=new Random();
        int rand2=rand.nextInt(10); 
        // Random：java.util 包里的类。
        // new Random()：创建一个随机数生成器对象。
        // rand.nextInt(10)：返回一个 int，范围 [0, 10)，也就是 0 到 9。
    }
}