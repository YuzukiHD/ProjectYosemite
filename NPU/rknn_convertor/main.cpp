#include <iostream>
#include <fstream>
#include <vector>

int main(int c, char *v[]){
	
	if(c < 2)
		return -1;

    size_t size = 0;

    size = std::filesystem::file_size(v[1]); 

    std::ifstream ifstream(v[1], std::ios::in | std::ios::binary);

    auto magic = new char[24];
    ifstream.read(reinterpret_cast<char *>(&magic), std::streamsize(24 * sizeof(char)));

    std::vector<char> temp;
    ifstream.read(reinterpret_cast<char *>(&temp[0]), std::streamsize((size - 24) * sizeof(char)));
    std::string indata(temp.begin(), temp.end());
}