#include <iostream> // not particularly required
using namespace std;
void ascii_cube()
{
    char cube[] = {
        "._____________,\n"
        "|\\            |\\\n"
        "| \\           | A\n"
        "|  \\          |  \\\n"
        "A   +------A------+\n"
        "|   |         |   |\n"
        "|___|_________|   |\n"
        "\\   |          \\  |\n"
        " \\  |           A |\n"
        "  \\ |            \\|\n"
        "   \\|_____________|\n"};
    cout << cube;
}

void ascii_triangle()
{
    char triangle[] = {
        "               .\n"
        " ^            / \\\n"
        " |           /   \\\n"
        " |          /     \\\n"
        " |         /       \\\n"
        " |        /         \\\n"
        " |       a           c\n"
        " |      /             \\\n"
        " |     /               \\\n"
        " |    /                 \\\n"
        " |   /                   \\\n"
        " |  /                     \\\n"
        " | /___________b___________\\\n"
        "```<----------------------->\n"};
    cout << triangle;
}
void ascii_rectangle()
{
    char rectangle[] = {
        "<-------------l------------->\n"
        " ___________________________ \n"
        "|                           |\n"
        "|                           |\n"
        "|                           |\n"
        "|                           b\n"
        "|                           |\n"
        "|                           |\n"
        "|___________________________|\n"};
    cout << rectangle;
}
void ascii_square()
{
    char square[] = {
        "<---------a--------->\n"
        " ___________________ \n"
        "|                   |\n"
        "|                   |\n"
        "|                   |\n"
        "|                   |\n"
        "|                   a\n"
        "|                   |\n"
        "|                   |\n"
        "|                   |\n"
        "|___________________|\n"};
    cout << square;
}

void ascii_cuboid()
{
    char cuboid[] = {
        ".___________L___________,\n"
        "|\\                      |\\\n"
        "| \\                     | B\n"
        "|  \\                    |  \\\n"
        "H   +-----------L-----------+\n"
        "|   |                   |   |\n"
        "|___|________L__________|   |\n"
        "\\   |                    \\  |\n"
        " \\  |                     B |\n"
        "  \\ |                      \\|\n"
        "   \\|___________L___________|\n"};
    cout << cuboid;
}
void ascii_circle()
{
    char circle[] = {
        "        , - ~ - ,\n"
        "    , '           ' ,\n"
        "  ,                   ,\n"
        " ,                     ,\n"
        ",                       ,\n"
        ",           *----R----->,\n"
        ",                       ,\n"
        " ,                     ,\n"
        "  ,                   ,\n"
        "    ,              , '\n"
        "      ' - , _ ,  '\n"};
    cout << circle;
}

void ascii_cylinder()
{
    char cylinder[] = {

        "   _..----------.._ \n"
        ".-~                ~-. ^\n"
        "|.        *----R----.| |\n"
        "| `\"-.._________..-\" | |\n"
        "|                    | |\n"
        "|                    | |\n"
        "|                    | L\n"
        "|                    | |\n"
        "|                    | |\n"
        "|                    | |\n"
        "|                    | |\n"
        ",                    , |\n"
        " \"-..____________..-\"  |\n"
        "                      ```\n"};
    cout << cylinder;
}
void ascii_hemisphere()
{
    char hemisphere[] = {
        ",----------*-----R-----,\n"
        ",                      ,\n"
        " ,                    ,\n"
        "  ,                  ,\n"
        "    ,             , '\n"
        "      ' - , _ , '\n"};
    cout << hemisphere;
}
void ascii_parallelogram()
{
    char parallelogram[] = {
        "      /------------------------------/\n"
        "     /                              /\n"
        "    /                              /\n"
        "   /                              B\n"
        "  /                              /\n"
        " /                              /\n"
        "/------------------------------/\n"
        "<--------------l--------------->\n"};
    cout << parallelogram;
}
void ascii_rhombus()
{
    char rhombus[] = {
        "       ,        \n"
        "      /|\\      \n"
        "     / | \\     \n"
        "    a  |  \\    \n"
        "   /   d1  \\   \n"
        "  /    |    \\  \n"
        " /_____|_d2__\\ \n"
        " \\     |     / \n"
        "  \\    |    /  \n"
        "   \\   |   /   \n"
        "    \\  |  /    \n"
        "     \\ | /     \n"
        "      \\|/      \n"
        "       *        \n"

    };
    cout << rhombus;
}
void ascii_cone()
{
    char cone[] = {
        "       ,\n"
        "      /|\\\n"
        "     / | \\\n"
        "    /  |  \\\n"
        "   /  h|   \\\n"
        "  /    |    \\\n"
        " /_____|_____\\\n"
        "|      <--r-->|\n"
        " \\           /\n"
        "  `~_~_~_~_~`\n"};
    cout << cone;
}
void ascii_trapezium()
{
    char trapezium[] = {

        "      <---------w2------->\n"
        "      /------------------\\\n"
        "     /                    \\\n"
        "    /                      \\\n"
        "   /                        L\n"
        "  /                          \\\n"
        " /                            \\\n"
        "/------------------------------\\\n"
        "<--------------w1-------------->\n"};
    cout << trapezium;
}
void ascii_intro_logo()
{
    char logo[] = {
        "\t\t\t    __       __   ______   ________  __    __         ______    ______   __     __     __  ________  _______    \n"
        "\t\t\t   /  \\     /  | /      \\ /        |/  |  /  |       /      \\  /      \\ /  |   /  |   /  |/        |/       \\\n"
        "\t\t\t   $$  \\   /$$ |/$$$$$$  |$$$$$$$$/ $$ |  $$ |      /$$$$$$  |/$$$$$$  |$$ |   $$ |   $$ |$$$$$$$$/ $$$$$$$  |\n"
        "\t\t\t   $$$  \\ /$$$ |$$ |__$$ |   $$ |   $$ |__$$ |      $$ \\__$$/ $$ |  $$ |$$ |   $$ |   $$ |$$ |__    $$ |__$$ |\n"
        "\t\t\t   $$$$  /$$$$ |$$    $$ |   $$ |   $$    $$ |      $$      \\ $$ |  $$ |$$ |   $$  \\ /$$/ $$    |   $$    $$< \n"
        "\t\t\t   $$ $$ $$/$$ |$$$$$$$$ |   $$ |   $$$$$$$$ |       $$$$$$  |$$ |  $$ |$$ |    $$  /$$/  $$$$$/    $$$$$$$  |\n"
        "\t\t\t   $$ |$$$/ $$ |$$ |  $$ |   $$ |   $$ |  $$ |      /  \\__$$ |$$ \\__$$ |$$ |_____$$ $$/   $$ |_____ $$ |  $$ |\n"
        "\t\t\t   $$ | $/  $$ |$$ |  $$ |   $$ |   $$ |  $$ |      $$    $$/ $$    $$/ $$       |$$$/    $$       |$$ |  $$ |\n"
        "\t\t\t   $$/      $$/ $$/   $$/    $$/    $$/   $$/        $$$$$$/   $$$$$$/  $$$$$$$$/  $/     $$$$$$$$/ $$/   $$/ \n"};
    cout << logo;
}
void ascii_page_logo()
{
    char page_logo[] = {

        "\t\t\t\t\t    __  ____  ___    ______  __  __    _____   ____    __   _    __  ______  ____ \n"
        "\t\t\t\t\t   /  |/   / /   |  /_  __/ / / / /   / ___/  / __ \\  / /  | |  / / / ____/ / __ \\\n"
        "\t\t\t\t\t  / /|_|/ / / /| |   / /   / /_/ /    \\__ \\  / / / / / /   | | / / / __/ / / /_/ /\n"
        "\t\t\t\t\t / /   / / / ___ |  / /   / __  /    ___/ / / /_/ / / /__  | |/ / / /___/ / _, _/ \n"
        "\t\t\t\t\t/_/   /_/ /_/  |_/ /_/   /_/ /_/    /____/  \\____/ /_____/ \\___/ /_____/ /_/ |_|  \n\n"};
    cout << page_logo;
}

string logo_symbols[] = {
    "\t\t\t\t\t\t\t\t\t _____________ \n"
    "\t\t\t\t\t\t\t\t\t|  __________ |\n"
    "\t\t\t\t\t\t\t\t\t \\ \\         \\|\n"
    "\t\t\t\t\t\t\t\t\t  \\ \\         `\n"
    "\t\t\t\t\t\t\t\t\t   \\ \\         \n"
    "\t\t\t\t\t\t\t\t\t   / /         \n"
    "\t\t\t\t\t\t\t\t\t  / /         ,\n"
    "\t\t\t\t\t\t\t\t\t / /_________/|\n"
    "\t\t\t\t\t\t\t\t\t|_____________|\n",
    "\t\t\t\t\t\t\t\t\t          \n"
    "\t\t\t\t\t\t\t\t\t  __      \n"
    "\t\t\t\t\t\t\t\t\t /\\ \\     \n"
    "\t\t\t\t\t\t\t\t\t \\_\\ \\___ \n"
    "\t\t\t\t\t\t\t\t\t/\\___  __\\\n"
    "\t\t\t\t\t\t\t\t\t\\/__/\\ \\_/\n"
    "\t\t\t\t\t\t\t\t\t    \\ \\_\\ \n"
    "\t\t\t\t\t\t\t\t\t     \\/_/ \n"
    "\t\t\t\t\t\t\t\t\t          \n",
    "\t\t\t\t\t\t\t\t\t           \n"
    "\t\t\t\t\t\t\t\t\t           \n"
    "\t\t\t\t\t\t\t\t\t _______   \n"
    "\t\t\t\t\t\t\t\t\t/\\______\\  \n"
    "\t\t\t\t\t\t\t\t\t\\/______/_ \n"
    "\t\t\t\t\t\t\t\t\t  /\\______\\\n"
    "\t\t\t\t\t\t\t\t\t  \\/______/\n"
    "\t\t\t\t\t\t\t\t\t           \n"
    "\t\t\t\t\t\t\t\t\t           \n",
    "\t\t\t\t\t\t\t\t\t             \n"
    "\t\t\t\t\t\t\t\t\t  __ __      \n"
    "\t\t\t\t\t\t\t\t\t _\\ \\ \\__   \n"
    "\t\t\t\t\t\t\t\t\t/\\__  _  _\\  \n"
    "\t\t\t\t\t\t\t\t\t\\/_L\\ \\ \\L_ \n"
    "\t\t\t\t\t\t\t\t\t  /\\_   _  _\\\n"
    "\t\t\t\t\t\t\t\t\t  \\/_/\\_\\_\\/\n"
    "\t\t\t\t\t\t\t\t\t     \\/_//_/ \n"
    "\t\t\t\t\t\t\t\t\t             \n",
    "\t\t\t\t\t\t\t\t\t            \n"
    "\t\t\t\t\t\t\t\t\t __     __  \n"
    "\t\t\t\t\t\t\t\t\t/\\_\\   / /  \n"
    "\t\t\t\t\t\t\t\t\t\\/_/  / /   \n"
    "\t\t\t\t\t\t\t\t\t     / /    \n"
    "\t\t\t\t\t\t\t\t\t    / /  __ \n"
    "\t\t\t\t\t\t\t\t\t   / /  /\\_\\\n"
    "\t\t\t\t\t\t\t\t\t  /_/   \\/_/\n"
    "\t\t\t\t\t\t\t\t\t            \n",
    "\t\t\t\t\t\t\t\t\t          \n"
    "\t\t\t\t\t\t\t\t\t  __      \n"
    "\t\t\t\t\t\t\t\t\t _\\ \\ _   \n"
    "\t\t\t\t\t\t\t\t\t/\\_` ' \\  \n"
    "\t\t\t\t\t\t\t\t\t\\/_>   <_ \n"
    "\t\t\t\t\t\t\t\t\t  /\\_, ,_\\\n"
    "\t\t\t\t\t\t\t\t\t  \\/_/\\_\\/\n"
    "\t\t\t\t\t\t\t\t\t     \\/_/ \n"
    "\t\t\t\t\t\t\t\t\t          \n",
    "\t\t\t\t\t\t\t\t\t        \n"
    "\t\t\t\t\t\t\t\t\t      __\n"
    "\t\t\t\t\t\t\t\t\t     / /\n"
    "\t\t\t\t\t\t\t\t\t    / / \n"
    "\t\t\t\t\t\t\t\t\t   / /  \n"
    "\t\t\t\t\t\t\t\t\t  / /   \n"
    "\t\t\t\t\t\t\t\t\t / /    \n"
    "\t\t\t\t\t\t\t\t\t/_/     \n"
    "\t\t\t\t\t\t\t\t\t        \n",
    "\t\t\t\t\t\t\t\t\t         \n"
    "\t\t\t\t\t\t\t\t\t __      \n"
    "\t\t\t\t\t\t\t\t\t/\\ `\\    \n"
    "\t\t\t\t\t\t\t\t\t\\`\\ `\\   \n"
    "\t\t\t\t\t\t\t\t\t`\\`\\ `\\  \n"
    "\t\t\t\t\t\t\t\t\t `\\`\\ `\\ \n"
    "\t\t\t\t\t\t\t\t\t  `\\`\\__\\\n"
    "\t\t\t\t\t\t\t\t\t   `\\/__/\n"
    "\t\t\t\t\t\t\t\t\t         \n",
    "\t\t\t\t\t\t\t\t\t                 \n"
    "\t\t\t\t\t\t\t\t\t _______________ \n"
    "\t\t\t\t\t\t\t\t\t/ ______________|\n"
    "\t\t\t\t\t\t\t\t\t|/  |  | |  |    \n"
    "\t\t\t\t\t\t\t\t\t`   |  | |  |    \n"
    "\t\t\t\t\t\t\t\t\t    |  | |  |    \n"
    "\t\t\t\t\t\t\t\t\t    |  | |  |    \n"
    "\t\t\t\t\t\t\t\t\t    |__| |__|    \n"
    "\t\t\t\t\t\t\t\t\t                 \n",
    "\t\t\t\t\t\t\t\t\t                \n"
    "\t\t\t\t\t\t\t\t\t _            _ \n"
    "\t\t\t\t\t\t\t\t\t| |  __  __  | |\n"
    "\t\t\t\t\t\t\t\t\t| |  \\ \\/ /  | |\n"
    "\t\t\t\t\t\t\t\t\t| |   \\  /   | |\n"
    "\t\t\t\t\t\t\t\t\t| |   /  \\   | |\n"
    "\t\t\t\t\t\t\t\t\t| |  /_/\\_\\  | |\n"
    "\t\t\t\t\t\t\t\t\t|_|          |_|\n"
    "\t\t\t\t\t\t\t\t\t                \n"};

void displayCalculatorInterface()
{
    char calc_img[] = {
        "  _________________ \n"
        " |                 |\n"
        " |  1   2   3   +  |\n"
        " |                 |\n"
        " |  4   5   6   -  |\n"
        " |                 |\n"
        " |  7   8   9   *  |\n"
        " |                 |\n"
        " |  0   .   =   /  |\n"
        " |_________________|\n"};
    cout << calc_img;
}
