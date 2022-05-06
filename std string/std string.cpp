#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

template <typename T>
inline std::string ToString(T tX)
{
    std::ostringstream oStream;
    oStream << tX;
    return oStream.str();
}

template <typename T>
inline bool FromString(const std::string& sString, T& tX)
{
    std::istringstream iStream(sString);
    return !(iStream >> tX).fail(); // extract value into tX, return success or not
}

void testToString()
{
    std::string sFour{ ToString(4) };
    std::string sSixPointSeven{ ToString(6.7) };
    std::string sA{ ToString('A') };
    std::cout << sFour << " Type: " << typeid(sFour).name() << '\n';
    std::cout << sSixPointSeven << " Type: " << typeid(sSixPointSeven).name() << '\n';
    std::cout << sA << " Type: " << typeid(sA).name() << '\n';
}

void testFromString()
{
    double dX;
    if (FromString("3.4", dX))
        std::cout << dX << " Type: " << typeid(dX).name() << '\n';
    if (FromString("ABC", dX))
        std::cout << dX << typeid(dX).name() << '\n';
}

void testStringSize()
{
    std::string source{ "012345678" };
    std::cout << source.length() << '\n';
    std::cout << source.size() << '\n';

    std::string string1{ "Not Empty" };
    std::cout << (string1.empty() ? "true" : "false") << '\n';
    std::string string2; // empty
    std::cout << (string2.empty() ? "true" : "false") << '\n';

    std::string s{ "MyString" };
    std::cout << s.max_size() << '\n';

    std::string s2{ "01234567" };
    std::cout << "Length: " << s2.length() << '\n';
    std::cout << "Capacity: " << s2.capacity() << '\n';

    std::string s3{ "01234567" };
    std::cout << "Length: " << s3.length() << '\n';
    std::cout << "Capacity: " << s3.capacity() << '\n';

    s3.reserve(200);
    std::cout << "Length: " << s3.length() << '\n';
    std::cout << "Capacity: " << s3.capacity() << '\n';

    s3.shrink_to_fit();
    std::cout << "Length: " << s3.length() << '\n';
    std::cout << "Capacity: " << s3.capacity() << '\n';

    std::srand(std::time(nullptr)); // seed random number generator

    std::string s4{}; // length 0
    s4.reserve(64); // reserve 64 characters

    // Fill string up with random lower case characters
    for (int count{ 0 }; count < 64; ++count)
        s4 += 'a' + std::rand() % 26;

    std::cout << s4;
}

void testStringAccess()
{
    std::string sSource{ "abcdefg" };
    std::cout << sSource[5] << '\n';
    sSource[5] = 'X';
    std::cout << sSource << '\n';

    sSource =  "abcdefg";
    std::cout << sSource.at(5) << '\n';
    sSource.at(5) = 'X';
    std::cout << sSource << '\n';
}

void testStringConversionToC()
{
    std::string sSource{ "abcdefg" };

    std::cout << std::strlen(sSource.c_str()) << '\n';

    const char* szString{ "abcdefg" };
    // memcmp compares the first n characters of two C-style strings and returns 0 if they are equal
    if (std::memcmp(sSource.data(), szString, sSource.length()) == 0)
        std::cout << "The strings are equal\n";
    else
        std::cout << "The strings are not equal\n";

    std::string sSource2{ "sphinx of black quartz, judge my vow" };

    char szBuf[20];
    int nLength{ static_cast<int>(sSource2.copy(szBuf, 5, 10)) };
    szBuf[nLength] = '\0';  // Make sure we terminate the string in the buffer

    std::cout << szBuf << '\n';
}

void testStringAssign()
{
    std::string sString;

    // Assign a string value
    sString = std::string("One");
    std::cout << sString << std::endl;

    const std::string sTwo("Two");
    sString.assign(sTwo);
    std::cout << sString << std::endl;

    // Assign a C-style string
    sString = "Three";
    std::cout << sString << std::endl;

    sString.assign("Four");
    std::cout << sString << std::endl;

    // Assign a char
    sString = '5';
    std::cout << sString << std::endl;

    // Chain assignment
    std::string sOther;
    sString = sOther = "Six";
    std::cout << sString << " " << sOther << std::endl;

    const std::string sSource("abcdefg");
    std::string sDest;

    sDest.assign(sSource, 2, 4); // assign a substring of source from index 2 of length 4
    std::cout << sDest << std::endl;

    std::string sStr1("red");
    std::string sStr2("blue");

    std::cout << sStr1 << " " << sStr2 << std::endl;
    swap(sStr1, sStr2);
    std::cout << sStr1 << " " << sStr2 << std::endl;
    sStr1.swap(sStr2);
    std::cout << sStr1 << " " << sStr2 << std::endl;
}

void testStringAppend()
{
    std::string sString1("one");

    sString1 += std::string(" two");

    std::string sThree(" three");
    sString1.append(sThree);

    std::cout << sString1 << std::endl;

    std::string sString("one ");

    const std::string sTemp("twothreefour");
    sString.append(sTemp, 3, 5); // append substring of sTemp starting at index 3 of length 5
    std::cout << sString << std::endl;

    std::string sString2("one");

    sString2 += ' ';
    sString2.push_back('2');
    std::cout << sString2 << std::endl;

    std::string sString3("aaa");

    sString3.append(4, 'b');
    std::cout << sString3 << std::endl;
}

void testStringInsert()
{
    std::string sString("aaaa");
    std::cout << sString << std::endl;

    sString.insert(2, std::string("bbbb"));
    std::cout << sString << std::endl;

    sString.insert(4, "cccc");
    std::cout << sString << std::endl;

    std::string sString1("aaaa");

    const std::string sInsert("01234567");
    sString1.insert(2, sInsert, 3, 4); // insert substring of sInsert from index [3,7) into sString at index 2
    std::cout << sString1 << std::endl;
}

int main()
{
    //testToString();
    //testFromString();
    //testStringSize();
    //testStringAccess();
    //testStringConversionToC();
    //testStringAssign();
    //testStringAppend();
    //testStringInsert();
}

