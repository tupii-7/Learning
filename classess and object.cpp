#include <iostream>

class abstractemployee {
    virtual void askforpromotion()=0;
};

class employee:abstractemployee{
private:
    std::string company;
    int age;

protected:
    std::string name;

public:
    void setname(std::string Name){
    name = Name;
    }
    std::string getname(){
        return name;
    }
    void setcompany(std::string Company){
        company = Company;
    }
    std::string getcompany(){
        return company;
    }
    void setage(int Age){
        if(Age>=18)
        age = Age;
    }
    int getage(){
        return age;
    }

    void introduce(){
        std::cout << "name: " << name << std::endl;
        std::cout << "company: " << company <<  std::endl;
        std::cout << "age: " << age << std::endl;
    }
    employee(std::string Name, std::string Company, int Age){
        name = Name;
        company = Company;
        age = Age;
    }
    void askforpromotion(){
        if(age>30)
            std::cout << name << " got promoted!" << std::endl;
        else
            std::cout << name << ", sorry, no promotion for you!" << std::endl;
    }
};

class developer:public employee {
public:
    std::string favprogramminglanguage;
    developer(std::string Name, std::string Company, int Age, std::string Favprogramminglanguage):employee(Name, Company, Age){
        favprogramminglanguage = Favprogramminglanguage;
    }

    void fixbug(){
        std::cout << name << " fixed a bug using " << favprogramminglanguage << std::endl;
    }
};

int main(){
    employee employee1 = employee("ari", "google", 31);
    employee1.introduce();

    std::cout << std::endl;

    developer dev = developer("vivi", "google", 33, "C++");
    dev.introduce();
    dev.fixbug();

    std::cout << std::endl;
    
    employee employee2 = employee("fiana", "microsoft", 22);
    employee2.introduce();

    std::cout << std::endl;
    
    employee1.askforpromotion();
    employee2.askforpromotion();
    dev.askforpromotion();

    return 0;
}