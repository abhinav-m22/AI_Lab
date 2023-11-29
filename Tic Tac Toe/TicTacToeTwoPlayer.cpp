#include <bits/stdc++.h>
using namespace std;
int main()
{
    char matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = '*';
        }
    }
    while (true)
    {
        int x, y;
        while (true)
        {
            int flag = 0;
            cout << "Player One" << endl;
            cout << "Enter row and column (0-2): ";
            cin >> x >> y;
            if (matrix[x][y] == '*' && x <= 2 && y <= 2)
            {
                matrix[x][y] = 'X';
                flag = 1;
            }
            if (flag == 1)
            {
                break;
            }
            else
            {
                cout << "Error Enter Valid coordinates" << endl;
            }
        }
        int countx = 0;
        int county = 0;
        int countd = 0;
        for (int i = 0; i < 3; i++)
        {
            if (matrix[x][i] == 'X')
            {
                countx++;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (matrix[i][y] == 'X')
            {
                county++;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j && matrix[i][j] == 'X')
                {
                    countd++;
                }
            }
        }
        if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
        {
            cout << "Player one wins" << endl;
            break;
        }
        if (countx == 3 || county == 3 || countd == 3)
        {
            cout << "Player one wins" << endl;
            break;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
        int x1, y1;
        while (true)
        {
            int flag = 0;
            cout << "Player Two " << endl;
            cout << "Enter row and column (0-2): ";
            cin >> x1 >> y1;
            if (matrix[x1][y1] == '*' && x1 <= 2 && y1 <= 2)
            {
                matrix[x1][y1] = 'O';
                flag = 1;
            }
            if (flag == 1)
            {
                break;
            }
            else
            {
                cout << "Error Enter Valid coordinates" << endl;
            }
        }
        countx = 0;
        county = 0;
        countd = 0;
        for (int i = 0; i < 3; i++)
        {
            if (matrix[x1][i] == 'O')
            {
                countx++;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (matrix[i][y1] == 'O')
            {
                county++;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j && matrix[i][j] == 'O')
                {
                    countd++;
                }
            }
        }
        if (countx == 3 || county == 3 || countd == 3)
        {
            cout << "Player two wins" << endl;
            break;
        }
        if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
        {
            cout << "Player two wins" << endl;
            break;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}