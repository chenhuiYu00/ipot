#include "uboost.h"
#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;

int main(){
    boost::filesystem::path path = boost::filesystem::current_path();
    cout<<path<<endl;
    return 0;
}


void uboost(){
    std::cout << "Hello, boost!" << std::endl;
}
