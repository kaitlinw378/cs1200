#include <fstream> 
#include <iostream> 
#include <cstdlib>
#include <string>
#include <iomanip>
#include <iostream> 

std::string repeat_square_string(std::string str, int num){
        std::string temp = str;
        for (int i =1; i < (num*num); i++){
            str += temp; 
        }
        return str;
}

std::string repeat_right_string(std::string str, int num){
    std::string temp = str;
    for (int i = 1; i <(num*2); i++){
        str += temp;
    }
    return str;
}

std::string repeat_iso_string(std::string str, int num){
    std::string temp = str; 
    for (int i = 1; i < (num*num); i++){
        str += temp;
    }
    return str;
}

void draw_square(std::string in_string, int size, std::string string_type,
                std::ofstream &output){
    for (int i = 0; i < size; i++){
        output << "*";
    }
    output << "\n";
    int i = 0; 
    in_string = repeat_square_string(in_string, size);    
    while (i < (size-2)){
        std::string str = in_string.substr(0, (size-2));
        output << "*" << str << "*\n";
        in_string.erase(0, (size-2));
        i++; 
    }
    for (int i = 0; i < size; i++){
        output << "*";
    }
    output << "\n";
}

void draw_right_triangle(std::string in_string, int size, std::string string_type, std::ofstream &output){
    output << "*\n";
    int i = 0;
    in_string = repeat_right_string(in_string, size);
    while ( i < (size-2)){
        std::string str = in_string.substr(0,i);
        output << "*" << str << "*\n"; 
        in_string.erase(0,i);
        i++;
    }
    for (int i = 0; i < size; i++){
        output << "*";
    }
    output << "\n";
}

void draw_isosceles_triangle(std::string in_string, int size, std::string string_type, std::ofstream &output){
    output << " " << std::setw(size-1) << "*" << "\n";
    int i = 1; 
    in_string = repeat_iso_string(in_string, size);

    output << " " << std::setw(size-1-i) << "*" << in_string.substr(0,i) << "*\n";
    while (i < (size-2)){
        output << " " << std::setw(size-2-i) << "*" << in_string.substr(i, 2*i+1) <<"*\n";
        in_string.erase(0,2*i);
        i++;
    }
    for (int i = 0; i < ((size*2)-1); i++){
        output << "*";
    }
    output << "\n";
}

int main(int argc, char *argv[]){

    if(argc < 5 ) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        return 1;
    }
  
    std::string input_string = (argv[1]); 
    int height = atoi (argv[2]);
    std::string shape (argv[3]);

    std::ofstream output (argv[4]); 
    if(output.is_open()) {
        if (shape == "square"){
    
            draw_square(argv[1], atoi (argv[2]), argv[3], output);     
        }
        else if (shape == "right_triangle"){
            draw_right_triangle(argv[1], atoi (argv[2]), argv[3], output);
        }
        else if (shape == "isosceles_triangle"){
            draw_isosceles_triangle(argv[1], atoi (argv[2]), argv[3], output); 
        } else{
            std::cerr << "There is a problem with arguments\n";
        }

        output.close();
    }
    else {
        std::cerr << "Could not open output file" << std::endl;
        return 1;
    }
    return 0;
}
