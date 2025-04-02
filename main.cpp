#include<iostream>
#include<vector>
#include<string>
#include<print>
#include<fstream>
class Point
{
private:
	int x;
	int y;
public:
	Point(int x, int y) : x(x), y(y) {}
	~Point() {}
	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		out << "(" << p.x << "," << p.y << ")";
		return out;
	}
	void print_point()
	{
		std::print("({},{})", x, y);
	}
};

std::vector<Point> originals_points;

void menu()
{
	int x, y;
	std::cout << "Please enter 7 points in the format (x,y) and press enter after each point\n";
	for (size_t i = 0; i < 7; i++)
	{
		std::cout << "µÚ" << i + 1 << "¸ö: ";
		std::cin >> x >> y;
		Point p(x, y);
		originals_points.push_back(p);
	}
}

void print_all_points()
{
	for (size_t i = 0; i < originals_points.size(); i++)
	{
		std::cout << originals_points[i] << " ";
	}
}
std::fstream pointts("points.txt");

int main()
{
    menu();
    print_all_points();
    pointts.open("points.txt", std::ios::out);
	if (!pointts.is_open()) throw std::runtime_error("File not opened");
	for (size_t i = 0; i < originals_points.size(); i++)
	{
		pointts << originals_points[i] << " ";
	}
    return 0;
}