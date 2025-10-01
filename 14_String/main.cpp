#include <iostream>
#include <string>
#include <fstream> 
#include <stdexcept>
using namespace std;



class file_utils {
public:
	/**
	 * @brief Зчитує весь вміст файлу в рядок.
	 *
	 * @param file_path Шлях до файлу.
	 * @return std::string Вміст файлу.
	 * @throws std::runtime_error якщо файл не вдалося відкрити.
	 */
	static string read_file_to_string(const string& file_path) {
		ifstream file_stream(file_path);

		if (!file_stream.is_open()) {
			throw runtime_error("Не вдалося відкрити файл для читання: " + file_path);
		}

		return string((istreambuf_iterator<char>(file_stream)),
			istreambuf_iterator<char>());
	}

	/**
	 * @brief Записує рядок у файл.
	 *
	 * @param file_path Шлях до файлу. Якщо файл існує, його буде перезаписано.
	 * @param content Рядок, який потрібно записати.
	 * @throws std::runtime_error якщо файл не вдалося відкрити для запису.
	 */
	static void write_string_to_file(const string& file_path, const string& content) {
		ofstream file_stream(file_path);

		if (!file_stream.is_open()) {
			throw runtime_error("Не вдалося відкрити файл для запису: " + file_path);
		}

		file_stream << content;
	}
};




int main() {



	/*string s1;
	string s2 = "hello";
	string s3(s2);
	string s4(10, '*');
	cout << s4;*/


	/*string str1 = "hello";
	string str2 = "world";

	string str3 = str1 + " " + str2;
	cout << str3;*/

	/*string str1 = "hello";
	string str2 = "world";
	str1 += str2;
	cout << str1 << endl << str2;*/

	/*string str1 = "hello";
	string str2;
	str2 = str1;
	cout << str2;*/

	/*string str = "hello world";
	cout << str[4];
	str[4] = 'a';
	cout << str[4];*/

	//string str1 = "hello";
	//string str2 = "hello";
	///*if (str1 == str2) cout << "Equals";
	//else cout << "Not Equals";*/
	//if (str1 > str2) cout << "First is bigger";
	//else cout << "Second is bigger";

	// insert

	/*string str = "hello world";
	str.insert(6, "all ");
	cout << str;*/

	// erase

	/*string str = "hello world";
	str.erase(2, 3);
	cout << str;*/

	// reaplace

	/*string str = "hello world";
	str.replace(6, 5, "all");
	cout << str;*/

	/*string str = "hello world";
	cout << str.length();*/

	// find

	/*string str = "hello all world all hello all hi";
	string search = "all";
	int pos = -1;
	do {
		pos = str.find(search, pos + 1);
		if (pos != -1) str.erase(pos, search.length());
	} while (pos != -1);

	cout << str;*/

	/*string str = "hello world";
	string str2 = str.substr(6, 3);
	cout << str2;*/

	/*string str = "g";
	if (str.empty()) cout << "String is empty";*/

	//string str;
	////cin >> str;
	//getline(cin, str);
	//cout << str;

	/*string str = "hellozzzzz all wzorld all hello alzl hi";
	string search = "z";
	int pos = 0;
	do {
		pos = str.find(search, pos);
		if (pos != -1) str.erase(pos, search.length());
	} while (pos != -1);
	str.insert(str.length() / 2, "ABC");
	cout << str;*/

	string filePath = "data.txt";
	string text =  file_utils::read_file_to_string(filePath);
	string a, b;
	int pos, count;

	int choice;
	do {

		cout << endl << endl << "1 - Show text" << endl;
		cout << "2 - Count symbols" << endl;
		cout << "3 - Find word" << endl;
		cout << "4 - Replace word" << endl;
		cout << "5 - Erase word" << endl;
		cout << "6 - Reverse" << endl;
		cin >> choice;
		system("cls");
		switch (choice) {
			case 1:
				cout << text;
				break;
			case 2:
				cout << text.length();
				break;
			case 3:
				cout << "Type a word: ";
				cin >> a;
				system("cls");
				if (text.find(a) == -1) cout << "Word was not found";
				else {
					count = 0;
					pos = -1;
					cout << "Positions: ";
					do {
						pos = text.find(a, pos + 1);
						cout << pos << " ";
						count++;
					} while (pos != -1);
					cout << endl << "Total amount: " << count;
				}
				break;
			case 4:
				cout << "Type a word: ";
				cin >> a;
				cout << "Type second word: ";
				cin >> b;
				system("cls");
				if (text.find(a) == -1) cout << "Word was not found";
				else {
					count = 0;
					pos = -1;
					cout << "Positions: ";
					do {
						pos = text.find(a, pos + 1);
						cout << pos << " ";
						count++;
					} while (pos != -1);
					cout << endl << "Total amount: " << count;
				}
				break;
		}

	} while (choice != 0);

	





	return 0;
}