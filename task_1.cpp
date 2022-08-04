#include <iostream>

class Calculator {
public:

    double add() { return num1 + num2; }
    double multiply() { return num1 * num2; }
    double subtract_1_2() { return num1 - num2; }
    double subtract_2_1() { return num2 - num1; }
    double divide_1_2() { return divide(num1, num2); }
    double divide_2_1() { return divide(num2, num1); }
    bool set_num1(double num1) { return set_num(num1, this->num1); }
    bool set_num2(double num2) { return set_num(num2, this->num2); }

private:

    double num1{ 0.0 };
    double num2{ 0.0 };

    bool is_null(double var) { return (var < 0.0 || var > 0.0) ? false : true; }    // != для double
    double divide(double dividend, double divider);                                 //Чтобы не писать 2 раза почти одно и тоже
    bool set_num(double num, double& target);                                       //Чтобы не писать 2 раза почти одно и тоже
};

double Calculator::divide(double dividend, double divider) {
    if (!is_null(divider))
    {
        return dividend / divider;
    }
    else
    {
        std::cout << dividend << " / " << divider << " Делитель = 0, деление невозможно!" << std::endl;
        return 0.0;
    }
}

bool Calculator::set_num(double num, double& target) {
    if (!is_null(num))
    {
        target = num;
        return true;
    }
    else
    {
        std::cout << "Вы ввели нулевое значение. Небходимо повторить ввод" << std::endl;
        return false;
    }
}

double get_user_input(std::string msg) {
    double user_input = 0.0;
    std::cout << msg;
    std::cin >> user_input;
    return user_input;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Calculator calc;
    while (true)
    {
        while (!calc.set_num1(get_user_input("Введите num1: ")));
        while (!calc.set_num2(get_user_input("Введите num2: ")));
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }
    
}

