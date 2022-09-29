#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "typeFunctions.hpp"

int main()
{
	Base	*base0 = generate();

	identify(base0);
	identify(*base0);
	delete base0;
	return 0;
}
