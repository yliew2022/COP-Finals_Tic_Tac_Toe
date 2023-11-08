// Yi Yang Liew
// COP Finals
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
using namespace std;

int a[3][3], t, y, game = 1;
char name[30], str[500];

void print()
{
    int i, j;
    cout << "\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
                cout << ".\t";
            else if (a[i][j] == 1)
                cout << "X\t";
            else
                cout << "O\t";
        }
        cout << endl;
    }
}

int check()
{
    for (int i = 0; i < 3; i++)
        if ((a[i][0] != 0 && a[i][0] == a[i][1] && a[i][1] == a[i][2]) || (a[0][i] != 0 && a[0][i] == a[1][i] && a[1][i] == a[2][i]))
            return 1;

    if (a[0][0] != 0 && a[0][0] == a[1][1] && a[1][1] == a[2][2])
        return 1;
    else if (a[0][2] != 0 && a[0][2] == a[1][1] && a[1][1] == a[2][0])
        return 1;
    else
        return 0;
}

void pin()
{
    int r = 0, c = 0;
    cout << "Enter row: ";
    cin >> r;
    cout << "Enter column: ";
    cin >> c;
    r--;
    c--;
    if (r > 2 || c > 2 || r < 0 || c < 0)
    {
        strcpy_s(str, "Wrong value");
        strcat_s(str, ".\n");
        puts(str);
        pin();
    }
    else if (a[r][c] != 0)
    {
        cout << "Enter another move.\n";
        pin();
    }
    else
        a[r][c] = t;

}



int defend(int c, int p, int b)
{
    if (b < 3)
        return 0;
    else if (a[0][0] + a[1][1] + a[2][2] == 2 * c && a[0][0] != p && a[1][1] != p && a[2][2] != p)
    {
        for (int i = 0; i < 3; i++)
        {
            if (a[i][i] == 0)
            {
                a[i][i] = y;
                cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                return 1;
            }
        }
    }
    else if (a[0][2] + a[1][1] + a[2][0] == 2 * c && a[0][2] != p && a[1][1] != p && a[2][0] != p)
    {
        for (int i = 0; i < 3; i++)
        {
            if (a[i][2 - i] == 0)
            {
                a[i][2 - i] = y;
                cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                return 1;
            }
        }
    }
    else
    {
        int i, j;
        for (i = 0; i < 3; i++)
        {
            if (a[i][0] + a[i][1] + a[i][2] == 2 * c && a[i][0] != p && a[i][1] != p && a[i][2] != p)
            {
                for (j = 0; j < 3; j++)
                {
                    if (a[i][j] == 0)
                    {
                        a[i][j] = y;
                        cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                        return 1;
                    }
                }
            }
            else if (a[0][i] + a[1][i] + a[2][i] == 2 * c && a[0][i] != p && a[1][i] != p && a[2][i] != p)
            {
                for (j = 0; j < 3; j++)
                {
                    if (a[j][i] == 0)
                    {
                        a[j][i] = y;
                        cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int attack()
{
    int i, j;
    if (a[0][0] + a[0][2] + a[2][0] + a[2][2] == t || a[0][0] + a[0][2] + a[2][0] + a[2][2] == 2 * t)
    {
        for (i = 0; i < 3; i++)
        {
            if (a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y))
            {
                if (i == 1)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (a[i][j] == 0)
                        {
                            a[i][j] = y;
                            cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for (j = 2; j >= 0; j--)
                    {
                        if (a[i][j] == 0)
                        {
                            a[i][j] = y;
                            cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                            return 1;
                        }
                    }
                }
            }
            if (a[0][i] + a[1][i] + a[2][i] == y && (a[0][i] == y || a[1][i] == y || a[2][i] == y))
            {
                if (i == 1)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (a[j][i] == 0)
                        {
                            a[j][i] = y;
                            cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for (j = 2; j >= 0; j--)
                    {
                        if (a[j][i] == 0)
                        {
                            a[j][i] = y;
                            cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                            return 1;
                        }
                    }
                }

            }
        }

        if (a[0][0] + a[1][1] + a[2][2] == y && (a[0][0] == y || a[1][1] == y || a[2][2] == y))
        {
            for (i = 2; i >= 0; i--)
            {
                if ((a[i][i] == 0) && ((a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y)) || ((a[0][i] + a[1][i] + a[2][i] == y) && (a[0][i] == y || a[1][i] == y || a[2][i] == y))))
                {
                    a[i][i] = y;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][i] == 0)
                {
                    if ((a[i][0] + a[i][1] + a[i][2] == t && (a[i][0] == t || a[i][1] == t || a[i][2] == t)) && (a[0][i] + a[1][i] + a[2][i] == t && (a[0][i] == t || a[1][i] == t || a[2][i] == t)))
                    {
                        a[i][i] = y;
                        cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                        return 1;
                    }
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][i] == 0)
                {
                    a[i][i] = y;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
        }
        else if (a[0][2] + a[1][1] + a[2][0] == y && (a[0][2] == y || a[1][1] == y || a[2][0] == y))
        {
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0 && ((a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y)) || ((a[0][2 - i] + a[1][2 - i] + a[2][2 - i] == y) && (a[0][2 - i] == y || a[1][2 - i] == y || a[2][2 - i] == y))))
                {
                    a[i][2 - i] = y;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0)
                {
                    if ((a[i][0] + a[i][1] + a[i][2] == t && (a[i][0] == t || a[i][1] == t || a[i][2] == t)) && (a[0][2 - i] + a[1][2 - i] + a[2][2 - i] == t && (a[0][2 - i] == t || a[1][2 - i] == t || a[2][2 - i] == t)))
                    {
                        a[i][2 - i] = y;
                        cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                        return 1;
                    }
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0)
                {
                    a[i][2 - i] = y;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
        }
    }
    else
    {
        if (a[0][0] + a[1][1] + a[2][2] == y && (a[0][0] == y || a[1][1] == y || a[2][2] == y))
        {
            for (i = 2; i >= 0; i--)
            {
                if ((a[i][i] == 0) && ((a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y)) || ((a[0][i] + a[1][i] + a[2][i] == y) && (a[0][i] == y || a[1][i] == y || a[2][i] == y))))
                {
                    a[i][i] = y;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][i] == 0)
                {
                    if ((a[i][0] + a[i][1] + a[i][2] == t && (a[i][0] == t || a[i][1] == t || a[i][2] == t)) && (a[0][i] + a[1][i] + a[2][i] == t && (a[0][i] == t || a[1][i] == t || a[2][i] == t)))
                    {
                        a[i][i] = y;
                        cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                        return 1;
                    }
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][i] == 0)
                {
                    a[i][i] = y;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
        }

        else if (a[0][2] + a[1][1] + a[2][0] == y && (a[0][2] == y || a[1][1] == y || a[2][0] == y))
        {
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0 && ((a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y)) || ((a[0][2 - i] + a[1][2 - i] + a[2][2 - i] == y) && (a[0][2 - i] == y || a[1][2 - i] == y || a[2][2 - i] == y))))
                {
                    a[i][2 - i] = y;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0)
                {
                    if ((a[i][0] + a[i][1] + a[i][2] == t && (a[i][0] == t || a[i][1] == t || a[i][2] == t)) && (a[0][2 - i] + a[1][2 - i] + a[2][2 - i] == t && (a[0][2 - i] == t || a[1][2 - i] == t || a[2][2 - i] == t)))
                    {
                        a[i][2 - i] = y;
                        cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                        return 1;
                    }
                }
            }

            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0)
                {
                    a[i][2 - i] = y;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
        }

        else
        {
            for (i = 0; i < 3; i++)
            {
                if (a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y))
                {
                    if (i == 1)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (a[i][j] == 0)
                            {
                                a[i][j] = y;
                                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                                return 1;
                            }
                        }
                    }
                    else {
                        for (j = 2; j >= 0; j--)
                        {
                            if (a[i][j] == 0)
                            {
                                a[i][j] = y;
                                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                                return 1;
                            }
                        }
                    }
                }
                else if (a[0][i] + a[1][i] + a[2][i] == y && (a[0][i] == y || a[1][i] == y || a[2][i] == y))
                {
                    if (i == 1)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (a[j][i] == 0)
                            {
                                a[j][i] = y;
                                cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for (j = 2; j >= 0; j--)
                        {
                            if (a[j][i] == 0)
                            {
                                a[j][i] = y;
                                cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void ai(int b)
{
    if (!defend(y, t, b))
    {
        if (!defend(t, y, b))
        {
            if ((a[0][0] + a[0][2] + a[2][0] + a[2][2] == t + y || a[0][0] + a[0][2] + a[2][0] + a[2][2] == t + 2 * y) && a[1][1] == 0)
            {
                for (int i = 0; i < 3; i += 2)
                {
                    for (int j = 0; j < 3; j += 2)
                        if (a[i][j] == 0)
                        {
                            a[i][j] = y;
                            cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                            goto end;
                        }
                }

            }
            else if (b == 2 && a[1][1] == 0)
            {
                a[1][1] = y;
                cout << "Computer turn: \n";
                goto end;
            }
            if (!attack())
            {
                if (b == 0)
                {
                    time_t seconds;
                    time(&seconds);
                    srand((unsigned int)seconds);
                    int i, j;
                    a[(rand() % 2) * 2][(rand() % 2) * 2] = y;
                    for (i = 0; i < 3; i += 2)
                    {
                        for (j = 0; j < 3; j += 2)
                            if (a[i][j] == y)
                                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                    }
                }
                else if (a[1][1] == 0)
                {
                    a[1][1] = y;
                    cout << "Computer turn: \n";
                }
                else
                {
                    int i, j;
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (a[i][j] == 0)
                            {
                                a[i][j] = y;
                                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                                goto end;
                            }
                        }
                    }
                }
            }
        }
    }
end:
    cout << endl;
}


int main()
{
    int i, j;
    int name;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            a[i][j] = 0;
    if (game == 1)
    {
        cout << "Please enter your name: ";
        gets_s(name);
        strcpy_s(str, "\nHello ");
        strcat_s(str, "\nWelcome to the unbeatable Tic Tac Toe Game.");
        puts(str);

        strcpy_s(str, "\n");
        strcat_s(str, "Enter 1 to go first or 2 to go second ");
        puts(str);
    }
    else
    {
        strcpy_s(str, "\n");
        strcat_s(str, "Try again.");
        puts(str);

        strcpy_s(str, "\nEnter 1 to go first or 2 to go second ");
        puts(str);
    }

input:
    cin >> t;
    switch (t)
    {
    case 1:
        y = 2;
        cout << "\nPlayer is X.\nPlayer is O.\n\nBegin game.";
        print();
        for (i = 0; i < 9;)
        {
            pin();
            print();
            i++;
            if (i > 4)
                if (check())
                {
                    strcpy_s(str, "\nHow did you win? ");
                    strcat_s(str, " .\nMaybe I need to work on the algorithm.");
                    puts(str);
                    exit(0);
                    break;
                }
            if (i >= 8)
                break;
            ai(i);
            print();
            i++;
            if (i > 5)
                if (check())
                {
                    strcpy_s(str, "\nComputer wins.");
                    puts(str);
                    break;
                }
        }
        break;

    case 2:
        y = 1;
        cout << "\nPlayer is O.\nPlayer is X.\n\nGame begin.";
        print();
        for (i = 0; i < 9;)
        {
            ai(i);
            print();
            i++;
            if (i > 4)
                if (check())
                {
                    strcpy_s(str, "\nComputer wins.");
                    puts(str);
                    break;
                }
            if (i >= 8)
                break;
            pin();
            print();
            i++;
            if (i > 5)
                if (check())
                {
                    strcpy_s(str, "\nHow did you win?");
                    strcat_s(str, " .\nMaybe I need to work on the algorithm.");
                    puts(str);
                    exit(0);
                    break;
                }
        }
        break;
    default:
        strcpy_s(str, "\nWrong input.");
        strcat_s(str, "\nPlease enter 1 or 2.");
        puts(str);
        cout << "\nTry again: ";
        goto input;
        break;
    }
    if (!check())
    {
        if (game > 1)
            cout << "\nTie.\n";
        else
            cout << "\nTie.\n";

    }
    char c;
    strcpy_s(str, "Do you want to play again (y/n)? ");
    puts(str);
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        game++;
        main();
    }
    else
        cout << "\nThank you for playing.\n";
    exit(0);
    return 0;
}
