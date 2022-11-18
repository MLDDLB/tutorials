#include <iostream>
#include <iomanip>
#include <ios>

int main()
{
	std::cout << "======Set Width=====" << std::endl
		  << "Unformatted data: " << std::endl
		  << "Daniel" << " " << "Gray" << " " << "25" << std::endl;
	std::cout << "Formatted data: " << std::endl;
	std::cout << std::left;
	std::cout << std::setw(10) << "Daniel" << std::setw(10) << "Gray" << std::setw(5) << "25" <<std::endl;

	std::cout << std::right;
	std::cout << "Formatted data(right): " << std::endl;
	std::cout << std::setw(10) << "Daniel" << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;

	std::cout << "Formatted data(fill): " << std::endl;
	std::cout << std::setfill('-'); // The fill character
	std::cout << std::setw(10) << "Daniel" << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;

	std::cout << "=====Show pos=====" << std::endl;

	int pos_num {45};
	int neg_num {-39};
	std::cout << "Without showpos: " << std::endl;
	std::cout << "Positive: " << pos_num << std::endl;
	std::cout << "Negative: " << neg_num << std::endl;

	std::cout << std::showpos;
	std::cout << "With showpos: " << std::endl;
	std::cout << "Positive: " << pos_num << std::endl;
	std::cout << "Negative: " << neg_num << std::endl;
	std::cout << std::noshowpos;
	
	std::cout << "=====Number systems=====" << std::endl;
	std::cout << "Dec: " << std::dec << pos_num << std::endl;
	std::cout << "Hex: " << std::hex << pos_num << std::endl;
	std::cout << "Oct: " << std::oct << pos_num << std::endl;
	
	std::cout << "With showbase: " << std::endl;
	std::cout << std::showbase;
	std::cout << "Dec: " << std::dec << pos_num << std::endl;
	std::cout << "Hex: " << std::hex << pos_num << std::endl;
	std::cout << "Oct: " << std::oct << pos_num << std::endl;
	std::cout << std::noshowbase;

	return 0;
}
