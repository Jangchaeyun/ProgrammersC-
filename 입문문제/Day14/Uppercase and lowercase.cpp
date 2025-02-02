#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
	string answer = "";

	for (auto& s : my_string)
	{
		if (s <= 'Z')
			s = tolower(s);
		else
			s = toupper(s);
	}

	return my_string;
}