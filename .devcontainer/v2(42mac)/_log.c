
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

// 新規で log.txt を作成し、一行目に現在の日時を記述する関数
void makeLog() {
    // ログファイルのパス
    const char *logFilePath = "log.txt";

    // ファイルを上書きモードで開く
    FILE *logFile = fopen(logFilePath, "w");

    // ファイルが正しく開けたか確認
    if (logFile == NULL) {
        perror("Error opening log file");
        return;
    }

    // 現在の日時を取得
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    // 日時を文字列に変換
    char timeString[64];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);

    // ファイルに日時を書き込み
    fprintf(logFile, "%s\n", timeString);

    // ファイルを閉じる
    fclose(logFile);
}

// ログファイルへの書き込み関数
void writeToLogfile(const char *format, ...) {
    // ログファイルのパス
    const char *logFilePath = "log.txt";

    // ファイルを追記モードで開く
    FILE *logFile = fopen(logFilePath, "a");

    // ファイルが正しく開けたか確認
    if (logFile == NULL) {
        perror("Error opening log file");
        return;
    }

    // 可変引数を処理するために va_list を初期化
    va_list args;
    va_start(args, format);

    // ファイルに書き込み
    vfprintf(logFile, format, args);

    // va_list の終了処理
    va_end(args);

    // ファイルを閉じる
    fclose(logFile);
}

// 使用例：
// if(x%100 == 0&& y%100 == 0){
//     writeToLogfile("(x,y) = (%d, %d)\n", x, y);
//     writeToLogfile("fractal->img.addr = %p\n", fractal->img.addr);
//     writeToLogfile("fractal->img.line_length = %d\n", fractal->img.line_length);
//     writeToLogfile("fractal->img.bits_per_pixel = %d\n", fractal->img.bits_per_pixel);
//     writeToLogfile("color = %d\n", color);
//     writeToLogfile("rendering 11: ok\n");
// }