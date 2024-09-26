#include <iostream>
#include <Windows.h>
using namespace std;

enum ColorEnum
{
	_Default = 7,
	_Blue = 1,
	_Green = 2,
	_Cyan = 3,
	_Red = 4,
	_Pink = 5,
	_Yellow = 6,
	_White = 7,
	_BrightBlue = 9,
	_BrightGreen = 10,
	_BrightCyan = 11,
	_BrightRed = 12,
	_BrightPink = 13,
	_BrightYellow = 14,
	_BrightWhite = 15
};

struct RGBA
{
	int r;
	int g;
	int b;
	int a;

	RGBA(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

	void get()
	{
		cout << "r: " << r << " g: " << g << " b: " << b << " a: " << a << endl;
	}
};

class Color abstract
{
protected:
	string _hex_color;
	string _color_name;
	RGBA* _rgba_color = nullptr;
public:
	Color()
	{
		_hex_color = "#000000";
		_color_name = "Black";
		_rgba_color = new RGBA(0, 0, 0, 255);
		cout << "Color constructor call" << endl;
	}
	Color(string hex_color, string color_name, RGBA* rgba_color)
	{
		this->_hex_color = hex_color;
		this->_color_name = color_name;
		this->_rgba_color = rgba_color;
		cout << "Color constructor call with params" << endl;
	}

	virtual void get_hex(HANDLE hConsole) = 0;
	virtual void get_name() = 0;
	virtual void get_rgba() = 0;

	~Color()
	{
		delete _rgba_color;
		cout << "Color destructor call" << endl;
	}
};

class Red : public Color
{
public:
	Red()
	{
		_hex_color = "#FF0000";
		_color_name = "Red";
		_rgba_color = new RGBA(255, 0, 0, 255);
		cout << "Red constructor call" << endl;
	}

	void get_hex(HANDLE hConsole)
	{
		cout << "Hex color: ";
		SetConsoleTextAttribute(hConsole, WORD(ColorEnum::_BrightRed << 4 | 15));
		cout << _hex_color;
		SetConsoleTextAttribute(hConsole, ColorEnum::_Default);
		cout << endl;
	}
	void get_name()
	{
		cout << " Color name: " << _color_name << endl;
	}
	void get_rgba()
	{
		cout << " RGBA color: ";
		_rgba_color->get();
	}

	~Red()
	{
		cout << "Red destructor call" << endl;
	}
};


int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Red* red = new Red();
	red->get_hex(hConsole);
	delete red;
	return 0;
} 