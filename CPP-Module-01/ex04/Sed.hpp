#ifndef SED_HPP
# define SED_HPP

#include <fstream>
#include <string>
class Sed
{
	public:
		Sed(std::string s1, std::string s2);
		~Sed(void); // Destructor

		void	replace();
		bool	openFiles(char *filename, std::string newFile);

	private:
		std::ifstream _input;
		std::ofstream _output;
		std::string _fileName;
		std::string _s1;
		std::string _s2;

		std::string _copyInput();
};

#endif
