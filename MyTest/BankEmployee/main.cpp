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
        cout << "\n欢迎使用银行管理系统" << endl;
        cout << "1. 添加客户" << endl;
        cout << "2. 创建账户" << endl;
        cout << "3. 存款" << endl;
        cout << "4. 取款" << endl;
        cout << "5. 查看账户余额" << endl;
        cout << "6. 查看客户信息" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, id, address, phoneNumber;
            cout << "输入客户姓名: ";
            cin >> name;
            cout << "输入客户ID: ";
            cin >> id;
            cout << "输入地址: ";
            cin >> address;
            cout << "输入电话: ";
            cin >> phoneNumber;
            customers.emplace_back(name, id, address, phoneNumber);
            cout << "客户添加成功！" << endl;
            break;
        }
        case 2: {
            if (customers.empty()) {
                cout << "请先添加客户！" << endl;
                break;
            }
            string accountNumber;
            cout << "输入账户号码: ";
            cin >> accountNumber;
            cout << "选择客户（输入客户ID）: ";
            string customerId;
            cin >> customerId;

            for (const auto& customer : customers) {
                if (customerId == customer.getInfo()) { // 根据实际情况修改匹配方式
                    accounts.emplace_back(accountNumber, customer);
                    cout << "账户创建成功！" << endl;
                    break;
                }
            }
            break;
        }
        case 3: {
            string accountNumber;
            double amount;
            cout << "输入账户号码: ";
            cin >> accountNumber;
            cout << "输入存款金额: ";
            cin >> amount;

            for (auto& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    account.deposit(amount);
                    cout << "存款成功！" << endl;
                    break;
                }
            }
            break;
        }
        case 4: {
            string accountNumber;
            double amount;
            cout << "输入账户号码: ";
            cin >> accountNumber;
            cout << "输入取款金额: ";
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
            cout << "输入账户号码: ";
            cin >> accountNumber;

            for (const auto& account : accounts) {
                if (account.getAccountNumber() == accountNumber) {
                    cout << "账户余额: " << account.getBalance() << endl;
                    break;
                }
            }
            break;
        }
        case 6: {
            string customerId;
            cout << "输入客户ID: ";
            cin >> customerId;

            for (const auto& customer : customers) {
                if (customerId == customer.getInfo()) { // 根据实际情况修改匹配方式
                    cout << customer.getInfo() << endl;
                    break;
                }
            }
            break;
        }
        case 0:
            cout << "退出系统。" << endl;
            break;
        default:
            cout << "无效选择，请重试。" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
