#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GRAY "\x1b[30m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

int beep = 0, sound = 1;

int game_result(char *block);
int game_result(char *block)
{
    int i, j;
    //  for rows O
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (strcmp(block + ((i * 3) * 2) + j * 2, "O") != 0)
                break;
        if (j == 3) // printf("< O win >\n");
            return 1;
    }
    //  for columns
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (strcmp(block + ((j * 3) * 2) + i * 2, "O") != 0)
                break;
        if (j == 3) // printf("< O win >\n");
            return 1;
    }
    //  for rows X
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (strcmp(block + ((i * 3) * 2) + j * 2, "X") != 0)
                break;
        if (j == 3) // printf("< X win >\n");
            return 2;
    }
    // printf("\nfor columns X");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            if (strcmp(block + ((j * 3) * 2) + i * 2, "X") != 0)
                break;
        if (j == 3) // printf("< X win >\n");
            return 2;
    }

    // printf("\nfor diagonal O");
    if ((strcmp(block + ((0 * 3) * 2) + 0 * 2, "O") == 0) && (strcmp(block + ((1 * 3) * 2) + 1 * 2, "O") == 0) && (strcmp(block + ((2 * 3) * 2) + 2 * 2, "O") == 0)) // printf("< O win >\n");
        return 1;
    if ((strcmp(block + ((0 * 3) * 2) + 2 * 2, "O") == 0) && (strcmp(block + ((1 * 3) * 2) + 1 * 2, "O") == 0) && (strcmp(block + ((2 * 3) * 2) + 0 * 2, "O") == 0)) // printf("< O win >\n");
        return 1;

    // printf("\nfor diagonal X");
    if ((strcmp(block + ((0 * 3) * 2) + 0 * 2, "X") == 0) && (strcmp(block + ((1 * 3) * 2) + 1 * 2, "X") == 0) && (strcmp(block + ((2 * 3) * 2) + 2 * 2, "X") == 0)) // printf("< X win >\n");
        return 2;
    if ((strcmp(block + ((0 * 3) * 2) + 2 * 2, "X") == 0) && (strcmp(block + ((1 * 3) * 2) + 1 * 2, "X") == 0) && (strcmp(block + ((2 * 3) * 2) + 0 * 2, "X") == 0)) // printf("< X win >\n");
        return 2;

    return 0;
}

void computers_turn(char *block, int *user_turns)
{
    int i, flag = 0, r;
    // check if computer win for i
    for (i = 0; i <= 8; i++)
    {
        if (*(block + (i * 2)) >= '1' && *(block + (i * 2)) <= '9')
        {
            *(block + (i * 2)) = 'X';
            if (game_result(block) == 2)
            {
                (*user_turns)++;
                return;
            }
            else
                *(block + (i * 2)) = 49 + i;
        }
    }
    // check if user win for i
    for (i = 0; i <= 8; i++)
    {
        if (*(block + (i * 2)) >= '1' && *(block + (i * 2)) <= '9')
        {
            *(block + (i * 2)) = 'O';
            if (game_result(block) == 1)
            {
                *(block + (i * 2)) = 'X';
                (*user_turns)++;
                return;
            }
            else
            {
                *(block + (i * 2)) = 49 + i;
            }
        }
    }
    // no one going to win the go for random
    if (flag == 0 && *(user_turns) <= 8)
    {
        while (1)
        {
            srand(time(NULL));
            r = rand() % 10;
            if (*(block + (r * 2)) >= '1' && *(block + (r * 2)) <= '9')
            {
                *(block + (r * 2)) = 'X';
                (*user_turns)++;
                return;
            }
        }
    }
}

void evil_computers_turn(char *block, int *user_turns)
{
    int i, flag = 0, r;
    // check where can computer win
    for (i = 0; i <= 8; i++)
    {
        if (*(block + (i * 2)) >= '1' && *(block + (i * 2)) <= '9')
        {
            *(block + (i * 2)) = 'X';
            if (game_result(block) == 2)
            {
                (*user_turns)++;
                return;
            }
            else
                *(block + (i * 2)) = 49 + i;
        }
    }

    // check where user is win
    for (i = 0; i <= 8; i++)
    {
        if (*(block + (i * 2)) >= '1' && *(block + (i * 2)) <= '9')
        {
            *(block + (i * 2)) = 'O';
            if (game_result(block) == 1)
            {
                *(block + (i * 2)) = 'X';
                (*user_turns)++;
                flag = 1;
            }
            else
            {
                *(block + (i * 2)) = 49 + i;
            }
        }
    }
    if (flag == 0 && *(user_turns) <= 9)
    {
        while (1)
        {
            r = rand() % 10;
            if (*(block + (r * 2)) >= '1' && *(block + (r * 2)) <= '9')
            {
                *(block + (r * 2)) = 'X';
                (*user_turns)++;
                break;
            }
        }
    }
}

void win_sound()
{
    int i;
    if (sound == 1)
    {
        for (i = 250; i <= 350; i += 50)
            Beep(i, 200);
        Beep(400, 290);
        Beep(300, 300);
        Beep(350, 200);
        Beep(200, 50);
        Beep(300, 200);
        Beep(400, 1000);
    }
}
void you_lose_sound()
{
    int i;
    if (sound == 1)
    {
        for (i = 600; i >= 300; i -= 50)
        {
            Beep(i, 200);
        }
        Beep(350, 1000);
    }
}
void draw_sound()
{
    if (sound == 1)
    {
        Beep(200, 500);
        Beep(300, 150);
        Beep(220, 400);
    }
}
void click_sound()
{
    if (sound == 1)
    {
        Beep(500, 175);
        Beep(600, 100);
    }
}
void play_game(int play_mode, char user_name[])
{
    int position, i, j, k, l, user_turn = 0, total_turns = 0;
    char block[3][3][2] = {"1\0", "2\0", "3\0", "4\0", "5\0", "6\0", "7\0", "8\0", "9\0"};
    char *bl_ptr = block[0][0];
    while (1)
    {
        system("cls");
        printf("################### TIC TAC TOE ####################%d %d %d", 0, 1, 9);
        printf("\n  < player 1 = O >  %s", user_name);
        switch (play_mode)
        {
        case 0:
            printf("\n  < player 2 = X >  second person");
            break;
        case 1:
            printf("\n  < player 2 = X >  smart computer");
            break;
        case 2:
            printf("\n  < player 2 = X >  evil computer");
            break;
        default:
            break;
        }
        for (i = 1; i <= 3; i++)
        {
            for (j = 0, k = 0; j < 3; j++)
            {
                if (i == 3 && j == 2)
                {
                    printf("\n                      |     |     ");
                    break;
                }
                switch (j)
                {
                case 0:
                    printf("\n                      |     |     ");
                    break;
                case 1:
                    if (i == 2 && user_turn == 0)
                        printf("\nyour turn :      ");
                    else
                        printf("\n                 ");
                    for (l = 0; l < 3; l++)
                    {
                        if (block[i - 1][k][0] >= '1' && block[i - 1][k][0] <= '9')
                            printf(ANSI_COLOR_GRAY "  %c  " ANSI_COLOR_RESET, block[i - 1][k][0]);
                        else
                            printf(ANSI_COLOR_YELLOW "  %c  " ANSI_COLOR_RESET, block[i - 1][k][0]);
                        if (l != 2)
                            printf("|");
                        k++;
                    }
                    if (i == 2 && user_turn == 1)
                    {
                        switch (play_mode)
                        {
                        case 0:
                            printf("     another players turn");
                            break;
                        case 1:
                            printf("     computers turn :   thinking...");
                            break;
                        case 2:
                            printf("     evil computers turn : thinking...");
                        default:
                            break;
                        }
                    }

                    break;
                default:
                    printf("\n                 _____|_____|_____");
                    break;
                }
            }
        }
        if (game_result(&block[0][0][0]) == 1)
        {
            printf("\n\n###########################################################\n\n         player 1 won\n\n###########################################################");
            win_sound();
            getch();
            return;
        }
        else if (game_result(&block[0][0][0]) == 2)
        {
            if (play_mode == 0)
            {
                printf("\n\n###########################################################\n\n         player 2 won\n\n###########################################################");
                win_sound();
                getch();
                return;
            }

            printf("\n\n###########################################################\n\n         computer won\n\n###########################################################");
            you_lose_sound();
            getch();
            return;
        }
        if (total_turns >= 9)
            break;
        // printf("\ntotal_turns = %d", total_turns);
        if (user_turn == 0)
        {
            printf("\n\n%s\nyours turn : ", user_name);
            position = readEnteredkey();
            position -= 49;
            if ((position >= 0 && position <= 8) && ((bl_ptr + (position * 2))[0] >= '1') && ((bl_ptr + (position * 2))[0] <= '9'))
            {
                (bl_ptr + (position * 2))[0] = 'O';
                user_turn = 1;
                total_turns++;
            }
        }
        else
        {
            printf("\n\n                                         player 2 turn : ");
            switch (play_mode)
            {
            case 0:
                position = readEnteredkey();
                position -= 49;
                break;
            case 1:
                Sleep(1500);
                click_sound();
                computers_turn(&block[0][0][0], &total_turns); // rand() % 10;
                user_turn = 0;
                break;
            case 2:
                Sleep(1500);
                click_sound();
                // printf("<evil>");
                // getch();
                evil_computers_turn(&block[0][0][0], &total_turns);
                user_turn = 0;
                // total_turns++;
                // getch();
                break;
                // default:
                //     position = readEnteredkey();
                //     position -= 49;
                //     if ((position >= 0 && position <= 8) && ((bl_ptr + (position * 2))[0] >= '1') && ((bl_ptr + (position * 2))[0] <= '9'))
                //     {
                //         (bl_ptr + (position * 2))[0] = 'X';
                //         user_turn = 0;
                //         total_turns++;
                //     }
                //     break;
            }
            if ((position >= 0 && position <= 8) && ((bl_ptr + (position * 2))[0] >= '1') && ((bl_ptr + (position * 2))[0] <= '9'))
            {
                (bl_ptr + (position * 2))[0] = 'X';
                user_turn = 0;
                total_turns++;
            }
        }
    }
    if (total_turns >= 9)
        printf("\n\n####################################\n\n         Game Draw\n\n####################################"), draw_sound();
    getch();
}

int readEnteredkey()
{
    char c;
    c = getch();
    if (c == -32)
        c = getch();
    sound ? Beep(450, 100):(NULL);
    return c;
}
int readEnteredkey2(int index)
{
    char c;
    c = getch();
    if (c == -32)
        c = getch();
    if (beep == 1 && sound == 1)
    {
        Beep(50 * index + 300, 200);
        beep = 0;
        return c;
    }
    beep = 1;
    return c;
}
void game_menu(int index, int mode_index)
{
    char menu_items[5][20] = {"play", "play with", "sound", "how to play", "exit"};
    char modes[3][20] = {"another player", "computer", "evil computer"};
    printf("\n\n\t\tWelcome to Tic Tac Toe\n\n");
    for (int i = 0; i < 5; i++)
    {
        if (i == index)
        {
            printf(ANSI_COLOR_YELLOW "\n--> %s" ANSI_COLOR_RESET, menu_items[i]);
        }
        else
        {
            printf("\n    %s", menu_items[i]);
        }
        if (i == 1)
        {
            printf(ANSI_COLOR_BLUE "    %20s     " ANSI_COLOR_GRAY " %30s" ANSI_COLOR_RESET, modes[mode_index], "press ENTER to change mode");
        }
        if (i == 2)
        {
            if (sound == 1)
                printf(ANSI_COLOR_GREEN "              on" ANSI_COLOR_RESET);
            else
                printf(ANSI_COLOR_RED "              off" ANSI_COLOR_RESET);
        }
    }
    printf("\n\n\n");
}

void how_to_play()
{
    printf(ANSI_COLOR_YELLOW "\n\t\thow to use menu screen" ANSI_COLOR_RESET);
    printf("\nuse up arrow key and down arrow key to go on the options");
    printf("\nuse enter key to select or change the options");

    printf(ANSI_COLOR_YELLOW "\n\n\thow to play game" ANSI_COLOR_RESET);
    printf("\nyou are paying as O (circle) ");
    printf("\nTo make a circle at your desired place,\njust press the number written on that place once");
    printf("\n\npress any key to back to memu");
    getch();
}

int main()
{
    char user_name[30] = "devendra dhare";
    int index = 0, mode_index = 0, key = 0, flag = 0;
    // draw_sound();
    // win_sound();
    system("cls");
    printf("\n\n\t\tWelcome to Tic Tac Toe\n\nEnter your user name : ");
    fgets(user_name, 30, stdin);
    user_name[strlen(user_name) - 1] = '\0';

    while (1)
    {
        system("cls");
        printf("<%d>", key);
        game_menu(index, mode_index);
        key = readEnteredkey2(index);
        switch (key)
        {
        case 72:
            if (index == 0)
            {
                index = 4;
                break;
            }
            index--;
            break;
        case 80:
            if (index == 4)
            {
                index = 0;
                break;
            }
            index++;
            break;
        case 13:
            beep = 1;
            switch (index)
            {
            case 0:
                flag = 1;
                play_game(mode_index, user_name);
                break;
            case 1:
                if (mode_index >= 2)
                    mode_index = 0;
                else
                    mode_index++;
                break;
            case 2:
                sound ? (sound = 0) : (sound = 1);
                break;
            case 3:
                how_to_play();
                break;
            case 4:
                exit(0);
            default:
                break;
            }
            break;
        case 27:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}