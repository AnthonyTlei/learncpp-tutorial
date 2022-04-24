#ifndef BOSS_H
#define BOSS_H

// "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
// Does not implicitly convert to an integral value
enum class Boss
{
	margit,
	woldOfRadagon,
	radhan,
	godfrey,
};

// Overload the unary + operator to convert Animals to the underlying type
// adapted from https://stackoverflow.com/a/42198760, thanks to Pixelchemist for the idea
constexpr auto operator+(Boss a) noexcept
{
	return static_cast<std::underlying_type_t<Boss>>(a);
}


#endif