#include <iostream>
#include <vector>
#include "Customer.h"
#include "Account.h"
#include "BankEmployee.h"
#include "Administrator.h"
#include "Transaction.h"
#include "LoanApplication.h"

using namespace std;

int main() {
    vector<Customer> customers;
    vector<Account> accounts;

    int choice;

    do {
        cout << "\n��ӭʹ�����й���ϵͳ" << endl;
        cout << "1. ��ӿͻ�" << endl;
        cout << "2. �����˻�" << endl;
        cout << "3. ���" << endl;
        cout << "4. ȡ��" << endl;
        cout << "5. �鿴�˻����" << endl;
        cout << "6. �鿴�ͻ���Ϣ" << endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ�����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, id, address, phoneNumber;
            cout << "����ͻ�����: ";
            cin >> name;
            cout << "����ͻ�ID: ";
            cin >> id;
            cout << "�����ַ: ";
            cin >> address;
            cout << "����绰: ";
            cin >> phoneNumber;
            customers.emplace_back(name, id, address, phoneNumber);
            cout << "�ͻ���ӳɹ���" << endl;
            break;
        }
        case 2: {
            if (customers.empty()) {
                cout << "������ӿͻ���" << endl;
                break;
            }
            string accountNumber;
            cout << "�����˻�����: ";
            cin >> accountNumber;
            cout << "ѡ��ͻ�������ͻ�ID��: ";
            string customerId;
            cin >> customerId;

            for (const auto& customer : customers) {
                if (customerId == customer.getInfo()) { // ����ʵ������޸�ƥ�䷽ʽ
                    accounts.emplace_back(accountNumber, customer);
                    cout << "�˻������ɹ���" << endl;
                    break;
                }
            }
            break;
        }
        case 3: {
            string accountNumber;
            double amount;
            cout << "�����˻�����: ";
            cin >> accountNumber;
            cout << "��������: ";
            cin >> amount;

            for (auto& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    account.deposit(amount);
                    cout << "���ɹ���" << endl;
                    break;
                }
            }
            break;
        }
        case 4: {
            string accountNumber;
            double amount;
            cout << "�����˻�����: ";
            cin >> accountNumber;
            cout << "����ȡ����: ";
            cin >> amount;

            for (auto& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    account.withdraw(amount);
                    break;
                }
            }
            break;
        }
        case 5: {
            string accountNumber;
            cout << "�����˻�����: ";
            cin >> accountNumber;

            for (const auto& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    cout << "�˻����: " << account.getBalance() << endl;
                    break;
                }
            }
            break;
        }
        case 6: {
            string customerId;
            cout << "����ͻ�ID: ";
            cin >> customerId;

            for (const auto& customer : customers) {
                if (customerId == customer.getInfo()) { // ����ʵ������޸�ƥ�䷽ʽ
                    cout << customer.getInfo() << endl;
                    break;
                }
            }
            break;
        }
        case 0:
            cout << "�˳�ϵͳ��" << endl;
            break;
        default:
            cout << "��Чѡ�������ԡ�" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
