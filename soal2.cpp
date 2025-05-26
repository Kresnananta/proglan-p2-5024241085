#include <iostream>
#include <string>

class Vocaloid {
protected:
    std::string nama;
    int accuracy;
    int stamina;
public:
    Vocaloid(std::string nama, int accuracy, int stamina)
        : nama(nama), accuracy(accuracy), stamina(stamina) {}
    virtual void serang(Vocaloid& target) = 0;
    bool isAlive() const {
        return stamina > 0;
    }
    void printStatus() const {
        std::cout << nama << " has " << stamina << " stamina remaining." << std::endl;
    }
    std::string getNama() const {
        return nama;
    }
    int& getStamina() {
        return stamina;
    } 
};
 
class FirstVocaloid : public Vocaloid {
public:
    FirstVocaloid(std::string nama, int accuracy, int stamina)
        : Vocaloid(nama, accuracy, stamina) {}
    void serang(Vocaloid& target) override {
        target.getStamina() -= accuracy;
        if (target.getStamina() < 0) {
            target.getStamina() = 0;
        }
    }
};

class SecondVocaloid : public Vocaloid {
public:
    SecondVocaloid(std::string nama, int accuracy, int stamina)
        : Vocaloid(nama, accuracy, stamina) {}
    void serang(Vocaloid& target) override {
        target.getStamina() -= accuracy;
        if (target.getStamina() < 0) {
            target.getStamina() = 0;
        }
    }
};

int main() {
    std::string n1, n2, roll;
    int atk1, stam1, atk2, stam2;

    std::cin >> n1 >> atk1 >> stam1;
    std::cin >> n2 >> atk2 >> stam2;
    std::cin >> roll;
    if(roll != "first" && roll != "second"){
        std::cout << "Salah, masukan 'first atau 'second'" << std::endl;
        return 1;
    }

    FirstVocaloid mikuchan(n1, atk1, stam1);
    SecondVocaloid lukachan(n2, atk2, stam2);
    

    mikuchan.printStatus();
    lukachan.printStatus();

    while(mikuchan.isAlive() && lukachan.isAlive()){
        if(roll == "first"){
            mikuchan.serang(lukachan);
            std::cout << mikuchan.getNama() << " atacks " << lukachan.getNama() << "!" << std::endl;
            lukachan.printStatus();

            if(lukachan.isAlive() == false){
                break;
            }

            lukachan.serang(mikuchan);
            std::cout << lukachan.getNama() << " atacks " << mikuchan.getNama() << "!" << std::endl;
            mikuchan.printStatus();
        } else {
            lukachan.serang(mikuchan);
            std::cout << lukachan.getNama() << " atacks " << mikuchan.getNama() << "!" << std::endl;
            mikuchan.printStatus();

            if(mikuchan.isAlive() == false){
                break;
            }

            mikuchan.serang(lukachan);
            std::cout << mikuchan.getNama() << " atacks " << lukachan.getNama() << "!" << std::endl;
            lukachan.printStatus();
        }
        
    }

    if(mikuchan.isAlive()){
        std::cout << mikuchan.getNama() << " wins the contest!" << std::endl;
    } else {
        std::cout << lukachan.getNama() << " wins the contest!" << std::endl;
    }
}
