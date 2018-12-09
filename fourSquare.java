import java.util.List;
import java.util.ArrayList;

public class Foursquare {

private static final char[][] Alp_sqr = new char[5][5];
private static final char[] Alp = "ABCDEFGHIJKLMNOPRSTUVWXYZ".toCharArray();

    static {
        int x = 0, y = 0;
        for (char c : Alp) {
            Alp_sqr[x][y] = c;
            x++;
            if (x == 5) {
                x = 0;
                y++;
            }
        }
    }

private static String clean(String input) {
        input = input.trim().replace(" ", "").replace("Q", "").toUpperCase();
        StringBuilder clean = new StringBuilder();
        for (char c : input.toCharArray()) {
            if (Character.getType(c) == Character.UPPERCASE_LETTER) {
                clean.append(c);
            }
        }
        return clean.toString();
    }

private static char[][] generateKeyTable(String keyword) {
        keyword = clean(keyword);
        char[][] keyTable = new char[5][5];
        List used = new ArrayList();
        int x = 0, y = 0;
        for (char c : keyword.toCharArray()) {
            if (!used.contains(c)) {
                keyTable[x][y] = c;
                used.add(c);
                x++;
                if (x == 5) {
                    x = 0;
                    y++;
                    if (y == 5) {
                        return keyTable;
                    }
                }
            }
        }
        for (char c : Alp) {
            if (!used.contains(c)) {
                keyTable[x][y] = c;
                x++;
                if (x == 5) {
                    x = 0;
                    y++;
                    if (y == 5) {
                        return keyTable;
                    }
                }
            }
        }
        return keyTable;
    }

private static String[] split(String plaintext) {
        if (plaintext.length() % 2 != 0) {
            plaintext = plaintext + "X";
        }
        String[] pairs = new String[plaintext.length() / 2];
        int count = 0;
        for (int i = 0; i < (plaintext.length() / 2); i++) {
            pairs[i] = plaintext.substring(count, count + 2);
            count = count + 2;
        }
        return pairs;
    }

public static String encrypt(String plaintext, String keyword1, String keyword2) {
        plaintext = clean(plaintext);
        String[] pairs = split(plaintext);
        char[][] keytable1 = generateKeyTable(keyword1);
        char[][] keytable2 = generateKeyTable(keyword2);
        char first, second;
        int xFirst = 0, yFirst = 0, xSecond = 0, ySecond = 0;
        StringBuilder ciphertext = new StringBuilder();
        for (String s : pairs) {
            first = s.charAt(0);
            second = s.charAt(1);
            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 5; x++) {
                    if (Alp_sqr[x][y] == first) {
                        xFirst = x;
                        yFirst = y;
                    } else if (Alp_sqr[x][y] == second) {
                        xSecond = x;
                        ySecond = y;
                    }
                }
            }
            ciphertext.append(keytable1[xSecond][yFirst]).append(keytable2[xFirst][ySecond]);
        }
        return ciphertext.toString();
    }

public static String decrypt(String ciphertext, String keyword1, String keyword2) {
        String[] pairs = split(ciphertext);
        char[][] keytable1 = generateKeyTable(keyword1);
        char[][] keytable2 = generateKeyTable(keyword2);
        char first, second;
        int xFirst = 0, yFirst = 0, xSecond = 0, ySecond = 0;
        StringBuilder plaintext = new StringBuilder();
        for (String s : pairs) {
            first = s.charAt(0);
            second = s.charAt(1);
            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 5; x++) {
                    if (keytable1[x][y] == first) {
                        xFirst = x;
                        yFirst = y;
                    } else if (keytable2[x][y] == second) {
                        xSecond = x;
                        ySecond = y;
                    }
                }
            }
            plaintext.append(Alp_sqr[xSecond][yFirst]).append(Alp_sqr[xFirst][ySecond]);
        }
        return plaintext.toString();
    }



public static void main(String[] args) {
        try {
            if(args[0].equalsIgnoreCase("-d")) {
                System.out.println(decrypt(args[1], args[2], args[3]));
            } else {
                System.out.println(encrypt(args[0], args[1], args[2]));
            }
        } catch (ArrayIndexOutOfBoundsException ex) {
            System.err.println("Caught IOException: " + e.getMessage());
        }
    }
}
