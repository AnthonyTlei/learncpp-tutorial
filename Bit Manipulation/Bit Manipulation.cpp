#include <iostream>
#include <bitset>

void bitManipTest()
{
    std::bitset<8> bits{ 0b0000'0101 }; // we need 8 bits, start with bit pattern 0000 0101
    bits.set(3); // set bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4); // flip bit 4 (now we have 0001 1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000 1101)

    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';
}

void bitShiftingTest()
{
    std::bitset<4> x{ 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000
}

// "rotl" stands for "rotate left"
std::bitset<4> rotl1(std::bitset<4> bits)
{
    const bool isOne{bits.test(3)};

    bits <<= 1;
    
    if (isOne) bits.set(0);

    return bits;
}

// My attempt at rotl without use of set/test
std::bitset<4> rotl2(std::bitset<4> bits)
{
    std::bitset<4> temp1{ bits };
    std::bitset<4> test{ 0b0001 };

    temp1 >>= 3;

    const bool isOne{ (temp1 & temp1) == test };

    bits <<= 1;

    if (isOne) bits |= test;

    return bits;
}

// Better than rotl2
std::bitset<4> rotl3(std::bitset<4> bits)
{
    // bits << 1 does the left shift
    // bits >> 3 handle the rotation of the leftmost bit
    return (bits << 1) | (bits >> 3);
}

void testingBitsExample()
{
    constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
    constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
}

void settingBitsExample()
{
    constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
    constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= mask1; // turn on bit 1

    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");

    flags |= (mask4 | mask5); // turn bits 4 and 5 on at the same time
}

void resetBitsExample()
{
    constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
    constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags &= ~mask2; // turn off bit 2

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags &= ~(mask4 | mask5); // turn bits 4 and 5 off at the same time
}

void flippingBitsExample()
{
    constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
    constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
    constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
    constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
    constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
    constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
    constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
    constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

    std::uint8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags

    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << ((flags & mask2) ? "on\n" : "off\n");

    flags ^= (mask4 | mask5); // flip bits 4 and 5 at the same time
}

void colorsRGB()
{
    constexpr std::uint32_t redBits{ 0xFF000000 };
    constexpr std::uint32_t greenBits{ 0x00FF0000 };
    constexpr std::uint32_t blueBits{ 0x0000FF00 };
    constexpr std::uint32_t alphaBits{ 0x000000FF };

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

    // use Bitwise AND to isolate red pixels,
    // then right shift the value into the lower 8 bits
    std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
    std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
    std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
    std::uint8_t alpha{ static_cast<std::uint8_t>(pixel & alphaBits) };

    std::cout << "Your color contains:\n";
    std::cout << std::hex; // print the following values in hex
    std::cout << static_cast<int>(red) << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue) << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";
}


int main()
{
    std::bitset<8> mybitset{}; // 8 bits in size means room for 8 flags

    std::bitset<4> bits1{ 0b0001 };
    std::cout << rotl1(bits1) << '\n';
    std::cout << rotl2(bits1) << '\n';

    std::bitset<4> bits2{ 0b1001 };
    std::cout << rotl1(bits2) << '\n';
    std::cout << rotl2(bits2) << '\n';
   
    
}

