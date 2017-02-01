
#include <boost/program_options.hpp>


#include <iostream>


int main(int ac, char* av[])
{
	boost::program_options::options_description desc("Allowed options");
    desc.add_options()
		("help,h", "produce help message")
		("config_name,c", boost::program_options::value<std::string>(), "configuration filename");

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(ac, av, desc), vm);
	boost::program_options::notify(vm);

	if (vm.count("help")) {
	    std::cout << desc << "\n";
	    return 1;
	}

     std::cout << "Hallo, du schöne Welt!" << std::endl;

     return 0;
 }
