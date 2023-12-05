#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
    // ประกาศ map ที่มี key เป็น int และ value เป็น queue ของ priority_queue ของ int
    std::map<int, std::queue<std::priority_queue<int> > > m;

    // เพิ่มข้อมูลเข้าไปใน map เพื่อทดสอบ
    m[1].push(std::priority_queue<int>({3, 1, 4}));
    m[2].push(std::priority_queue<int>({2, 7, 5}));

    // แสดงผลลัพธ์
    for (auto& entry : m) {
        std::cout << "Key: " << entry.first << " | Values: ";

        while (!entry.second.empty()) {
            std::priority_queue<int> pq = entry.second.front();
            entry.second.pop();

            while (!pq.empty()) {
                std::cout << pq.top() << ' ';
                pq.pop();
            }

            std::cout << " | ";
        }

        std::cout << std::endl;
    }

    // แก้ไข m
    m[3].push(std::priority_queue<int>({9, 8, 6}));

    // แสดงผลลัพธ์หลังจากแก้ไข
    std::cout << "\nAfter modification:\n";

    for (auto& entry : m) {
        std::cout << "Key: " << entry.first << " | Values: ";

        while (!entry.second.empty()) {
            std::priority_queue<int> pq = entry.second.front();
            entry.second.pop();

            while (!pq.empty()) {
                std::cout << pq.top() << ' ';
                pq.pop();
            }

            std::cout << " | ";
        }

        std::cout << std::endl;
    }

    return 0;
}
