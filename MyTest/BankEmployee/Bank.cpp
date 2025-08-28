#include <iostream>
#include <string>
#include "Customer.h"
#include "Account.h"
#include "BankEmployee.h"
#include "Administrator.h"
#include "Transaction.h"
#include "LoanApplication.h"


// ������
int main() {
    // �����ͻ�����
    Customer customer1("����", "123456789", "����", "13800000000");

    // �����˻�����
    Account account1("ACC1001", customer1);
    account1.deposit(1000);

    // ��������ְԱ����
    BankEmployee employee1("EMP001", "����");

    // ��������Ա����
    Administrator admin1("ADMIN001", "����");

    // �������׼�¼����
    Transaction transaction1("TRANS001", account1.getAccountNumber(), 500, "2023-10-01", "ȡ��");

    // ���������������
    LoanApplication loan1("LOAN001", customer1, 50000);

    // ��ʾ����
    std::cout << "�ͻ���Ϣ: " << customer1.getInfo() << std::endl;
    std::cout << "�˻����: " << account1.getBalance() << std::endl;
    employee1.viewCustomerInfo(customer1);
    admin1.addUser(customer1);
    transaction1.displayTransaction();
    loan1.approve();
    std::cout << "��������״̬: " << loan1.getStatus() << std::endl;

    return 0;
}
