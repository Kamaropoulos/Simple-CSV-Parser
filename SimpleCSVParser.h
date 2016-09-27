#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

vector<vector<string>> Parse_CSV(string csv_file_name) {
	ifstream csv_file(csv_file_name);
	vector<vector<string>> records;
	if (!csv_file) {
		cout << "Error while opening file!" << endl; system("PAUSE"); exit(1); }
	string line;
	int line_count = -1;
	while (getline(csv_file, line)) {
		vector<string> current_line;
		++line_count;
		int quotes = 0;
		int records_count = 0;
		string temp_record = "";
		for (int i = 0; i < line.length(); i++) {
			char temp_char;
			temp_char = line[i];
			switch (temp_char) {
			case ',': if (quotes == 1) { temp_record += temp_char; continue; }
					  else {
						  current_line.push_back(temp_record);
						  temp_record = "";
						  ++records_count;

					  }
					  break;

			case '\"': if (quotes == 0) {
				quotes = 1;
				break;
			}
					   else if (quotes == 1) {
						   quotes = 0;
					   }
					   break;
			default: temp_record += temp_char;
				break;
			}
		}
		current_line.push_back(temp_record);
		records.push_back(current_line);
	}
	return records;
}