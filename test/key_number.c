
// ---------------------------非同期モードでのキー入力---------------------------
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// ターミナルの非同期モードを有効化
void enableRawMode()
{
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main()
{
    enableRawMode();
    printf("Press any key to get its keycode. Press 'q' to quit.\n");

    while (1)
    {
        char ch;
        if (read(STDIN_FILENO, &ch, 1) == 1)
        {
            if (ch == 'q')
            {
                printf("Exiting...\n");
                break;
            }

            // キーの番号を表示
            printf("Keycode: %d\n", ch);
        }
    }

    return 0;
}
// -----------------------------同期モードでのキー入力---------------------------
// #include <stdio.h>

// int main()
// {
//     printf("Press any key to get its keycode. Press 'q' to quit.\n");

//     while (1)
//     {
//         char ch = getchar(); // キー入力を取得

//         if (ch == 'q')
//         {
//             printf("Exiting...\n");
//             break;
//         }

//         // キーの番号を表示
//         printf("Keycode: %d\n", ch);
//         fflush(stdin); // バッファをクリア
//     }

//     return 0;
// }
