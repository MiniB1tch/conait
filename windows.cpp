#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_CTYPE,"RUS");
    int H, W, mH = 32, mW = 64, xM = 1, yM = 1, k = 1, lastX = 1, lastY = 1, track = 0;
    char cM = '+', cP = 'o', cS;
    char points[255][255];
    bool Online = false;

    for(int i = 0; i < mH; i++)
    {
        for(int j = 0; j < mW; j++)
        {
            points[i][j] = ' ';
        }
    }

    do
    {
        cout << "Введите высоту (1 - " << mH << "): ";
        cin >> H;
        system("cls");
    }
    while(H < 1 || mH < H);

    do
    {
        cout << "Введите ширину (1 - " << mW << "): ";
        cin >> W;
        system("cls");
    }
    while(W < 1 || mW < W);

    do
    {
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                if(xM - 1 == j && yM - 1 == i)
                {
                    cout << cM << " ";
                }

                else
                {
                    cout << points[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << "(Mouse " << xM << ":" << yM << ")" << endl;
        cout << "[W][A][S][D] - Управление курсором;" << endl;
        cout << "[E][Q][R][Z] - Поставить / удалить / сменить / очистить символ(ы);" << endl;
        cout << "[X][C][+][-] - Шаг, символ курсора | Online-mode;" << endl;
        cout << "[F] - Выход." << endl;
        cout << "> ";
        cin >> cS;

        if(cS == 'W' || cS == 'w')
        {
            lastY = yM;
            if(yM - k > 1)
                yM -= k;
            else
                yM = 1;
            track = 1;
        }

        else if(cS == 'A' || cS == 'a')
        {
            lastX = xM;
            if(xM - k > 1)
                xM -= k;
            else
                xM = 1;
            track = 2;
        }

        else if(cS == 'S' || cS == 's')
        {
            lastY = yM;
            if(yM + k < H)
                yM += k;
            else
                yM = H;
            track = 3;
        }

        else if(cS == 'D' || cS == 'd')
        {
            lastX = xM;
            if(xM + k < W)
                xM += k;
            else
                xM = W;
            track = 4;
        }

        else if(cS == 'E' || cS == 'e')
        {
            points[yM - 1][xM - 1] = cP;
        }

        else if(cS == 'Q' || cS == 'q')
        {
            points[yM - 1][xM - 1] = ' ';
        }

        else if(cS == 'R' || cS == 'r')
        {
            cout << "Символ => ";
            cin >> cP;
        }

        else if(cS == 'Z' || cS == 'z')
        {
            for(int i = 0; i < mH; i++)
            {
                for(int j = 0; j < mW; j++)
                {
                    points[i][j] = ' ';
                }
            }
        }

        else if(cS == 'X' || cS == 'x')
        {
            do
            {
                cout << "Шаг => ";
                cin >> k;
            }
            while(k < 1);
        }

        else if(cS == 'C' || cS == 'c')
        {
            cout << "Символ => ";
            cin >> cM;
        }

        else if(cS == '+' || cS == '-')
        {
            if(cS == '+')
            {
                track = 0;
                Online = true;
            }
            else
            {
                Online = false;
            }
        }

        if(Online)
        {
            if(track == 1)
            {
                for(int i = lastY; i >= yM; i--)
                {
                    points[i - 1][xM - 1] = cP;
                }
            }

            else if(track == 2)
            {
                for(int i = lastX; i >= xM; i--)
                {
                    points[yM - 1][i - 1] = cP;
                }
            }

            else if(track == 3)
            {
                for(int i = lastY; i <= yM; i++)
                {
                    points[i - 1][xM - 1] = cP;
                }
            }

            else if(track == 4)
            {
                for(int i = lastX; i <= xM; i++)
                {
                    points[yM - 1][i - 1] = cP;
                }
            }
        }

        system("cls");
    }
    while(cS != 'F' && cS != 'f');

    return 0;
}
