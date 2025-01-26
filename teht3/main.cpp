#include <iostream>
#include <string>
#include <algorithm>

class Chef {
protected:
    std::string chefName;

public:
    Chef(const std::string& name) : chefName(name) {
        std::cout << "Chef " << chefName << " konstruktori\n";
    }

    virtual ~Chef() {
        std::cout << "Chef " << chefName << " destruktori\n";
    }

    int makeSalad(int ingredients) const {
        int portions = ingredients / 5;
        std::cout << "Chef " << chefName << " with " << ingredients
                  << " items can make salad " << portions << " portions\n";
        return portions;
    }

    int makeSoup(int ingredients) const {
        int portions = ingredients / 3;
        std::cout << "Chef " << chefName << " with " << ingredients
                  << " items can make soup " << portions << " portions\n";
        return portions;
    }
};

class ItalianChef : public Chef {
private:
    std::string password = "pizza";
    int flour;
    int water;


    int makePizza(int flourAmount, int waterAmount) {
        int pizzas = std::min(flourAmount / 5, waterAmount / 5);
        std::cout << "ItalianChef " << chefName << " with " << flourAmount
                  << " flour and " << waterAmount << " water can make " << pizzas
                  << " pizzas\n";
        return pizzas;
    }

public:
    ItalianChef(const std::string& name, int initialFlour, int initialWater)
        : Chef(name), flour(initialFlour), water(initialWater) {
        std::cout << "ItalianChef " << chefName << " konstruktori\n";
    }

    ~ItalianChef() override {
        std::cout << "ItalianChef " << chefName << " destruktori\n";
    }

    bool askSecret(const std::string& inputPassword, int flourAmount, int waterAmount) {
        if (inputPassword.compare(password) == 0) { // Password is correct
            std::cout << "Password ok!\n";
            makePizza(flourAmount, waterAmount);
            return true;
        } else {
            std::cout << "Incorrect password. Cannot make pizzas.\n";
            return false;
        }
    }
};

int main() {
    Chef generalChef("Gordon");
    generalChef.makeSalad(11);
    generalChef.makeSoup(14);

    std::cout << "\n";

    ItalianChef italianChef("Mario", 12, 12);
    italianChef.makeSalad(9);
    italianChef.askSecret("pizza", 12, 12);

    std::cout << "\n";

    return 0;
}
