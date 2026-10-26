#include <iostream>
#include <cmath> 
#include <Windows.h>

//f(x)
double f(double x) 
{
    return log(x) - cos(x);
}

//f'(x)
double df(double x) 
{
    return (1.0 / x) + sin(x);
}

int main() 
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::cout << "Шаг 1 сканирование" << std::endl;
    double a_start = 0.5;
    double b_end = 3.0;
    double h = 0.1;

    double a = 0.0;
    double b = 0.0;

    
    for (double x = a_start; x <= b_end - h; x = x + h) 
    {
        double x_next = x + h;

        
        if (f(x) * f(x_next) < 0) 
        {
            a = x;
            b = x_next;
            break;
        }
    }

    std::cout << "Найден отрезок [" << a << ", " << b << "]" << std::endl << std::endl;

   
    std::cout << "Шаг 2 Биссектриса" << std::endl;

    
    for (int i = 1; i <= 3; i = i + 1) 
    {
        double c = (a + b) / 2.0;
        std::cout << "Шаг " << i << ": c = " << c << ", f(c) = " << f(c) << std::endl;

        if (f(a) * f(c) < 0) 
        {
            b = c;
        }
        else 
        {
            a = c;
        }
    }

    
    double x0 = (a + b) / 2.0;
    std::cout << "Начальное приближённое х0 = " << x0 << std::endl << std::endl;

    
    std::cout << "Шаг 3 Ньютон" << std::endl;

    double accur = 0.00001;
    double x_curr = x0;
    double x_next = x0;
    int iter = 0;

    while (true) 
    {
        iter = iter + 1;
        double derivative = df(x_curr);

        
        double abs_derivative = derivative;
        if (abs_derivative < 0) 
        {
            abs_derivative = -abs_derivative;
        }

        if (abs_derivative < 0.0000000001) 
        {
            std::cout << "Ошибка! на ноль делить нельзя!" << std::endl;
            break;
        }

       
        x_next = x_curr - f(x_curr) / derivative;

        std::cout << "Итерация " << iter << ": x = " << x_next << ", f(x) = " << f(x_next) << std::endl;

        
        double diff = x_next - x_curr;
        if (diff < 0) 
        {
            diff = -diff; 
        }

        if (diff < accur) 
        {
            break; 
        }

        x_curr = x_next;
    }

    std::cout << std::endl;
    std::cout << "Корень найден: x = " << x_next << ", f(x) = " << f(x_next) << std::endl;

    return 0;
}
