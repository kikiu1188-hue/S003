//Main.cpp

#include <iostream>
#include <string>

//using namespace std;

template <typename T>
class Inventory {
private:
    T* pItems_;
    int capacity_;
    int size_;

public:
    Inventory(int capacity = 10) {
        if (capacity <= 0) {
            capacity_ = 1;
        }
        else {
            capacity_ = capacity;
        }

        size_ = 0;
        pItems_ = new T[capacity_];
    }

    ~Inventory() {
        if (pItems_ != nullptr) {
            delete[] pItems_;
            pItems_ = nullptr;
        }
    }

    void AddItem(const T& item) {
        if (size_ < capacity_) {
            pItems_[size_] = item;
            size_++;
        }
        else {
            std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;
        }
    }

    void RemoveLastItem() {
        if (size_ > 0) {
        }
        else {
            std::cout << "인벤토리가 비어있습니다." << std::endl;
        }
    }

    int GetSize() const {
        return size_;
    }

    int GetCapacity() const {
        return capacity_;
    }

    void PrintAllItems() const {
        if (size_ == 0) {
            std::cout << "비어있음" << std::endl;
            return;
        }

        for (int i = 0; i < size_; i++) {
            pItems_[i].PrintInfo();
        }
    }
};


class Item {
private:
    std::string name_;
    int price_;

public:
    Item() : name_("Unknown"), price_(0) {}
    Item(std::string name, int price) : name_(name), price_(price) {}

    void PrintInfo() const {
        std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << std::endl;
    }
};

int main() {
    Inventory<Item> myInventory(3);

    std::cout << "--- 아이템 추가 ---" << std::endl;
    myInventory.AddItem(Item("초보자의 검", 100));
    myInventory.AddItem(Item("빨간 포션", 50));
    myInventory.AddItem(Item("나무 방패", 150));

    myInventory.AddItem(Item("전설의 활", 10000));

    std::cout << "\n--- 현재 인벤토리 상태 (" << myInventory.GetSize() << "/" << myInventory.GetCapacity() << ") ---" << std::endl;
    myInventory.PrintAllItems();

    std::cout << "\n--- 마지막 아이템 제거 ---" << std::endl;
    myInventory.RemoveLastItem();
    myInventory.PrintAllItems();

    std::cout << "\n--- 모두 제거 ---" << std::endl;
    myInventory.RemoveLastItem();
    myInventory.RemoveLastItem();
    myInventory.RemoveLastItem();

    std::cout << "\n--- 최종 인벤토리 상태 ---" << std::endl;
    myInventory.PrintAllItems();

    return 0;
}
