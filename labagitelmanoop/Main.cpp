#include "Table.h" 
int main() {
    setlocale(LC_ALL, "Russian");
    int employees;
    cout << "Введите количество работников: ";
    cin >> employees;

    Table table(employees);
    char choice, endline;
    Job Object;
    Job* buf = &Object;

    do {
        cout << "1 - ввод" << endl;
        cout << "2 - вывод" << endl;
        cout << "3 - поиск" << endl;
        cout << "4 - erase" << endl;
        cout << "5 - удаление" << endl;
        cout << "6 - замена" << endl;
        cout << "7 - сортировка" << endl;
        cout << "0 - выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (choice) {
        case '1':
        {
            cout << "Ввод элемента" << endl;
            table.input(buf);
            cin.clear();
            break;
        }

        case '2':
        {
            cout << "Элементы:" << endl;
            table.output();
            cin.clear();
            break;
        }
        case '3':
        {

            cout << "Введите элемент для поиска:" << endl;
            buf->input();
            int i = table.find(buf);
            if (i >= 0) {
                cout << "position" << i << endl;
            }
            else {
                cout << "Элемент не найден" << endl;
            }
            break;
        }
        case '4':
        {
            cout << "Введите позицию для удаления:" << endl;

            int pos;
            cin >> pos;
            cin.get(endline);
            table.erase(table.begin() + pos);
            break;
        }
        case '5':
        {
            cout << "Введите элемент для удаления по данным" << endl;
            buf->input();
            int i = table.remove(buf);
            if (i == 0) {
                cout << "Не найден элемент" << endl;
            }
            break;
        }
        case '6':
        {
            cout << "Введите старый элемент для замены:" << endl;
            //cin.ignore();
            Job OldObject;
            Job* oldBuf = &OldObject;
            oldBuf->input();
            if (table.find(oldBuf) >= 0) {
                cout << "Введите новый элемент:" << endl;
                Job NewObject;
                Job* newBuf = &NewObject;
                newBuf->input();
                table.replace(oldBuf, newBuf);
                cout << "Элемент успешно заменен." << endl;
            }
            else {
                cout << "Старый элемент не найден." << endl;
            }
            break;
        }

        case '7': {
            cout << "Сортировка" << endl;
            table.bubblesort();
            break;
        }

        default:
            if (choice != '0') {
                cout << "Неверный выбор. Попробуйте еще раз." << endl;
            }
            break;
        }
    } while (choice != '0');
    return 0;
}