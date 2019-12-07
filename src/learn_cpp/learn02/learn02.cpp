#include<iostream>
#include<string>

using namespace std;
class Human{
    public:
        string name;
        Human(){
            name = "none";
        }
        Human(string _name){
            name = _name;
        }

        void Say_Name(){
            Say(name);
        }
    private:
        string p_string;
        void Say(string a) {
            cout << a << endl;
        }
};

class Asian : public Human{
    public:
        Asian(string _name) : Human(){
            name = _name;
        }
};

int main(){
    Human h1("A");
    Human h2("B");
    
    Asian a1("C");

    h1.Say_Name();
    h2.Say_Name();

    a1.Say_Name();

    return 0;
}