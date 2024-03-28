#include "Table.h" 
int main() {
    setlocale(LC_ALL, "Russian");
    int employees;
    cout << "������� ���������� ����������: ";
    cin >> employees;

    Table table(employees);
    char choice, endline;
    Job Object;
    Job* buf = &Object;

    do {
        cout << "1 - ����" << endl;
        cout << "2 - �����" << endl;
        cout << "3 - �����" << endl;
        cout << "4 - erase" << endl;
        cout << "5 - ��������" << endl;
        cout << "6 - ������" << endl;
        cout << "7 - ����������" << endl;
        cout << "0 - �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (choice) {
        case '1':
        {
            cout << "���� ��������" << endl;
            table.input(buf);
            cin.clear();
            break;
        }

        case '2':
        {
            cout << "��������:" << endl;
            table.output();
            cin.clear();
            break;
        }
        case '3':
        {

            cout << "������� ������� ��� ������:" << endl;
            buf->input();
            int i = table.find(buf);
            if (i >= 0) {
                cout << "position" << i << endl;
            }
            else {
                cout << "������� �� ������" << endl;
            }
            break;
        }
        case '4':
        {
            cout << "������� ������� ��� ��������:" << endl;

            int pos;
            cin >> pos;
            cin.get(endline);
            table.erase(table.begin() + pos);
            break;
        }
        case '5':
        {
            cout << "������� ������� ��� �������� �� ������" << endl;
            buf->input();
            int i = table.remove(buf);
            if (i == 0) {
                cout << "�� ������ �������" << endl;
            }
            break;
        }
        case '6':
        {
            cout << "������� ������ ������� ��� ������:" << endl;
            //cin.ignore();
            Job OldObject;
            Job* oldBuf = &OldObject;
            oldBuf->input();
            if (table.find(oldBuf) >= 0) {
                cout << "������� ����� �������:" << endl;
                Job NewObject;
                Job* newBuf = &NewObject;
                newBuf->input();
                table.replace(oldBuf, newBuf);
                cout << "������� ������� �������." << endl;
            }
            else {
                cout << "������ ������� �� ������." << endl;
            }
            break;
        }

        case '7': {
            cout << "����������" << endl;
            table.bubblesort();
            break;
        }

        default:
            if (choice != '0') {
                cout << "�������� �����. ���������� ��� ���." << endl;
            }
            break;
        }
    } while (choice != '0');
    return 0;
}