#include<iostream>
#include<yaml-cpp/yaml.h>

int main(){
    YAML::Node books = YAML::LoadFile("data/book.yaml");

    for(const auto& pair : books["books"]){
        const auto& book = pair.second;

        std::cout<<book["name"]<<'\n';
        std::cout<<"    Pages: "<<book["pages"].as<std::string>()<<'\n';
        std::cout<<"\n";
    }
/*
    // Compress the file
    bool success = compress("data/books.yaml", "books.br");
    if(!success){
        std::cerr<<"Compression failed.\n";
        return 1;
    }
*/
    return 0;
}