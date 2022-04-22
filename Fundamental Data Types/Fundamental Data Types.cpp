#include <iostream>
#include <cstdint> // for fixed-width integers
#include <iomanip> // for output manipulator std::setprecision()
#include <string>
#include <bitset> // for std::bitset
#include <math.h>

void typeSizes()
{
    // Different types' sizes

    std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
}

void overflowExample()
{
    // Overflow example

    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get wrap-around
    std::cout << "x is now: " << x << '\n';
}

void integerTypes()
{
    // FIxed-width integers

    std::int16_t i{ 5 };
    std::cout << i;

    // Fast and least integers

    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

    // std::size_t

    std::cout << sizeof(std::size_t) << '\n';
}

void floatingPointTypes()
{
    // Floating point numbers

    std::cout << 5.0 << '\n';
    std::cout << 6.7f << '\n';
    std::cout << 9876543.21 << '\n';

    // Float precision

    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    std::cout << std::setprecision(16); // show 16 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

    double d{ 0.1 };
    std::cout << d << '\n'; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << d << '\n';

    std::cout << std::setprecision(17);

    double d1{ 1.0 };
    std::cout << d1 << '\n';

    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should equal 1.0
    std::cout << d2 << '\n';
}

void ifStatements()
{
    // If statements

    std::cout << "Enter an integer: ";
    int yx{};
    std::cin >> yx;

    if (yx > 0)
        std::cout << "The value is positive\n";
    else if (yx < 0)
        std::cout << "The value is negative\n";
    else
        std::cout << "The value is zero\n";
}

void charactersExample()
{
    // Chars

    char ch1{ 'a' };
    std::cout << ch1;

    char ch2{ 98 }; // code point for 'b' (not preferred)
    std::cout << ch2 << "\n";

    std::cout << "Input multiple keyboard characters: "; // assume the user enters "abcd" (without quotes)

    char ch{};
    std::cin >> ch; // ch = 'a', "bcd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    std::cin.clear(); // Restore input stream to working state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore to the end of line

    // Type conversion

    static_cast<int>(5.5); //coverts the 5.5 double to the int 5

    char ch3{};
    std::cout << "Input a single keyboard character: ";
    std::cin >> ch3;
    std::cout << ch3 << " ASCII: " << static_cast<int>(ch3) << '\n';
}

void stringsExample()
{
    // String

    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name
    // (ws): input manipulator that ignores leading white space

    std::cout << "Your name is " << name << "\n";
}

void literalConstantsExample()
{
    // Binary, Octal, Decimal and Hexadecimal Literal Constants
    int zyx{ 12 };
    std::cout << zyx << '\n'; // decimal (by default)
    std::cout << std::hex << zyx << '\n'; // hexadecimal
    std::cout << zyx << '\n'; // now hexadecimal
    std::cout << std::oct << zyx << '\n'; // octal
    std::cout << std::dec << zyx << '\n'; // return to decimal
    std::cout << zyx << '\n'; // decimal

    // std::bitset<8> means we want to store 8 bits
    std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
    std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101

    std::cout << bin1 << ' ' << bin2 << '\n';
    std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it
}

void operate()
{
    double num1{};
    double num2{};
    char symbol{};

    std::cout << "Enter number 1: ";
    std::cin >> num1;
    std::cout << "Enter number 2: ";
    std::cin >> num2;
    std::cout << "Enter operatio symbol: ";
    std::cin >> symbol;

    if (symbol == '+')
        std::cout << num1 + num2 << "\n";
    else if (symbol == '-')
        std::cout << num1 - num2 << "\n";
    else if (symbol == '*')
        std::cout << num1 * num2 << "\n";
    else if (symbol == '/')
        std::cout << num1 / num2 << "\n";
    else
        std::cout << "\n";
}

double calculateHeight(int height, int seconds)
{
    constexpr double gravity{ 9.8 };
    const double distanceFallen{ (gravity * (seconds * seconds)) / 2.0 };
    const double ballDistance{height - distanceFallen};

    if (ballDistance <= 0) return 0;

    return ballDistance;
}

void startGame()
{
    double height{};
    std::cout << "Enter tower height (m): ";
    std::cin >> height;
    std::cout << "\n";

    std::cout << "At 0 seconds, the ball is at height: " << calculateHeight(height, 0) << "\n";
    std::cout << "At 1 seconds, the ball is at height: " << calculateHeight(height, 1) << "\n";
    std::cout << "At 2 seconds, the ball is at height: " << calculateHeight(height, 2) << "\n";
    std::cout << "At 3 seconds, the ball is at height: " << calculateHeight(height, 3) << "\n";
    std::cout << "At 4 seconds, the ball is at height: " << calculateHeight(height, 4) << "\n";
    std::cout << "At 5 seconds, the ball is at height: " << calculateHeight(height, 5) << "\n";
}

int main()
{
    
    startGame();

    

   
}