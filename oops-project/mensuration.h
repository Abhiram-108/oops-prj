#include <iostream> // not particularly required
using namespace std;
void ascii_cube()
{
    char cube[] = {
        ".______A______,\n"
        "|\\            |\\\n"
        "| \\           | A\n"
        "|  \\          |  \\\n"
        "A   +------A------+\n"
        "|   |         |   |\n"
        "|___|___A_____|   |\n"
        "\\   |          \\  |\n"
        " \\  |           A |\n"
        "  \\ |            \\|\n"
        "   \\|______A______|\n"};
    cout << cube;
}

void ascii_triangle()
{
    char triangle[] = {
        "|̂             .\n"
        "|            / \\\n"
        "|           /   \\\n"
        "|          /     \\\n"
        "|         /       \\\n"
        "H        /         \\\n"
        "|       /           \\\n"
        "|      /             \\\n"
        "|     /               \\\n"
        "|    /                 \\\n"
        "|   /                   \\\n"
        "|  /                     \\\n"
        "| /_______________________\\\n"
        "˅ ‹-----------B-----------›\n"};
    cout << triangle;
}
void ascii_rectangle()
{
    char rectangle[] = {
        "‹-------------l-------------›\n"
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
        "‹---------a---------›\n"
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
        ",           ·----R-----›,\n"
        ",                       ,\n"
        " ,                     ,\n"
        "  ,                   ,\n"
        "    ,              , '\n"
        "      ' - , _ ,  '\n"};
    cout << circle;
}

/*
void ascii_sphere()
{
    char circle[] = {

        "        , - ~ - ,\n"
        "    , '            ' ,\n"
        "  ,                   ,\n"
        " , , - ~ - ~ - ~ - ~ \\  ̀,\n"
        ",.                    `. ,,\n"
        ",.                       .,\n"
        ", ` ~ . _ , _ , _ _ . ~ ,\n"
        " ,                       ,\n"
        "  ,                   ,\n"
        "    ,              , '\n"
        "      ' - , _ ,  '\n"};
    cout << circle;
}
*/

void ascii_cylinder()
{
    char cylinder[] = {

        "   _..----------.._ \n"
        ".-~̀̀                ~̀̀-. ˰\n"
        "|.        ·----R----.| |\n"
        "| `\"-.._________..-\" | |\n"
        "|                    | |\n"
        "|                    | |\n"
        "|                    | L\n"
        "|                    | |\n"
        "|                    | |\n"
        "|                    | |\n"
        "|                    | |\n"
        ",                    , |\n"
        " \"-..____________..-\"  ˅\n"};
    cout << cylinder;
}
void ascii_hemisphere()
{
    char hemisphere[] = {
        ",----------·-----R-----,\n"
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
        "‹--------------l---------------›\n"};
    cout << parallelogram;
}
void ascii_rhombus()
{
    char rhombus[] = {
        "       ,        \n"
        "      /|\\      \n"
        "     / | \\     \n"
        "    /  |  \\    \n"
        "   /   d1  \\   \n"
        "  /    |    \\  \n"
        " /_____|_d2__\\ \n"
        " \\     |     / \n"
        "  \\    |    /  \n"
        "   \\   |   /   \n"
        "    \\  |  /    \n"
        "     \\ | /     \n"
        "      \\|/      \n"
        "       ̀̀        \n"

    };
    cout << rhombus;
}
void ascii_cone()
{
    char cone[] = {
        "       ,\n"
        "      /|\\\n"
        "     / | \\\n"
        "    /  |  l\n"
        "   /  h|   \\\n"
        "  /    |    \\\n"
        " /_____|_____\\\n"
        "|      ‹--r--›|\n"
        " \\           /\n"
        "  `~_~_~_~_~`\n"};
    cout << cone;
}
