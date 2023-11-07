#include <iostream>
#include <fstream>
int countValue; //значений в list 
struct Hub
{
    int data;
    Hub* next;
    Hub* prev;
};

int InputData(const char* mes = "Введите число: ", const char* mesError = "!!ERROR!!") //Ввод неотрицательного числа
{
    setlocale(0, "rus");

    std::string str;
    bool isInt = true;
    std::cout << mes << "\n";
    std::cin >> str;
    bool isMinus = str[0] == '-' or isdigit(str[0]);
    for (int i = 1; i < str.size() or !isMinus; ++i) {
        if (!isdigit(str[i])) {
            isInt = false;
            std::cout << mesError << "\n";
            int resalt = InputData(mes, mesError);
            return resalt;
        }
    }
    if (isInt and isMinus) {
        int resalt = atoi(str.c_str());
        return resalt;
    }
}
struct LinkedList
{
    Hub* last, * tail, * curr, * head;
    void CreateList() {
        countValue = InputData("Введите желаемое количество элементов:");
        while (countValue <= 0)
        {
            countValue = InputData("Введите желаемое количество элементов:");
        }
        last = new Hub;
        last->data = InputData("Введите 1 элемент: ");
        last->next = NULL;
        last->prev = NULL;
        head = last;
        for (int i = 1; i < countValue; i++) {
            curr = new Hub;
            std::cout << "Введите" << ' ' << i + 1 << " элемент: ";
            curr->data = InputData("");
            curr->prev = last;
            last->next = curr;
            last = curr;
        }
        tail = last;
        last->next = NULL;
        std::cout << "\n------------------------------------------------";
        std::cout << "\n[! Список успешно сформирован !]\n";
        std::cout << "------------------------------------------------\n";
    }
    void WriteList(bool isLeft = true) {
        if (countValue > 0)
            if (isLeft)
            {
                curr = head;
                std::cout << "\n------------------------------------------------\n";
                while (curr != NULL) {
                    std::cout << curr->data << '\t';
                    curr = curr->next;
                }
                std::cout << "\n------------------------------------------------\n";
            }
            else
            {
                curr = tail;
                std::cout << "\n------------------------------------------------\n";
                while (curr != NULL) {
                    std::cout << curr->data << '\t';
                    curr = curr->prev;
                }
                std::cout << "\n------------------------------------------------\n";
            }
        else 
        {
            std::cout << "\n------------------------------------------------";
            std::cout << "\n[! Список пуст !]\n";
            std::cout << "------------------------------------------------\n";
        }
    }
    void AddElement()
    {
        int positionElement;
        positionElement = InputData("Введите номер элемента перед которым желаете добавить новый элемент: ");
        while (!(positionElement > 0 and positionElement <= countValue))
        {
            positionElement = InputData("Введите номер элемента перед которым желаете добавить новый элемент: ");
        }
        if (positionElement > countValue / 2)
        {
            last = tail;
            for (int i = 0; i < countValue - positionElement + 1; i++)
            {
                last = last->prev;
            }
            Hub* AddElement = last->next;
            if (positionElement > 0) {
                curr = new Hub;
                curr->data = InputData("Введите элемент: ");
                curr->prev = last;
                last->next = curr;
                last = curr;
            }
            AddElement->prev = last;
            last->next = AddElement;
        }
        else {
            last = positionElement > 1 ? head : NULL;
            if (positionElement > 1) last = head;
            else last = NULL;
            for (int i = 0; i < positionElement - 2; i++)
            {
                last = last->next;
            }
            Hub* AddElement;
            if (last == NULL) AddElement = head;
            else AddElement = last->next;
            if (positionElement) {
                curr = new Hub;
                curr->data = InputData("Введите элемент: ");
                if (last != NULL) {
                    curr->prev = last;
                    last->next = curr;
                }
                else {
                    curr->prev = NULL;
                    head = curr;
                }
                last = curr;
            }
            if (last != NULL) {
                AddElement->prev = last;
                last->next = AddElement;
            }
        }
        countValue++;
        std::cout << "\n------------------------------------------------";
        std::cout << "\n[! В список успешно добавлен новый элемент !]\n";
        std::cout << "------------------------------------------------\n";
    }
    void WriteFile() 
    {
        std::ofstream FileList("FileList.txt");
        if (!FileList.is_open()) 
        {
            std::cout << "Ошибка при открытии файла";
            return;
        }
        curr = head;
        FileList << ' ' << countValue;
        while (curr != NULL) {
            FileList << ' ' << curr->data;
            curr = curr->next;
        }
        FileList.close();
        std::cout << "\n------------------------------------------------";
        std::cout << "\n[! Список успешно записан в файл FileList.txt !]\n";
        std::cout << "------------------------------------------------\n";
    }
    void ReadFile() 
    {
        std::ifstream FileList("FileList.txt");
        if (!FileList.is_open())
        {
            std::cout << "Ошибка при открытии файла";
            return;
        }
        FileList >> countValue;
        head = new Hub;
        FileList >> head->data;
        head->prev = NULL;
        last = head;
        while (FileList.get() && !FileList.eof()) {
            curr = new Hub;
            FileList >> curr->data;
            curr->prev = last;
            last->next = curr;
            last = curr;
        }
        last->next = NULL;
        tail = last;
        FileList.close();
        std::cout << "\n------------------------------------------------";
        std::cout << "\n[! Список успешно считан из файла FileList.txt !]\n";
        std::cout << "------------------------------------------------\n";
    }
    void DeleteElementsEnd() 
    {
        int countElement;
        countElement = InputData("Введите количество элементов для удаления с конца: ");
        while (!(countElement > 0 and countElement <= countValue))
        {
            countElement = InputData("Введите количество элементов для удаления с конца: ");
        }

        while (countElement-->0)
        {
            if (tail == NULL) return;
            Hub* curr = tail->prev;
            if (curr != NULL)
                curr->next = NULL;
            else
                head = NULL;
            delete tail;
            tail = curr;
            countValue--;
        }
        std::cout << "\n------------------------------------------------";
        std::cout << "\n[! Из списка успешно удалены элементы !]\n";
        std::cout << "------------------------------------------------\n";
        
    }
    void DeleteList() 
    {
        last = head;
        while (last != NULL) {
            curr = last->next;
            delete last;
            last = curr;
        }
        countValue = 0;
        std::cout << "\n------------------------------------------------";
        std::cout << "\n[! Список успешно удален !]\n";
        std::cout << "------------------------------------------------\n";
    }

};
int main()
{
    setlocale(0, "rus");
    std::srand(time(NULL));
    std::cout << "Hello World!\n";
    LinkedList list;
    list.CreateList();
    list.WriteList();
    list.AddElement();
    list.WriteList();
    list.DeleteElementsEnd();
    list.WriteList();
    list.WriteFile();
    list.DeleteList();
    list.WriteList();
    list.ReadFile();
    list.WriteList();
    list.DeleteList();
    std::cout << "\vКОНЕЦ";
}
