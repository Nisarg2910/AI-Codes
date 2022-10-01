import java.util.Arrays;
import java.util.Scanner;

public class TicTacToe {
    public static void main(String[] args) {
        char[] board = new char[9];
        Scanner scanner = new Scanner(System.in);
        int turn = 0;
        for (int i = 0; i < 9; i++) {
            board[i] = (char) (i + 49);
        }
        print(board);
        for (int i = 0; i < 9; i++) {
            switch (turn) {
                case 0:
                    System.out.print("X takes turn:");
                    if (turn(board, scanner.nextInt(), 'X')) {
                        print(board);
                        System.out.println("X wins");
                        return;
                    }
                    break;
                case 1:
                    System.out.print("O takes turn:");
                    if (turn(board, scanner.nextInt(), 'O')) {
                        print(board);
                        System.out.println("O wins");
                        return;
                    }
            }
            turn = 1 - turn;
        }
        System.out.println("Draw");
    }

    public static boolean turn(char[] board, int value, char player) {
        board[value - 1] = player;
        switch (value) {
            case 1:
                if (("" + board[0] + board[1] + board[2]).equals("" + player + player + player))
                    return true;
                else if (("" + board[0] + board[3] + board[6]).equals("" + player + player + player))
                    return true;
                else if (("" + board[0] + board[4] + board[8]).equals("" + player + player + player))
                    return true;
                break;
            case 2:
                if (("" + board[0] + board[1] + board[2]).equals("" + player + player + player))
                    return true;
                else if (("" + board[1] + board[4] + board[8]).equals("" + player + player + player))
                    return true;
                break;
            case 3:
                if (("" + board[0] + board[1] + board[2]).equals("" + player + player + player))
                    return true;
                else if (("" + board[2] + board[5] + board[8]).equals("" + player + player + player))
                    return true;
                else if (("" + board[2] + board[4] + board[6]).equals("" + player + player + player))
                    return true;
                break;
            case 4:
                if (("" + board[0] + board[3] + board[6]).equals("" + player + player + player))
                    return true;
                else if (("" + board[3] + board[4] + board[5]).equals("" + player + player + player))
                    return true;
                break;
            case 5:
                if (("" + board[1] + board[4] + board[7]).equals("" + player + player + player))
                    return true;
                else if (("" + board[3] + board[4] + board[5]).equals("" + player + player + player))
                    return true;
                else if (("" + board[0] + board[4] + board[8]).equals("" + player + player + player))
                    return true;
                else if (("" + board[2] + board[4] + board[6]).equals("" + player + player + player))
                    return true;
                break;
            case 6:
                if (("" + board[2] + board[5] + board[8]).equals("" + player + player + player))
                    return true;
                else if (("" + board[3] + board[4] + board[5]).equals("" + player + player + player))
                    return true;
                break;
            case 7:
                if (("" + board[0] + board[3] + board[6]).equals("" + player + player + player))
                    return true;
                else if (("" + board[6] + board[7] + board[8]).equals("" + player + player + player))
                    return true;
                else if (("" + board[2] + board[4] + board[6]).equals("" + player + player + player))
                    return true;
                break;
            case 8:
                if (("" + board[1] + board[4] + board[7]).equals("" + player + player + player))
                    return true;
                else if (("" + board[6] + board[7] + board[8]).equals("" + player + player + player))
                    return true;
                break;
            case 9:
                if (("" + board[2] + board[5] + board[8]).equals("" + player + player + player))
                    return true;
                else if (("" + board[6] + board[7] + board[8]).equals("" + player + player + player))
                    return true;
                else if (("" + board[0] + board[4] + board[8]).equals("" + player + player + player))
                    return true;
                break;
        }
        print(board);
        return false;
    }

    public static void print(char[] board) {
        System.out.println(board[0] + " " + board[1] + " " + board[2]);
        System.out.println(board[3] + " " + board[4] + " " + board[5]);
        System.out.println(board[6] + " " + board[7] + " " + board[8]);
    }
}
