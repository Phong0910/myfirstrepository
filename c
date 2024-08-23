#include <iostream>
#include <vector>
#include <cmath> // Để sử dụng hàm abs()

// Hàm kiểm tra chữ số đầu tiên có phải là số lẻ không
bool isOddFirstDigit(int number) {
    number = abs(number);
    
    // Lấy chữ số đầu tiên
    while (number >= 10) {
        number /= 10;
    }
    
    // Kiểm tra nếu chữ số đầu là số lẻ
    return (number % 2 == 1);
}

// Hàm kiểm tra số lượng chữ số của một số
int countDigits(int number) {
    number = abs(number);
    int count = 0;
    
    while (number > 0) {
        number /= 10;
        count++;
    }
    
    return count;
}

// Hàm lọc các phần tử có chữ số đầu là số lẻ và có đúng số chữ số được chỉ định
std::vector<int> filterOddFirstDigitWithNDigits(const std::vector<int>& numbers, int n) {
    std::vector<int> result;
    
    for (int number : numbers) {
        if (isOddFirstDigit(number) && countDigits(number) == n) {
            result.push_back(number);
        }
    }
    
    return result;
}

int main() {
    std::vector<int> numbers = {123, 456, -789, 812, 37, -49, 1, 99, 12345};
    int n = 3; // Số chữ số mong muốn
    
    std::vector<int> filteredNumbers = filterOddFirstDigitWithNDigits(numbers, n);
    
    std::cout << "Các phần tử có " << n << " chữ số và chữ số đầu là số lẻ: ";
    for (int number : filteredNumbers) {
        std::cout << number << " ";
    }
    
    return 0;
}
