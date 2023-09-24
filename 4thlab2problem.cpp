#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");
	char n;
	std::cout << "Введите N:" << std::endl;
	std::cin >> n;
	switch (n)
	{
	case 1:
		std::cout << "Понедельник" << std::endl;
		break;
	case 2:
		std::cout << "Вторник" << std::endl;
		break;
	case 3:
		std::cout << "Среда" << std::endl;
		break;
	case 4:
		std::cout << "Четверг" << std::endl;
		break;
	case 5:
		std::cout << "Пятница" << std::endl;
		break;
	case 6:
		std::cout << "Суббота" << std::endl;
		break;
	case 7:
		std::cout << "Воскресенье" << std::endl;
		break;
	default:
		std::cout << "Ошибка! Неверное число." << std::endl;
		break;
	}
	return 0;
}