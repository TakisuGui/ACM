import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        String line = br.readLine();
        if (line == null) return;
        int t = Integer.parseInt(line.trim());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            st = new StringTokenizer(br.readLine());
            
            List<Integer> a = new ArrayList<>();
            Map<Integer, Integer> mp = new HashMap<>();

            for (int i = 0; i < n; i++) {
                int x = Integer.parseInt(st.nextToken());
                mp.put(x, mp.getOrDefault(x, 0) + 1);


                if (x <= 31622 && x != 1) {
                    a.add(x);
                }
            }

            if (solve(n, a, mp)) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }
        out.flush();
        out.close();
    }

    private static boolean solve(int n, List<Integer> a, Map<Integer, Integer> mp) {

        if (mp.getOrDefault(1, 0) >= 2) {
            return true;
        }


        if (mp.containsKey(1)) {
            for (int count : mp.values()) {
                if (count >= 2) {
                    return true;
                }
            }
        }


        for (int v : a) {
            long x = (long) v * v;
            for (int i = 2; x <= 1000000000; i++) {

                if (mp.containsKey(i) && mp.containsKey((int) x)) {
                    return true;
                }
                x *= v;
                if (x > 1000000000) break; 
            }
        }

        return false;
    }
}