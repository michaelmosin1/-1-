#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");
	char n;
	std::cout << "������� N:" << std::endl;
	std::cin >> n;
	switch (n)
	{
	case 1:
		std::cout << "�����������" << std::endl;
		break;
	case 2:
		std::cout << "�������" << std::endl;
		break;
	case 3:
		std::cout << "�����" << std::endl;
		break;
	case 4:
		std::cout << "�������" << std::endl;
		break;
	case 5:
		std::cout << "�������" << std::endl;
		break;
	case 6:
		std::cout << "�������" << std::endl;
		break;
	case 7:
		std::cout << "�����������" << std::endl;
		break;
	default:
		std::cout << "������! �������� �����." << std::endl;
		break;
	}
	return 0;
}