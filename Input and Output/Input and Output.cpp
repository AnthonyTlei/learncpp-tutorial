#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <string_view>
#include <algorithm> // std::all_of
#include <cctype> // std::isdigit, std::isspace, std::isalpha
#include <map>
#include <fstream>

bool isValidName(std::string_view name)
{
    return std::ranges::all_of(name, [](char ch) {
        return (std::isalpha(ch) || std::isspace(ch));
        });

    // Before C++20, without ranges
    // return std::all_of(name.begin(), name.end(), [](char ch) {
    //    return (std::isalpha(ch) || std::isspace(ch));
    // });
}

bool inputMatches(std::string_view input, std::string_view pattern)
{
    if (input.length() != pattern.length())
    {
        return false;
    }

    // We have to use a C-style function pointer, because std::isdigit and friends
    // have overloads and would be ambiguous otherwise.
    static const std::map<char, int (*)(int)> validators{
      { '#', &std::isdigit },
      { '_', &std::isspace },
      { '@', &std::isalpha },
      { '?', [](int) { return 1; } }
    };

    // Before C++20, use
    // return std::equal(input.begin(), input.end(), pattern.begin(), [](char ch, char mask) -> bool {
    // ...

    return std::ranges::equal(input, pattern, [](char ch, char mask) -> bool {
        if (auto found{ validators.find(mask) }; found != validators.end())
        {
            // The pattern's current element was found in the validators. Call the
            // corresponding function.
            return (*found->second)(ch);
        }
        else
        {
            // The pattern's current element was not found in the validators. The
            // characters have to be an exact match.
            return (ch == mask);
        }
        });
}

void testInput()
{
    //char buf[5];
    //std::cin >> std::setw(5) >> buf;
    //std::cout << buf << '\n';

    // Cin Ignpores white space
    //char ch;
    //while (std::cin >> ch)
    //    std::cout << ch;

    // Get does not ignore white space
    //char ch;
    //while (std::cin.get(ch))
    //    std::cout << ch;

    //char strBuf[11];
    //std::cin.get(strBuf, 11);
    //std::cout << strBuf << '\n';

    //char strBuf[11];
    //// Read up to 10 characters
    //std::cin.getline(strBuf, 11);
    //std::cout << strBuf << '\n';

    //// Read up to 10 more characters
    //std::cin.getline(strBuf, 11);
    //std::cout << strBuf << '\n';

    //char strBuf[100];
    //std::cin.getline(strBuf, 100);
    //std::cout << strBuf << '\n';
    //std::cout << std::cin.gcount() << " characters were read" << std::endl;

    //std::string strBuf;
    //std::getline(std::cin, strBuf);
    //std::cout << strBuf << '\n';
}

void testOutput()
{
    // Flags
    std::cout.setf(std::ios::showpos | std::ios::uppercase); // turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << 1234567.89f << '\n';

    std::cout << 27 << '\n';
    std::cout.unsetf(std::ios::showpos | std::ios::uppercase); // turn off the std::ios::showpos flag
    std::cout << 1234567.89f << '\n';

    std::cout.unsetf(std::ios::dec); // turn off decimal output
    std::cout.setf(std::ios::hex); // turn on hexadecimal output
    std::cout << 27 << '\n';

    std::cout.unsetf(std::ios::hex); // turn on hexadecimal output
    std::cout.setf(std::ios::dec); // turn off decimal output
    std::cout << 27 << '\n';

    // Turn on std::ios::hex as the only std::ios::basefield flag
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';
    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << 27 << '\n';

    // Manipulators
    std::cout << std::hex << 27 << '\n'; // print 27 in hex
    std::cout << 28 << '\n'; // we're still in hex
    std::cout << std::dec << 29 << '\n'; // back to decimal

    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified

    std::cout.fill('*');
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
}

void testStreamString()
{
    std::stringstream os;
    os << "en garde!" << '\n'; // insert "en garde!" into the stringstream

    std::stringstream os2;
    os2.str("en garde!"); // set the stringstream buffer to "en garde!"



    std::stringstream os3;
    os3 << "12345 67.89" << '\n';
    std::cout << os3.str() << '\n';

    std::stringstream os4;
    os4 << "12345 67.89"; // insert a string of numbers into the stream

    std::string strValue;
    os4 >> strValue;

    std::string strValue2;
    os4 >> strValue2;

    // print the numbers separated by a dash
    std::cout << strValue << " - " << strValue2 << '\n';



    // Convert number to string
    std::stringstream os5;
    int nValue{ 12345 };
    double dValue{ 67.89 };
    os5 << nValue << ' ' << dValue;

    std::string strValue3, strValue4;
    os5 >> strValue3 >> strValue4;

    std::cout << strValue3 << ' ' << strValue4 << '\n';


    // Convert string to number
    std::stringstream os6;
    os6 << "12345 67.89"; // insert a string of numbers into the stream
    int nValue2;
    double dValue2;

    os6 >> nValue2 >> dValue2;

    std::cout << nValue2 << ' ' << dValue2 << '\n';


    // Clear stringstream
    std::stringstream os7;
    os7 << "Hello ";

    os7.str(""); // erase the buffer
    // Or:
    //os7.str(std::string{}); // erase the buffer

    os.clear(); // reset error flags

    os7 << "World!";
    std::cout << os7.str();

}

void testStreamState()
{
    std::string name{};

    do
    {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name); // get the entire line, including spaces
    } while (!isValidName(name));

    std::cout << "Hello " << name << "!\n";

    std::string phoneNumber{};

    do
    {
        std::cout << "Enter a phone number (###) ###-####: ";
        std::getline(std::cin, phoneNumber);
    } while (!inputMatches(phoneNumber, "(###) ###-####"));

    std::cout << "You entered: " << phoneNumber << '\n';
}

int testStreamFileOutput()
{
    // ofstream is used for writing files
    // We'll make a file called Sample.txt
    std::ofstream outf{ "Sample.txt" };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "This is line 1" << '\n';
    outf << "This is line 2" << '\n';

    outf.close();
}

int testStreamFileInput()
{
    // ifstream is used for reading files
    // We'll read from a file called Sample.txt
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
        return 1;
    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(inf, strInput);
        std::cout << strInput << '\n';
    }

    inf.close();
}

void testSeek()
{
    std::ifstream inf;
    inf.open("Sample.txt", std::ios::app);

    inf.seekg(14, std::ios::cur); // move forward 14 bytes
    inf.seekg(-18, std::ios::cur); // move backwards 18 bytes
    inf.seekg(22, std::ios::beg); // move to 22nd byte in file
    inf.seekg(24); // move to 24th byte in file
    inf.seekg(-28, std::ios::end); // move to the 28th byte before end of the file

    inf.seekg(0, std::ios::beg); // move to beginning of file
    inf.seekg(0, std::ios::end); // move to end of file

    std::cout << inf.tellg(); // return the absolute position of the file pointer
}

int testFstream()
{
    // Note we have to specify both in and out because we're using fstream
    std::fstream iofile{ "Sample.txt", std::ios::in | std::ios::out };

    // If we couldn't open iofile, print an error
    if (!iofile)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened!\n";
        return 1;
    }

    char chChar{}; // we're going to do this character by character

    // While there's still data to process
    while (iofile.get(chChar))
    {
        switch (chChar)
        {
            // If we find a vowel
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':

            // Back up one character
            iofile.seekg(-1, std::ios::cur);

            // Because we did a seek, we can now safely do a write, so
            // let's write a # over the vowel
            iofile << '#';

            // Now we want to go back to read mode so the next call
            // to get() will perform correctly.  We'll seekg() to the current
            // location because we don't want to move the file pointer.
            iofile.seekg(iofile.tellg(), std::ios::beg);

            break;
        }
    }
}

int main()
{
    //
    //testStreamFileOutput();
    //testStreamFileInput();
    testFstream();
}
