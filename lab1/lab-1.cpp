#include <iostream>
#include <limits>
void module_arr( int n, int* arr);
int null_count(int zero_counter);
int input();

int main()
{
    std::cout << "Введите кол-во элементов массива ";
    int n = input();

    srand(time(NULL));

    int minA = - ( (n / 2) -1);
    int maxA = n / 2;

    int arr[n];


    int zero = 0;
    for (int i =0; i < n; i++){
        arr[i] = minA + rand() % (maxA - minA +1);
        std::cout << arr[i] << " ";
        if (arr[i] == 0){
            zero++;
        }
    }
    std::cout << std::endl;



    std::cout << "Выбери функцию: \n \
    1)Заменить все отрицательные значения элементов на модули их значений O(n)\n \
    2)Подсчитать количество элементов с нулевым значением O(1)\n" ;

    int ans= input();

    if (ans == 1) {
        module_arr(n, arr);
        std::cout << "\nЗамена проведена\n";
    }   else if (ans == 2) {
        std::cout << "Количество нулей: " << null_count(zero) << std::endl;
    } else {
        std::cout << "Нету функции под номером " << ans << "\n";
        return 1;
    }
    return 0;
}
int input() {
    int n;
    std::cout << "Введите число: ";
    
    while (true) {
        std::cin >> n;
        
        if (std::cin.fail()) {
            std::cout << "Введите число (n must be integer): ";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else {
            return n;
        }
    }
}


void module_arr( int n, int* arr){
    for (int i=0; i < n; i++){
        if (arr[i] < 0) {
            arr[i] = - arr[i];
        }
        std::cout << arr[i] << " ";
    }
}

int null_count(int zero_counter){
    return zero_counter;
}
