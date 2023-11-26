#include <iostream>
#include <vector>


int main(){
    short N = 0;
    std::cout << "Please input length of the massive: ";
    std::cin >> N;
    if ((N < 1) || (N > 10000)) {
        std::cerr << "Error! Wrong length of the massive." << std::endl;
        return -99;
    }
    else{
    std::vector <int> vect(N);
    //-----------------------The 1`st question-------------------------------
    //There are XXX different ways to change the length of std::vector:
    //1)vector.push_back(*something*),
    //  vector.emplace_back(*something*),
    //  vector.insert(pointer, *something*),
    //  vector.emplace(pointer, *something*) that adds new elements to the vector
    vect.push_back(1);
    vect.emplace_back(2);
    vect.insert(vect.begin() + 2, 3);
    vect.emplace(vect.begin() + 3, 4);
    // 2)vector.erase(pointer), vector.erase(begin, end) and std::erase(vector, *something*)
    vect.erase(vect.begin() + 3);
    // 3)vector.clear() that removes all elements of vector
    // 4)vector.resize(size) that changes number of elements in vector
    vect.resize(20);
    //-----------------------The 2`nd question---------------------------------
    //capacity is a parameter that says how many elements can contain vector before allocating more memory
    //size is a current number of elements in vector
    //capacity >= size
    //vector.resize(number) changes size of vector and if need its capacity
    //vector.reserve(number) changes capacity of vector and doesn`t change its size
    //vector.shrink_to_fit() makes capacity of vector equal to its size
    //-----------------------The 3`rd question---------------------------------
    //in <> we write type of data that the vector must contain
    //We even can do that: std::vector <std::vector <int>> matrix
    //-----------------------The 4`th question---------------------------------
    //As you see
    //-----------------------The 5`th question---------------------------------
    vect.resize(50);
    std::cout << vect[52]; //that will try to read memory out of range of vector
    std::cout << vect.at(52); //that will give you an error message
    //this happens because vector.at() checks if index bigger that size
    //if you are confident about indexes, its better to use []
    //although you can use vector.at() for debugging
    for (short i = 0; i < vect.size(); i++) std::cout << vect[i] << ' ';
    std::cout << std::endl;
    vect.clear();
    for (short i = 0; i < vect.size(); i++) std::cout << vect[i] << ' ';
    std::cout << std::endl;
    
    }
    return 0;
}