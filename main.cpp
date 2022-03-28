#include <iostream>
#include <vector>
#include <string>
#include <exception>

class NoElementExeption: public std::exception{
    const char* what() const noexcept override{
        return "Element not Found";
    }
};


template<typename T1,typename T2>
class Register{
    std::vector<std::pair<T1,T2>> reg;

public:
    Register(){};

    void add(){
        T1 key;
        T2 value;
        std::cout<<"Input key and value"<<std::endl;
        std::cin>>key>>value;
        reg.push_back(std::pair(key,value));
    }
    void print(){
        for(int i = 0; i < reg.size(); i++){
            std::cout<<reg[i].first<<" "<<reg[i].second<<std::endl;
        }
    }
    void find(T1 key){
        bool found = false;
        for(int i = 0; i < reg.size(); i++){
            if(reg[i].first == key){
                std::cout<<reg[i].second<<std::endl;
                found = true;
            }
        }
        if(!found) throw NoElementExeption();
    }

    void remove(T1 key){
        bool found = false;
        for(int i = 0; i < reg.size(); i++){
            if(reg[i].first == key){
                reg.erase(reg.begin()+i);
                i--;
                found = true;
            }
        }
        if(!found) throw NoElementExeption();
    }
};

int main() {
    std::string request;
    auto r = new Register<std::string,std::string>();
    std::cout<<"Input your request: add, remove, print, find, exit"<<std::endl;
    std::cin>>request;
    while(request!="exit") {
        if(request == "add") {
            r->add();
        }else if(request == "print") {
            r->print();
        }else if(request == "find"){
            try{
                std::string key;
                std::cout<<"Input key!"<<std::endl;
                std::cin>>key;
                r->find(key);
            }
            catch(const std::exception& x) {
                std::cerr << "Caught exception: " << x.what() << std::endl;
            }

        }else if(request == "remove"){
            try{
                std::string key;
                std::cout<<"Input key!"<<std::endl;
                std::cin>>key;
                r->remove(key);
            }
            catch(const std::exception& x) {
                std::cerr << "Caught exception: " << x.what() << std::endl;
            }

        }
        std::cout<<"Input your request: add, remove, print, find, exit"<<std::endl;
        std::cin>>request;
    }


    return 0;
}
